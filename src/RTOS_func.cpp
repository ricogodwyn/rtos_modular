#include "header.h"
#include <arduino.h>

SemaphoreHandle_t sem;
TaskHandle_t tempTaskHandle = NULL; // digunakan untuk mendefine task handle
TaskHandle_t humTaskHandle = NULL;
TaskHandle_t lightTaskHandle = NULL;

void InitializeRTOS()
{
    sem = xSemaphoreCreateMutex();                                            // untuk membuat semaphore
    xTaskCreatePinnedToCore(Temp, "Temp", 1024, NULL, 1, &tempTaskHandle, 0); // untuk membuat task
    xTaskCreatePinnedToCore(Hum, "Hum", 1024, NULL, 1, &humTaskHandle, 0);    // rtos digunakan untuk membuat task yang berjalan secara paralel
    // xTaskCreatePinnedToCore(Light, "Light", 1024, NULL, 1, &lightTaskHandle, 1);
    Serial.println("begin");
    if (sem == NULL)
    {
        Serial.println("Failed to create semaphore");
    }
    // if (tempTaskHandle == NULL || humTaskHandle == NULL || lightTaskHandle == NULL)
    // {
    //     Serial.println("Failed to create one or more tasks");
    // }
}