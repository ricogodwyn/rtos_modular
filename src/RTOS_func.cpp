#include "header.h"
#include <arduino.h>

SemaphoreHandle_t sem;
TaskHandle_t tempTaskHandle = NULL; // digunakan untuk mendefine task handle
TaskHandle_t humTaskHandle = NULL;
TaskHandle_t lightTaskHandle = NULL;
void InitializeRTOS()
{
    sem = xSemaphoreCreateBinary();                                                                      // untuk membuat semaphore
    xTaskCreatePinnedToCore(Temp, "Temp", configMINIMAL_STACK_SIZE + 1024, NULL, 1, &tempTaskHandle, 0); // untuk membuat task
    xTaskCreatePinnedToCore(Hum, "Hum", configMINIMAL_STACK_SIZE + 1024, NULL, 1, &humTaskHandle, 0);    // rtos digunakan untuk membuat task yang berjalan secara paralel
    xTaskCreatePinnedToCore(Light, "Light", configMINIMAL_STACK_SIZE + 1024, NULL, 1, &lightTaskHandle, 1);
}