//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment

This file is part of Duke Nukem 3D version 1.5 - Atomic Edition

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

Original Source: 1996 - Todd Replogle
Prepared for public release: 03/21/2003 - Charlie Wiederhold, 3D Realms
*/
//-------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "duke3d.h"
#include "scriplib.h"

/*
==============
=
= SCRIPT_Init
=
==============
*/
int32 SCRIPT_Init( char * name )
{
	STUBBED("Init");
	
	return -1;
}


/*
==============
=
= SCRIPT_Free
=
==============
*/
void SCRIPT_Free( int32 scripthandle )
{
	STUBBED("Free");
}


/*
==============
=
= SCRIPT_Parse
=
==============
*/

int32 SCRIPT_Parse ( char *data, int32 length, char * name )
{
	STUBBED("Parse");
	
	return -1;
}


/*
==============
=
= SCRIPT_Load
=
==============
*/

int32 SCRIPT_Load ( char * filename )
{
	STUBBED("Load");
	
	return -1;
}

/*
==============
=
= SCRIPT_Save
=
==============
*/
void SCRIPT_Save (int32 scripthandle, char * filename)
{
	STUBBED("Save");
}


/*
==============
=
= SCRIPT_NumberSections
=
==============
*/

int32 SCRIPT_NumberSections( int32 scripthandle )
{
	STUBBED("NumberSections");
	
	return -1;
}

/*
==============
=
= SCRIPT_Section
=
==============
*/

char * SCRIPT_Section( int32 scripthandle, int32 which )
{
	STUBBED("Section");
	
	return NULL;
}

/*
==============
=
= SCRIPT_NumberEntries
=
==============
*/

int32 SCRIPT_NumberEntries( int32 scripthandle, char * sectionname )
{
	STUBBED("NumberEntries");
	
	return 0;
}


/*
==============
=
= SCRIPT_Entry
=
==============
*/

char * SCRIPT_Entry( int32 scripthandle, char * sectionname, int32 which )
{
	STUBBED("Entry");
	
	return NULL;
}


/*
==============
=
= SCRIPT_GetRaw
=
==============
*/
char * SCRIPT_GetRaw(int32 scripthandle, char * sectionname, char * entryname)
{
	STUBBED("GetRaw");
	
	return NULL;
}

/*
==============
=
= SCRIPT_GetString
=
==============
*/
void SCRIPT_GetString
   (
   int32 scripthandle,
   char * sectionname,
   char * entryname,
   char * dest
   )
{
	STUBBED("GetString");
}

/*
==============
=
= SCRIPT_GetDoubleString
=
==============
*/
void SCRIPT_GetDoubleString
   (
   int32 scripthandle,
   char * sectionname,
   char * entryname,
   char * dest1,
   char * dest2
   )
{
	STUBBED("GetDoubleString");
}

/*
==============
=
= SCRIPT_GetNumber
=
==============
*/
boolean SCRIPT_GetNumber
   (
   int32 scripthandle,
   char * sectionname,
   char * entryname,
   int32 * number
   )
{
	STUBBED("GetNumber");
	
	return false;
}

/*
==============
=
= SCRIPT_GetBoolean
=
==============
*/
void SCRIPT_GetBoolean
   (
   int32 scripthandle,
   char * sectionname,
   char * entryname,
   boolean * bool
   )
{
	STUBBED("GetBoolean");
}

/*
==============
=
= SCRIPT_GetDouble
=
==============
*/

void SCRIPT_GetDouble
   (
   int32 scripthandle,
   char * sectionname,
   char * entryname,
   double * number
   )
{
	STUBBED("GetDouble");
}



/*
==============
=
= SCRIPT_PutComment
=
==============
*/
void SCRIPT_PutComment( int32 scripthandle, char * sectionname, char * comment )
{
	STUBBED("PutComment");
}

/*
==============
=
= SCRIPT_PutEOL
=
==============
*/
void SCRIPT_PutEOL( int32 scripthandle, char * sectionname )
{
	STUBBED("PutEOL");
}

/*
==============
=
= SCRIPT_PutMultiComment
=
==============
*/
void SCRIPT_PutMultiComment
   (
   int32 scripthandle,
   char * sectionname,
   char * comment,
   ...
   )
{
	STUBBED("PutMultiComment");
}

/*
==============
=
= SCRIPT_PutSection
=
==============
*/
void SCRIPT_PutSection( int32 scripthandle, char * sectionname )
{
	STUBBED("PutSection");
}

/*
==============
=
= SCRIPT_PutRaw
=
==============
*/
void SCRIPT_PutRaw
   (
   int32 scripthandle,
   char * sectionname,
   char * entryname,
   char * raw
   )
{
	STUBBED("PutRaw");
}

/*
==============
=
= SCRIPT_PutString
=
==============
*/
void SCRIPT_PutString
   (
   int32 scripthandle,
   char * sectionname,
   char * entryname,
   char * string
   )
{
	STUBBED("PutString");
}

/*
==============
=
= SCRIPT_PutDoubleString
=
==============
*/
void SCRIPT_PutDoubleString
   (
   int32 scripthandle,
   char * sectionname,
   char * entryname,
   char * string1,
   char * string2
   )
{
	STUBBED("PutDoubleString");
}

/*
==============
=
= SCRIPT_PutNumber
=
==============
*/
void SCRIPT_PutNumber
   (
   int32 scripthandle,
   char * sectionname,
   char * entryname,
   int32 number,
   boolean hexadecimal,
   boolean defaultvalue
   )
{
	STUBBED("PutNumber");
}

/*
==============
=
= SCRIPT_PutBoolean
=
==============
*/
void SCRIPT_PutBoolean
   (
   int32 scripthandle,
   char * sectionname,
   char * entryname,
   boolean bool
   )
{
	STUBBED("PutBoolean");
}

/*
==============
=
= SCRIPT_PutDouble
=
==============
*/

void SCRIPT_PutDouble
   (
   int32 scripthandle,
   char * sectionname,
   char * entryname,
   double number,
   boolean defaultvalue
   )
{
	STUBBED("PutDouble");
}
