
/*
  For the JeVois camera.  Camera is configured for 9600 baud
    - http://jevois.org/doc/UserSerial.html
    - http://jevois.org/tutorials/UserArduinoBlink.html


*/

#include <Arduino.h>

#include "camera.h"

String str;

HardwareSerial &myCamera = Serial3;

void initCamera()
{
  myCamera.begin(115200);
  // myCamera.setTimeout(2000);
}

/*
  The camera serial stream is documented - http://jevois.org/doc/UserSerialStyle.html

  For our case, the camera cannot be in Terse mode because we want the item descriptor.
  Sample output:  N2 win.png -22297 -11881 43244 22800

  I should clear the buffer before reading 
  
  OUTPUT a text string describing what the reported object is, i.e. the second token
*/
char *readType()
{
  if ((str = recvString()) != NULL)
  {
    Serial.print("Received Data = <");
    Serial.print(str);   //display same received Data back in serial monitor.
    Serial.println(">"); //display same received Data back in serial monitor.
  }
  return NULL;
}

String recvString()
{

  str = myCamera.readStringUntil('\n'); // s1 is String type variable.

  return str;
}

void cameraFlush()
{
  while (myCamera.available() > 0)
  {
    myCamera.read();
  }
}