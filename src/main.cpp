#include "BigBoyInclude.h"
#include "Wire_Clavier_Encoder.h"

void setup() {
  Wire.begin(2);
  // Wire1.begin(3);
  Wire.onRequest(requestEvent); // register event
  Serial.begin(115200);
  BTN_setup();
  encoder_zero();
  encoder_setup(26, 32, 38, 44, 50, 10);
}

void loop() {
  BTN_I2C();
  encoder_loop();
}