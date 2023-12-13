/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 *        File Name:  MEMSET.H
 * Last Modified By:  FB  - 07.03.97 - Checked and formatted
 *                    R. Rowan - 1/11/1996 - Modified for Version 6.0
 *
 *            Notes:  Contains the ANSI required memory definitions for
 *                    direct allocation
 *
 *            Usage:  This file is included by CALLOC.C, MALLOC.C,
 *                    REALLOC.C, FREE.C, and INITMEM.C.
 */

struct mem  {
  struct mem xdata *next;
  struct mem xdata *prev;
  unsigned int       len;
  unsigned char      mem[1];
};
 
