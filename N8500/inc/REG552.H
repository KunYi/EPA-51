/* Copyright Franklin Software, Inc. 1989 - 1996
* REG552.H
* Last Modified By: R. Rowan
* Last Modified:	1/11/1996
* Modified for Version 6.0
* Notes:
* Declarations for 83C552
*/

#include <reg51.h>

#define	IEN0	IE
#define	IP0		IP
#define	S0BUF	SBUF
#define	S0CON	SCON
#define	ES0		ES
#define	PS0		PS

/*Byte registers*/

sfr at 0xA9 CML0;
sfr at 0xAA CML1;
sfr at 0xAB CML2;
sfr at 0xAC CTL0;
sfr at 0xAD CTL1;
sfr at 0xAE CTL2;
sfr at 0xAF CTL3;

sfr at 0xC0 P4;


sfr at 0xC4 P5;
sfr at 0xC5 ADCON;
sfr at 0xC6 ADCH;


sfr at 0xC8 TM2IR;
sfr at 0xC9 CMH0;
sfr at 0xCA CMH1;
sfr at 0xCB CMH2;
sfr at 0xCC CTH0;
sfr at 0xCD CTH1;
sfr at 0xCE CTH2;
sfr at 0xCF CTH3;

sfr at 0xD8 S1CON;
sfr at 0xD9 S1STA;
sfr at 0xDA S1DAT;
sfr at 0xDB S1ADR;

sfr at 0xE8 IEN1;

sfr at 0xEA TM2CON;
sfr at 0xEB CTCON;
sfr at 0xEC TML2;
sfr at 0xED TMH2;
sfr at 0xEE STE;
sfr at 0xEF RTE;

sfr at 0xF8 IP1;

sfr at 0xFC PWM0;
sfr at 0xFD PWM1;
sfr at 0xFE PWMP;
sfr at 0xFF T3;


/*BIT registers*/

/*IEN0 bits*/
sbit at 0xAD ES1;
sbit at 0xAE EAD;

/*IP0 bits*/
sbit at 0xBD PS1;
sbit at 0xBE PAD;

/*TM2IR bits*/
sbit at 0xC8 CTI0;
sbit at 0xC9 CTI1;
sbit at 0xCA CTI2;
sbit at 0xCB CTI3;
sbit at 0xCC CMI0;
sbit at 0xCD CMI1;
sbit at 0xCE CMI2;
sbit at 0xCF T2OV;

/*S1CON bits*/
sbit at 0xD8 CR0;
sbit at 0xD9 CR1;
sbit at 0xDA AA;
sbit at 0xDB SI;
sbit at 0xDC ST0;
sbit at 0xDD STA;
sbit at 0xDE ENSI;
sbit at 0xDF CR2;

/*IEN1 Bits*/
sbit at 0xE8 ECT0;
sbit at 0xE9 ECT1;
sbit at 0xEA ECT2;
sbit at 0xEB ECT3;
sbit at 0xEC ECM0;
sbit at 0xED ECM1;
sbit at 0xEE ECM2;
sbit at 0xEF ET2;

/*IP1 bits*/
sbit at 0xF8 PCT0;
sbit at 0xF9 PCT1;
sbit at 0xFA PCT2;
sbit at 0xFB PCT3;
sbit at 0xFC PCM0;
sbit at 0xFD PCM1;
sbit at 0xFE PCM2;
sbit at 0xFF PT2;

