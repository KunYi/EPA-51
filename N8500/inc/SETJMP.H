/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 *        File Name:  SETJMP.H
 * Last Modified By:  R. Rowan
 *    Last Modified:  1/11/1996
 *                    Modified for Version 6.0
 *            Notes:  Prototypes for 8051 longjmp facility
 */
 
#ifndef _SETJMP_H_
#define _SETJMP_H_

// Available only for 8051
#ifndef __CXA__
/* define the buffer type for holding the state information */

#pragma SAVE
#pragma REGPARMS
#ifndef _JMP_BUF_DEFINED
#define _JBLEN	7  /* RET-ADDR, ?C_XBP, ?C_IBP, ?C_BP, SP */
typedef  char jmp_buf[_JBLEN];
#define _JMP_BUF_DEFINED
#endif

/* function prototypes */
int  setjmp  (jmp_buf);
void longjmp (jmp_buf, int);
#pragma RESTORE

#endif

#endif
