  // 按鍵代表 LED 亮或暗
  GetFromQue(P1FIFOIn, &ReceID);  // ID
  GetFromQue(P1FIFOIn, &status1); // KEY
  GetFromQue(P1FIFOIn, &status2); // Key Status


  P2TxCMD(AckID, ReceID, CMD_KEY, status1, status2);
