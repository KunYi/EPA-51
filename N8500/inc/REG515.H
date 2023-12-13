/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 *        File Name:  REG515.H
 * Last Modified By:  R. Rowan
 *    Last Modified:  1/11/1996
 *                    Modified for Version 6.0
 *            Notes:  Declarations for 83C515
 */

// BYTE Register Definitions
sfr  at 0x80 P0   ;
sfr  at 0x81 SP   ;
sfr  at 0x82 DPL  ;
sfr  at 0x83 DPH  ;
sfr  at 0x87 PCON ;
sfr  at 0x88 TCON ;
sfr  at 0x89 TMOD ;
sfr  at 0x8A TL0  ;
sfr  at 0x8B TL1  ;
sfr  at 0x8C TH0  ;
sfr  at 0x8D TH1  ;
sfr  at 0x90 P1   ;
sfr  at 0x98 SCON ;
sfr  at 0x99 SBUF ;
sfr  at 0xA0 P2   ;
sfr  at 0xA8 IE   ;
sfr  at 0xB0 P3   ;
sfr  at 0xB8 IP   ;
sfr  at 0xD0 PSW  ;
sfr  at 0xE0 ACC  ;
sfr  at 0xF0 B    ;


//  Special Function bit addresses
//  TCON
sbit at 0x8F TF1  ;
sbit at 0x8E TR1  ;
sbit at 0x8D TF0  ;
sbit at 0x8C TR0  ;
sbit at 0x8B IE1  ;
sbit at 0x8A IT1  ;
sbit at 0x89 IE0  ;
sbit at 0x88 IT0  ;

/*  SCON  */
sbit at 0x9F SM0  ;
sbit at 0x9E SM1  ;
sbit at 0x9D SM2  ;
sbit at 0x9C REN  ;
sbit at 0x9B TB8  ;
sbit at 0x9A RB8  ;
sbit at 0x99 TI   ;
sbit at 0x98 RI   ;

/*  IE   */
sbit at 0xAF EA   ;
sbit at 0xAC ES   ;
sbit at 0xAB ET1  ;
sbit at 0xAA EX1  ;
sbit at 0xA9 ET0  ;
sbit at 0xA8 EX0  ;

/*  IP   */ 
sbit at 0xBC PS   ;
sbit at 0xBB PT1  ;
sbit at 0xBA PX1  ;
sbit at 0xB9 PT0  ;
sbit at 0xB8 PX0  ;

/*  P3  */
sbit at 0xB7 RD   ;
sbit at 0xB6 WR   ;
sbit at 0xB5 T1   ;
sbit at 0xB4 T0   ;
sbit at 0xB3 INT1 ;
sbit at 0xB2 INT0 ;
sbit at 0xB1 TXD  ;
sbit at 0xB0 RXD  ;

/*  PSW   */
sbit at 0xD7 CY   ;
sbit at 0xD6 AC   ;
sbit at 0xD5 F0   ;
sbit at 0xD4 RS1  ;
sbit at 0xD3 RS0  ;
sbit at 0xD2 OV   ;
sbit at 0xD0 P    ;


// 8xC515 specific defintions
sfr at 0xA8 IEN0;
sfr at 0xA9 IP0;

sfr at 0xB8 IEN1;
sfr at 0xB9 IP1;

sfr at 0xC0 IRCON;
sfr at 0xC1 CCEN;
sfr at 0xC2 CCL1;
sfr at 0xC3 CCH1;
sfr at 0xC4 CCL2;
sfr at 0xC5 CCH2;
sfr at 0xC6 CCL3;
sfr at 0xC7 CCH3;
sfr at 0xC8 T2CON;
sfr at 0xCA CRCL;
sfr at 0xCB CRCH;
sfr at 0xCC TL2;
sfr at 0xCD TH2;

sfr at 0xD8 ADCON;

sfr at 0xE8 P4;

sfr at 0xF8 P5;

#define EAL EA

// SFR BIT Definitions
sbit at 0xAD ET2;

/*IEN1 bits*/
sbit at 0xB8 EADC;
sbit at 0xB9 EX2;
sbit at 0xBA EX3;
sbit at 0xBB EX4;
sbit at 0xBC EX5;
sbit at 0xBD EX6;
sbit at 0xBE SWDT;
sbit at 0xBF EXEN2;

/*T2CON bits*/
sbit at 0xC8 T2I0;
sbit at 0xC9 T2I1;
sbit at 0xCA T2CM;
sbit at 0xCB T2R0;
sbit at 0xCC T2R1;
sbit at 0xCD I2FR;
sbit at 0xCE I3FR;
sbit at 0xCF T2PS;

/*IRCON bits*/
sbit at 0xC0 IADC;
sbit at 0xC1 IEX2;
sbit at 0xC2 IEX3;
sbit at 0xC3 IEX4;
sbit at 0xC4 IEX5;
sbit at 0xC5 IEX6;
sbit at 0xC6 TF2;
sbit at 0xC7 EXF2;

/*ADCON bits*/
sbit at 0xD8 MX0;
sbit at 0xD9 MX1;
sbit at 0xDA MX2;
sbit at 0xDB ADM;
sbit at 0xDC BSY;
sbit at 0xDD CLK;
sbit at 0xDF BD;


