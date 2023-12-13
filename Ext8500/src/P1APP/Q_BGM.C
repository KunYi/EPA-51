  case CMD_QUIT_BGM:
    //sysStatus.IsBGM = FALSE;
    ClearGLED();
    LcdScreen(LCD_NORMAL);
    sysStatus.Proc = SYS_NORMAL;
    LCDDelay();
    LcdScreen(LCD_BL_AUTO_OFF);
    break;
