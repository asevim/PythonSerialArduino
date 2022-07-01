#include "SerialTransfer.h"


SerialTransfer myTransfer;

struct STRUCT {
  int32_t accX = 0;
  int32_t accY = 400;
  int32_t accZ = 10;
  int32_t gyroX = 0;
  int32_t gyroY = 0;
  int32_t gyroZ = 0;
  int32_t pressure = 0;
  int32_t batteryVolt = 0;
  int32_t batteryAmp = 0;
  int32_t waterTemp = 0;
  int32_t internalTemp = 0;
} rovDataTx;

struct STRUCT1 {
  int32_t buttons;
  int32_t leftTrigger;
  int32_t rightTrigger;
  int32_t leftThumbX;
  int32_t leftThumbY;
  int32_t rightThumbX;
  int32_t rightThumbY;
} rovDataRx;

void setup()
{
  Serial.begin(115200);
  myTransfer.begin(Serial);
  pinMode(25,OUTPUT);
}


void loop()
{
  if(myTransfer.available())
  {
    uint16_t recSize = 0;
    uint16_t sendSize = 0;

    recSize = myTransfer.rxObj(rovDataRx, recSize);
    
    sendSize = myTransfer.txObj(rovDataTx, sendSize);

    myTransfer.sendData(sendSize);
    rovDataTx.accX += 1;
    //rovDataTx.accY += 1;
    delay(100);
    if(rovDataRx.buttons > 99){
      digitalWrite(25,HIGH);
    }


  }
}