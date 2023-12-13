/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 *        File Name:  PUTCHAR.C
 * Last Modified By:  FB  - 07.03.97 - Checked and formatted
 *                    R. Rowan - 1/11/1996 - Modified for Version 6.0
 *
 *            Usage:  This is an alternate PutChar file written in C.  It may
 *                    be better suited for your specific application then the 
 *                    one in the libraries.  NOTE!  This routine returns a "char"
 *                    you will need to modify your include file to correctly use
 *                    this version.  Otherwise, use the one in the ..\LIB directory.
 *
 *                    However, it is recommended that you use the library version
 *                    unless you need specific changes to accomodate your specific
 *                    conditions or needs.  This file is provided "as is" by Franklin
 *                    Software.  We have used and tested this file in this configuration
 *                    any changes are the responsibility of the user.
 *
 *            Notes:  Using ProView:  Include a copy of this file into your project, 
 *                    and process it in the normal manner.
 *
 *                    Using DOS:  Compile this file with C51, like this:
 *                                        C51 PUTCHAR.C [memory_model]
 *
 *                                Link the file with l51 into your app. like this:
 *                                        L51 <.OBJ_list>, PUTCHAR.OBJ [L51_controls]
 *
 *                   NOTE:  It is NOT recommended that this modified file be incorporated
 *                          into your standard Franklin Software library files.
 */
 
#include <reg51.h>

#define XON  0x11
#define XOFF 0x13

char putchar (char c) reentrant {

  if (c == '\n')  {		// is it a CRLF?
    if (RI)  {
      if (SBUF == XOFF)  {
        do  {
          RI = 0;
          while (!RI);
        }
        while (SBUF != XON);
        RI = 0; 
      }
    }
    while (!TI);
    TI = 0;
    SBUF = 0x0d;		// output a carriage return if needed
  }
  if (RI)  {
    if (SBUF == XOFF)  {
      do  {
        RI = 0;
        while (!RI);
      }
      while (SBUF != XON);
      RI = 0; 
    }
  }
  while (!TI);
  TI = 0;
  return (SBUF = c);
}
