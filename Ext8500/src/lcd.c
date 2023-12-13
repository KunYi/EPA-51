#include "lcd.h"
BYTE LcdErrorCount;
BYTE LcdCount,LcdCount1;
void LcdScreen(BYTE sc)
{
LcdCount = 0;
LcdCount1 = 0;
	PHYSICAL_LCD=~sc;
for(LcdCount = 0;LcdCount < 10;LcdCount++){
for(LcdCount1 = 0;LcdCount1 < 200;LcdCount1++){
		}}

/*
if(LcdErrorCount>=3){
	LcdErrorCount=0;
 	PHYSICAL_LCD=~LCDERR;
 	}
*/
}

BOOLEAN IsSlaveRead(void)
{
BYTE TEMP;
TEMP = PHYSICAL_SLAVE_CPU_STATE & 0x04;
if(TEMP==0x04)
   {  return FALSE; }
 else { return TRUE; }
}

void LCDDelay(void) {
  BYTE LcdCount,LcdCount1;

  LcdCount = 0;
  LcdCount1 = 0;

  for (LcdCount = 0;LcdCount < 10;LcdCount++) {
    for(LcdCount1 = 0;LcdCount1 < 200;LcdCount1++){
	}
  }
}














































































































