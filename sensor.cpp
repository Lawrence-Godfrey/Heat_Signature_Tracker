#include "sensor.h"

bool print_sensor_values (void) 
{
  sensor.measure();
  for(int y=0;y<4;y++){ //go through all the rows
    Serial.print("[");
    
    for(int x=0;x<16;x++){ //go through all the columns
      double tempAtXY= sensor.getTemperature(y+x*4); // extract the temperature at position x/y
      Serial.print(tempAtXY);
        
      if (x<15) Serial.print(",");
    }

    Serial.print("]");
    if (y<3)Serial.print("~"); 
  }
  Serial.println("\n");
}

  