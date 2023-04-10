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
  setupBMS();
}

void loop()
{
  BTN_I2C_Serial();
  encoder_loop();
  // BMS();

  if (millis() - lastChristmas >= 10)
  {
    lastChristmas = millis();

  }
  Wire1.beginTransmission((I2C_GROUP_ADDR << 3) + CELL_CTL);
  Wire1.write(0x10);
  Wire1.endTransmission();
  delay(1);
  adc = analogRead(A2);

  VCOUT = adc * (3.3 / 4096.0) - Voffset;
  VC1 = VCOUT / Gvcout;
  // VC1 = ((VCOUT * GCref + OCvc1)/Gvcout)* (1 + GCvc1);

  Wire1.beginTransmission((I2C_GROUP_ADDR << 3) + CELL_CTL);
  Wire1.write(0x11);
  Wire1.endTransmission();
  delay(1);

  adc = analogRead(A2);
  VCOUT = adc * (3.3 / 4096.0) - Voffset;
  VC2 = VCOUT / Gvcout;
  // VC2 = ((VCOUT * GCref + OCvc2) / Gvcout) * (1 + GCvc2);

  Wire1.beginTransmission((I2C_GROUP_ADDR << 3) + CELL_CTL);
  Wire1.write(0x12);
  Wire1.endTransmission();
  delay(1);

  adc = analogRead(A2);
  VCOUT = adc * (3.3 / 4096.0) - Voffset;
  VC3 = VCOUT / Gvcout;
  // VC3 = ((VCOUT * GCref + OCvc3) / Gvcout) * (1 + GCvc3);

  Wire1.beginTransmission((I2C_GROUP_ADDR << 3) + CELL_CTL);
  Wire1.write(0x13);
  Wire1.endTransmission();
  delay(1);

  adc = analogRead(A2);
  VCOUT = adc * (3.3 / 4096.0) - Voffset;
  VC4 = VCOUT / Gvcout;
  // VC4 = ((VCOUT * GCref + OCvc4) / Gvcout) * (1 + GCvc4);
  delay(1);
  VCtotal = VC1 + VC2 + VC3 + VC4;
  pourcentage_batterie = (VCtotal - B_MIN) / (B_MAX - B_MIN) * 100;
  // Check if 500ms have elapsed since last print time
  if (millis() - lastPrintTime >= 250)
  {
    printBMS();
    lastPrintTime = millis(); // update last print time
  }
}
