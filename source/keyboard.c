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

static boolean keyIsWaiting = 0;

/*
=============================================================================
FUNCTIONS
=============================================================================
*/

void keyhandler(void)
{
    int lastkey = _readlastkeyhit();
    if (lastkey >= MAXKEYBOARDSCAN)
    {
        STUBBED("Scancode out of range!");
        return;
    }

    KB_LastScan = lastkey;

    // 128 bit means key was released.
    KB_KeyDown[lastkey] = (lastkey & 128) ? 0 : 1;

    keyIsWaiting = ((keyIsWaiting) || (KB_KeyDown[lastkey]));
}

void KB_KeyEvent( int scancode, boolean keypressed )
{
	STUBBED("KB_KeyEvent");
}

boolean KB_KeyWaiting( void )
{
    _handle_events();
    return keyIsWaiting;
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
    _handle_events();
	keyIsWaiting = false;
}

void KB_ClearKeysDown( void )
{
    memset(KB_KeyDown, '\0', sizeof (KB_KeyDown));
	keyIsWaiting = false;
}

char *KB_ScanCodeToString( kb_scancode scancode )
{
	STUBBED("KB_ScanCodeToString");
	return 0;
}

static struct {
	char* name;
	int code;
} keyname2scancode[] = {
	{ ",",		sc_Comma	},
	{ ".",		sc_Period	},
	{ "Enter",	sc_Return	},
//	{ "Escape",	sc_Escape	},
	{ "Space",	sc_Space	},
	{ "BakSpc",	sc_BackSpace	},
	{ "Tab",	sc_Tab		},
	{ "LAlt",	sc_LeftAlt	},
	{ "LCtrl",	sc_LeftControl	},
	{ "CapLck",	sc_CapsLock	},
	{ "LShift",	sc_LeftShift	},
	{ "RShift",	sc_RightShift	},
	{ "F1",		sc_F1		},
	{ "F2",		sc_F2		},
	{ "F3",		sc_F3		},
	{ "F4",		sc_F4		},
	{ "F5",		sc_F5		},
	{ "F6",		sc_F6		},
	{ "F7",		sc_F7		},
	{ "F8",		sc_F8		},
	{ "F9",		sc_F9		},
	{ "F10",	sc_F10		},
	{ "F11",	sc_F11		},
	{ "F12",	sc_F12		},
	{ "Kpad*",	sc_Kpad_Star	},
	{ "Pause",	sc_Pause	},
	{ "ScrLck",	sc_ScrollLock	},
	{ "NumLock",	sc_NumLock	},
	{ "/",		sc_Slash	},
	{ ";",		sc_SemiColon	},
	{ "'",		sc_Quote	},
	{ "~",		sc_Tilde	},
	{ "\\",		sc_BackSlash	},
	{ "(",		sc_OpenBracket	},
	{ ")",		sc_CloseBracket	},
	{ "1",		sc_1		},
	{ "2",		sc_2		},
	{ "3",		sc_3		},
	{ "4",		sc_4		},
	{ "5",		sc_5		},
	{ "6",		sc_6		},
	{ "7",		sc_7		},
	{ "8",		sc_8		},
	{ "9",		sc_9		},
	{ "0",		sc_0		},
	{ "-",		sc_Minus	},
	{ "=",		sc_Equals	},
	{ "+",		sc_Plus		},
	{ "Kpad1",	sc_kpad_1	},
	{ "Kpad2",	sc_kpad_2	},
	{ "Kpad3",	sc_kpad_3	},
	{ "Kpad4",	sc_kpad_4	},
	{ "Kpad5",	sc_kpad_5	},
	{ "Kpad6",	sc_kpad_6	},
	{ "Kpad7",	sc_kpad_7	},
	{ "Kpad8",	sc_kpad_8	},
	{ "Kpad9",	sc_kpad_9	},
	{ "Kpad0",	sc_kpad_0	},
	{ "Kpad-",	sc_kpad_Minus	},
	{ "Kpad+",	sc_kpad_Plus	},
	{ "Kpad.",	sc_kpad_Period	},
	{ "A",		sc_A		},
	{ "B",		sc_B		},
	{ "C",		sc_C		},
	{ "D",		sc_D		},
	{ "E",		sc_E		},
	{ "F",		sc_F		},
	{ "G",		sc_G		},
	{ "H",		sc_H		},
	{ "I",		sc_I		},
	{ "J",		sc_J		},
	{ "K",		sc_K		},
	{ "L",		sc_L		},
	{ "M",		sc_M		},
	{ "N",		sc_N		},
	{ "O",		sc_O		},
	{ "P",		sc_P		},
	{ "Q",		sc_Q		},
	{ "R",		sc_R		},
	{ "S",		sc_S		},
	{ "T",		sc_T		},
	{ "U",		sc_U		},
	{ "V",		sc_V		},
	{ "W",		sc_W		},
	{ "X",		sc_X		},
	{ "Y",		sc_Y		},
	{ "Z",		sc_Z		},
	{ "Up",		sc_UpArrow	},
	{ "Down",	sc_DownArrow	},
	{ "Left",	sc_LeftArrow	},
	{ "Right",	sc_RightArrow	},
	{ "Insert",	sc_Insert	},
	{ "Delete",	sc_Delete	},
	{ "Home",	sc_Home		},
	{ "End",	sc_End		},
	{ "PgUp",	sc_PgUp		},
	{ "PgDn",	sc_PgDn		},
	{ "RAlt",	sc_RightAlt	},
	{ "RCtrl",	sc_RightControl	},
	{ "Kpad/",	sc_kpad_Slash	},
	{ "KpdEnt",	sc_kpad_Enter	},
	{ "PrtScr",	sc_PrintScreen	},
	{ NULL,		0		}
};

kb_scancode KB_StringToScanCode( char * string )
{
	char* name = NULL;
	int32 i=0;
	name = keyname2scancode[i].name;
	for(;name;++i, name=keyname2scancode[i].name)
	{
		if(!strcmp(name,string))
			break;
	}
	
	return keyname2scancode[i].code;
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
	KB_ClearKeysDown();
}

void KB_Shutdown( void )
{
	KB_ClearKeysDown();
}

