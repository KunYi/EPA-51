/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 *        File Name:  STRING.H
 * Last Modified By:  R. Rowan
 *    Last Modified:  1/11/1996
 *                    Modified for Version 6.0
 *            Notes:  ANSI string functions 
 */

#ifndef  _STRING_H_
#define  _STRING_H_

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
#define NULL 0L
#endif

#pragma SAVE
#pragma GENERIC
#ifndef __CXA__
#pragma NOAREGS
#pragma REGPARMS
#else
#define reentrant
#endif

extern char	generic * strrchr  (char generic *s, int c) reentrant;
extern char	generic * strcat   (char generic *p1, const char  generic *p2 ) reentrant;
extern char	generic * strncat  (char generic *p1, const char  generic *p2, size_t n) reentrant;
extern size_t		  strpos   (const char  generic *s, int c) reentrant;
extern char	generic * strncpy  (char  generic *p1, const char generic *p2, size_t n) reentrant;
extern char	generic * strcpy   (char  generic *p1, const char generic *p2) reentrant;
extern int		  strcmp   (const char  generic *p1,const char generic *p2) reentrant;
extern int		  strncmp  (const char  generic *p1,const char generic *p2, size_t n) reentrant;
extern size_t		  strlen   (const char  generic *s) reentrant;
extern char	generic * strchr   (char   generic *s, int c) reentrant;
extern size_t		  strrpos  (const char generic *s, int c) reentrant;

extern int		  memcmp   (const void generic *s1, const void  generic *s2, size_t n) reentrant;
extern void	generic * memcpy   (const void  generic *dest, const void generic *src, size_t n) reentrant;
#define memmove(a,b,c) 	memcpy(a,b,c)
extern void	generic * memchr   (const void  generic *s, int c, size_t n) reentrant;
extern void	generic * memset   (const void  generic *s, int c, size_t n) reentrant;
#pragma RESTORE

#endif
