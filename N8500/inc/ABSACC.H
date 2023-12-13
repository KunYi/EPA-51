/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 *        File Name:  ABSACC.H
 * Last Modified By:  FB  - 07.03.97 - Checked and formatted
 *                    R. Rowan - 1/11/1996 - Modified for Version 6.0
 *
 *            Notes:  ABSolute ACCess macro definitions to permit
 *                    direct access to 8051 and XA memory spaces
 */

#define CBYTE ((unsigned char volatile code  *) 0)
#define DBYTE ((unsigned char volatile data  *) 0)
#define CWORD ((unsigned int volatile code  *) 0)
#define DWORD ((unsigned int volatile data  *) 0)

// pdata and xdata defined only for 8051
#ifndef __CXA__
#define PBYTE ((unsigned char volatile pdata *) 0)
#define XBYTE ((unsigned char volatile xdata *) 0)
#define PWORD ((unsigned int volatile pdata *) 0)
#define XWORD ((unsigned int volatile xdata *) 0)
#endif

