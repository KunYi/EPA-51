/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 * INTRINS.H
 * Last Modified By:  F. Blair - 21.04.97 - added 3 new XA definitions
 *                    F. Blair - 18.04.97 - fixed swapnibble & swapbyte
 *                    R. Rowan - 1/11/1996 - modified for Version 6.0
 *
 *            Notes:  Intrinsic function descriptions for the 8051 and XA
 */

#ifndef __INTRINSIC_H__
#define __INTRINSIC_H__

#pragma SAVE
#pragma GENERIC

#ifndef __CXA__
#pragma NOAREGS
#pragma REGPARMS
#endif

extern void          _nop_     ( void );
extern bit           _testbit_ ( bit );
extern unsigned char _cror_    ( unsigned char, unsigned char );
extern unsigned int  _iror_    ( unsigned int,  unsigned char );
extern unsigned long _lror_    ( unsigned long, unsigned char );
extern unsigned char _crol_    ( unsigned char, unsigned char );
extern unsigned int  _irol_    ( unsigned int,  unsigned char );
extern unsigned long _lrol_    ( unsigned long, unsigned char );
extern unsigned char _chkfloat_( float );
extern unsigned char _swapnibble_ ( unsigned char );	// _swapnibble_ ( 0xA5 ) == 0x5A
extern unsigned int  _swapbyte_   ( unsigned int  );	// _swapbyte_ ( 0x1234 ) == 0x3412

// XA compiler provides intrinsic functions to write or read
// a byte or a word in xdata memory (MOVX instruction is used)
#ifdef __CXA__
extern unsigned char _readextb_  (unsigned int);
extern unsigned int  _readextw_  (unsigned int);
extern void          _writeextb_ (unsigned int, unsigned char);
extern void          _writeextw_ (unsigned int, unsigned int);
extern unsigned int  _getreg_	 (unsigned char);
extern unsigned char _getreglow_ (unsigned char);
extern unsigned char _getreghigh_(unsigned char);
#endif

#pragma RESTORE

#endif
