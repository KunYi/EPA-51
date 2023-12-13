//
// File Name   : P2Layer3.C
// Auther      : Kun Yi Chen
// Create      : 07/26/2003
// version     :
// Objective   :
// Description : link remote extend unit
// History     :

#include "P1Layer3.h"
#include "P2Layer3.h"
#include "display.h"

ExportQueFunction(P2FIFOIn)
ExportQueFunction(P2FIFOOut)
ExportQueFunction(P1FIFOOut)
ExportQueFunction(P1FIFOIn)

data P2L3_STATUS  P2Status;

// Create FIFO & Operator function


void P2Process(void) {
  // ������@ �B�w�g��@
  // P2 term
  // �����ƾ��Ǩ�t�κ�
  // No.   Address   content
  //  1       0x80   0xAA, ID, nn Key            �����ƾ��o�X Key
  //  2       0x80   0x55, ID,                   ACK
  if (P2RxBuff[0] != 0x80) { // Address
   // failed packet
    return;
  }

  switch(P2RxBuff[1]) {
  case P2CMD_RMKEY:
    PutToQue(P2FIFOIn, P2_RMEU_KEY);
    PutToQue(P2FIFOIn, P2RxBuff[2]); // ID
    PutToQue(P2FIFOIn, P2RxBuff[3]); // nn Key
    break;
  case P2CMD_ACK:
    break;
  }
}

//  �t�κݶǰe�쩵���ƾ�
//  4       SubID  0xF1                                       ���լO�_���o�� ID
//  12      0xFF   0x01, ID, RED LED, ACKID         ( 2 BYTE)
//  13      0xFF   0x02, ID, Green LED, ACKID       ( 2 BYTE)
//  14      0xFF   0x03, ID, Flash RED LED, ACKID   ( 2 BYTE)
//  15      0xFF   0x04, ID, Flash GREEN LED, ACKID ( 2 BYTE)
//  3       SubID  0xF0, CMD                                  �^�� ACK �� �����ƾ�

void P2ResponseACK(BYTE ID, BYTE CMD)
{
  BYTE CheckSum;

  P2Port_Put(P2Package_SYNC);
  P2Port_Put(P2ACK_Len);
  CheckSum = P2ACK_Len;

  CheckSum += ID;
  P2Port_Put(ID);

  CheckSum += 0xF0;     // ACK
  P2Port_Put(0xF0);

  CheckSum += CMD;
  P2Port_Put(CMD);

  P2Port_Put((~CheckSum+1));
}

//#define P2TxRLEDStatus(ID, RLED1, RLED2)     P2TxCMD((ID), CMD_RLEDSTATUS, (RLED1), (RLED2))
//#define P2TxGLEDStatus(ID, GLED1, GLED2)     P2TxCMD((ID), CMD_GLEDSTATUS, (GLED1), (GLED2))
//#define P2TxFRLEDStatus(ID, FRLED1, FRLED2)  P2TxCMD((ID), CMD_FRLEDSTATUS, (FRLED1), (FRLED2))
//#define P2TxFGLEDStatus(ID, FGLED1, FGLED2)  P2TxCMD((ID), CMD_FRLEDSTATUS, (FGLED1), (FGLED2))
//#define P2TxOLEDStatus(ID, OLED1, OLED2)     P2TxCMD((ID), CMD_OLEDSTATUS, (OLED1), (OLED2))

void P2TxCMD(BYTE ID, BYTE CMD, BYTE S1, BYTE S2) {
  BYTE CheckSum = P2CMD_LEN;

  P2Port_Put(P2Package_SYNC);
  P2Port_Put(P2CMD_LEN);

  CheckSum += ID;    // ack ID
  P2Port_Put(ID);

  CheckSum += CMD;   // command
  P2Port_Put(CMD);

  CheckSum += S1;    // byte 1 for status
  P2Port_Put(S1);

  CheckSum += S2;    // byte 2 for status
  P2Port_Put(S2);

  P2Port_Put((~CheckSum+1));
}

/*
void P2QueryID(BYTE ID)
{
  BYTE CheckSum = P2QueryID_LEN;

  P2Port_Put(P2Package_SYNC);
  P2Port_Put(P2QueryID_LEN);

  CheckSum += ID;    // Query ID
  P2Port_Put(ID);

  CheckSum += CMD_QUERY_ID;
  P2Port_Put(CMD_QUERY_ID);

  P2Port_Put((~CheckSum+1));
}
*/
