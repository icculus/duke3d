/*
 * A reimplementation of James R. Dose's FX_MAN routines, using a hacked
 *  version of SDL_mixer 1.2.0. Whee.
 *
 * Written by Ryan C. Gordon. (icculus@linuxgames.com)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include "SDL.h"
#include "SDL_mixer.h"
#include "fx_man.h"

#if ((defined __WATCOMC__) && (!defined snprintf))
#define snprintf _snprintf
#endif

#define __FX_TRUE  (1 == 1)
#define __FX_FALSE (!FX_TRUE)

#define DUKESND_DEBUG       "DUKESND_DEBUG"


static char[50] __FX_warningMessage;
static char[50] __FX_errorMessage;
static int __FX_initialized = 0;
static int __FX_numChannels = MIX_CHANNELS;
static void (*__FX_callback)(unsigned long);
static int __FX_reverseStereo = 0;
static int __FX_reverbLevel = 0;
static int __FX_fastReverb = 0;
static unsigned long *__FX_callbackvals = NULL;
static FILE *__FX_debug_file = NULL;
static int __FX_initialized_debugging = 0;
static int __FX_maxReverbDelay = 256;


static void snddebug(const char *fmt, ...)
{
    va_list ap;

    if (__FX_debug_file)
    {
        fprintf(__FX_debug_file, "DUKESND: ");
        va_start(ap, fmt);
        vfprintf(__FX_debug_file, fmt, ap);
        va_end(ap);
        fprintf(__FX_debug_file, "\n");
        fflush(__FX_debug_file);
    } // if
} // snddebug


static void init_debugging(void)
{
    const char *envr;

    if (__FX_initialized_debugging)
        return;

    envr = getenv(DUKESND_DEBUG);
    if (envr != NULL)
    {
        if (strcmp(envr, "-") == 0)
            __FX_debug_file = stdout;
        else
            __FX_debug_file = fopen(envr, "w");

        if (__FX_debug_file == NULL)
            printf("DUKESND: -WARNING- Could not open debug file!\n");
        else
            setbuf(__FX_debug_file, NULL);
    } // if

    __FX_initialized_debugging = 1;
} // init_debugging



// !!! FIXME: Is this correct behaviour?
char *FX_ErrorString( int ErrorNumber )
{
    switch (ErrorNumber)
    {
        case FX_Warning:
            return(__FX_warningMessage);

        case FX_Error:
            return(__FX_errorMessage);

        case FX_Ok:
            return("OK; no error.");

        case FX_ASSVersion:
            return("Incorrect sound library version.");

        case FX_BlasterError:
            return("SoundBlaster Error.");

        case FX_SoundCardError:
            return("General sound card error.");

        case FX_InvalidCard:
            return("Invalid sound card.");

        case FX_MultiVocError:
            return("Multiple voc error.");

        case FX_DPMI_Error:
            return("DPMI error.");

        default:
            return("Unknown error.");
    } // switch

    assert(0);    // shouldn't hit this point.
    return(NULL);
} // FX_ErrorString


// I use snprintf(), because, unline strncpy, it'll always add the null char.
static void __FX_setWarningMessage(const char *msg)
{
    snddebug("setting warning message to [%s].", msg);
    snprintf(__FX_warningMessage, sizeof (__FX_warningMessage), "%s", msg);
} // __FX_setErrorMessage


static void __FX_setErrorMessage(const char *msg)
{
    snddebug("setting error message to [%s].", msg);
    snprintf(__FX_errorMessage, sizeof (__FX_errorMessage), "%s", msg);
} // __FX_setErrorMessage


int FX_GetBlasterSettings( fx_blaster_config *blaster )
{
    __FX_setErrorMessage("No SoundBlaster cards available.");
    return(FX_Error);
} // FX_GetBlasterSettings


int FX_SetupSoundBlaster( fx_blaster_config blaster, int *MaxVoices,
                          int *MaxSampleBits, int *MaxChannels )
{
    __FX_setErrorMessage("No SoundBlaster cards available.");
    return(FX_Error);
} // FX_SetupSoundBlaster


static void __FX_postMixFilter(void *udata, Uint8 *stream, int len)
{
    // !!! FIXME: Add reverb filter here!
    // !!! FIXME: Add stereo reverse filter here!
} // __FX_postMixFilter


static void __FX_channelDoneCallback(int channel)
{
    if (__FX_callback)
    {
        __FX_callback(__FX_callbackvals[channel]);
        Mix_FreeChunk(Mix_GetChunk(channel));
    } // if
} // __FX_postMixFilter


int FX_SetupCard( int SoundCard, fx_device *device )
{
    init_debugging();

    snddebug("FX_SetupCard looking at card id #%d...", SoundCard);

    if (device == NULL)  // sanity check.
    {
        __FX_setErrorMessage("fx_device is NULL in FX_SetupCard!");
        return(FX_Error);
    } // if

        // Since the actual hardware is abstracted out on modern operating
        //  systems, we just pretend that the system's got a SoundScape.
        //  I always liked that card, even though Ensoniq screwed me on OS/2
        //  drivers back in the day.  :)
    if (SoundCard != SoundScape)
    {
        __FX_setErrorMessage("Card not found.");
        return(FX_Error);
    } // if

    device->MaxVoices = 8;
    device->MaxSampleBits = 16;       // SDL_mixer downsamples if needed.
    device->MaxChannels = 2;          // SDL_mixer converts to mono if needed.

    return(FX_Ok);
} // FX_SetupCard


int FX_Init(int SoundCard, int numvoices, int numchannels,
            int samplebits, unsigned mixrate)
{
    Uint16 audio_format = 0;

    init_debugging();

    snddebug("INIT! card=>%d, voices=>%d, chan=>%d, bits=>%d, rate=>%du...",
                SoundCard, numvoices, numchannels, samplebits, mixrate);

    if (__FX_initialized)
    {
        __FX_setErrorMessage("Sound system is already initialized.");
        return(FX_Error);
    } // if

    if (SoundCard != SoundScape) // We pretend there's a SoundScape installed.
    {
        __FX_setErrorMessage("Card not found.");
        return(FX_Error);
    } // if

        // other sanity checks...
    if ((numvoices < 0) || (numvoices > 8))
    {
        __FX_setErrorMessage("Invalid number of voices to mix (must be 0-8).");
        return(FX_Error);
    } // if

    if ((numchannels != MonoFx) && (numchannels != StereoFx))
    {
        __FX_setErrorMessage("Invalid number of channels (must be 1 or 2).");
        return(FX_Error);
    } // if

    if ((samplebits != 8) && (samplebits != 16))
    {
        __FX_setErrorMessage("Invalid sample size (must be 8 or 16).");
        return(FX_Error);
    } // if

    audio_format = (sample_bits == 8) ? AUDIO_U8 : AUDIO_S16;
    if (Mix_OpenAudio(mixrate, audio_format, numchannels, 4096) < 0)
    {
        __FX_setErrorMessage(SDL_GetError());
        return(FX_Error);
    } // if

    __FX_numChannels = Mix_AllocateChannels(numvoices);
    if (__FX_numChannels != numvoices)
    {
        __FX_setErrorMessage(SDL_GetError());
        Mix_CloseAudio();
        return(FX_Error);
    } // if

    blocksize = sizeof (unsigned long) * numvoices;
    __FX_callbackvals = malloc(blocksize);
    if (__FX_callbackvals == NULL)
    {
        __FX_setErrorMessage("Out of memory");
        Mix_CloseAudio();
        return(FX_Error);
    } // if
    memset(__FX_callbackvals, '\0', blocksize);

    Mix_SetPostMix(__FX_postMixFilter, NULL);
    Mix_ChannelFinished(__FX_channelDoneCallback);
    __FX_maxReverbDelay = (int) (((float) mixrate) * 0.5);

    __FX_initialized = 1;
    return(FX_Ok);
} // FX_Init


int FX_Shutdown( void )
{
    snddebug("shutting down sound subsystem.");

    if (!__FX_initialized)
    {
        __FX_setErrorMessage("Sound system is not currently initialized.");
        return(FX_Error);
    } // if

    Mix_CloseAudio();
    __FX_callback = NULL;
    free(__FX_callbackvals);
    __FX_callbackvals = NULL;
    __FX_reverseStereo = 0;
    __FX_reverbLevel = 0;
    __FX_fastReverb = 0;
    __FX_initialized = 0;
    __FX_maxReverbDelay = 256;
    return(FX_Ok);
} // FX_Shutdown


int FX_SetCallBack(void (*func)(unsigned long))
{
    __FX_callback = func;
    return(FX_Ok);
} // FX_SetCallBack


void FX_SetVolume(int volume)
{
    snddebug("setting master volume to %f.2 percent.", (volume / 255.0) * 100);
    Mix_Volume(-1, volume >> 1);  // it's 0-128 in SDL_mixer, not 0-255.
} // FX_SetVolume


int FX_GetVolume(void)
{
    return(Mix_Volume(-1, -1) << 1);
} // FX_GetVolume


void FX_SetReverseStereo(int setting)
{
    __FX_reverseStereo = setting;

#if 1
    // !!! FIXME
    if (__FX_reverseStereo)
        __FX_setWarningMessage("reverse stereo filter is not yet implemented!");
#endif
} // FX_SetReverseStereo


int FX_GetReverseStereo(void)
{
    return(__FX_reverseStereo);
} // FX_GetReverseStereo


void FX_SetReverb(int reverb)
{
    __FX_reverbLevel = reverb;
    __FX_fastReverb = 0;

#if 1
    // !!! FIXME
    if (__FX_reverbLevel)
        __FX_setWarningMessage("reverb filter is not yet implemented!");
#endif
} // FX_SetReverb


void FX_SetFastReverb(int reverb)
{
    __FX_reverbLevel = reverb;
    __FX_fastReverb = 1;

#if 1
    // !!! FIXME
    if (__FX_reverbLevel)
        __FX_setWarningMessage("fast reverb filter is not yet implemented!");
#endif
} // FX_SetFastReverb


int FX_GetMaxReverbDelay(void)
{
    return(__FX_maxReverbDelay);
} // FX_GetMaxReverbDelay


int FX_GetReverbDelay(void)
{
    return(__FX_reverbDelay);
} // FX_GetReverbDelay


void FX_SetReverbDelay(int delay)
{
        // !!! FIXME: Should I be clamping these values?
    if (delay < 256)
        delay = 256;

    if (delay > __FX_maxReverbDelay)
        delay = __FX_maxReverbDelay;

    __FX_reverbDelay = delay;

#if 1
    // !!! FIXME
    __FX_setWarningMessage("reverb delay is not yet implemented!");
#endif
} // FX_SetReverbDelay


int FX_VoiceAvailable(int priority)
{
} // FX_VoiceAvailable


int FX_SetPan(int handle, int vol, int left, int right)
{
} // FX_SetPan


int FX_SetPitch(int handle, int pitchoffset)
{
} // FX_SetPitch


int FX_SetFrequency(int handle, int frequency)
{
} // FX_SetFrequency


int FX_PlayVOC(char *ptr, int pitchoffset,
               int vol, int left, int right,
               int priority, unsigned long callbackval)
{
    snddebug("FX_PlayVOC() ... NOT IMPLEMENTED YET!");
} // FX_PlayVOC


int FX_PlayLoopedVOC( char *ptr, long loopstart, long loopend,
       int pitchoffset, int vol, int left, int right, int priority,
       unsigned long callbackval )
{
    snddebug("FX_PlayLoopedVOC() ... NOT IMPLEMENTED YET!");
} // FX_PlayLoopedVOC


int FX_PlayVOC3D( char *ptr, int pitchoffset, int angle, int distance,
       int priority, unsigned long callbackval )
{
    snddebug("FX_PlayVOC3D() ... NOT IMPLEMENTED YET!");
} // FX_PlayVOC3D


    // it's all the same to SDL_mixer.  :)
int FX_PlayWAV( char *ptr, int pitchoffset, int vol, int left, int right,
       int priority, unsigned long callbackval )
{
    FX_PlayVOC(ptr, pitchoffset, vol, left, right, priority, callbackval);
} // FX_PlayWAV


int FX_PlayLoopedWAV( char *ptr, long loopstart, long loopend,
       int pitchoffset, int vol, int left, int right, int priority,
       unsigned long callbackval )
{
    FX_PlayLoopedVOC(ptr, loopstart, loopend, pitchoffset, vol, left,
                     right, priority, callbackval);
} // FX_PlayLoopedWAV


int FX_PlayWAV3D( char *ptr, int pitchoffset, int angle, int distance,
       int priority, unsigned long callbackval )
{
    FX_PlayVOC3D(ptr, pitchoffset, angle, distance, priority, callbackval);
} // FX_PlayWAV3D


int FX_PlayRaw( char *ptr, unsigned long length, unsigned rate,
       int pitchoffset, int vol, int left, int right, int priority,
       unsigned long callbackval )
{
    snddebug("FX_PlayRaw() ... NOT IMPLEMENTED!");
} // FX_PlayRaw


int FX_PlayLoopedRaw( char *ptr, unsigned long length, char *loopstart,
       char *loopend, unsigned rate, int pitchoffset, int vol, int left,
       int right, int priority, unsigned long callbackval )
{
    snddebug("FX_PlayLoopedRaw() ... NOT IMPLEMENTED!");
} // FX_PlayLoopedRaw


int FX_Pan3D(int handle, int angle, int distance)
{
    snddebug("FX_Pan3D() ... NOT IMPLEMENTED YET!");
} // FX_Pan3D


int FX_SoundActive(int handle)
{
    int retval = __FX_FALSE;

    if ((handle < 0) || (handle >= __FX_numChannels))
        __FX_setWarningMessage("Invalid handle in FX_SoundActive().");
    else
    {
        if (Mix_Playing(handle))
            retval = __FX_TRUE;
    } // else

    return(retval);
} // FX_SoundActive


int FX_SoundsPlaying(void)
{
    return(Mix_Playing(-1));
} // FX_SoundsPlaying


int FX_StopSound(int handle)
{
    snddebug("halting channel (%d).", handle);
        // !!! FIXME: Should the user callback fire for this?
    Mix_HaltChannel(handle);
} // FX_StopSound


int FX_StopAllSounds(void)
{
    snddebug("halting all channels.");
        // !!! FIXME: Should the user callback fire for this?
    Mix_HaltGroup(-1);
} // FX_StopAllSounds


int FX_StartDemandFeedPlayback( void ( *function )( char **ptr, unsigned long *length ),
       int rate, int pitchoffset, int vol, int left, int right,
       int priority, unsigned long callbackval )
{
    snddebug("FX_StartDemandFeedPlayback() ... NOT IMPLEMENTED!");
}


int FX_StartRecording(int MixRate, void (*function)(char *ptr, int length))
{
    snddebug("FX_StartRecording() ... NOT IMPLEMENTED!");
} // FX_StartRecording


void FX_StopRecord( void )
{
    snddebug("FX_StopRecord() ... NOT IMPLEMENTED!");
} // FX_StopRecord

// end of fx_man.c ...

