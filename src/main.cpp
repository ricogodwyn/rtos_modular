// #include <Arduino.h> //untuk mendefine library arduino
// #include <Wire.h>
// #include <BH1750.h>
// #include <DHT.h>
// #include <Adafruit_Sensor.h>
#include "header.h"
// digunakan untuk mendefine semaphore, semaphore digunakan untuk memberi tahu bahwa task sudah selesai ke task yang lain
TaskHandle_t tempTaskHandle = NULL; // digunakan untuk mendefine task handle
TaskHandle_t humTaskHandle = NULL;
TaskHandle_t lightTaskHandle = NULL;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  dht.begin();
  sem = xSemaphoreCreateBinary(); // untuk membuat semaphore
  lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);

  xTaskCreatePinnedToCore(Temp, "Temp", configMINIMAL_STACK_SIZE + 1024, NULL, 1, &tempTaskHandle, 0); // untuk membuat task
  xTaskCreatePinnedToCore(Hum, "Hum", configMINIMAL_STACK_SIZE + 1024, NULL, 1, &humTaskHandle, 0);    // rtos digunakan untuk membuat task yang berjalan secara paralel
  xTaskCreatePinnedToCore(Light, "Light", configMINIMAL_STACK_SIZE + 1024, NULL, 1, &lightTaskHandle, 1);
}

void loop()
{
}