#include <HX711.h>
#define LOADCELL_DOUT_PIN 3
#define LOADCELL_SCK_PIN 2

//wiring from loadcell to HX711 (red to E+ ,black to E-.white to A-, and Green to A+)
//wiring from HX711 to Uno (Gnd to Gnd,DT to D3, SCK to D2,VCC to 5V)
HX711 scale;

float calibration_factor = -7050; //subject to change depending on setup

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 calibration initiated");
  Serial.println("Disconnect Stand From Load Cell For Calibration");
  Serial.println("Once reading of calibration is done, reconnect stand to Load Cell");
  Serial.println("press + to increase calibration factor");
  Serial.println("press - to decrease calibration factor");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();
  scale.tare(); //this resets scale to zero

  long zero_factor = scale.read_average();
  Serial.print("Zero factor: ");
  Serial.println(zero_factor);
}

void loop() { 
  scale.set_scale(calibration_factor);
  Serial.print("Thrust:");
  Serial.print(scale.get_units(), 1);
  Serial.print("g"); //change this to grams once HX711 is wired and tested to see units
  //Serial.println("calibration_factor: ");
  //Serial.print(calibration_factor);
  Serial.println();
  delay(100);
  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+')
      calibration_factor += 10; //this is subject to change depending on units change
    else if(temp == '-')
      calibration_factor -= 10; //same as the one above this may change depending on my units conversion
    }

}
