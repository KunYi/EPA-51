/* Copyright (c) Franklin Software, Inc. 1989 - 1997
 *        File Name:  REG320.H
 * Last Modified By:  R. Rowan
 *    Last Modified:  1/11/1996
 *                    Modified for Version 6.0
 *            Notes:  Register Declarations for DALLAS DS80C320
 */

/*  BYTE Registers  */
sfr at 0x80 P0     ;
sfr at 0x90 P1     ;
sfr at 0xA0 P2     ;
sfr at 0xB0 P3     ;
sfr at 0xD0 PSW    ;
sfr at 0xE0 ACC    ;
sfr at 0xF0 B      ;
sfr at 0x81 SP     ;
sfr at 0x82 DPL    ;
sfr at 0x83 DPH    ;
sfr at 0x87 PCON   ;
sfr at 0x88 TCON   ;
sfr at 0x89 TMOD   ;
sfr at 0x8A TL0    ;
sfr at 0x8B TL1    ;
sfr at 0x8C TH0    ;
sfr at 0x8D TH1    ;
sfr at 0xA8 IE     ;
sfr at 0xB8 IP     ;
sfr at 0x98 SCON   ;
sfr at 0x99 SBUF   ;

/*  DS80C320 Extensions  */
sfr at 0x84 DPL1   ;
sfr at 0x85 DPH1   ;
sfr at 0x86 DPS    ;
sfr at 0x8E CKCON  ;
sfr at 0x91 EXIF   ;
sfr at 0xA9 SADDR0 ;
sfr at 0xAA SADDR1 ;
sfr at 0xB9 SADEN0 ;
sfr at 0xBA SADEN1 ;
sfr at 0xC0 SCON1  ;
sfr at 0xC1 SBUF1  ;
sfr at 0xC7 TA     ;
sfr at 0xC8 T2CON  ;
sfr at 0xC9 T2MOD  ;
sfr at 0xCA RCAP2L ;
sfr at 0xCB RCAP2H ;
sfr at 0xCC TL2    ;
sfr at 0xCD TH2    ;
sfr at 0xD8 WDCON  ;
sfr at 0xE8 EIE    ;
sfr at 0xF8 EIP    ;


/*  BIT Registers  */
/*  PSW  */
sbit at 0xD7  CY    ;
sbit at 0xD6  AC    ;
sbit at 0xD5  F0    ;
sbit at 0xD4  RS1   ;
sbit at 0xD3  RS0   ;
sbit at 0xD2  OV    ;
sbit at 0xD1  FL    ;
sbit at 0xD0  P     ;

/*  TCON  */
sbit at 0x8F  TF1   ;
sbit at 0x8E  TR1   ;
sbit at 0x8D  TF0   ;
sbit at 0x8C  TR0   ;
sbit at 0x8B  IE1   ;
sbit at 0x8A  IT1   ;
sbit at 0x89  IE0   ;
sbit at 0x88  IT0   ;

/*  IE  */
sbit at 0xAF  EA    ;
sbit at 0xAE  ES1   ;
sbit at 0xAD  ET2   ;
sbit at 0xAC  ES0   ;
sbit at 0xAB  ET1   ;
sbit at 0xAA  EX1   ;
sbit at 0xA9  ET0   ;
sbit at 0xA8  EX0   ;

/*  IP  */
sbit at 0xBE  PS1   ;
sbit at 0xBD  PT2   ;
sbit at 0xBC  PS0   ;
sbit at 0xBB  PT1   ;
sbit at 0xBA  PX1   ;
sbit at 0xB9  PT0   ;
sbit at 0xB8  PX0   ;

/*  P1  */
sbit at 0x97  INT5  ;
sbit at 0x96  INT4  ;
sbit at 0x95  INT3  ;
sbit at 0x94  INT2  ;
sbit at 0x93  TXD1  ;
sbit at 0x92  RXD1  ;
sbit at 0x91  T2EX  ;
sbit at 0x90  T2    ;

/*  P3  */
sbit at 0xB7  RD    ;
sbit at 0xB6  WR    ;
sbit at 0xB5  T1    ;
sbit at 0xB4  T0    ;
sbit at 0xB3  INT1  ;
sbit at 0xB2  INT0  ;
sbit at 0xB1  TXD0  ;
sbit at 0xB0  RXD0  ;

/*  SCON0  */
sbit at 0x9F  SM0   ;
sbit at 0x9E  SM1   ;
sbit at 0x9D  SM2   ;
sbit at 0x9C  REN   ;
sbit at 0x9B  TB8   ;
sbit at 0x9A  RB8   ;
sbit at 0x99  TI    ;
sbit at 0x98  RI    ;

/*  SCON1  */
sbit at 0xC7  SM01  ;
sbit at 0xC6  SM11  ;
sbit at 0xC5  SM21  ;
sbit at 0xC4  REN1  ;
sbit at 0xC3  TB81  ;
sbit at 0xC2  RB81  ;
sbit at 0xC1  TI1   ;
sbit at 0xC0  RI1   ;

/*  T2CON  */
sbit at 0xCF  TF2   ;
sbit at 0xCE  EXF2  ;
sbit at 0xCD  RCLK  ;
sbit at 0xCC  TCLK  ;
sbit at 0xCB  EXEN2 ;
sbit at 0xCA  TR2   ;
sbit at 0xC9  C_T2  ;
sbit at 0xC8  CP_RL2;

/*  WDCON  */
sbit at 0xDF  SMOD  ;
sbit at 0xDE  POR   ;
sbit at 0xDD  EPFI  ;
sbit at 0xDC  PFI   ;
sbit at 0xDB  WDIF  ;
sbit at 0xDA  WDRF  ;
sbit at 0xD9  EWT   ;
sbit at 0xD8  RWT   ;

/*  EIE  */
sbit at 0xEC  EWDI  ;
sbit at 0xEB  EX5   ;
sbit at 0xEA  EX4   ;
sbit at 0xE9  EX3   ;
sbit at 0xE8  EX2   ;

/*  EIP  */
sbit at 0xEC  PWDI  ;
sbit at 0xEB  PX5   ;
sbit at 0xEA  PX4   ;
sbit at 0xE9  PX3   ;
sbit at 0xE8  PX2   ;
