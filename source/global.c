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
#include <stdarg.h>
#include <errno.h>

#include "duke3d.h"

char *mymembuf;
char MusicPtr[72000];

short global_random;
short neartagsector, neartagwall, neartagsprite;

long gc,neartaghitdist,lockclock,max_player_health,max_armour_amount,max_ammo_amount[MAX_WEAPONS];

// long temp_data[MAXSPRITES][6];
struct weaponhit hittype[MAXSPRITES];
short spriteq[1024],spriteqloc,spriteqamount=64;

// ported build engine has this, too.  --ryan.
#if PLATFORM_DOS
short moustat = 0;
#endif

struct animwalltype animwall[MAXANIMWALLS];
short numanimwalls;
long *animateptr[MAXANIMATES], animategoal[MAXANIMATES], animatevel[MAXANIMATES], animatecnt;
// long oanimateval[MAXANIMATES];
short animatesect[MAXANIMATES];
long msx[2048],msy[2048];
short cyclers[MAXCYCLERS][6],numcyclers;

char fta_quotes[NUMOFFIRSTTIMEACTIVE][64];

unsigned char tempbuf[2048], packbuf[576];

char buf[80];

short camsprite;
short mirrorwall[64], mirrorsector[64], mirrorcnt;

int current_menu;

char betaname[80];

char level_names[44][33],level_file_names[44][128];
long partime[44],designertime[44];
char volume_names[4][33];
char skill_names[5][33];

volatile long checksume;
long soundsiz[NUM_SOUNDS];

short soundps[NUM_SOUNDS],soundpe[NUM_SOUNDS],soundvo[NUM_SOUNDS];
char soundm[NUM_SOUNDS],soundpr[NUM_SOUNDS];
char sounds[NUM_SOUNDS][14];

short title_zoom;

fx_device device;

SAMPLE Sound[ NUM_SOUNDS ];
SOUNDOWNER SoundOwner[NUM_SOUNDS][4];

char numplayersprites,loadfromgrouponly,earthquaketime;

long fricxv,fricyv;
struct player_orig po[MAXPLAYERS];
struct player_struct ps[MAXPLAYERS];
struct user_defs ud;

char pus, pub;
char syncstat, syncval[MAXPLAYERS][MOVEFIFOSIZ];
long syncvalhead[MAXPLAYERS], syncvaltail, syncvaltottail;

input sync[MAXPLAYERS], loc;
input recsync[RECSYNCBUFSIZ];
long avgfvel, avgsvel, avgavel, avghorz, avgbits;


input inputfifo[MOVEFIFOSIZ][MAXPLAYERS];
input recsync[RECSYNCBUFSIZ];

long movefifosendplc;

  //Multiplayer syncing variables
short screenpeek;
long movefifoend[MAXPLAYERS];


    //Game recording variables

char playerreadyflag[MAXPLAYERS],ready2send;
char playerquitflag[MAXPLAYERS];
long vel, svel, angvel, horiz, ototalclock, respawnactortime=768, respawnitemtime=768, groupfile;

long script[MAXSCRIPTSIZE],*scriptptr,*insptr,*labelcode,labelcnt;
long *actorscrptr[MAXTILES],*parsing_actor;
char *label,*textptr,error,warning,killit_flag;
char *music_pointer;
char actortype[MAXTILES];


char display_mirror,typebuflen,typebuf[41];

char music_fn[4][11][13],music_select;
char env_music_fn[4][13];
char rtsplaying;


short weaponsandammosprites[15] = {
        RPGSPRITE,
        CHAINGUNSPRITE,
        DEVISTATORAMMO,
        RPGAMMO,
        RPGAMMO,
        JETPACK,
        SHIELD,
        FIRSTAID,
        STEROIDS,
        RPGAMMO,
        RPGAMMO,
        RPGSPRITE,
        RPGAMMO,
        FREEZESPRITE,
        FREEZEAMMO
    };

long impact_damage;

        //GLOBAL.C - replace the end "my's" with this
long myx, omyx, myxvel, myy, omyy, myyvel, myz, omyz, myzvel;
short myhoriz, omyhoriz, myhorizoff, omyhorizoff;
short myang, omyang, mycursectnum, myjumpingcounter,frags[MAXPLAYERS][MAXPLAYERS];

char myjumpingtoggle, myonground, myhardlanding, myreturntocenter;
signed char multiwho, multipos, multiwhat, multiflag;

long fakemovefifoplc,movefifoplc;
long myxbak[MOVEFIFOSIZ], myybak[MOVEFIFOSIZ], myzbak[MOVEFIFOSIZ];
long myhorizbak[MOVEFIFOSIZ],dukefriction = 0xcc00, show_shareware;

short myangbak[MOVEFIFOSIZ];
char myname[32],camerashitable,freezerhurtowner=0,lasermode;
// CTW - MODIFICATION
// char networkmode = 255, movesperpacket = 1,gamequit = 0,playonten = 0,everyothertime;
char networkmode = 255, movesperpacket = 1,gamequit = 0,everyothertime;
// CTW END - MODIFICATION
long numfreezebounces=3,rpgblastradius,pipebombblastradius,tripbombblastradius,shrinkerblastradius,morterblastradius,bouncemineblastradius,seenineblastradius;
STATUSBARTYPE sbar;

long myminlag[MAXPLAYERS], mymaxlag, otherminlag, bufferjitter = 1;
short numclouds,clouds[128],cloudx[128],cloudy[128];
long cloudtotalclock = 0,totalmemory = 0;
long numinterpolations = 0, startofdynamicinterpolations = 0;
long oldipos[MAXINTERPOLATIONS];
long bakipos[MAXINTERPOLATIONS];
long *curipos[MAXINTERPOLATIONS];


// portability stuff.  --ryan.
// A good portion of this was ripped from GPL'd Rise of the Triad.  --ryan.

void FixFilePath(char *filename)
{
#if PLATFORM_UNIX
    char *ptr;
    char *lastsep = filename;

    if ((!filename) || (*filename == '\0'))
        return;

    if (access(filename, F_OK) == 0)  /* File exists; we're good to go. */
        return;

    for (ptr = filename; 1; ptr++)
    {
        if (*ptr == '\\')
            *ptr = PATH_SEP_CHAR;

        if ((*ptr == PATH_SEP_CHAR) || (*ptr == '\0'))
        {
            char pch = *ptr;
            struct dirent *dent = NULL;
            DIR *dir;

            if ((pch == PATH_SEP_CHAR) && (*(ptr + 1) == '\0'))
                return; /* eos is pathsep; we're done. */

            if (lastsep == ptr)
                continue;  /* absolute path; skip to next one. */

            *ptr = '\0';
            if (lastsep == filename) {
                dir = opendir((*lastsep == PATH_SEP_CHAR) ? ROOTDIR : CURDIR);
                
                if (*lastsep == PATH_SEP_CHAR) {
                    lastsep++;
                }
            } 
            else
            {
                *lastsep = '\0';
                dir = opendir(filename);
                *lastsep = PATH_SEP_CHAR;
                lastsep++;
            }

            if (dir == NULL)
            {
                *ptr = PATH_SEP_CHAR;
                return;  /* maybe dir doesn't exist? give up. */
            }

            while ((dent = readdir(dir)) != NULL)
            {
                if (strcasecmp(dent->d_name, lastsep) == 0)
                {
                    /* found match; replace it. */
                    strcpy(lastsep, dent->d_name);
                    break;
                }
            }

            closedir(dir);
            *ptr = pch;
            lastsep = ptr;

            if (dent == NULL)
                return;  /* no match. oh well. */

            if (pch == '\0')  /* eos? */
                return;
        }
    }
#endif
}


#if PLATFORM_DOS
 /* no-op. */

#elif PLATFORM_WIN32
int _dos_findfirst(char *filename, int x, struct find_t *f)
{
    long rc = _findfirst(filename, &f->data);
    f->handle = rc;
    if (rc != -1)
    {
        strncpy(f->name, f->data.name, sizeof (f->name) - 1);
        f->name[sizeof (f->name) - 1] = '\0';
        return(0);
    }
    return(1);
}

int _dos_findnext(struct find_t *f)
{
    int rc = 0;
    if (f->handle == -1)
        return(1);   /* invalid handle. */

    rc = _findnext(f->handle, &f->data);
    if (rc == -1)
    {
        _findclose(f->handle);
        f->handle = -1;
        return(1);
    }

    strncpy(f->name, f->data.name, sizeof (f->name) - 1);
    f->name[sizeof (f->name) - 1] = '\0';
    return(0);
}

#elif PLATFORM_UNIX 
int _dos_findfirst(char *filename, int x, struct find_t *f)
{
    char *ptr;

    if (strlen(filename) >= sizeof (f->pattern))
        return(1);

    strcpy(f->pattern, filename);
    FixFilePath(f->pattern);
    ptr = strrchr(f->pattern, PATH_SEP_CHAR);

    if (ptr == NULL)
    {
        ptr = filename;
        f->dir = opendir(CURDIR);
    }
    else
    {
        *ptr = '\0';
        f->dir = opendir(f->pattern);
        memmove(f->pattern, ptr + 1, strlen(ptr + 1) + 1);
    }

    return(_dos_findnext(f));
}


static int check_pattern_nocase(const char *x, const char *y)
{
    if ((x == NULL) || (y == NULL))
        return(0);  /* not a match. */

    while ((*x) && (*y))
    {
        if (*x == '*')
            Error("Unexpected wildcard!");  /* FIXME? */

        else if (*x == '?')
        {
            if (*y == '\0')
                return(0);  /* anything but EOS is okay. */
        }

        else
        {
            if (toupper((int) *x) != toupper((int) *y))
                return(0);  /* not a match. */
        }

        x++;
        y++;
    }

    return(*x == *y);  /* it's a match (both should be EOS). */
}

int _dos_findnext(struct find_t *f)
{
    struct dirent *dent;

    if (f->dir == NULL)
        return(1);  /* no such dir or we're just done searching. */

    while ((dent = readdir(f->dir)) != NULL)
    {
        if (check_pattern_nocase(f->pattern, dent->d_name))
        {
            if (strlen(dent->d_name) < sizeof (f->name))
            {
                strcpy(f->name, dent->d_name);
                return(0);  /* match. */
            }
        }
    }

    closedir(f->dir);
    f->dir = NULL;
    return(1);  /* no match in whole directory. */
}
#else
#error please define for your platform.
#endif


#if !PLATFORM_DOS
void _dos_getdate(struct dosdate_t *date)
{
	time_t curtime = time(NULL);
	struct tm *tm;
	
	if (date == NULL) {
		return;
	}
	
	memset(date, 0, sizeof(struct dosdate_t));
	
	if ((tm = localtime(&curtime)) != NULL) {
		date->day = tm->tm_mday;
		date->month = tm->tm_mon + 1;
		date->year = tm->tm_year + 1900;
		date->dayofweek = tm->tm_wday + 1;
	}
}
#endif


int FindDistance2D(int ix, int iy)
{
  int   t;

  ix= abs(ix);        /* absolute values */
  iy= abs(iy);

  if (ix<iy)
  {
     int tmp = ix;
     ix = iy;
     iy = tmp;
  }

  t = iy + (iy>>1);

  return (ix - (ix>>5) - (ix>>7)  + (t>>2) + (t>>6));
}

int FindDistance3D(int ix, int iy, int iz)
{
   int   t;

   ix= abs(ix);           /* absolute values */
   iy= abs(iy);
   iz= abs(iz);

   if (ix<iy)
   {
     int tmp = ix;
     ix = iy;
     iy = tmp;
   }

   if (ix<iz)
   {
     int tmp = ix;
     ix = iz;
     iz = tmp;
   }

   t = iy + iz;

   return (ix - (ix>>4) + (t>>2) + (t>>3));
}

void Error (char *error, ...)
{
   char msgbuf[300];
   va_list argptr;
   static int inerror = 0;

   inerror++;
   if (inerror > 1)
      return;

   #if USE_SDL
   SDL_Quit();
   #endif

   va_start (argptr, error);
   vfprintf(stderr, error, argptr);
   va_end (argptr);

   exit (1);
}


int32 SafeOpenAppend (const char *_filename, int32 filetype)
{
	int	handle;
    char filename[MAX_PATH];
    strncpy(filename, _filename, sizeof (filename));
    filename[sizeof (filename) - 1] = '\0';
    FixFilePath(filename);

	handle = open(filename,O_RDWR | O_BINARY | O_CREAT | O_APPEND
	, S_IREAD | S_IWRITE);

	if (handle == -1)
		Error ("Error opening for append %s: %s",filename,strerror(errno));

	return handle;
}

int32 SafeOpenWrite (const char *_filename, int32 filetype)
{
	int	handle;
    char filename[MAX_PATH];
    strncpy(filename, _filename, sizeof (filename));
    filename[sizeof (filename) - 1] = '\0';
    FixFilePath(filename);

	handle = open(filename,O_RDWR | O_BINARY | O_CREAT | O_TRUNC
	, S_IREAD | S_IWRITE);

	if (handle == -1)
		Error ("Error opening %s: %s",filename,strerror(errno));

	return handle;
}

int32 SafeOpenRead (const char *_filename, int32 filetype)
{
	int	handle;
    char filename[MAX_PATH];
    strncpy(filename, _filename, sizeof (filename));
    filename[sizeof (filename) - 1] = '\0';
    FixFilePath(filename);

	handle = open(filename,O_RDONLY | O_BINARY);

	if (handle == -1)
		Error ("Error opening %s: %s",filename,strerror(errno));

	return handle;
}


void SafeRead (int32 handle, void *buffer, int32 count)
{
	unsigned	iocount;

	while (count)
	{
		iocount = count > 0x8000 ? 0x8000 : count;
		if (read (handle,buffer,iocount) != (int)iocount)
			Error ("File read failure reading %ld bytes",count);
		buffer = (void *)( (byte *)buffer + iocount );
		count -= iocount;
	}
}


void SafeWrite (int32 handle, void *buffer, int32 count)
{
	unsigned	iocount;

	while (count)
	{
		iocount = count > 0x8000 ? 0x8000 : count;
		if (write (handle,buffer,iocount) != (int)iocount)
			Error ("File write failure writing %ld bytes",count);
		buffer = (void *)( (byte *)buffer + iocount );
		count -= iocount;
	}
}

void SafeWriteString (int handle, char * buffer)
{
	unsigned	iocount;

   iocount=strlen(buffer);
	if (write (handle,buffer,iocount) != (int)iocount)
			Error ("File write string failure writing %s\n",buffer);
}

void *SafeMalloc (long size)
{
	void *ptr;

#if 0
   if (zonememorystarted==false)
      Error("Called SafeMalloc without starting zone memory\n");
	ptr = Z_Malloc (size,PU_STATIC,NULL);
#else
    ptr = malloc(size);
#endif

	if (!ptr)
      Error ("SafeMalloc failure for %lu bytes",size);

	return ptr;
}

void *SafeLevelMalloc (long size)
{
	void *ptr;

#if 0
   if (zonememorystarted==false)
      Error("Called SafeLevelMalloc without starting zone memory\n");
   ptr = Z_LevelMalloc (size,PU_STATIC,NULL);
#else
    ptr = malloc(size);
#endif

	if (!ptr)
      Error ("SafeLevelMalloc failure for %lu bytes",size);

	return ptr;
}

void SafeFree (void * ptr)
{
   if ( ptr == NULL )
      Error ("SafeFree : Tried to free a freed pointer\n");

#if 0
	Z_Free (ptr);
#else
    free(ptr);
#endif
}
