/* Copyright Franklin Software, Inc. 1989 - 1996
 * REG654.H
 * Last Modified By: F. Blair - 13.08.96
 *                   Created for the 87C654 Processor for C51 V6
 *
 * Notes:
 * Declarations for 83C654
 */

/*  BYTE Register  */
sfr at 0x80 P0   ;
sfr at 0x90 P1   ;
sfr at 0xA0 P2   ;
sfr at 0xB0 P3   ;

sfr at 0xD0 PSW  ;
sfr at 0xE0 ACC  ;
sfr at 0xF0 B    ;
sfr at 0x81 SP   ;
sfr at 0x82 DPL  ;
sfr at 0x83 DPH  ;
sfr at 0x87 PCON ;
sfr at 0x88 TCON ;
sfr at 0x89 TMOD ;
sfr at 0x8A TL0  ;
sfr at 0x8B TL1  ;
sfr at 0x8C TH0  ;
sfr at 0x8D TH1  ;
sfr at 0xA8 IE   ;
sfr at 0xB8 IP   ;
sfr at 0x98 SCON ;
sfr at 0x99 SBUF ;


/* BIT Registers */
/* PSW   */
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

/*  IE   */
sbit at 0xA8 EX0  ;	/* External 0 Enable */
sbit at 0xA9 ET0  ;	/* Timer 0 Enable */
sbit at 0xAA EX1  ;	/* External 1 Enable */
sbit at 0xAB ET1  ;	/* Timer 1 Enable */
sbit at 0xAC ES   ;	/* Serial Port Enable */	
sbit at 0xAD ES1  ;	/* IIC Enable */
sbit at 0xAF EA   ;	/* Enable Interrupt Group */

/*  IP   */ 
sbit at 0xB8 PX0  ;
sbit at 0xB9 PT0  ;
sbit at 0xBA PX1  ;
sbit at 0xBB PT1  ;
sbit at 0xBC PS   ;
sbit at 0xBD PS1  ;
sbit at 0xBE PAD  ;

/*  P3  */
sbit at 0xB7 RD   ;
sbit at 0xB6 WR   ;
sbit at 0xB5 T1   ;
sbit at 0xB4 T0   ;
sbit at 0xB3 INT1 ;
sbit at 0xB2 INT0 ;
sbit at 0xB1 TXD  ;
sbit at 0xB0 RXD  ;

/*  SCON  */
sbit at 0x9F SM0  ;
sbit at 0x9E SM1  ;
sbit at 0x9D SM2  ;
sbit at 0x9C REN  ;
sbit at 0x9B TB8  ;
sbit at 0x9A RB8  ;
sbit at 0x99 TI   ;
sbit at 0x98 RI   ;

/* The 654 specific BYTE registers*/
sfr at 0xD8 S1CON;
/* S1CON bits */
sbit at 0xD8 CR0;	
sbit at 0xD9 CR1;
sbit at 0xDA AA;
sbit at 0xDB SI;
sbit at 0xDC ST0;	
sbit at 0xDD STA;
sbit at 0xDE ENSI;

sfr at 0xD9 S1STA;
sfr at 0xDA S1DAT;
sfr at 0xDB S1ADR;

