//
// Copyright (c) Franklin Software, Inc. 1995 - 1997
// 	REGXAG3.H
// 	Modified By:	F. Blair - 06.03.97 Fixed address errors
//                      F. Blair - 19/11/1996
// 	 Created By:	R. Rowan - 10/10/1995
// 	      Notes:	Based upon the Philips XA-G3 SFR 
//				Definition Rev. 1.2, 6/26/95
//
// Register Declarations for Philips Semiconductors XA-G3 Processor 
// =============================================================
//

//----------------------------------------------
at	0x400	sfr	PSWL;
at	0x207	sbit	CY;
at	0x206	sbit	AC;
at	0x202	sbit	V;
at	0x201	sbit	N;
at	0x200	sbit	Z;

//----------------------------------------------
at	0x401	sfr	PSWH;
at	0x20f	sbit	SM;
at	0x20e	sbit	TM;
at	0x20d	sbit	RS1;
at	0x20c	sbit	RS0;
at	0x20b	sbit	IM3;
at	0x20a	sbit	IM2;
at	0x209	sbit	IM1;
at	0x208	sbit	IM0;

//----------------------------------------------
at	0x402	sfr	PSW51;
at	0x215	sbit	F0;
at	0x211	sbit	F1;
at	0x210	sbit	P;

//----------------------------------------------
at	0x403	sfr	SSEL;
at	0x218	sbit	R0SEG;
at	0x219	sbit	R1SEG;
at	0x21a	sbit	R2SEG;
at	0x21b	sbit	R3SEG;
at	0x21c	sbit	R4SEG;
at	0x21d	sbit	R5SEG;
at	0x21e	sbit	R6SEG;
at	0x21f	sbit	ESWEN;

//----------------------------------------------
at	0x404	sfr	PCON;
at	0x221	sbit	PD;
at	0x220	sbit	IDL;

//----------------------------------------------
at	0x410	sfr	TCON;
at	0x280	sbit	IT0;
at	0x281	sbit	IE0;
at	0x282	sbit	IT1;
at	0x283	sbit	IE1;
at	0x284	sbit	TR0;
at	0x285	sbit	TF0;
at	0x286	sbit	TR1;
at	0x287	sbit	TF1;

//----------------------------------------------
at	0x411	sfr	TSTAT;
at	0x288	sbit	T0OE;
at	0x289	sbit	T0RD;		//	To be verified
at	0x28a	sbit	T1OE;
at	0x28b	sbit	T1RD;		//	To be verified

//----------------------------------------------
at	0x418	sfr	T2CON;
at	0x2c0	sbit	CPRL2;
at	0x2c1	sbit	CT2;
at	0x2c2	sbit	TR2;
at	0x2c3	sbit	EXEN2;
at	0x2c4	sbit	TCLK0;
at	0x2c5	sbit	RCLK0;
at	0x2c6	sbit	EXF2;
at	0x2c7	sbit	TF2;

//----------------------------------------------
at	0x419	sfr	T2MOD;
at	0x2c8	sbit	DCEN;
at	0x2c9	sbit	T2OE;
at	0x2ca	sbit	T2RD;		//	To be verified
at	0x2cc	sbit	TCLK1;
at	0x2cd	sbit	RCLK1;

//----------------------------------------------
at	0x41f	sfr	WDCON;
at	0x2f8	sbit	WDMOD;		//	To be verified
at	0x2f9	sbit	WDTOF;
at	0x2fa	sbit	WDRUN;
at	0x2fd	sbit	PRE0;
at	0x2fe	sbit	PRE1;
at	0x2ff	sbit	PRE2;

//----------------------------------------------
at	0x420	sfr	S0CON;
at	0x300	sbit	RI0;
at	0x301	sbit	TI0;
at	0x302	sbit	RB80;
at	0x303	sbit	TB80;
at	0x304	sbit	REN0;
at	0x305	sbit	SM20;
at	0x306	sbit	SM10;
at	0x307	sbit	SM00;

//----------------------------------------------
at	0x421	sfr	S0STAT;
at	0x308	sbit	STINT0;
at	0x309	sbit	OE0;
at	0x30a	sbit	BR0;
at	0x30b	sbit	FE0;

//----------------------------------------------
at	0x424	sfr	S1CON;
at	0x320	sbit	RI1;
at	0x321	sbit	TI1;
at	0x322	sbit	RB81;
at	0x323	sbit	TB81;
at	0x324	sbit	REN1;
at	0x325	sbit	SM21;
at	0x326	sbit	SM11;
at	0x327	sbit	SM01;

//----------------------------------------------
at	0x425	sfr	S1STAT;
at	0x328	sbit	STINT1;
at	0x329	sbit	OE1;
at	0x32a	sbit	BR1;
at	0x32b	sbit	FE1;

//----------------------------------------------
at	0x426	sfr	IEL;
at	0x337	sbit	EA;
at	0x334	sbit	ET2;
at	0x333	sbit	ET1;
at	0x332	sbit	EX1;
at	0x331	sbit	ET0;
at	0x330	sbit	EX0;

//----------------------------------------------
at	0x427	sfr	IEH;
at	0x338	sbit	ERI0;
at	0x339	sbit	ETI0;
at	0x33a	sbit	ERI1;
at	0x33b	sbit	ETI1;

//----------------------------------------------
at	0x42a	sfr	SWR;
at	0x350	sbit	SWR1;
at	0x351	sbit	SWR2;
at	0x352	sbit	SWR3;
at	0x353	sbit	SWR4;
at	0x354	sbit	SWR5;
at	0x355	sbit	SWR6;
at	0x356	sbit	SWR7;

//----------------------------------------------
at	0x430	sfr	P0;
at	0x380	sbit	AD0;
at	0x381	sbit	AD1;
at	0x382	sbit	AD2;
at	0x383	sbit	AD3;
at	0x384	sbit	AD4;
at	0x385	sbit	AD5;
at	0x386	sbit	AD6;
at	0x387	sbit	AD7;

//----------------------------------------------
at	0x431	sfr	P1;
at	0x388	sbit	WRH;
at	0x389	sbit	A1;
at	0x38a	sbit	A2;
at	0x38b	sbit	A3;
at	0x38c	sbit	RXD1;
at	0x38d	sbit	TXD1;
at	0x38e	sbit	T2;
at	0x38f	sbit	T2EX;

//----------------------------------------------
at	0x432	sfr	P2;

//----------------------------------------------
at	0x433	sfr	P3;
at	0x398	sbit	RXD0;
at	0x399	sbit	TXD0;
at	0x39a	sbit	INT0;
at	0x39b	sbit	INT1;
at	0x39c	sbit	T0;
at	0x39d	sbit	T1;
at	0x39e	sbit	WR;
at	0x39f	sbit	RD;

//-----------------------------------------------------
//	SFR addresses above 0x43F are NOT bit addressable
//-----------------------------------------------------

//----------------------------------------------
at	0x440	sfr	SCR;
at	0x441	sfr	_DS;
at	0x442	sfr	_ES;
at	0x443	sfr	_CS;

//----------------------------------------------
at	0x450	sfr	TL0;
at	0x451	sfr	TH0;
at	0x452	sfr	TL1;
at	0x453	sfr	TH1;
at	0x454	sfr	RTL0;
at	0x455	sfr	RTH0;
at	0x456	sfr	RTL1;
at	0x457	sfr	RTH1;
at	0x458	sfr	TL2;
at	0x459	sfr	TH2;
at	0x45a	sfr	T2CAPL;
at	0x45b	sfr	T2CAPH;
at	0x45c	sfr	TMOD;
at	0x45d	sfr	WFEED1;
at	0x45e	sfr	WFEED2;
at	0x45f	sfr	WDL;

//----------------------------------------------
at	0x460	sfr	S0BUF;
at	0x461	sfr	S0ADDR;
at	0x462	sfr	S0ADEN;
at	0x464	sfr	S1BUF;
at	0x465	sfr	S1ADDR;
at	0x466	sfr	S1ADEN;
at	0x468	sfr	BTRL;
at	0x469	sfr	BTRH;
at	0x46a	sfr	BCR;

//----------------------------------------------
at	0x470	sfr	P0CFGA;
at	0x471	sfr	P1CFGA;
at	0x472	sfr	P2CFGA;
at	0x473	sfr	P3CFGA;
at	0x47a	sfr	SWE;

//----------------------------------------------
at	0x4a0	sfr	IPA0;
at	0x4a1	sfr	IPA1;
at	0x4a2	sfr	IPA2;
at	0x4a4	sfr	IPA4;
at	0x4a5	sfr	IPA5;

//----------------------------------------------
at	0x4f0	sfr	P0CFGB;
at	0x4f1	sfr	P1CFGB;
at	0x4f2	sfr	P2CFGB;
at	0x4f3	sfr	P3CFGB;
//----------------------------------------------

//----------------------------------------------
// Duplicate labels for 8051 code compatibility
//----------------------------------------------
at	0x420	sfr	SCON;
at	0x460	sfr	SBUF;

at	0x300	sbit	RI;
at	0x301	sbit	TI;
at	0x302	sbit	RB8;
at	0x303	sbit	TB8;
at	0x304	sbit	REN;
at	0x305	sbit	SM2;
at	0x306	sbit	SM1;
at	0x307	sbit	SM0;
//----------------------------------------------

