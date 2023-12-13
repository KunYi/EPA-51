  if (GetFromQue(P1FIFOIn, &Item)) {
    switch(Item) {
    case P1_SELF_RLED:     case P1_SELF_GLED:    case P1_SELF_CLED:
    case P1_SELF_GPLED:    case P1_SELF_FRLED:   case P1_SELF_FGLED:
    case P1_SELF_FCLED:    case P1_SELF_FGPLED:  case P1_EXUNIT_RLED:
    case P1_EXUNIT_GLED:   case P1_EXUNIT_CLED:  case P1_EXUNIT_GPLED:
    case P1_EXUNIT_FRLED:  case P1_EXUNIT_FGLED: case P1_EXUNIT_FCLED:
    case P1_EXUNIT_FGPLED: case P1_LCD_STATE:
      GetFromQue(P1FIFOIn, &ReceID);
      GetFromQue(P1FIFOIn, &Status1);
      GetFromQue(P1FIFOIn, &Status2);
      switch(Item) {
      case P1_EXUNIT_RLED:
      case P1_EXUNIT_GLED:
      case P1_EXUNIT_CLED:
      case P1_EXUNIT_GPLED:
      case P1_EXUNIT_FRLED:
      case P1_EXUNIT_FGLED:
      case P1_EXUNIT_FCLED:
      case P1_EXUNIT_FGPLED:
        P2TxCMD(ReceID, Item, Status1, Status2);
      }
      break;
    }
  }

/*
   // Application
  if (GetFromQue(P1FIFOIn, &Item)) {
    GetFromQue(P1FIFOIn, &Temp1); // ID
    GetFromQue(P1FIFOIn, &Temp2); // value1

    if (Item <= 0x08) {
      GetFromQue(P1FIFOIn, &Temp3); // value2
      if (Temp1 == 0) {
      // ID == 0, so it is Ext8500 setting protocol
        switch(Item) {
        case RLED_STATUS: // set red   LED status
          SetRLED_RAM(Temp2, Temp3);
          break;
        case GLED_STATUS: // set green LED status
          SetGLED_RAM(Temp2, Temp3);
          break;
        case CNTLED_STATUS:
          SetCNTLED_RAM(Temp2, Temp3);
          break;
        case GRPLED_STATUS:
          SetGROUPLED_RAM(Temp2, Temp3);
          break;
        case FRLED_STATUS: // set red   flash LED status
          SetFRLED_RAM(Temp2, Temp3);
          break;
        case FGLED_STATUS:  // set green flash LED status
          SetFGLED_RAM(Temp2, Temp3);
          break;
        case FCNTLED_STATUS:
          SetFCLED_RAM(Temp2, Temp3);
          break;
        case FGRPLED_STATUS:
          SetFGPLED_RAM(Temp2, Temp3);
          break;
        }
      // other ID, so it is Ext8310 setting protocl
      } else if (Temp1 < 0x10) {
        // send to port 2
        // Temp1, ID
        // Item,  Type, have setting status of LED
        // Temp2, Value1
        // Temp3, Value2
        P2TxCMD( Temp1, Item, Temp2, Temp3);
        // TranslateP2(Item);
      }
    } else {
      switch(Item) {
      case 0x09: // set Show screen
        LcdScreen(Temp2);
        break;
      default:
        break;
      }
    }
  }
*/

