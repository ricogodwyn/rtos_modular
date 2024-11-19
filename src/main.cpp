// #include <Arduino.h> //untuk mendefine library arduino
// #include <Wire.h>
// #include <BH1750.h>
// #include <DHT.h>
// #include <Adafruit_Sensor.h>
#include "header.h"
// digunakan untuk mendefine semaphore, semaphore digunakan untuk memberi tahu bahwa task sudah selesai ke task yang lain
void setup()
{
  Serial.begin(9600);
  InitializeSensor();
  InitializeRTOS();
}

void loop()
{
}