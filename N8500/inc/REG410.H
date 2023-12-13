/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 * REG410.H
 * Last Modified By: R. Rowan
 * Last Modified:	1/11/1996
 * Modified for Version 6.0
 * Notes:
 * Register Declarations for 8XCL410 Processor 
 */

/*  BYTE Register  */
sfr  at 0x80 P0   ;
sfr  at 0x90 P1   ;
sfr  at 0xA0 P2   ;
sfr  at 0xB0 P3   ;
sfr  at 0xD0 PSW  ;
sfr  at 0xE0 ACC  ;
sfr  at 0xF0 B    ;
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
sfr  at 0xA8 IEN0 ;
sfr  at 0xE8 IEN1 ;
sfr  at 0xB8 IP0  ;
sfr  at 0xF8 IP1  ;
sfr  at 0xC0 IRQ1 ;
sfr  at 0xE9 IX1  ;
sfr  at 0xDB S1ADR;
sfr  at 0xD8 S1CON;
sfr  at 0xDA S1DAT;
sfr  at 0xD9 S1STA;


/*  BIT Register  */
/*  PSW   */
sbit at 0xD7 CY   ;
sbit at 0xD6 AC   ;
sbit at 0xD5 F0   ;
sbit at 0xD4 RS1  ;
sbit at 0xD3 RS0  ;
sbit at 0xD2 OV   ;
sbit at 0xD0 P    ;

/*  TCON  */
sbit at 0x8F TF1  ;
sbit at 0x8E TR1  ;
sbit at 0x8D TF0  ;
sbit at 0x8C TR0  ;
sbit at 0x8B IE1  ;
sbit at 0x8A IT1  ;
sbit at 0x89 IE0  ;
sbit at 0x88 IT0  ;

/*  IEN0   */
sbit at 0xAF EA   ;
sbit at 0xAD ES1  ;
sbit at 0xAB ET1  ;
sbit at 0xAA EX1  ;
sbit at 0xA9 ET0  ;
sbit at 0xA8 EX0  ;

/*  IEN1   */
sbit at 0xEF EX9  ;
sbit at 0xEE EX8  ;
sbit at 0xED EX7  ;
sbit at 0xEC EX6  ;
sbit at 0xEB EX5  ;
sbit at 0xEA EX4  ;
sbit at 0xE9 EX3  ;
sbit at 0xE8 EX2  ;

/*  IRQ1   */
sbit at 0xC7 IQ9  ;
sbit at 0xC6 IQ8  ;
sbit at 0xC5 IQ7  ;
sbit at 0xC4 IQ6  ;
sbit at 0xC3 IQ5  ;
sbit at 0xC2 IQ4  ;
sbit at 0xC1 IQ3  ;
sbit at 0xC0 IQ2  ;

/*  IP0   */ 
sbit at 0xBD PS1  ;
sbit at 0xBB PT1  ;
sbit at 0xBA PX1  ;
sbit at 0xB9 PT0  ;
sbit at 0xB8 PX0  ;

/*  IP1   */ 
sbit at 0xFF PX9  ;
sbit at 0xFE PX8  ;
sbit at 0xFD PX7  ;
sbit at 0xFC PX6  ;
sbit at 0xFB PX5  ;
sbit at 0xFA PX4  ;
sbit at 0xF9 PX3  ;
sbit at 0xF8 PX2  ;

/*  P1  */
sbit at 0x97 INT9 ;
sbit at 0x97 SDA  ;
sbit at 0x96 INT8 ;
sbit at 0x96 SCL  ;
sbit at 0x95 INT7 ;
sbit at 0x94 INT6 ;
sbit at 0x93 INT5 ;
sbit at 0x92 INT4 ;
sbit at 0x91 INT3 ;
sbit at 0x90 INT2 ;

/*  P3  */
sbit at 0xB7 RD   ;
sbit at 0xB6 WR   ;
sbit at 0xB5 T1   ;
sbit at 0xB4 T0   ;
sbit at 0xB3 INT1 ;
sbit at 0xB2 INT0 ;

/*  S1CON  */
sbit at 0xDE ENS1 ;
sbit at 0xDD STA  ;
sbit at 0xDC STO  ;
sbit at 0xDB SI   ;
sbit at 0xDA AA   ;
sbit at 0xD9 CR1  ;
sbit at 0xD8 CR0  ;

