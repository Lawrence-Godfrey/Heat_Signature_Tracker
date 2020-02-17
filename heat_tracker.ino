#include "motor_driver.h"


void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println("trying to initialize sensor...");
  sensor.initialise (16); // start the thermo cam with 8 frames per second
  Serial.println("sensor initialized!");
  
  OC06.begin();
  OC06.enable();
}
void loop() {
  print_sensor_values();

  OC06.move(5000, 200, FORWARD);
  delay(500);
  OC06.move(5000, 200, REVERSE);
  delay(500);
  
  delay(31);
}