
/*
 *  This is a Watcom C support header. It was autogenerated by a perl script
 *  (watcom_sdl_syms.pl). The perl was written by Ryan C. Gordon
 *  (icculus@clutteredmind.org).
 */

#ifndef _SDL_syms_for_watcom_h_
#define _SDL_syms_for_watcom_h_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __WATCOMC__
#pragma aux (__cdecl) Mix_AllocateChannels;
#pragma aux (__cdecl) Mix_ChannelFinished;
#pragma aux (__cdecl) Mix_CloseAudio;
#pragma aux (__cdecl) Mix_FadeOutMusic;
#pragma aux (__cdecl) Mix_FadingMusic;
#pragma aux (__cdecl) Mix_FreeChunk;
#pragma aux (__cdecl) Mix_FreeMusic;
#pragma aux (__cdecl) Mix_GetChunk;
#pragma aux (__cdecl) Mix_HaltChannel;
#pragma aux (__cdecl) Mix_HaltGroup;
#pragma aux (__cdecl) Mix_HaltMusic;
#pragma aux (__cdecl) Mix_Linked_Version;
#pragma aux (__cdecl) Mix_LoadWAV_RW;
#pragma aux (__cdecl) Mix_OpenAudio;
#pragma aux (__cdecl) Mix_PauseMusic;
#pragma aux (__cdecl) Mix_PausedMusic;
#pragma aux (__cdecl) Mix_PlayChannelTimed;
#pragma aux (__cdecl) Mix_Playing;
#pragma aux (__cdecl) Mix_PlayingMusic;
#pragma aux (__cdecl) Mix_QuerySpec;
#pragma aux (__cdecl) Mix_ResumeMusic;
#pragma aux (__cdecl) Mix_SetPanning;
#pragma aux (__cdecl) Mix_SetPosition;
#pragma aux (__cdecl) Mix_SetReverseStereo;
#pragma aux (__cdecl) Mix_Volume;
#pragma aux (__cdecl) Mix_VolumeMusic;
#pragma aux (__cdecl) SDL_ClearError;
#pragma aux (__cdecl) SDL_GetError;
#pragma aux (__cdecl) SDL_GetTicks;
#pragma aux (__cdecl) SDL_Init;
#pragma aux (__cdecl) SDL_Linked_Version;
#pragma aux (__cdecl) SDL_RWFromMem;

/*
 * Don't forget to compile your code with wcc386.exe's -ei option, so that
 *  enums in Watcom and SDL are the same size, and remember that any SDL
 *  callbacks (for sound or event filtering, etc) in your Watcom C-based code
 *  must be labelled as __cdecl. An example:
 *
 *   int my_sdl_event_filter_function(const SDL_Event *event);
 *   #ifdef __WATCOMC__
 *   #pragma aux (__cdecl) my_sdl_event_filter_function;
 *   #endif
 *
 *     Have fun, and good luck!   --ryan.  (icculus@clutteredmind.org)
 */


#endif /* __WATCOMC__ */
#endif /* _SDL_syms_for_watcom_h_ */

