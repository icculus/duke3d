/*
 * This is temporary, since I'm missing headers. It's based on Dose's
 *  notes, and may be incomplete AND incorrect to boot.
 *
 *  Written by Ryan C. Gordon (icculus@linuxgames.com) ...
 */

#ifndef _INCLUDE_SNDCARDS_H_
#define _INCLUDE_SNDCARDS_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    SoundBlaster,
    ProAudioSpectrum,
    SoundMan16,
    Adlib,
    GenMidi,
    SoundCanvas,
    Awe32,
    WaveBlaster,
    SoundScape,
    UltraSound,
    SoundSource,
    TandySoundSource,
    PC,
    NumSoundCards
} soundcardnames;

#ifdef __cplusplus
}
#endif

#endif

// end of sndcards.h ...

