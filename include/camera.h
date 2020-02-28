#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

/*
   Functions to handle the JeVois camera
*/

#define DEBUG  // Debug messages to the Serial Port
#define DEBUG1 // Debug messages to the Serial Port

void initCamera(); // Initialize the camera
char *readType();  // Return the image identifier from the camera

String recvString();
void cameraFlush();

#endif