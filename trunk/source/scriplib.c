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

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "duke3d.h"
#include "scriplib.h"

/* #define DEBUG_SCRIPLIB */

#define MAX_SCRIPTS 5

typedef enum {
	SCRIPTFLAG_UNKNOWN,
	SCRIPTFLAG_CATEGORY,
	SCRIPTFLAG_ONESTRING,
	SCRIPTFLAG_TWOSTRING,
	SCRIPTFLAG_NUMBER
} scriptflag_t;

typedef struct scriptnode_s {
	struct scriptnode_s *child;
	struct scriptnode_s *sibling;
	char *key;
	scriptflag_t type;
	union {
		char *string[2];
		int number;
	} data;
} scriptnode_t;

static int script_nexthandle = 0;
static int script_numscriptsopen = 0;

static scriptnode_t *script_headnode[MAX_SCRIPTS];

/* Utility functions */
static scriptnode_t *SCRIPT_constructnode (void)
{
	scriptnode_t *s;

	s = (scriptnode_t *) malloc (sizeof (scriptnode_t));
	if (s != NULL)
	{
		s->child = NULL;
		s->sibling = NULL;
		s->key = NULL;
		s->data.string[0] = NULL;
		s->data.string[1] = NULL;
		s->type = SCRIPTFLAG_UNKNOWN;
	}
	return s;
}

static void SCRIPT_freenode (scriptnode_t *node)
{
	assert (node != NULL);

	if (node->type == SCRIPTFLAG_ONESTRING) {
		free (node->data.string[0]);
	} else if (node->type == SCRIPTFLAG_TWOSTRING) {
		free (node->data.string[0]);
		free (node->data.string[1]);
	}

	free (node->key);
	free (node->sibling);
	free (node->child);
	free (node);
	node = NULL;
}

static void SCRIPT_recursivefree (scriptnode_t *node)
{
	assert (node != NULL);

	/* Free dependant nodes first */
	if (node->child) {
		SCRIPT_recursivefree (node->child);
	}

	if (node->sibling) {
		SCRIPT_recursivefree (node->sibling);
	}

	SCRIPT_freenode (node);
}

static void SCRIPT_addsibling (scriptnode_t *node, scriptnode_t *sibling)
{
	assert (node != NULL);
	assert (sibling != NULL);
	
	/* printf ("addsib: %p, %p, %p\n", node, node->sibling, sibling); */

	if (node->sibling == NULL) {
		node->sibling = sibling;
	} else {
		SCRIPT_addsibling (node->sibling, sibling);
	}
}

static void SCRIPT_addchild (scriptnode_t *parent, scriptnode_t *child)
{
	assert (parent != NULL);
	assert (child != NULL);

	if (parent->child == NULL) {
		parent->child = child;
	} else {
		SCRIPT_addsibling (parent->child, child);
	}
}

static char *SCRIPT_copystring (char * s)
{
	char *ret;

	ret = (char *) malloc (strlen (s)+1);
	if (ret != NULL)
	{
		strcpy (ret, s);
	}
	return ret;
}

static int SCRIPT_getnexttoken (char *buffer, char* token, int start)
{
	int iterator = start;

	if (buffer[start] == '\0') {
		token[0] = '\0';
		return start;
	}

	while (iterator < 128 && !isspace (buffer[iterator]))
	{
		token[iterator-start] = buffer[iterator];
		iterator++;
	}

	token[iterator-start] = '\0';

	/* Trim off any extra whitespace */
	while (iterator < 127 && isspace(buffer[iterator+1]))
		iterator++;

	return ++iterator;
}

/* Fills in a scriptnode with the interpreted contents of a line */
static void SCRIPT_parseline (char *curline, scriptnode_t *node)
{
	char token[128];
	int i;

	/* Needs to handle 5 cases: */
	/* 	key = someint */
	/* 	key = 0xsomehexnum */
	/* 	key = ~ */
	/* 	key = "onestring" */
	/* 	key = "two" "strings" */

	assert (node != NULL);
	assert (curline != NULL);

	i = SCRIPT_getnexttoken (curline, token, 0);
	node->key = SCRIPT_copystring (token);

	i = SCRIPT_getnexttoken (curline, token, i);
	/* Sanity check... this token should be "=" */
	if (strcmp (token, "=")) {
		/* Error state, free the memory allocated */
		SCRIPT_recursivefree (node);
		return;
	}

	/* This is where the real fun begins... */
	/* we can begin to determine which of the 5 */
	/* possibilities the node is now */
	i = SCRIPT_getnexttoken (curline, token, i);

	if (!strncmp (token, "0x", 2)) {
		/* Found a hex digit! */
		node->type = SCRIPTFLAG_NUMBER;
		node->data.number = strtol (token, NULL, 16);
	} else if (isdigit (token[0])) {
		/* Found a number! */
		node->type = SCRIPTFLAG_NUMBER;
		node->data.number = atoi (token);
	} else if (token[0] == '~') {
		/* Found a ... who knows */
		node->type = SCRIPTFLAG_NUMBER;
		node->data.number = -1;
	} else if (token[0] == '"') {
		char workbuf[128];
		int r;

		/* Found one of possibly two strings */
		strcpy (workbuf, token);
		while (token != NULL && workbuf[strlen(workbuf)-2] != '"')
		{
			i = SCRIPT_getnexttoken (curline, token, i);
			strcat (workbuf, " ");
			strcat (workbuf, token);
		}
		r = sscanf(workbuf, "\"%[^\"]\"", workbuf);
		if (r == 0) workbuf[0] = '\0';

		node->type = SCRIPTFLAG_ONESTRING;
		node->data.string[0] = SCRIPT_copystring (workbuf);
		/* Check for a second string */
		i = SCRIPT_getnexttoken (curline, token, i);
		if (token[0] == '"') {
			strcpy (workbuf, token);
			while (token != NULL && workbuf[strlen(workbuf)-2] != '"')
			{
				i = SCRIPT_getnexttoken (curline, token, i);
				strcat (workbuf, " ");
				strcat (workbuf, token);
			}
			r = sscanf(workbuf, "\"%[^\"]\"", workbuf);
			if (r == 0) workbuf[0] = '\0';

			node->type = SCRIPTFLAG_TWOSTRING;
			node->data.string[1] = SCRIPT_copystring (workbuf);
		}
	} else {
		/* Error state! */
		SCRIPT_recursivefree (node);
	}
}

static scriptnode_t *SCRIPT_findinchildren (scriptnode_t *parent, char *s)
{
	scriptnode_t *cur = parent;

	if (cur == NULL) return NULL;
	cur = cur->child;
	if (cur == NULL) return NULL;
	while (cur != NULL)
	{
		if (!strcmp(cur->key, s))
			break;
		cur = cur->sibling;
	}

	return cur;
}

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
	/* STUBBED("Free"); */
	if (scripthandle == -1) return;

	SCRIPT_recursivefree (script_headnode[scripthandle]);
	script_numscriptsopen--;
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
	FILE *fp;
	char curline[128];
	scriptnode_t *headnode = NULL;
	scriptnode_t *cur_subsection = NULL;

	if (script_numscriptsopen == MAX_SCRIPTS) return -1;

	/* The main program does not check for any sort of */
	/* error in loading, so each SCRIPT_ function needs */
	/* to check if the handle is -1 before doing anything */
	fp = fopen (filename, "r");

	if (fp == NULL) return -1;

	/* Start loading the script */
	/* Loads and parse the entire file into a tree */
	script_numscriptsopen++;

	/* script_nexthandle is the current handle until we increment it */
	script_headnode[script_nexthandle] = SCRIPT_constructnode ();
	headnode = script_headnode[script_nexthandle];

	while (!feof (fp))
	{
		fgets (curline, 128, fp);
		
		/* Skip comments */
		if (curline[0] == ';') continue;

		/* Parse line */
		/* We have two options... it starts with a [, making it */
		/* a new subsection (child of headnode) or it starts with */
		/* a letter, making it a child of a subsection. */
		if (curline[0] == '[')
		{
			scriptnode_t *node;
			int i;
			
			/* Remove [] manually */
			for (i = 0; i < 127; i++)
				curline[i] = curline[i+1];
			for (i = 127; i >= 0; i--)
			{
				if (curline[i] == ']') {
					curline[i] = '\0';
					break;
				} else {
					curline[i] = '\0';
				}
			}

			/* Insert into head */
			node = SCRIPT_constructnode ();
			node->type = SCRIPTFLAG_CATEGORY;
			node->key = SCRIPT_copystring (curline);
			SCRIPT_addchild (headnode, node);
			cur_subsection = node;
			/* printf ("Working in section \"%s\"\n", node->key); */
		} else if (isalpha (curline[0])) {
			scriptnode_t *node;

			/* Ignore if not under a subsection */
			if (cur_subsection == NULL)
				continue;

			node = SCRIPT_constructnode ();
			
			/* TODO: Parse line here */
			SCRIPT_parseline (curline, node);
			if (node != NULL)
			{
				/* printf ("Adding node with key \"%s\"\n", node->key); */
				SCRIPT_addchild (cur_subsection, node);
			}
		}
	}

	fclose (fp);

	return script_nexthandle++;	/* postincrement is important here */
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
    scriptnode_t *cur;

	/* STUBBED("GetString"); */
	if (scripthandle == -1) return;

	cur = script_headnode[scripthandle];

	cur = SCRIPT_findinchildren (cur, sectionname);
	cur = SCRIPT_findinchildren (cur, entryname);

	if (cur != NULL && cur->type == SCRIPTFLAG_ONESTRING)
	{
		strcpy (dest, cur->data.string[0]);
#ifdef DEBUG_SCRIPLIB
		printf ("GetString: value for %s:%s is %s\n", sectionname, entryname, dest);
#endif
	}
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
    scriptnode_t *cur;

	/* STUBBED("GetDoubleString"); */
	if (scripthandle == -1) return;

	cur = script_headnode[scripthandle];

	cur = SCRIPT_findinchildren (cur, sectionname);
	cur = SCRIPT_findinchildren (cur, entryname);

	if (cur != NULL && cur->type == SCRIPTFLAG_TWOSTRING)
	{
		strcpy (dest1, cur->data.string[0]);
		strcpy (dest2, cur->data.string[1]);
#ifdef DEBUG_SCRIPLIB
		printf ("GetDoubleString: value for %s:%s is %s %s\n", sectionname, entryname, dest1, dest2);
#endif
	}
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
	scriptnode_t *cur;

	/* STUBBED("GetNumber"); */
	if (scripthandle == -1) return false;

	cur = script_headnode[scripthandle];

	cur = SCRIPT_findinchildren (cur, sectionname);
	cur = SCRIPT_findinchildren (cur, entryname);

	if (cur != NULL && cur->type == SCRIPTFLAG_NUMBER)
	{
		*number = cur->data.number;
#ifdef DEBUG_SCRIPLIB
		printf ("GetNumber: value for %s:%s is %ld\n", sectionname, entryname, *number);
#endif
	}

	return (cur != NULL) ? true : false;
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
