/* Copyright (c) Franklin Software, Inc. 1989 - 1997
* REG550.H
* Last Modified By:  FB - 26.03.97 Updated
*   Initial design:  Paul Tarnow - 03/25/97
* Modified for Version 6.0
* Notes:
* Declarations for 8xC550
*/

#include <reg51.h>

/*************************************
 * Donnelly, Corp. 
 * 414 E. 40th, Holland, MI 49423
 * AAE Group
 *************************************
 */

/* Byte registers */
/* A to D */
sfr at 0xC5 ADCON;      
sfr at 0xC6 ADAT;

/* Watchdog */
sfr at 0xC0 WDCON;
sfr at 0xC1 WDL;
sfr at 0xC2 WFEED1;
sfr at 0xC3 WFEED2;

/* BIT registers */
/* ADCON bits*/
sbit at 0xC9 ADCI;
sbit at 0xC8 ADCS;
sbit at 0xC7 AADR2;
sbit at 0xC6 AADR1;
sbit at 0xC5 AADR0;

/* ADAT bits
 * not addressable
 */

/* WDCON bits*/
sbit at 0xC7 PRE2;
sbit at 0xC6 PRE1;
sbit at 0xC5 PRE0;
sbit at 0xC2 WDRUN;
sbit at 0xC1 WDTOF;
sbit at 0xC0 WDMOD;

/* WDL bits
 * not addressable
 */

/* WFEED1 bits
 * not addressable
 */

/* WFEED2 bits
 * not addressable
 */

