/*----------------------------------------------*/
/* CTYPE.H: standard ctype function definition	*/
/* Copyright Franklin Software, Inc. 1997       */
/*----------------------------------------------*/
#ifndef _CTYPE_H_
#define _CTYPE_H_

#pragma SAVE

// for XA, all functions are reentrant
#ifdef __CXA__
#define	reentrant
#endif

// those pragmas are not available with XA compiler
#ifndef __CXA__
#pragma NOAREGS
#pragma REGPARMS
#endif
#pragma GENERIC
extern char _flag1(char c), _flag2(char c);
extern char toupper(char c) reentrant;
extern char tolower(char c) reentrant;
extern int isprint (char c) reentrant;

#define _IS_HEX 1               /* Mask for isxdigit */
#define _IS_DIG 2               /* Mask for isdigit  */
#define _IS_UPP 4               /* Mask for isupper  */
#define _IS_LOW 8               /* Mask for islower  */

#define _IS_SPA 1               /* Mask for isspace  */
#define _IS_CNT 2               /* Mask for iscntrl  */
#define _IS_PUN 4               /* Mask for ispunct  */

#define isalnum(c)  (_flag1(c) & (_IS_DIG | _IS_UPP | _IS_LOW))
#define isalpha(c)  (_flag1(c) & (_IS_UPP | _IS_LOW))
#define isascii(c)  ((unsigned)(c) < 128)
#define isupper(c)  (_flag1(c) & _IS_UPP)
#define islower(c)  (_flag1(c) & _IS_LOW)
#define isxdigit(c) (_flag1(c) & (_IS_DIG | _IS_HEX))

#define iscntrl(c)  (_flag2(c) & _IS_CNT)
#define ispunct(c)  (_flag2(c) & _IS_PUN)

#define toascii(c)  ((c) & 0x7f)

// #define isspace(c)  (_flag2(c) & _IS_SPA)
// #define isdigit(c)  (_flag1(c) & _IS_DIG)
extern bit isspace ( unsigned char c ) reentrant;
extern bit isdigit ( unsigned char c ) reentrant;

#pragma RESTORE

#endif
