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
    static boolean gotextended = false;
    
    int rawkey = _readlastkeyhit();
    int lastkey = rawkey & 0x7f;
    
    // 128 bit means key was released.
    int pressed = !(rawkey & 0x80);
    
    if (rawkey == 0xe0 && !gotextended)
    {
    	gotextended = true;
        return;
    }

    if (rawkey == 0xe1)
    {
    	STUBBED("Another extended key!");
    	return;
    }
        
    if (gotextended) {
    	gotextended = false;
    	
    	switch (lastkey) {
    	    case 0x35: /* kp divide */
    	        /* no suitable mapping */
    	        return;
    	    case 0x47: /* home */
    	        lastkey = sc_Home;
    	        break;
    	    case 0x48: /* up */
    	        lastkey = sc_UpArrow;
    	        break;
    	    case 0x49: /* page up */
    	        lastkey = sc_PgUp;
    	        // SBF - SEE BUILDENGINE'S sdl_driver.c
    	        // scancodes[SDLK_PAGEUP]          = 0xE0C9;
    	        pressed = !pressed; /* invert */
    	        
    	        break;
    	    case 0x4A: /* kpad minus */
    	        lastkey = sc_kpad_Minus;
    	        break;
    	    case 0x4B: /* left */
    	        lastkey = sc_LeftArrow;
    	        break;
    	    case 0x4D: /* right */
    	        lastkey = sc_RightArrow;
    	        break;
    	    case 0x4E: /* kpad plus */
    	        lastkey = sc_kpad_Plus;
    	        break;
    	    case 0x4F: /* end */
    	    	lastkey = sc_End;
    	    	break;
    	    case 0x50: /* down */
    	        lastkey = sc_DownArrow;
    	        break;
    	    case 0x51: /* page down */
    	    	lastkey = sc_PgDn;
    	    	// SBF - SEE BUILDENGINE'S sdl_driver.c
    	    	// scancodes[SDLK_PAGEDOWN]        = 0xE0D1;
    	    	pressed = !pressed; /* invert */
    	    	
    	    	// printf("PAGE DOWN: last: 0x%x raw: 0x%x pressed: %d\n",
    	    	//	lastkey, rawkey, pressed);
    	    	break;
    	    case 0x53: /* delete */
    	    	lastkey = sc_Delete;
    	    	// SBF - SEE BUILDENGINE'S sdl_driver.c
    	    	// scancodes[SDLK_DELETE]          = 0xE0D3;
    	    	pressed = !pressed; /* invert */
    	    	
    	    	//printf("DELETE: last: 0x%x raw: 0x%x pressed: %d\n",
    	    	//	lastkey, rawkey, pressed);
    	    	break;
    	    case 0x52: /* kpad 0 */
    	    	lastkey = sc_kpad_0;
    	    	break;
    	    case 0x1C: /* kpad enter */
    	    	lastkey = sc_kpad_Enter;
    	    	break;
    	    default:
    	    	STUBBED("Unknown extended key!");
    	    	return;
    	}
    }
    
    if (lastkey >= MAXKEYBOARDSCAN)
    {
        STUBBED("Scancode out of range!");
        return;
    }

    if (pressed)
    {
         KB_LastScan = lastkey;
    }

    KB_KeyDown[lastkey] = pressed;

    keyIsWaiting = ((keyIsWaiting) || (KB_KeyDown[lastkey]));
    
    CONTROL_UpdateKeyboardState(lastkey, pressed);
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
		if(!stricmp(name,string))
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

