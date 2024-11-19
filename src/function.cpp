#include "header.h"
DHT dht(DhtPin, DhtType);
BH1750 lightMeter(0x23); // digunakan untuk mendefine bh1750
SemaphoreHandle_t sem;
void Temp(void *pvParameters)
{ // untuk menghitung temperatur dan menampilkan hasilnya
    while (1)
    {
        if (xSemaphoreTake(sem, portMAX_DELAY) == pdTRUE)
        {
            float temp = dht.readTemperature();
            Serial.print("Temperature: ");
            Serial.print(temp);
            Serial.print("°C\n");
            xSemaphoreGive(sem); // untuk memberikan semaphore
            vTaskDelay(4000);
        }
    }
}

void Hum(void *pvParameters)
{ // untuk menghitung kelembaban dan menampilkan hasilnya
    while (1)
    {
        if (xSemaphoreTake(sem, portMAX_DELAY) == pdTRUE)
        {
            float hum = dht.readHumidity();
            Serial.print("Humidity: ");
            Serial.print(hum);
            Serial.print(" RH\n");
            xSemaphoreGive(sem); // untuk memberikan semaphore
            vTaskDelay(3000);
        }
    }
}
void Light(void *pvParameters)
{ // untuk menghitung intensitas cahaya dan menampilkan hasilnya
    while (1)
    {
        if (xSemaphoreTake(sem, portMAX_DELAY) == pdTRUE)
        {
            float lux = lightMeter.readLightLevel();
            Serial.print("Light: ");
            Serial.print(lux);
            Serial.print(" lx\n");
            xSemaphoreGive(sem); // untuk memberikan semaphore
            vTaskDelay(3000);
        }
    }
}