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

#include "duke3d.h"
#include "keyboard.h"

/*
=============================================================================

                               GLOBAL VARIABLES

=============================================================================
*/

volatile byte  KB_KeyDown[ MAXKEYBOARDSCAN ];   // Keyboard state array
volatile kb_scancode KB_LastScan;

/*
=============================================================================
FUNCTIONS
=============================================================================
*/

void keyhandler(void)
{
	STUBBED("hook this up from buildengine");
}

void KB_KeyEvent( int scancode, boolean keypressed )
{
	STUBBED("KB_KeyEvent");
}

boolean KB_KeyWaiting( void )
{
	STUBBED("KB_KeyWaiting");
	return true;
}

char KB_Getch( void )
{
	STUBBED("KB_Getch");
	return 0;
}

void KB_Addch( char ch )
{
	STUBBED("KB_Addch");
}

void KB_FlushKeyboardQueue( void )
{
	STUBBED("KB_FlushKeyboardQueue");
}

void KB_ClearKeysDown( void )
{
	STUBBED("KB_ClearKeysDown");
}

char *KB_ScanCodeToString( kb_scancode scancode )
{
	STUBBED("KB_ScanCodeToString");
	return 0;
}

kb_scancode KB_StringToScanCode( char * string )
{
	STUBBED("KB_StringToScanCode");
	return 0;
}

void KB_TurnKeypadOn( void )
{
	STUBBED("KB_TurnKeypadOn");
}

void KB_TurnKeypadOff( void )
{
	STUBBED("KB_TurnKeypadOff");
}

boolean KB_KeypadActive( void )
{
	STUBBED("KB_KeypadActive");
	return false;
}

void KB_Startup( void )
{
	STUBBED("KB_Startup");
}

void KB_Shutdown( void )
{
	STUBBED("KB_Shutdown");
}

