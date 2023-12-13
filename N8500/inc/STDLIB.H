/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 *        File Name:  STDLIB.H
 * Last Modified By:  SWB      - 23.06.97 added calloc, free,
 *                               init_mempool, malloc, and realloc.
 *                    R. Rowan - 1/11/1996
 *                    Modified for Version 6.0
 *            Notes:  Standard ANSI function declarations
 */

#ifndef  _STDLIB_H_
#define  _STDLIB_H_

#if (!defined(__C51V6__) && !defined(__CXA__))
#ifndef generic
#define generic
#endif
#endif

//------------------------------------------------------------------------------
// For C51 V6 compiler only
//------------------------------------------------------------------------------
#ifdef __C51V6__
#if __FLOATTYPE__ == 1 	// IEEE floating point
#	define	atof	atoff
#	define strtod	strtodf
#else         		// BCD floating point
#	if __FLOATOPTION__ == 0		// all types
#	elif __FLOATOPTION__ == 1 	// Floats assumed as BCD float type
#		define	atof	atoff
#		define strtod	strtodf
#	elif __FLOATOPTION__ == 2 	// Floats assumed as BCD double type
#		define	atof	atof
#		define strtod	strtod
#	else 					// Floats assumed as BCD long double type
#		define	atof	atofl
#		define strtod	strtodl
#	endif
#endif
#endif

//------------------------------------------------------------------------------
// For CXA compiler only
//------------------------------------------------------------------------------
// only IEEE floating point is available at the moment
#ifdef __CXA__
#	define	atof	atoff
#	define strtod	strtodf
#endif

#pragma SAVE
#pragma GENERIC
#ifndef __CXA__
#pragma NOAREGS
#pragma REGPARMS
#else
#define reentrant
#endif

extern int		atoi (const char  generic *s) reentrant;
extern long		atol (const char  generic *s) reentrant;
extern long		strtol (const char  generic *s, char  generic * generic *end, int base) reentrant;
extern unsigned long	strtoul (const char  generic *s, char  generic * generic *endp, int base) reentrant;
extern int 		rand (void) reentrant;
extern void		srand (unsigned int seed) reentrant;
extern int		abs (int n) reentrant;
extern long		labs (long n) reentrant;

extern double		atof (const char  generic *s) reentrant;
extern double		strtod (const char  generic *s, char  generic * generic *endp) reentrant;

extern	void	*calloc( unsigned int size, unsigned int len );
extern	void	free( xdata *p );
extern	void	init_mempool( xdata *p, unsigned int size );
extern	void	*malloc( unsigned int size );
extern	void	*realloc( xdata *p, unsigned int size );

#pragma RESTORE

#endif
