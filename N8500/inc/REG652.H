/* Copyright Franklin Software, Inc. 1989 - 1996
* REG652.H
* Last Modified By: R. Rowan
* Last Modified:	1/11/1996
* Modified for Version 6.0
* Notes:
* Declarations for 83C652
*/

#include <reg51.h>

#define SOBUF SBUF
#define SOCON SCON

/* BYTE registers*/

sfr at 0xD8 S1CON;
sfr at 0xD9 S1STA;
sfr at 0xDA S1DAT;
sfr at 0xDB S1ADR;

/* BIT register */

/*S1CON bits*/
sbit at 0xD8 CR0;	
sbit at 0xD9 CR1;
sbit at 0xDA AA;
sbit at 0xDB SI;
sbit at 0xDC ST0;	
sbit at 0xDD STA;
sbit at 0xDE ENSI;


sbit at 0xAD ES1;

sbit at 0xBD PS1;

