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

#ifndef __TASK_MAN_H
#define __TASK_MAN_H

enum TASK_ERRORS
   {
   TASK_Warning = -2,
   TASK_Error = -1,
   TASK_Ok = 0
   };

typedef struct task
{
    struct   task *next;
    struct   task *prev;
    void          ( *TaskService )( struct task * );
    void          *data;
    long          rate;
    volatile long count;
    int           priority;
    int           active;
} task;

// TS_InInterrupt is TRUE during a taskman interrupt.
// Use this if you have code that may be used both outside
// and within interrupts.

extern volatile int TS_InInterrupt;

void    TS_Shutdown( void );
task    *TS_ScheduleTask( void ( *Function )( task * ), int rate,
                          int priority, void *data );
int     TS_Terminate( task *ptr );
void    TS_Dispatch( void );
void    TS_SetTaskRate( task *Task, int rate );
void    TS_UnlockMemory( void );
int     TS_LockMemory( void );

#endif
