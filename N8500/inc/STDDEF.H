/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 *        File Name:  STDDEF.H
 * Last Modified By:  R. Rowan
 *    Last Modified:  1/11/1996
 *                    Modified for Version 6.0
 *            Notes:  Standard definitions
 */

#ifndef _STDDEF_H_
#define _STDDEF_H_

#ifndef NULL
#define NULL 0L
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif

typedef int ptrdiff_t;
#define offsetof(s,m)	(size_t)&(((s *)0)->m)

#endif
