/* ***************************************************************************************
    System to sort brass by headstamp - Demo

    Demonstration of the basic components to sort brass by headstamp include:
    - Stepper motor to move cases along a track
    - Camera interface (JeVois) to identify headstamps
    - Servo to move gates to sort selected items

    Components
    - Arduino Mega
    - Stepper Motor and controller
    - JeVois camera
    - Servo
    - LCD -  http://wiki.sunfounder.cc/index.php?title=I2C_LCD2004#Step_2:Add_library

 ***************************************************************************************** */
#include <Arduino.h>
#include "camera.h"

void setup()
{
  // Initialize the Serial and LCD interfaces for status messages
  // Do this first so we can see what is going on
  Serial.begin(9600);

  // Initialize Serial interface for Camera messages
  Serial.println("Initialize Camera");

  initCamera();
}

char *type_p; // Pointer to a string that is the name of the object seen by the camera

void loop()
{
  // Read the camera and see what type of case we have
  if ((type_p = readType()) != NULL)
  {
    // Serial.print("Read Case Type - ");
    // Serial.println(type_p);
  }

  cameraFlush();
}
