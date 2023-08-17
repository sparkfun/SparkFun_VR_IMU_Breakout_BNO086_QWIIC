/*
  Using the BNO08x IMU

  This example shows how to output the i/j/k/real parts of the rotation vector.
  https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation
  
  Note that this is a modified example which comments out unnecessary Serial Prints
  so that we can simply output the comma separated values of the rotation vector
  for the Processing demo "Serial_Cube_Rotate.pde".

  By: Nathan Seidle
  SparkFun Electronics
  Date: December 21st, 2017
  SparkFun code, firmware, and software is released under the MIT License.
	Please see LICENSE.md for further details.

  Originally written by Nathan Seidle @ SparkFun Electronics, December 28th, 2017

  Adjusted by Pete Lewis @ SparkFun Electronics, June 2023 to incorporate the
  CEVA Sensor Hub Driver, found here:
  https://github.com/ceva-dsp/sh2

  Also, utilizing code from the Adafruit BNO08x Arduino Library by Bryan Siepert
  for Adafruit Industries. Found here:
  https://github.com/adafruit/Adafruit_BNO08x

  Also, utilizing I2C and SPI read/write functions and code from the Adafruit
  BusIO library found here:
  https://github.com/adafruit/Adafruit_BusIO

  Hardware Connections:
  Plug the sensor into IoT RedBoard via QWIIC cable.
  Serial.print it out at 115200 baud to serial monitor.

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/22857
*/

#include <Wire.h>

#include "SparkFun_BNO08x_Arduino_Library.h"  // Click here to get the library: http://librarymanager/All#SparkFun_BNO08x
BNO08x myIMU;

void setup() {
  Serial.begin(9600); //115200 baud seems to be too much for Processing?... 9600 baud seems better
  //Serial.println();
  //Serial.println("BNO08x Read Example");

  Wire.begin();

  if (myIMU.begin() == false) {
    //Serial.println("BNO08x not detected at default I2C address. Check your jumpers and the hookup guide. Freezing...");
    while (1)
      ;
  }
  //Serial.println("BNO08x found!");

  // Wire.setClock(400000); //Increase I2C data rate to 400kHz

  setReports();

  //Serial.println("Reading events");
  delay(100);
}

// Here is where you define the sensor outputs you want to receive
void setReports(void) {
  //Serial.println("Setting desired reports");
  if (myIMU.enableRotationVector() == true) {
    //Serial.println(F("Rotation vector enabled"));
    //Serial.println(F("Output in form i, j, k, real, accuracy"));
  } else {
    //Serial.println("Could not enable rotation vector");
  }
}

void loop() {
  delay(10);

  if (myIMU.wasReset()) {
    //Serial.print("sensor was reset ");
    setReports();
  }

  // Has a new event come in on the Sensor Hub Bus?
  if (myIMU.getSensorEvent() == true) {

    // is it the correct sensor data we want?
    if (myIMU.getSensorEventID() == SENSOR_REPORTID_ROTATION_VECTOR) {

      float quatI = myIMU.getQuatI();
      float quatJ = myIMU.getQuatJ();
      float quatK = myIMU.getQuatK();
      float quatReal = myIMU.getQuatReal();
      float quatRadianAccuracy = myIMU.getQuatRadianAccuracy();

      
      Serial.print(quatReal, 2);  //<==move these two lines of code 
      Serial.print(F(","));       //   for Processing
      Serial.print(quatI, 2);
      Serial.print(F(","));
      Serial.print(quatJ, 2);
      Serial.print(F(","));
      Serial.print(quatK, 2);
      // Serial.print(F(","));
      //Serial.print(quatRadianAccuracy, 2);

      Serial.println();
    }
  }
}
