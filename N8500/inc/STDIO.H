/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 *        File Name:  STDIO.H
 * Last Modified By:  SWB - 17.04.97 - Changed PUTCHAR to be NON reentrant
 *                    R. Rowan - 1/11/1996 - Modified for Version 6.0
 *            Notes:  Standard I/O function declarations
 */

#ifndef _STDIO_H_
#define _STDIO_H_

#if (!defined(__C51V6__) && !defined(__CXA__))
#ifndef generic
#define generic
#endif
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifndef NULL
#define NULL 0L
#endif

#ifndef EOF
#define EOF -1
#endif

#pragma SAVE
#pragma GENERIC
#ifndef __CXA__
#pragma NOAREGS
#pragma REGPARMS
#else
#define reentrant
#endif
extern int	_getkey(void);
extern int	getchar (  void  ) reentrant;
extern char	ungetchar ( char c ) reentrant;
extern char	generic *gets ( char   generic *s ) reentrant;
extern int	putchar ( const int c );
extern int	puts ( const char   generic *s ) reentrant;
extern int	printf ( const char   generic *format, ...) reentrant;
extern int	sprintf ( char   generic *buffer, const char   generic *format, ...) reentrant;
extern int	scanf ( const char   generic *format, ...) reentrant;
extern int	sscanf ( const char   generic *buffer, const char   generic *format, ...) reentrant;
#pragma RESTORE

#endif
