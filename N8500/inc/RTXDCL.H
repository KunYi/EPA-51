//==================================================================
//==================================================================
//
// Copyright (c) Franklin Software, Inc. 1989 - 1997
// File Name:  RTXDCL.H  Declarations for using RTX-51 with C51.
//   Version:  2.06
//  Modified:  F. Blair  25.03.97 - Minor expansions
//             S. Bleher 12.03.97 - corrections and additions
//             F. Blair  07.03.97 - Added "General notes and methods"
//             F. Blair  25.06.96 - Added function descriptions
//             F. Blair  15.05.96 - additions & corrections
//             S. Bleher 28.04.96 - Updated and extended
//             R. Rowan   1.11.96 - Modified for C51 V6
//             FL - Original definition
//
// Synopsis:
// The RTX-51 RTOS subsystem consists of THREE distinct models; 
// RTX Tiny, RTX Standard, and RTX Professional.  All three use this 
// include file.  All models use TIMER0 for their clock, and care must 
// be taken to ensure that this does not interfere with other timer0
// users (such as a monitor or watchdog, for instance).
//
// The RTX Tiny version uses the library files:  RTY.LIB
// The RTX Standard version uses the library files:  RTX.LIB
// The RTX Professional version uses the library files:  RTH.LIB
//
// Those libraries with the "S" descriptor have SEMAPHORE capable 
// functions:  RTYS.LIB, RTXS.LIB, and RTHS.LIB.
//
// Those libraries with the "D_" descriptor provide additional debug 
// capability and features such as stack overflow status handling, 
// broken mailbox handling, invalid task handling, and so on.  
// When erroneous events occur they are trapped for further 
// evaluation.  In the non-debug version, these routines are not 
// included.  This makes the code smaller, but a little harder to 
// debug.
//
// Defining or creating a "TASK" for RTX-51 is relatively simple.
// Please note that in the following illustrations standard 
// presentation rules apply:
// void name(void) task # [group # [priority # [istack # [xstack #]]]]
//   where:
//          task      is an unsigned char; the task ID being created
//                    Range:   0-6   for RTY
//                             0-28  for RTX
//                             0-124 for RTH
//          group     is an unsigned char in the range of 0-1 for RTY,
//                    and 0-3 for RTX and RTH. This "groups" all tasks 
//                    with the same "group number" together.  The 
//                    default value for "group" is 0.  Each group is 
//                    defined by it's "tick rate".  The different tick
//                    rates are built by successive divisions.  These
//                    division steps are specified in ProView's
//                    "Options/Linker/RTX" dialog box.
//          priority  is an unsigned char in the range of 0 - 3
//                    The default value is 0.
//          istack    is an unsigned char indicating the number of
//                    stack bytes to reserve in IDATA memory.
//                    The default value is 8 for RTY and 16 for RTX & 
//                    RTH.
//          xstack    is an unsigned char indicating the number of
//                    stack bytes to reserve in XDATA memory.  Since
//                    RTY is intrinsically SMALL and uses internal RAM
//                    space, this directive applies only to RTX and 
//                    RTH.
//                    The default value is 16.
//
//
//==================================================================
//===== Description of RTY "Tiny" model version of the 8051 RTOS
//  - Requires only DATA and IDATA space
//  - Can manage up to 8 tasks at a time (0-7).  Task #7 is reserved
//    by the system to manage the tasks of group #1.
//  - Requires no explicit XDATA memory for operation (unless mail
//    boxes are used).  It can, however, access all XDATA space in
//    the usual manner.
//  - Resource usage:
//       1 byte of BDATA space for state
//       5 bytes of DATA space for clock/timer and SP initialization
//      10 bytes of IDATA space PER PRIORITY LEVEL, containing
//        - the return address (stacked during TIMER0 interrupt svc)
//        - ACC, PSW, B, DPL, DPH
//        - the previous task_id
//        - the next task_id
//        PER TASK:
//          3 bytes of DATA for the status, the counter and the queue.
//          3 bytes + "istack" bytes of IDATA for stack storage
//        Additional:
//          3 bytes of DATA space if the DEBUG libraries are used
//          4 bits of BDATA space for semaphore versions.
//    Code size is number and complexity of tasks dependent, but
//    can be less than 800 bytes.  Add approximately 200 bytes if
//    semaphores are used, and 300 bytes if mailboxes are used.
//    The kernel uses TIMER0 for its interrupt services.
//  - Uses RTY.LIB, RTYS.LIB if using semaphores, or D_RTY.LIB
//    (D_RTYS.LIB with semaphores) for debugging.
//
// Defining or creating a "TASK" for RTY:
// void name(void) task # [group # [priority # [istack #]]]
//
// Note:  The task's name is not used to manage task related events.
//        It is usually best to create a macro definition for this
//        type of action.  For example:
//        #define TSK_menu 3
//        #define SET_alarm 5
//        ...
//        void fMenu( void ) task TSK_menu { ...
//        void Alarm( void ) task SET_alarm { ...
//
//
//==================================================================
//===== Description of RTX "Standard" model version of the 8051 RTOS
//  - Requires 256 bytes of XDATA space
//  - Can manage up to 29 tasks at a time
//  - Resource usage:
//      1 byte of BDATA space for state
//      5 bytes of DATA space for clock/timer and SP initialization
//      10 bytes of IDATA space PER PRIORITY LEVEL, containing
//        - the return address (stacked during TIMER0 interrupt svc)
//        - ACC, PSW, B, DPL, DPH
//        - the previous task_id
//        - the next task_id
//      Additional:
//        3 bytes of DATA space if the DEBUG libraries are used
//        4 bits of BDATA space for semaphore versions.
//      Code size is number and complexity of tasks dependent, but
//      can be less than 900 bytes.  Add approximately 200 bytes if
//      semaphores are used, and 300 bytes if mailboxes are used.
//      The kernel uses TIMER0 for its interrupt services.
//  - Uses RTX.LIB, RTXS.LIB if using semaphores, or D_RTX.LIB
//    (D_RTXS.LIB with semaphores) for debugging.
//
// Defining or creating a "TASK" for RTX:
// void name(void) task # [group # [priority # [istack # [xstack #]]]]
// { ... };
//
// Note:  The task's name is not used to manage task related events.
//        It is usually best to create a macro definition for this
//        type of action.  For example:
//        #define TSK_menu 3
//        #define SET_alarm 5
//        #define FIRST_group 1
//        ...
//        void fMenu( void ) task TSK_menu { ...
//        void Alarm( void ) task SET_alarm group FIRST_group { ...
//
//
//==================================================================
//===== Description of RTH "Professional" (huge) model of the RTOS
//  - Requires 1K of XDATA space
//  - Can manage up to 125 tasks at a time
//  - Supports cascaded timer events
//  - Resource usage:
//      1 byte of BDATA space for state
//      5 bytes of DATA space for clock/timer and SP init. info
//      4 bytes PER TASK of XDATA
//      10 bytes of IDATA space PER PRIORITY LEVEL, containing
//        - the return address (stacked during TIMER0 interrupt svc)
//        - ACC, PSW, B, DPL, DPH
//        - the previous task_id
//        - the next task_id
//      Additional:
//        3 bytes of DATA space if the DEBUG libraries are used
//        4 bits of BDATA space for semaphore versions.
//      Code size is number and complexity of tasks dependent, but
//      can be less than 1 KByte.  Add approximately 200 bytes if
//      semaphores are used, and 300 bytes if mailboxes are used.
//      The kernel uses TIMER0 for its interrupt services.
//  - Uses RTH.LIB, RTHS.LIB if using semaphores, or D_RTH.LIB
//    (D_RTHS.LIB with semaphores) for debugging.
//
// Defining or creating a "TASK" for RTH:
// void name(void) task # [group # [priority # [istack # [xstack #]]]]
// { ... };
//
// Note:  The task's name is not used to manage task related events.
//        It is usually best to create a macro definition for this 
//        type of action.  For example:
//        #define TSK_menu 3
//        #define SET_alarm 5
//        #define FIRST_group 1
//        ...
//        void fMenu( void ) task TSK_menu { ...
//        void Alarm( void ) task SET_alarm group FIRST_group { ...
//
//
//==================================================================
//===== Using the MAIL BOX feature
// The MAILBOX features are independent of the RTX model being used.
// Resources will be allocated and consumed only if a task makes use
// of one (or more) of the MAILBOX service routines.  Using the
// MAILBOX features will add about 300 bytes to your code space
// requirements.
//
// The absolute physical location of the mail box data is in on a
// single contiguous page (256 bytes) of XDATA memory.  This page can
// be located at any valid and convenient location.  The first
// 16 bytes indicate the states of the 8 mailboxes.  The subsequent
// 240 bytes correspond to the mailboxes contents.  In addition, 2
// DATA bytes in the chips BIT area (BDATA) contain the mail box FULL
// and EMPTY semaphores for each of the 8 mail boxes.
//
//
//==================================================================
//===== System Definitions (times shown below are computed @12Mhz)
//
//    name    default   result           description
//------------------------------------------------------------------
// TIM0_INIT   -1000     1ms     Tick Rate (reload value of TIMER0)
//  DIVIDE_1     100     0.1s    Group 1 divisor
//  DIVIDE_2     100     10s     Group 2 divisor
//  DIVIDE_3      90     15min.  Group 3 divisor
//   OS_XLEN    1024             size of XDATA for stacks and use by
//                               the memory allocator
//
// These definitions are internal library values and are modified by
// using compiler directives.  For example:
//   #pragma defj=OS_XLEN/2048
//
// Resets the length value for OS_XLEN to 2048 instead of the default
// XDATA section length value of 1024.  Other values similar.
//
//
//==================================================================
//===== General notes and methods
// 1.  You must use a main() routine.  This routine should be terminated 
//     with a "while(1);"  // dead end
//
// 2.  In the main(), you must call OS_INIT() at least once, before any
//     other kernel routine.  OS_INIT() and it's functionality is NOT
//     integrated into the startup routine to permit those users who 
//     wish to do their own hardware initializations.  Those should be 
//     done before calling OS_INIT().
//
// 3.  OS_FREE() must be called after any calls to OS_TST() in order to 
//     release the semaphore resource called by OS_TST().  For instance:
//        os_tst( semaphore_reference );
//           ...				// use the resource ...
//        os_free( semaphore_reference );
//     Failure to release the resource will cause it to be unavailable
//     to other functions, procedures, or operations.
//
// 4.  The return value for OS_TST() should be ignored for now.  It was 
//     left in to assure compatibility to earlier releases.
//
// 5.  OS_TST_TOUT() works that same as OS_TST, with the addition of a
//     time-out value.  Use this routine in case the resource selected
//     could be busy for a long time.  This will prevent the system from
//     being unable to continue while it's waiting on the resource to 
//     become available.  The semaphore resource should be held until the 
//     test has finished.
//
// 6.  The RTX51 RTOS system does NOT support time-slicing.  Any executing
//     task must "give" permission for the next task to be run.  While 
//     this is a less optimum solution, it results in smaller cleaner 
//     code.  The single other biggest advantage is that the kernal can
//     not 'freeze' a task.  This improves performance.  The best way to 
//     "hook" an interrupt to a task is for the interrupt to start, or 
//     signal a task.  You should set the priority of your task 
//     "interrupt" to a higher level then the kernel interrupt, which is 
//     set to 0 by default.
//
// 7.  The OS_TST() function is intended to be "uninterruptible" from
//     start to finish.  This permits one caller, and only one caller, to 
//     check the status of any particular semaphore.  This function is 
//     most often used to control access to:
//        a non-reentrant functions
//        a peripheral (UART, I/O)
//        a shared memory area
//        another task...
//------------------------------------------------------------------
//
//==================================================================
//===== Define some working designators
typedef unsigned char state, event, delay, semaphore, task_id;
extern char OS_ERR1, OS_ERR2;


//==================================================================
//===== List of events
#define SIGNAL          0x10    /* event = signal */
#define TOUT            0x20    /* event = delay  */


//==================================================================
//===== This structure defines the TCB (Task Control Block)
// Note:  This structure is shown for informational completeness only.  It
// is NOT necessary for the user to create or manage this structure.  C51
// and the L51 linker will manage this structure for you. 
typedef struct {
	char task_num;
	void (*fct)();
	char _priority;   /* Note:  "priority" IS a KEYWORD! */
	char period;
	char stack_size;
	char xstack_size;
} taskx;


//==================================================================
//===== System FUNCTION Prototypes
//
// Most of the system services have only 1 parameter and are one byte
// in length.  That parameter is passed via R4.  Return values are 
// passed back via R4.
//
//------------------------------------------------------------------
// SYSTEM FUNCTION; creates the designated task, RETURNS NOTHING.
void os_create( task_id ) reentrant;
// If the task being created has a higher priority then the currently 
// active task, it will begin running immediately.

//------------------------------------------------------------------
// SYSTEM FUNCTION; halts the designated task, RETURNS NOTHING.
void os_delete( task_id ) reentrant;
// This function causes a forced termination of the designated task.
// The deleted task gets set to the INVALID state.  State switching
// occurs immediately.  Use of this function should be regarded as
// an exception.  If the task is an interrupted task, it will not 
// resume. os_delete could be interrupted by CLOCK.  The scheduler
// is blocked by disabling the EA bit for a time that may exceed a
// several hundred clock cycles (depending upon the number of tasks
// in the READY state.  
//
// To abort a task, a call to os_create is not necessary.  A simple 
// "RETURN" is far better.  The DEBUG version will generate an
// exception (0x12) only if the task is unknown.
//
// SPECIAL NOTE:  os_delete SHOULD NOT be called from an interrupt
// routine.

//------------------------------------------------------------------
// SYSTEM FUNCTION; initializes the RTX, RETURNS NOTHING.
void os_init( void );

//------------------------------------------------------------------
// SYSTEM FUNCTION; suspend the task and wait for a signal, RETURNS
// NOTHING.
void os_waitsig( void ) reentrant;

//------------------------------------------------------------------
// SYSTEM FUNCTION; moves a task to the READY state, RETURNS NOTHING.
void os_pause( void ) reentrant;
// Moves the calling task to the READY state if another task of equal
// priority is also ready to run.

//------------------------------------------------------------------
// SYSTEM FUNCTION; sends a signal to the indicated task, RETURNS
// NOTHING.
void os_sendsig( task_id ) reentrant;
// Sends a signal to the specified task.  The signal is ignored if the
// task is NOT WAITING for a signal.  If the task is not waiting for
// any other signal it moves the task to the READY state.

//------------------------------------------------------------------
// SYSTEM FUNCTION; sets a task to the IDLE_STATE for the specified
// (absolute) period.  It RETURNS NOTHING.
void os_del_abs( delay ) reentrant;
// The delay period is given in "ticks" of the RTX clock.

//------------------------------------------------------------------
// SYSTEM FUNCTION; puts a task to SLEEP for the specified period
// It RETURNS NOTHING.  
void os_del_rel( delay ) reentrant;
// This function reloads the value of the timer associated with the
// task with:  time_remaining + delay.  The task will then be declared
// ready when that period has expired.

//------------------------------------------------------------------
// SYSTEM FUNCTION; wait for a DELAY or SIGNAL.  RETURNS 0 if the 
// delay period has elapsed BEFORE a signal is received, otherwise !0.
char os_delsig( delay ) reentrant;
// This function moves a task to the WAITING state.  The wait period
// is limited by delay.  This function is identical to OS_WAITSIG, as 
// the "wait_for_signal" bit is also asserted (set).  The task will 
// leave the WAITING state (move to the READY state) at the occurrence 
// of a "time_out" or "signal" event.

//------------------------------------------------------------------
// SYSTEM FUNCTION; wait for a SIGNAL.  RETURNS 0 if the delay period 
// has elapsed BEFORE a signal is received, otherwise !0.
char os_delsig_rel( delay ) reentrant;
// This function moves a task to the WAITING state.  The wait period
// is limited by delay.  This function is identical to OS_WAITSIG, as 
// the "wait_for_signal" bit is also asserted (set).  The task will 
// leave the WAITING state (move to the READY state) at the occurrence 
// of a "signal" event.

//------------------------------------------------------------------
// SYSTEM FUNCTION; waits a specified amount of time for a SIGNAL.  
// RETURNS 0 if the delay period has elapsed BEFORE a signal is 
// received, otherwise !0.
char os_delsig_abs( delay ) reentrant;
// This function moves a task to the WAITING state.  The wait period
// is limited by delay as an absolute value.  This function is 
// identical to OS_WAITSIG, as the "wait_for_signal" bit is also 
// asserted (set).  The task will leave the WAITING state (move to the 
// READY state) at the occurrence of a "signal" event.

//------------------------------------------------------------------
// Test and Set a semaphore
char os_tst( semaphore ) reentrant;

//------------------------------------------------------------------
// Release a semaphore
char os_free( semaphore ) reentrant;

//------------------------------------------------------------------
// Test and Set a semaphore after a delay
char os_tst_tout( delay, semaphore ) reentrant;

//------------------------------------------------------------------
// Release a semaphore
char os_free_tout( semaphore ) reentrant;


//==================================================================
//===== List of TASK STATES used by the SYSTEM INFORMATION functions
// READY:  Task is waiting to be executed
#define READY           0x00

// RUNNING:  Task currently being executed
#define RUNNING         0x01

// UNDEFINED:  This state identifier is not currently in use
//#define <TBD>         0x02

// UNDEFINED:  This state identifier is not currently in use
//#define <TBD>         0x03

// WAITING:  Task is waiting for an event.  When the specified
//           event occurs, the task will become READY
#define WAITING         0x04

// UNDEFINED:  This state identifier is not currently in use
//#define <TBD>         0x05

// UNDEFINED:  This state identifier is not currently in use
//#define <TBD>         0x06

// UNDEFINED:  This state identifier is not currently in use
//#define <TBD>         0x07

// DELETED:  The task is no longer READY, ACTIVE, RUNNING, or WAITING
#define DELETED         0x08

// UNDEFINED:  This state identifier is not currently in use
//#define <TBD>         0x09

// UNDEFINED:  This state identifier is not currently in use
//#define <TBD>         0x0A

// UNDEFINED:  This state identifier is not currently in use
//#define <TBD>         0x0B

// ACTIVE:  The indicated task is active, but another 
//          task with a higher priority level is running
#define ACTIVE          0x0C

// UNDEFINED:  This state identifier is not currently in use
//#define <TBD>         0x0D

// UNDEFINED:  This state identifier is not currently in use
//#define <TBD>         0x0E

// UNDEFINED:  This state identifier is not currently in use
//#define <TBD>         0x0F

// UNDEFINED:  All of the following state identifiers are 
// currently NOT in use!
//#define <TBD>         0x10 through 0xFE

// UNKNOWN:  The task was not declared and doesn't exist.  
// This status can be returned when os_getstatus is called and
// the requested TASK_ID is not known and/or not in use.
#define UNKNOWN         0xFF


//==================================================================
//===== System INFORMATION Prototypes
//
// SYSTEM INFORMATION; get the status of the indicated task.  
// RETURN:  See the list above.
state os_getstatus( task_id ) reentrant;

// SYSTEM INFORMATION; get the priority of the indicated task.  
// RETURN:  See the list above.
unsigned char os_getpriority( task_id ) reentrant;

// SYSTEM INFORMATION; get a list of events for the indicated task.
// RETURN:  1 byte; bits 4, 5, &6 respectively indicate whether a 
// signal, a time_out or flag_release is awaited (time_out and 
// flag_release may not be awaited at the same time)
event os_getevents( task_id )reentrant;

// SYSTEM INFORMATION; get the ID of the current task.  
// RETURN:  The task ID as an unsigned char
unsigned char os_gettaskcur( void ) reentrant;

// SYSTEM INFORMATION; get the priority of the current task.  
// RETURN:  The priority level (0-3) of the current task.
unsigned char os_getprioritycur( void ) reentrant;


//==================================================================
//===== System UTILITY Prototypes
// 
// The mail box system is a message passing service used to pass 
// messages between tasks.  In RTX messages are limited to simple
// expressions and entered as characters.
//
// Mailboxes are most often used to pass parameters between tasks.
// Task execution should start with a read of the appropriate box
// to check for information.
//
// Mailboxes are also used for data flow management.  For example, a
// task must send a character to the serial port.  The data is sent to
// the mailbox which will act as a buffer.
//
// RTX can manage up to 8 mailboxes.  The first mailbox has a capacity
// of 128 bytes and is well suited for data flow management.  The 
// other 7 mailboxes have a capacity of 16 bytes each.  Mailbox 
// messages are handled on a FIFO mode.  The mailbox capacities apply 
// apply to all kernel versions.
//
// The mailbox state can be known by calling mail_size() which returns
// number of characters contained in the box.  
// 
//
extern bdata char MAIL_FULL;
extern bdata char MAIL_EMPTY;

//
// ERROR Messages for the Mail System
#define MBX_UNKNOWN	0x81	// A number > 7 was entered
#define MBX_INVALID	0x8D	// Internal pointer error
#define MBX_FULL	0x8E	// Write attempted to a FULL mailbox
#define MBX_EMPTY	0x8F	// Read attempted to an EMPTY mailbox

//
// SYSTEM UTILITY; sets up and initializes the mailbox system
// RETURN:  Nothing
// ERRORS:  None
void mail_reset( void ) reentrant;
// This function should be called (and terminated) before the first 
// mailbox reference is made.  It initializes all mailboxes, sets the
// full bits to 0, and the EMPTY bits to 1.

//
// SYSTEM UTILITY; sends message character to the mailbox
// RETURN:  Nothing
// ERRORS:  None
// Send a message to a mail box
void mail_send( char box, char message )reentrant;

//
// SYSTEM UTILITY; reads a message character from the mailbox
// RETURN:  The FIFO character, or an error code as defined above.
// ERRORS:  MBX_UNKNOWN, MBX_INVALID, MBX_EMPTY
unsigned char mail_read( char box )reentrant;

//
// SYSTEM UTILITY; returns the number of characters in the mailbox
// RETURN:  An error code or 1 character of size
// ERRORS: MBX_UNKNOWN, MBX_INVALID
unsigned char mail_size( char box )reentrant;
// If the FULL bit is set it returns the SIZE of the mailbox
// Else it returns number of bytes still to be read.  

//
// SYSTEM UTILITY; Clears any characters in the mailbox
// RETURN:  Nothing
// ERROR: MBX_UNKNOWN, MBX_INVALID
void mail_flush( char box )reentrant;
// Sets the FULL bit associated with that mailbox to 0, and the EMPTY
// bit to 1;

//
// SYSTEM UTILITY; Tests the mailbox
// RETURN:  *
// ERRORS:  *
unsigned char mail_test( char box ) reentrant;
// The test consists of verifying the consistency of internal pointers
// and the status of the MAIL_FULL and MAIL_EMPTY bits associated with
// that box.  If abnormalities are detected, the OS_TRAP function is 
// called.
// NOTE:  The function requires the DEBUG LIBRARIES of the RTX 
// system.  mail_test is automatically initiated at the beginning
// of; READ, SEND, SIZE, and FLUSH.  If an abnormality is detected,
// the service is aborted, and the OS_TRAP function is initiated.


//==================================================================
//===== System UTILITY Prototypes:  MEMORY Management
// Memory management is performed only for XDATA memory spaces.
unsigned char xdata *mem_alloc( unsigned int ) reentrant;

// Free previously allocated XDATA memory
void mem_free (char xdata *pointer) reentrant;


//==================================================================
//===== System UTILITY Prototypes:  Calendar Functions
// Date and time structure general definition
struct stime {
	char dayofweek;    // 0(Sunday)..6(Saturday)
	char year;         // 0..99  (note:  19xx is >91, & 20xx is <92)
	char month;        // 1..12
	char day;          // 1..31
	char hour;         // 0..23
	char minute;       // 0..59
	char second;       // 0..59
};

#define ULONG unsigned long
ULONG time_2long (generic struct stime *st1) reentrant;
void time_2struct (ULONG l1,generic struct stime *st1 )reentrant;

//===== End of RTXDCL.H
//==================================================================
//==================================================================
