  case CMD_SHORT_STATE:
    // Original ID == P1RxBuff[2]
    // 10 bit  == P1RxBuff[3]
    //            P1RxBuff[4]
    if (P1RxBuff[2] == 0) {
      // main unit
    } else {
      // other unit
    }
    break;
