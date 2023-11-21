const int VIN = A1; // define the Arduino pin A0 as voltage input (V in)
const float VCC   = 5.04;// supply voltage
const int MODEL = 12;   // enter the model (see above list)
        //using ACS770x-050U
#include <Robojax_AllegroACS_Current_Sensor.h>

Robojax_AllegroACS_Current_Sensor robojax(MODEL,VIN);

void setup() {
    //Robojax.com Allegro ACS Current Sensor 
    Serial.begin(9600);// initialize serial monitor
    Serial.println("Robojax Tutorial");
    Serial.println("ACS770 Current Sensor");
	
}

void loop() {
   //Robojax.com Allegro ACS Current Sensor  
    Serial.println(analogRead(VIN));

    /*Serial.print("Current: ");
    Serial.print(robojax.getCurrent(),3); // print the current with 3 decimal places
    Serial.print("A Avg:");
    Serial.print(robojax.getCurrentAverage(300),3);//   
    Serial.println("A");
   //robojax.debug();*/
   
  delay(150);
}
 