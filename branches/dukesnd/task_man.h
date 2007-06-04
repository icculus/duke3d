/**********************************************************************
   module: TASK_MAN.C

   author: James R. Dos�
   phone:  (214)-271-1365 Ext #221
   date:   July 25, 1994

   Public header for TASK_MAN.C, a low level timer task scheduler.

   (c) Copyright 1994 James R. Dos�.  All Rights Reserved.
**********************************************************************/

#ifndef __TASK_MAN_H
#define __TASK_MAN_H

#ifdef __cplusplus
extern "C" {
#endif

enum TASK_ERRORS
   {
   TASK_Warning = -2,
   TASK_Error = -1,
   TASK_Ok = 0
   };

struct TASK
{
    TASK			*next;
    TASK			*prev;
    void			(*TaskService)( TASK * );
    void			*data;
    long			rate;
    volatile long	count;
    int				priority;
    int				active;
};

// TS_InInterrupt is TRUE during a taskman interrupt.
// Use this if you have code that may be used both outside
// and within interrupts.

extern volatile int TS_InInterrupt;

void    TS_Shutdown( void );
TASK    *TS_ScheduleTask( void Function( TASK * ), int rate, int priority, void *data );
int     TS_Terminate( TASK *task );
void    TS_Dispatch( void );
void    TS_SetTaskRate( TASK *task, int rate );
void    TS_UnlockMemory( void );
int     TS_LockMemory( void );

#ifdef __cplusplus
}
#endif

#endif
