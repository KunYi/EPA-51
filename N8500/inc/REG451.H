/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 *        File Name:  REG451.H
 * Last Modified By:  R. Rowan
 *    Last Modified:  1/11/1996
 *                    Modified for Version 6.0
 *            Notes:  Declarations for 83C451
 */

/*  BYTE Register  */
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


/*  Special Function bit addresses  */
/*  TCON  */
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

// Extensions for the 83C451
sfr  at 0xC0 P4  ;
sfr  at 0xC8 P5  ;
sfr  at 0xD8 P6  ;
sfr  at 0xE8 CSR ;

// BIT definitions 
// CSR bits
sbit at 0xE8 IBF	   ;
sbit at 0xE9 OBF     ;
sbit at 0xEA IDSM    ;
sbit at 0xEB OBFC    ;
sbit at 0xEC MA0	   ;
sbit at 0xED MA1     ;
sbit at 0xEE MB0     ;
sbit at 0xEF MB1	   ;

