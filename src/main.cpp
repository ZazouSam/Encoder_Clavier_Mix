#include "BigBoyInclude.h"
#include "Wire_Clavier_Encoder.h"

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
  setupBMS();
}

void loop()
{
  BTN_I2C();
  encoder_loop();
  BMS();
  // uint32_t valtemp1 = adc_get_channel_value(ADC, ADC_CHANNEL_0);
  // uint32_t valtemp2 = adc_get_channel_value(ADC, ADC_CHANNEL_1);
  // val = valtemp1 - valtemp2;
  // voltage = val * 3.3;
  // voltage /= 4095.0;
  // peut-etre mettre un delay pour ne pas surcharger le bus I2C
  if (millis() - lastChristmas >= 10 && millis() - lastChristmas < 20)
  {
    cell_select = 1;
  }
  else if (millis() - lastChristmas >= 20 && millis() - lastChristmas < 30)
  {
    cell_select = 2;
  }
  else if (millis() - lastChristmas >= 30 && millis() - lastChristmas < 40)
  {
    cell_select = 3;
  }
  else if (millis() - lastChristmas >= 40 && millis() - lastChristmas < 50)
  {
    cell_select = 4;
  }
  else if (millis() - lastChristmas >= 50) //I gave you my heart but the very next day you gave it away
  {
    cell_select = 0;
    lastChristmas = millis();
  }



  // Check if 500ms have elapsed since last print time
  if (millis() - lastPrintTime >= 250)
  {
    //printBMS();
    lastPrintTime = millis(); // update last print time
  }
}
