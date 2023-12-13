#define __IMPLEMENT_SENSOR__
#include "sensor.h"
#define  RelayTable LEDTable

// Test Fire Alarm
//#define  __DEBUG_FIRE_ALARM__

// only active one item test it for following
//#define  __FIRE_ALARM_ONE_ZONE__
//#define  __FIRE_ALARM_MULTI_ZONE__
//#define  __EMG_TEL_

extern CODE_DATA BYTE LEDTable[];
//extern bit IsPreEmergencyMode,IsEmergencyMode;
//extern  Status  ProcState;
static EXTERN_DATA BYTE FireSensor[2];
static EXTERN_DATA BYTE TelSensor[2];
static EXTERN_DATA BYTE PreFireStatus[2];
P_INTERNAL_DATA           BYTE PreTelStatus[2];
static EXTERN_DATA      BYTE PreFireSensor[2];
static EXTERN_DATA      BYTE PreTelSensor[2];
static EXTERN_DATA BYTE ShortSensor[2];
static EXTERN_DATA BYTE PreShortStatus[2];
static EXTERN_DATA BYTE PreShortSensor[2];
static EXTERN_DATA BYTE FireDebounce;
static EXTERN_DATA BYTE TelDebounce;
static EXTERN_DATA BYTE ShortDebounce;
EXTERN_DATA BYTE PreAlramTime;
static bit IsRemoteMicPress;

void InitialSensor(void)
{
  FireSensor[0] = FireSensor[1] = 0;
  TelSensor[0] = TelSensor[1] = 0;
  PreFireStatus[0] = PreFireStatus[1] = 0;
  PreTelStatus[0] = PreTelStatus[1] = 0;
  PreFireSensor[0] = PreFireSensor[1] = 0;
  PreTelSensor[0] = PreTelSensor[1] = 0;
  ShortSensor[0] = ShortSensor[1] = 0;
  PreShortStatus[0] = PreShortStatus[1] = 0;
  FireDebounce = ShortDebounce = TelDebounce = 0;
//  IsPreEmergencyMode = FALSE;

  GetPreAlarmTime();
}

BOOLEAN IsAnyFireAction(void)
{

 // Modify TelSensor
 if ((FireSensor[0] != 0) || (FireSensor[1] != 0))
 {
   return TRUE;
 }
 else
 {
   return FALSE;
 }
}

void CheckFire(void)
{
  BYTE Temp1, Temp2;

  //scan fire state
  if (IsFireNormalClose()) /* sensor relay normal close  high level */
  {
     Temp1 = ~PHYSICAL_FIRESENSOR0;
     Temp2 = ~PHYSICAL_FIRESENSOR1;
  }
  else /* sensor relay normal open with low level */
  {
     Temp1 = PHYSICAL_FIRESENSOR0;
     Temp2 = PHYSICAL_FIRESENSOR1;
  }

  Temp2 &= 0x03;

//fire debounce
  if ((PreFireSensor[0] != Temp1) ||
      (PreFireSensor[1] != Temp2))
  {
    PreFireSensor[0] = Temp1;
    PreFireSensor[1] = Temp2;
    FireDebounce = 0;
  }
  else
  {
    FireDebounce++;
  }

#ifdef  __DEBUG_FIRE_ALARM__
  // debug version
  #ifdef  __FIRE_ALARM_ONE_ZONE__
    // test fire alram for one zone
    FireSensor[0] = 0x01;
    FireSensor[1] = 0x00;
  #else
    #ifdef __FIRE_ALARM_MULTI_ZONE
      // test fire alram for three zone
      FireSensor[0] = 0x07;
      FireSensor[1] = 0x00;
    #endif
  #endif


#else
  // release version
  if (FireDebounce > 3)
  {
     FireDebounce = 0;
     FireSensor[0] = Temp1;
     FireSensor[1] = Temp2;
//	  IsPreEmergencyMode = TRUE;
  }
#endif

}

#define COUNT_TEL_DEBOUNCE  10
void CheckTel(void)
{
 BYTE Temp1, Temp2;
//scan tel state
 if (IsTelNormalClose()) /* sensor relay normal close  high level */
 {
     Temp1 = ~PHYSICAL_TELSENSOR0;
     Temp2 = ~PHYSICAL_TELSENSOR1;
 }
 else /* sensor relay normal open with low level */
 {
     Temp1 = PHYSICAL_TELSENSOR0;
     Temp2 = PHYSICAL_TELSENSOR1;
 }


 Temp2 = Temp2 >> 4;
 Temp2 &= 0x03;

//tel debounce
 if ((PreTelSensor[0] != Temp1) ||
     (PreTelSensor[1] != Temp2))
 {
   TelDebounce = 0;
   PreTelSensor[0] = Temp1;
   PreTelSensor[1] = Temp2;
 }
 else
 {
   if (TelDebounce <= COUNT_TEL_DEBOUNCE)
   {
       TelDebounce++;
   }
 }

#ifdef  __DEBUG_FIRE_ALARM__
  // debug version

#else
  // release version
 if (TelDebounce >= COUNT_TEL_DEBOUNCE)
 {
  //   TelDebounce = 0;
    TelSensor[0] = Temp1;
    TelSensor[1] = Temp2;
 }
#endif

}

void CheckShort(void)
{
 BYTE Temp3, Temp4;
 Temp3 = ~PHYSICAL_SHORTSENSOR0;
 Temp4 = ~PHYSICAL_SHORTSENSOR1;
 Temp4 = Temp4 >> 6;
 Temp4 &= 0x03;

 if ((PreShortSensor[0] != Temp3) ||
     (PreShortSensor[1] != Temp4))
   {
     ShortDebounce = 0;
     PreShortSensor[0] = Temp3;
     PreShortSensor[1] = Temp4;
   }
 else
   { ShortDebounce++; }

 if (ShortDebounce > 1)
   {
     ShortDebounce = 0;
     ShortSensor[0] = Temp3;
     ShortSensor[1] = Temp4;
   }
}

BOOLEAN IsAnyLoopShort(void)
{
 if ((ShortSensor[0] != 0) || (ShortSensor[1] != 0) )
   {  return TRUE; }
 else { return FALSE; }
}

BOOLEAN IsLoopShort(const BYTE RelayNumber)
{
  BYTE Temp1, Temp2;

  if (RelayNumber <= ZONE10_RELAY )
    {
      if (RelayNumber <= ZONE08_RELAY)
        { Temp1 = 0; Temp2 = RelayNumber; }
      else
        { Temp1 = 1; Temp2 = (RelayNumber - 8); }

      if ((PreShortSensor[Temp1] & RelayTable[Temp2]) == RelayTable[Temp2])
        { return TRUE; }
      else { return FALSE; }
    }
  else { return FALSE; }
}

BOOLEAN IsFireDiffer(void)
{
  if (( FireSensor[0] != PreFireStatus[0] ) ||( FireSensor[1] != PreFireStatus[1] ))
  {
    PreFireStatus[0] = FireSensor[0];
    PreFireStatus[1] = FireSensor[1];
    return TRUE;
  }
  return FALSE;
}

// Added new function at 04/27/2004 by Kunyi Chen
// because change function of from EmgTel sensor to Extend Group
BOOLEAN IsExGroupDiffer(void)
{
  if (( TelSensor[0] != PreTelStatus[0] ) ||( TelSensor[1] != PreTelStatus[1] ))
  {
    PreTelStatus[0] = TelSensor[0];
    PreTelStatus[1] = TelSensor[1];
    return TRUE;
  }
  return FALSE;
}

BOOLEAN IsShortDiffer(void)
{
 if (( ShortSensor[0] != PreShortStatus[0] ) ||
     ( ShortSensor[1] != PreShortStatus[1] ))
   {
     PreShortStatus[0] = ShortSensor[0];
     PreShortStatus[1] = ShortSensor[1];
     return TRUE;
   }
 return FALSE;
}

BOOLEAN IsFireNormalClose(void)
{
 return ((PreAlramTime & 0x10) == 0x10) ? TRUE : FALSE;
}

BOOLEAN IsTelNormalClose(void)
{
 return ((PreAlramTime & 0x20) == 0x20) ? TRUE : FALSE;
}

BYTE GetPreAlarmTime(void)
{
 PreAlramTime = ~PHYSICAL_SYSTEMSET;
 return (PreAlramTime & 0x0f);
}

BYTE GetPreAlarmTimerSet(void)
{
 return (PreAlramTime & 0x0f);
}

void GetFireStatus(BYTE *Buffer)
{
 Buffer[0] = PreFireStatus[0];
 Buffer[1] = PreFireStatus[1];
}

void GetTelStatus(BYTE *Buffer0)
{
 Buffer0[0] = PreTelStatus[0];
 Buffer0[1] = PreTelStatus[1];
}

void GetShortStatus(BYTE *Buffer2)
{

 Buffer2[0] = PreShortStatus[0];
 Buffer2[1] = PreShortStatus[1];

}

void ClrFireSensorState(void)
{
 PreFireStatus[0] = 0;
 PreFireStatus[1] = 0;
// PreTelStatus[0] = 0;
// PreTelStatus[1] = 0;
}

void ClrShortSensorState(void)
{
 PreShortStatus[0] = 0;
 PreShortStatus[1] = 0;
}

void ClrShortState(const BYTE Number)
{
  BYTE Temp1, Temp2;

  if (Number <= ZONE10_RELAY )
    {
      if (Number <= ZONE08_RELAY)
        { Temp1 = 0; Temp2 = Number; }
      else
        { Temp1 = 1; Temp2 = (Number - 8); }
      PreShortSensor[Temp1] &= ~RelayTable[Temp2];
    }

}

bit IsMicPhonePress(void)
{
  BYTE temp;
  temp = PORT9_RW;
	temp &= 0x01;


	if ((temp == 0x01) || (IsRemoteMicPress == TRUE))
    {
	  return TRUE;
    }
	else
    {
      return FALSE;
    }
}

void SetRemoteMicPress(void)
{
  IsRemoteMicPress = TRUE;
}

void ClrRemoteMicPress(void)
{
  IsRemoteMicPress = OFF;
}

/*
BOOLEAN IsMicPhonePress(void)
{
 return ~MicPhonePTT;
}
*/
