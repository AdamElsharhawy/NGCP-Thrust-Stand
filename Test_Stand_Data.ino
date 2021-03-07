#include <HX711.h>
#define calibration_factor -7050 // this is taken from Test_Stand_Calibration
#define LOADCELL_DOUT_PIN 3
#define LOADCELL_SCK_PIN 2

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("Thrust Stand Test");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor); //remember to change calibration_factor if it is changed in Test_Stand_calibration
  scale.tare();
  Serial.println("Readings:");
  
}

void loop() {
  Serial.print("Thrust Readings");
  Serial.print(scale.get_units(), 1); //returns a float
  Serial.print("g");// consider to change calibration_factor if using g 
  Serial.println();
}
