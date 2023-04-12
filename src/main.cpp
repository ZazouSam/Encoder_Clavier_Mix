#include "BigBoyInclude.h"
#include "Wire_Clavier_Encoder.h"
#include "BMS.h"

unsigned long lastPrintTime = 0; // variable to store the last print time
unsigned long lastChristmas = 0;

void setup()
{
  Wire.begin(2);
  Wire1.begin();
  Wire.onRequest(requestEvent); // register event
  Serial.begin(115200);
  BTN_setup();
  encoder_zero();
  encoder_setup(26, 32, 38, 44, 50, 10);
  //setupBMS();
}

void loop()
{
  BTN_I2C();
  encoder_loop();
  // BMS();
  // // peut-etre mettre un delay pour ne pas surcharger le bus I2C
  // // if (millis() - lastChristmas >= 10)
  // // {
  // //   lastChristmas = millis();
  // // }
  // // Check if 500ms have elapsed since last print time
  // if (millis() - lastPrintTime >= 250)
  // {
  //   printBMS();
  //   lastPrintTime = millis(); // update last print time
  // }
}
