/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 *        File Name:  REG51GB.H
 * Last Modified By:  R. Rowan - 1/11/1996
 *                    Modified for Version 6.0
 *            Notes:  Intel 80C51GB Processor Declarations
 */

/*  BYTE Registers  */
sfr at 0x80 P0   ;
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
sfr at 0x90 P1   ;
sfr at 0x98 SCON ;
sfr at 0x99 SBUF ;
sfr at 0xA0 P2   ;
sfr at 0xA8 IE   ;
sfr at 0xB0 P3   ;
sfr at 0xB8 IP   ;
sfr at 0xD0 PSW  ;
sfr at 0xE0 ACC  ;
sfr at 0xF0 B    ;

/*  80C51GB Specific Extensions  */
sfr at 0xA9 SADDR  ;
sfr at 0xB9 SADEN  ;
sfr at 0xC8 T2CON  ;
sfr at 0xC9 T2MOD  ;
sfr at 0xCA RCAP2L ;
sfr at 0xCB RCAP2H ;
sfr at 0xCC TL2    ;
sfr at 0xCD TH2    ;
sfr at 0xC0 P4     ;
sfr at 0x84 ADRES0 ;
sfr at 0x94 ADRES1 ;
sfr at 0xA4 ADRES2 ;
sfr at 0xB4 ADRES3 ;
sfr at 0xC4 ADRES4 ;
sfr at 0xD4 ADRES5 ;
sfr at 0xE4 ADRES6 ;
sfr at 0xF4 ADRES7 ;
sfr at 0x8E AUXR   ;
sfr at 0xA5 OFDCON ;
sfr at 0xB5 IPA1   ;
sfr at 0xA6 WDTCON ;
sfr at 0xB6 IPA    ;
sfr at 0xC6 EXICON ;
sfr at 0x97 ADCON  ;
sfr at 0xA7 IEA    ;
sfr at 0xB7 IP1    ;
sfr at 0xC7 ACMP   ;
sfr at 0xD7 SEPCON ;
sfr at 0xE7 SEPDAT ;
sfr at 0xF7 SEPSTA ;
sfr at 0xF8 P5     ;

/******** PCA0 SFRS *******/
sfr at 0xD8 CCON   ;
sfr at 0xD9 CMOD   ;
sfr at 0xDA CCAPM0 ;
sfr at 0xDB CCAPM1 ;
sfr at 0xDC CCAPM2 ;
sfr at 0xDD CCAPM3 ;
sfr at 0xDE CCAPM4 ;
sfr at 0xE9 CL     ;
sfr at 0xEA CCAP0L ;
sfr at 0xEB CCAP1L ;
sfr at 0xEC CCAP2L ;
sfr at 0xED CCAP3L ;
sfr at 0xEE CCAP4L ;
sfr at 0xF9 CH     ;
sfr at 0xFA CCAP0H ;
sfr at 0xFB CCAP1H ;
sfr at 0xFC CCAP2H ;
sfr at 0xFD CCAP3H ;
sfr at 0xFE CCAP4H ;

/******** PCA1 SFRS *******/
sfr at 0xE8 C1CON   ;
sfr at 0x9F C1MOD   ;
sfr at 0x9A C1CAPM0 ;
sfr at 0x9B C1CAPM1 ;
sfr at 0x9C C1CAPM2 ;
sfr at 0x9D C1CAPM3 ;
sfr at 0x9E C1CAPM4 ;
sfr at 0xAF CL1     ;
sfr at 0xAA C1CAP0L ;
sfr at 0xAB C1CAP1L ;
sfr at 0xAC C1CAP2L ;
sfr at 0xAD C1CAP3L ;
sfr at 0xAE C1CAP4L ;
sfr at 0xBF CH1     ;
sfr at 0xBA C1CAP0H ;
sfr at 0xBB C1CAP1H ;
sfr at 0xBC C1CAP2H ;
sfr at 0xBD C1CAP3H ;
sfr at 0xBE C1CAP4H ;

/*  SFR BIT Registers  */
/*  PSW  */
sbit at 0xD7  CY    ;
sbit at 0xD6  AC    ;
sbit at 0xD5  F0    ;
sbit at 0xD4  RS1   ;
sbit at 0xD3  RS0   ;
sbit at 0xD2  OV    ;
sbit at 0xD0  P     ;

/*  TCON  */
sbit at 0x8F  TF1    ;
sbit at 0x8E  TR1    ;
sbit at 0x8D  TF0    ;
sbit at 0x8C  TR0    ;
sbit at 0x8B  IE1    ;
sbit at 0x8A  IT1    ;
sbit at 0x89  IE0    ;
sbit at 0x88  IT0    ;

/*  IE  */
sbit at 0xAF  EA     ;
sbit at 0xAE  EC     ;
sbit at 0xAD  ET2    ;
sbit at 0xAC  ES     ;
sbit at 0xAB  ET1    ;
sbit at 0xAA  EX1    ;
sbit at 0xA9  ET0    ;
sbit at 0xA8  EX0    ;

/*  IP  */
sbit at 0xBE  PPC    ;
sbit at 0xBD  PT2    ;
sbit at 0xBC  PS     ;
sbit at 0xBB  PT1    ;
sbit at 0xBA  PX1    ;
sbit at 0xB9  PT0    ;
sbit at 0xB8  PX0    ;

/********  P1  Bits *******/
sbit at 0x97  CEX4   ;
sbit at 0x96  CEX3   ;
sbit at 0x95  CEX2   ;
sbit at 0x94  CEX1   ;
sbit at 0x93  CEX0   ;
sbit at 0x92  ECI    ;
sbit at 0x91  T2EX   ;
sbit at 0x90  T2     ;

/********  P3  Bits ********/
sbit at 0xB7  RD     ;
sbit at 0xB6  WR     ;
sbit at 0xB5  T1     ;
sbit at 0xB4  T0     ;
sbit at 0xB3  INT1   ;
sbit at 0xB2  INT0   ;
sbit at 0xB1  TXD    ;
sbit at 0xB0  RXD    ;

/********  P4  BITS *******/
sbit at 0xC7  C1EX4  ;
sbit at 0xC6  C1EX3  ;
sbit at 0xC5  C1EX2  ;
sbit at 0xC4  C1EX1  ;
sbit at 0xC3  C1EX0  ;
sbit at 0xC2  C1     ;
sbit at 0xC1  SEPIO  ;
sbit at 0xC0  SEPCLK ;

/********  P5  BITS *******/
sbit at 0xFE  INT6   ;
sbit at 0xFD  INT5   ;
sbit at 0xFC  INT4   ;
sbit at 0xFB  INT3   ;
sbit at 0xFA  INT2   ;

/********  SCON  Bits  ********/
sbit at 0x9F  SM0    ;
sbit at 0x9E  SM1    ;
sbit at 0x9D  SM2    ;
sbit at 0x9C  REN    ;
sbit at 0x9B  TB8    ;
sbit at 0x9A  RB8    ;
sbit at 0x99  TI     ;
sbit at 0x98  RI     ;

/******** T2CON BITS *******/
sbit at 0xCF  TF2    ; 
sbit at 0xCE  EXF2   ;
sbit at 0xCD  RCLK   ;
sbit at 0xCC  TCLK   ;
sbit at 0xCB  EXEN2  ;
sbit at 0xCA  TR2    ;
sbit at 0xC9  CT2    ;
sbit at 0xC8  CPRL2  ;

/******** CCON BITS *******/
sbit at 0xDF  CF     ;
sbit at 0xDE  CR     ;
sbit at 0xDC  CCF4   ;
sbit at 0xDB  CCF3   ;
sbit at 0xDA  CCF2   ;
sbit at 0xD9  CCF1   ;
sbit at 0xD8  CCF0   ;

/******** CCON1 BITS *******/
sbit at 0xEF  CF1    ;
sbit at 0xEE  CR1    ;
sbit at 0xED  CRE    ;
sbit at 0xEC  C1CF4  ;
sbit at 0xEB  C1CF3  ;
sbit at 0xEA  C1CF2  ;
sbit at 0xE9  C1CF1  ;
sbit at 0xE8  C1CF0  ;
