#define _PHYSICAL_UART_

#define OSC 22118400L
#define UART0_BaudRate 9600L
#define UART1_BaudRate 19200L


#include "common.h"
#include "uart.h"
#include "P1Layer2.h"
#include "P2Layer2.h"

// #define DEBUG_RECEIVE_PORT1
// #define DEBUG_RECEIVE_PORT2

BYTE TLength0 = 0;
BYTE RLength0 = 0;

BYTE TLength1 = 0;
BYTE RLength1 = 0;

static EXTERN_DATA BYTE UART0_RFIFO[MaxLength];
static EXTERN_DATA BYTE UART0_TFIFO[MaxLength];
static EXTERN_DATA BYTE UART1_RFIFO[MaxLength];
static EXTERN_DATA BYTE UART1_TFIFO[MaxLength];

static P_INTERNAL_DATA BYTE R_Tail0;
static P_INTERNAL_DATA BYTE R_Head0;
static P_INTERNAL_DATA BYTE T_Tail0;
static P_INTERNAL_DATA BYTE T_Head0;

static P_INTERNAL_DATA BYTE R_Tail1;
static P_INTERNAL_DATA BYTE R_Head1;
static P_INTERNAL_DATA BYTE T_Tail1;
static P_INTERNAL_DATA BYTE T_Head1;

bit __uart0;
bit __uart1;

void UART0_Interrupt(void) interrupt 4 using 2
{
   int i;
   register BYTE temp;

   if (TI)                                        /* Is TI flag set                          */
     {  RESET_REGISTER(TI);                       /* Clear TI Flage                          */
        if (TLength0 != 0 )                       /* UART0 Tx FIFO is empty                  */
          { SBUF = UART0_TFIFO[T_Tail0];          /* Put a byte to SBUF                      */
            if (++T_Tail0 == MaxLength)           /* Is T_Tail0 point to UART0 Tx FIFO tail  */
              { T_Tail0 = 0; }                    /* Set T_Tail0 point to UART0 Tx FIFO head */
            TLength0--;
          }
        else
          {
            __uart0 = OFF;
       #if defined( UART0_RS485_Adapter )              /* Is UART0 use RS485 Adapter        */
                                                       /* UART0 Tx FIFO is empty            */
            for ( i = 0; i < UART0_RS485_DelayTime;)   /* then delay one bit time           */
               { i++; }
            __DIR0 = RECEIVE;                            /* change R/T Direction              */
       #endif
          }
     }
   else
     {
      RESET_REGISTER(RI);
      temp = SBUF;                                     /* Get a byte from SBUF                    */
      if (!(RLength0 == MaxLength))                    /* Is UART0 Rx FIFO not full               */
        { UART0_RFIFO[R_Head0] = temp;                 /* Put a byte to UART0 Rx FIFO             */
          if (++R_Head0 == MaxLength)                  /* Is R_Head0 point to UART0 Rx FIFO tail  */
            { R_Head0 = 0; }                           /* Set R_Head0 point to UART0 Rx FIFO head */
          RLength0++;
        }
     }
}

void UART1_Interrupt(void) interrupt 7  using 2
{
   int i;
   register BYTE temp;
   if (TI1)                                             /* Is TI flag set                          */
     {  RESET_REGISTER(TI1);                            /* Clear TI Flage                          */
        if (TLength1 != 0 )                             /* UART1 Tx FIFO is empty                  */
          {
          /* Special Proc
             Philips Call station */
            for ( i = 0; i < UART1_RS485_DelayTime;)    /* then delay one bit time           */
               { i++; }

          /* Special Proc
             Philips Call station */

            SBUF1 = UART1_TFIFO[T_Tail1];               /* Put a byte to SBUF1                     */
            if (++T_Tail1 == MaxLength)                 /* Is T_Tail1 point to UART1 Tx FIFO tail  */
              { T_Tail1 = 0; }                          /* Set T_Tail1 point to UART1 Tx FIFO head */
            TLength1--;
          }
        else                                            /* UART1 Tx FIFO is empty            */
          {
            __uart1 = OFF;
       #if defined( UART1_RS485_Adapter )               /* Is UART1 use RS485 Adapter        */
            for ( i = 0; i < UART1_RS485_DelayTime;)    /* then delay one bit time           */
               { i++; }
            __DIR1 = RECEIVE;                             /* change R/T Direction              */
       #endif
          }
     }
   else
     {
      RESET_REGISTER(RI1);
      temp = SBUF1;                                    /* Get a byte from SBUF                    */
      if (!(RLength1 == MaxLength))                    /* Is UART1 Rx FIFO not full               */
        { UART1_RFIFO[R_Head1] = temp;                 /* Put a byte to UART1 Rx FIFO             */
          if (++R_Head1 == MaxLength)                  /* Is R_Head1 point to UART1 Rx FIFO tail  */
            { R_Head1 = 0; }                           /* Set R_Head1 point to UART1 Rx FIFO head */
          RLength1++;
        }
     }
}

BOOLEAN UART0_Put(const BYTE Value)
{
  RESET_REGISTER(EA);                         /* Disable Interrupt                         */
  if (TLength0 == MaxLength)                  /* Is UART0 Tx FIFO full                     */
    { SET_REGISTER(EA);                       /* Enable Interrupt                          */
      return FALSE; }                         /* Return FLASE                              */
  if (__uart0 == OFF)                           /* Is TLength0 zero then                     */
    {
       if (!P1_IsReceive())
       {
         SET_REGISTER(TI);
         __uart0 = ON;
         #if defined (UART0_RS485_Adapter)
            __DIR0 = TRANSMIT;
         #endif
       }
    }                                         /* Enable UART0 TI FLAG                      */
  UART0_TFIFO[T_Head0] = Value;               /* Put a byte to UART0 Tx FIFO               */
  TLength0++;
  if (++T_Head0 == MaxLength)                 /* Is T_Head0 point to UART0 Tx FIFO tail    */
    { T_Head0 = 0; }                          /* Set T_Head0 point to UART0 Tx FIFO head   */
  SET_REGISTER(EA);                           /* Enable Interrupt                          */
  return TRUE;
}

BOOLEAN UART0_Get(BYTE *Value)
{
  RESET_REGISTER(EA);                           /* Disable Interrupt                       */
    if (RLength0 == 0 )                         /* Is UART0 Rx FIFO empty                  */
      { SET_REGISTER(EA);                       /* Enable Interrupt                        */
        return FALSE; }                         /* Return FLASE                            */
    *Value = UART0_RFIFO[R_Tail0];              /* Get a Byte from UART0 Rx FIFO           */
    if (++R_Tail0 == MaxLength)                 /* Is R_Tail0 point to UART0 Rx FIFO tail  */
      { R_Tail0 = 0; }                          /* Set R_Tail0 point to UART0 Rx FIFO head */
    RLength0--;                                 /*                                         */
    SET_REGISTER(EA);                           /* Enable Interrupt                        */
    return TRUE;
}

BOOLEAN UART1_Put(BYTE Value)
{
  RESET_REGISTER(EA);                           /* Disable Interrupt                       */
  if (TLength1 == MaxLength)                    /* Is UART1 Tx FIFO full                   */
  { SET_REGISTER(EA);                           /* Enable Interrupt                        */
    return FALSE; }                             /* Return FLASE                            */

  if (__uart1 == OFF)
    {
      if (!P2_IsReceive())
      {
      	SET_REGISTER(TI1);                        /* Enable UART1 TI FLAG                    */
        __uart1 = ON;
        #if defined ( UART1_RS485_Adapter )
           __DIR1 = TRANSMIT;
        #endif
      }
    }

  UART1_TFIFO[T_Head1] = Value;                 /* Put a byte to UART1 Tx FIFO             */
  if (++T_Head1 == MaxLength)                   /* Is T_Head0 point to UART0 Tx FIFO tail  */
    { T_Head1 = 0; }                            /* Set T_Head0 point to UART0 Tx FIFO head */
  TLength1++;
  SET_REGISTER(EA);                             /* Enable Interrupt                        */
  return TRUE;
}

BOOLEAN UART1_Get(BYTE *Value)
{
  RESET_REGISTER(EA);                           /* Disable Interrupt                       */
  if (RLength1 == 0 )                           /* Is UART0 Rx FIFO empty                  */
  { SET_REGISTER(EA);                           /* Enable Interrupt                        */
    return FALSE; }                             /* Return FLASE                            */

  *Value = UART1_RFIFO[R_Tail1];                /* Get a Byte from UART0 Rx FIFO           */

  if (++R_Tail1 == MaxLength)                   /* Is R_Tail0 point to UART0 Rx FIFO tail  */
  { R_Tail1 = 0; }                              /* Set R_Tail0 point to UART0 Rx FIFO head */

  RLength1--;                                   /*                                         */
  SET_REGISTER(EA);                             /* Enable Interrupt                        */
  return TRUE;
}

void InitUART0(void)
{
/* ===================================================
   UART 0 Use Time 2 Baud General 9600bps @ 22.118MHZ
   RCAP2H,RCAP2L = 65535 - (Osc) / (32 * Baud Rate)
   ===================================================
 CKCON Register   (clock  control)
 MSB   Bit    Function
  .     7        WD1
  .     6        WD0
  .     5        T2M
  .     4        T1M
  .     3        T0M
  .     2        MD2
  .     1        MD1
 LSB    0        MD0
 Set Time Clk ;Osc/4 or Osc/12

 SCON Register  (serial port control)
 MSB   Bit    Function
  .     7        SM0          MODE  SM0 SM1
  .     6        SM1           0     0   0
  .     5        SM2           1     0   1
  .     4        REN           2     1   0
  .     3        TB8           3     1   1
  .     2        RB8
  .     1        TI
 LSB    0        RI
*/
   R_Head0 = 0;
   R_Tail0 = 0;
   T_Head0 = 0;
   T_Tail0 = 0;
   RLength0 = 0;
   TLength0 = 0;

   CKCON  = 0x82;
   SCON   = 0x50;
   RCAP2H = (65535 - (OSC / (32 * UART0_BaudRate))/256);
   RCAP2L = (65535 - (OSC / (32 * UART0_BaudRate))%256)+1;
   TH2 = RCAP2H;
   TL2 = RCAP2L;
   T2CON  = 0x34;
   __uart0 = 0;
   #if defined( UART0_RS485_Adapter )              /* Is UART0 use RS485 Adapter        */
      __DIR0 = RECEIVE;                              /* change R/T Direction              */
   #endif
   SET_REGISTER(PS);
   ES0    = ENABLE; /* Enable UART 0 Interrupt */
}
void InitUART1(void)
{
// UART 1 Use Time 1 Baud General 1200bps @ 22.118MHz
// SoftTime Use Time 0, Mode 1
// SMOD = 0, then K = 1 else K = 2
// W77E5X or DS80C3X
// T1M = 1, then C = 3, else C = 1
// TH1 = 256 - (osc * K(1 or 2) * C(1 or 3) /32*12*Baud Rate)
   R_Head1 = 0;
   R_Tail1 = 0;
   T_Head1 = 0;
   T_Tail1 = 0;
   RLength1 = 0;
   TLength1 = 0;

   SCON1 = 0x50;
   TMOD  = 0x21;
   TH1 = (256 - ((OSC)/(32*12*UART1_BaudRate)));
   TR1 = ENABLE;
   __uart1 = 0;
   SET_REGISTER(PS1);
   ES1 = ENABLE; /* Enable UART1 Interrupt */
/*   TMOD |= 0x21;
   TH0 = 0xFD;       */
      __DIR1 = RECEIVE;                              /* change R/T Direction              */
}

// UART 0 Driver
void UART0Drive(void) {
  if (!P1_IsReceive())  {
    if ((TLength0 > 0) && (__uart0 == OFF))  {
      __uart0 = ON;
      __DIR0 = TRANSMIT;
      SET_REGISTER(TI);
    }
  }
}


// UART 1 Driver
void UART1Drive(void)  {
  if (!P2_IsReceive()) {
    if ((TLength1 > 0) && (__uart1 == OFF)) {
      __uart1 = ON;
      __DIR1 = TRANSMIT;
      SET_REGISTER(TI);
    }
  }
}

#ifdef DEBUG_RECEIVE_PORT1
// Debug function
void DEBUG_PORT1(void)
{
  // 0x15, 0x09, 0x40, 0x53, 0x53, 0x00, 0x03, 0x03, 0x0F, 0xFC
  // 0x15, 0x09, 0x40, 0x53, 0x53, 0x00, 0x09, 0x00, 0x15, 0xF3
  // 0x15, 0x09, 0x40  0x53, 0x53, 0x00, 0x09  0x00, 0x0F, 0xF9
  UART0_RFIFO[0] = 0x15;
  UART0_RFIFO[1] = 0x09;
  UART0_RFIFO[2] = 0x40;
  UART0_RFIFO[3] = 'S';
  UART0_RFIFO[4] = 'S';
  UART0_RFIFO[5] = 0x00;
  UART0_RFIFO[6] = 0x09;
  UART0_RFIFO[7] = 0x00;
  UART0_RFIFO[8] = 0x0F;
  UART0_RFIFO[9] = 0xF9;
  UART0_RFIFO[10] = 0x15;
  UART0_RFIFO[11] = 0x09;
  UART0_RFIFO[12] = 0x40;
  UART0_RFIFO[13] = 'S';
  UART0_RFIFO[14] = 'S';
  UART0_RFIFO[15] = 0x00;
  UART0_RFIFO[16] = 0x09;
  UART0_RFIFO[17] = 0x00;
  UART0_RFIFO[18] = 0x15;
  UART0_RFIFO[19] = 0xF3;

  R_Head0 = 19;
  UART0_R_Length = 20;
}
#endif

#ifdef DEBUG_RECEIVE_PORT2
// Debug function
void DEBUG_PORT2(void)
{
     //      sync, leng, GMASTERID, Type,  MyID, TagetID,  KeyCode, CheckSum
     // send 0x15, 0x07,      0x80, 0x01,  0x00,    0x00,     0x01,     0x77
     // send 0x15, 0x07,      0x80, 0x01,  0x00,    0x00,     0x0a,     0x6E
     // send 0x15, 0x07,      0x80, 0x01,  0x00,    0x00,     0x27,     0x51
     // send 0x15, 0x07,      0x80, 0x01,  0x00,    0x01,     0x03,     0x74
     // send 0x15, 0x07,      0x80, 0x01,  0x00,    0x02      0x05,     0x71
  UART1_RFIFO[0] = 0x15;
  UART1_RFIFO[1] = 0x07;
  UART1_RFIFO[2] = 0x80;
  UART1_RFIFO[3] = 0x01;
  UART1_RFIFO[4] = 0x00;
  UART1_RFIFO[5] = 0x00;
  UART1_RFIFO[6] = 0x01;
  UART1_RFIFO[7] = 0x77;
  UART1_RFIFO[8] = 0x15;
  UART1_RFIFO[9] = 0x07;
  UART1_RFIFO[10] = 0x80;
  UART1_RFIFO[11] = 0x01;
  UART1_RFIFO[12] = 0x00;
  UART1_RFIFO[13] = 0x01;
  UART1_RFIFO[14] = 0x03;
  UART1_RFIFO[15] = 0x74;

  R_Head1 = 15;
  UART1_R_Length = 16;
}
#endif

























































































































