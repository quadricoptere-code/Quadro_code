
// Include Libraries
#include "Arduino.h"
#include "Servo.h"
#include "DS18B20.h"
#include "NewPing.h"
#include <Arduino_LSM9DS1.h>
#include <math.h>

// Pin Definitions
#define BRUSHLESSMOTOR1_1_PIN_DATA	5
#define BRUSHLESSMOTOR2_2_PIN_DATA	6
#define BRUSHLESSMOTOR3_3_PIN_DATA  7
#define BRUSHLESSMOTOR4_4_PIN_DATA  8
#define DS18B20_PIN_DQ	2
#define HCSR04_PIN_TRIG	4
#define HCSR04_PIN_ECHO	3



// Global variables and defines
const int brushlessMotor1_1LowSpeed = 1000;  //Starting speed
const int brushlessMotor1_1FastSpeed = 2000; //Top speed
const int brushlessMotor2_2LowSpeed = 1000;  //Starting speed
const int brushlessMotor2_2FastSpeed = 2000; //Top speed
const int brushlessMotor3_3LowSpeed = 1000;  //Starting speed
const int brushlessMotor3_3FastSpeed = 2000; //Top speed
const int brushlessMotor4_4LowSpeed = 1000;  //Starting speed
const int brushlessMotor4_4FastSpeed = 2000; //Top speed
// object initialization
Servo brushlessMotor1_1;
Servo brushlessMotor2_2;
Servo brushlessMotor3_3;
Servo brushlessMotor4_4;
DS18B20 ds18b20(DS18B20_PIN_DQ);
NewPing hcsr04(HCSR04_PIN_TRIG,HCSR04_PIN_ECHO);
float x,y,z;
float xa,ya,za;
const float a = 0.5;
double fxa,fya,fza;
double roll , pitch , yaw;



void tempGestion(float temp)
{
  if (temp > 60)
  {
    Serial.println("en surchaufe");
    Atterissage();  
  }
  else 
  {
    Serial.println("stable");
  }  
  
}



// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    // WARNING! DO NOT CONNECT THE PROPELLER UNDER TEST!
    brushlessMotor1_1.attach(BRUSHLESSMOTOR1_1_PIN_DATA);
    brushlessMotor1_1.writeMicroseconds(brushlessMotor1_1LowSpeed);
    // WARNING! DO NOT CONNECT THE PROPELLER UNDER TEST!
    brushlessMotor2_2.attach(BRUSHLESSMOTOR2_2_PIN_DATA);
    brushlessMotor2_2.writeMicroseconds(brushlessMotor2_2LowSpeed);
    // WARNING! DO NOT CONNECT THE PROPELLER UNDER TEST!
    brushlessMotor3_3.attach(BRUSHLESSMOTOR3_3_PIN_DATA);
    brushlessMotor3_3.writeMicroseconds(brushlessMotor3_3LowSpeed);
    // WARNING! DO NOT CONNECT THE PROPELLER UNDER TEST!
    brushlessMotor4_4.attach(BRUSHLESSMOTOR4_4_PIN_DATA);
    brushlessMotor4_4.writeMicroseconds(brushlessMotor4_4LowSpeed);
    IMU.begin();
   
    if(!IMU.gyroscopeAvailable())
    {
      Serial.println("Gyro not functionnal");
      exit(0);
    }
    if(!IMU.accelerationAvailable())
    {
      Serial.println("accelerometre not functionnal");
      exit(0);
    }
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    // DS18B20 1-Wire Temperature Sensor - Test Code
    // Read DS18B20 temp sensor value in degrees celsius. for degrees fahrenheit use ds18b20.ReadTempF()
    float ds18b20TempC = ds18b20.readTempC();
    Serial.print(F("Temp: ")); Serial.print(ds18b20TempC); Serial.println(F(" [C]"));
    //ajout dans la partie test du capteur de temperature afin de tester les fonctions de gestion d'actions lié à la temperature(exemple batterie en surchauffe == atterisage)
    tempGestion(ds18b20TempC);
//////////////////////////////////////////////////////////////////////////////
    // Ultrasonic Sensor - HC-SR04 - Test Code
    // Read distance measurment from UltraSonic sensor           
    int hcsr04Dist = hcsr04.ping_cm();
    delay(10);
    Serial.print(F("Distance: ")); Serial.print(hcsr04Dist); Serial.println(F("[cm]"));
    //ajout dans la partie test du capteur ultrasonic afin de tester les fonctions de gestion lié à l'altitude( decollage , atterissage ,sustentation)   
//////////////////////////////////////////////////////////////////////////////   
    // Disclaimer: The Accelerometer/Magnetometer/Gyroscope + Temp LSM9DS1 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
      fxa = 0;
      fya = 0;
      fza = 0;
      IMU.readGyroscope(x,y,z);
      IMU.readAcceleration(xa,ya,za);
      Serial.println("gyro");
      Serial.println(x);
      Serial.println(y);
      Serial.println(z);
      Serial.println("Acceleration");
      Serial.println(xa);
      Serial.println(ya);
      Serial.println(za);
      //filtre de fluctuation
      fxa = xa*a+(fxa*(1.0 - a));
      fya = ya*a+(fya*(1.0 - a));
      fza = za*a+(fza*(1.0 - a));
      //calculating roll pitch and yaw;
      roll = (atan2(fya,fza)*180.0)/M_PI;
      pitch = (atan2(-fxa , sqrt(fya*fya + fza*fza))*180.0)/M_PI;
      yaw = 180.0*atan(fza/sqrt(fxa*fxa+fza*fza))/M_PI;  
      
   
}


// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions


/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/
