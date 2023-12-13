/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 *        File Name:  STDARG.H
 * Last Modified By:  R. Rowan
 *    Last Modified:  1/11/1996
 *                    Modified for Version 6.0
 *            Notes:  Prototypes for variable argument lists
 */

#ifndef _STDARG_H_
#define _STDARG_H_

#ifndef NULL
# define NULL 0L
#endif

#ifndef _VA_LIST_DEFINED
typedef unsigned char idata *va_list;
#define _VA_LIST_DEFINED
#endif

#define va_start(ap,v) ap = (va_list)(SP - __STARTPOS__)
#define va_arg(ap,t) (*(t idata *)((ap-=sizeof(t))+1))

#define va_end(ap)

#endif
