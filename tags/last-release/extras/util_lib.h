//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment

This file is NOT part of Duke Nukem 3D version 1.5 - Atomic Edition
However, it is either an older version of a file that is, or is
some test code written during the development of Duke Nukem 3D.
This file is provided purely for educational interest.

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Prepared for public release: 03/21/2003 - Charlie Wiederhold, 3D Realms
*/
//-------------------------------------------------------------------------

//***************************************************************************
//
//    UTIL_LIB.C - various utils
//
//***************************************************************************

#ifndef _util_lib_public
#define _util_lib_public
#ifdef __cplusplus
extern "C" {
#endif

#if (defined(__MSDOS__) && !defined(__FLAT__))
extern  int16    _argc;
#else
extern  int32    _argc;
#endif
extern  char **  _argv;

void RegisterShutdownFunction( void (* shutdown) (void) );
void   Error (char *error, ...);

char   CheckParm (char *check);

void   *SafeMalloc (int32 size);
int32  SafeMallocSize (void * ptr);
void   SafeFree (void * ptr);
void   SafeRealloc (void ** ptr, int32 newsize);
int32  ParseHex (char *hex);
int32  ParseNum (char *str);
int16  MotoShort (int16 l);
int16  IntelShort (int16 l);
int32  MotoLong (int32 l);
int32  IntelLong (int32 l);

void HeapSort(char * base, int32 nel, int32 width, int32 (*compare)(), void (*switcher)());

#ifdef __cplusplus
};
#endif
#endif
