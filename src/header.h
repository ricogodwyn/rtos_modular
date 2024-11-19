#ifndef HEADER_H
#define HEADER_H
#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <BH1750.h>

#define DhtPin 5      // digunakan untuk mendefine pin yang digunakan untuk sensor DHT11
#define DhtType DHT11 // digunakan untuk mendefine tipe sensor DHT11
extern DHT dht;
extern BH1750 lightMeter; // digunakan untuk mendefine bh1750

extern SemaphoreHandle_t sem;
void InitializeSensor();
void InitializeRTOS();
void Temp(void *pvParameters);
void Hum(void *pvParameters);
void Light(void *pvParameters);

#endif