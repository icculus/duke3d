/**********************************************************************
   module: SNDCARDS.H

   author: James R. Dos‚
   phone:  (214)-271-1365 Ext #221
   date:   March 31, 1994

   Contains enumerated type definitions for sound cards.

   (c) Copyright 1994 James R. Dos‚.  All Rights Reserved.
**********************************************************************/

#ifndef __SNDCARDS_H
#define __SNDCARDS_H

#define ASS_VERSION_STRING "1.07"

typedef enum
   {
//   ASS_NoSound,
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

#endif
