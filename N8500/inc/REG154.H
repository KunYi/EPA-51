/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 * REG154.H
 * Last Modified By:  R. Rowan
 *    Last Modified:  1/11/1996
 *                    Modified for Version 6.0
 *            Notes:  Declarations for 83C154 processor 
 */

/* Byte registers*/

sfr at 0x80 P0      ;
sfr at 0x81 SP      ;
sfr at 0x82 DPL     ;
sfr at 0x83 DPH     ;

sfr at 0x87 PCON    ;
sfr at 0x88 TCON    ;
sfr at 0x89 TMOD    ;
sfr at 0x8A TL0     ;
sfr at 0x8B TL1     ;
sfr at 0x8C TH0     ;
sfr at 0x8D TH1     ;

sfr at 0x90 P1      ;

sfr at 0x98 SCON    ;
sfr at 0x99 SBUF    ;

sfr at 0xA0 P2      ;

sfr at 0xA8 IE      ;

sfr at 0xB0 P3      ;

sfr at 0xB8 IP      ;

sfr at 0xC8 T2CON   ;

sfr at 0xCA RCAP2L  ;
sfr at 0xCB RCAP2H  ;
sfr at 0xCC TL2     ;
sfr at 0xCD TH2     ;

sfr at 0xD0 PSW     ;

sfr at 0xE0 ACC     ;

sfr at 0xF0 B       ;

sfr at 0xF8 IOCON   ;

/*Bit registers */

/*TCON bits*/
sbit at 0x88 IT0    ;
sbit at 0x89 IE0    ;
sbit at 0x8A IT1    ;
sbit at 0x8B IE1    ;
sbit at 0x8C TR0    ;
sbit at 0x8D TF0    ;
sbit at 0x8E TR1    ;
sbit at 0x8F TF1    ;


/*SCON bits*/	
sbit at 0x98 RI     ;
sbit at 0x98 TI     ;
sbit at 0x98 RB8    ;
sbit at 0x98 TB8    ;
sbit at 0x98 REN    ;
sbit at 0x98 SM2    ;
sbit at 0x98 SM1    ;
sbit at 0x98 SM0    ;

/*IE bits*/
sbit at 0xA8 EX0   ;
sbit at 0xA9 ET0   ;
sbit at 0xAA EX1   ;
sbit at 0xAB ET1   ;
sbit at 0xAC ES    ;
sbit at 0xAD ET2   ;
sbit at 0xAF EA    ;


/*P3 bits*/
sbit at 0xB0 RXD    ;
sbit at 0xB1 TXD    ;
sbit at 0xB2 INT0   ;
sbit at 0xB3 INT1   ;
sbit at 0xB4 T0     ;
sbit at 0xB5 T1     ;
sbit at 0xB6 WR     ;
sbit at 0xB7 RD     ;

/*IP bits*/
sbit at 0xB8 PX0    ;
sbit at 0xB8 PT0    ;
sbit at 0xB8 PX1    ;
sbit at 0xB8 PT1    ;
sbit at 0xB8 PS     ;
sbit at 0xB8 PT2    ;

/*T2CON bits*/	
sbit at 0xC8 CP_RL2 ;
sbit at 0xC9 C_T2   ;
sbit at 0xCA TR2    ;
sbit at 0xCB EXEN2  ;
sbit at 0xCC TCLK   ;
sbit at 0xCD RCLK   ;
sbit at 0xCE EXF2   ;
sbit at 0xCF TF2    ;

/*PSW bits*/
sbit at 0xD0 P      ;
sbit at 0xD1 F1     ;
sbit at 0xD2 OV     ;
sbit at 0xD3 RS0    ;
sbit at 0xD4 RS1    ;
sbit at 0xD5 F0     ;
sbit at 0xD6 AC     ;
sbit at 0xD7 CY     ;

/*IOCON bits*/
sbit at 0xF8 ALF    ;
sbit at 0xF9 P1HZ   ;
sbit at 0xFA P2HZ   ;
sbit at 0xFB P3HZ   ;
sbit at 0xFC IZC    ;
sbit at 0xFD SERR   ;
sbit at 0xFE T32    ;
sbit at 0xFF WDT    ;

