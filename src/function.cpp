#include "header.h"
// DHT dht(DhtPin, DhtType);
// BH1750 lightMeter(0x23); // digunakan untuk mendefine bh1750

void InitializeSensor()
{
    // Wire.begin();
    // dht.begin();
    // lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
    Serial.println("begin");
}

void Temp(void *pvParameters)
{ // untuk menghitung temperatur dan menampilkan hasilnya
    while (1)
    {
        Serial.println("hello from ESP");

        vTaskDelay(pdMS_TO_TICKS(500));
        // delay(500);
        // if (xSemaphoreTake(sem, portMAX_DELAY) == pdTRUE)
        // {
        //     Serial.print("30.25°C,");
        //     xSemaphoreGive(sem); // untuk memberikan semaphore
        //     vTaskDelay(pdMS_TO_TICKS(1000));
        //     // Serial.println("succesfuly giving sema");
        //     // Serial.println("receive sema");
        //     // float temp = dht.readTemperature();
        //     // Serial.print("Temperature: ");
        //     // Serial.print(temp);
        //     // Serial.print("°C\n");
        // }
    }
}

void Hum(void *pvParameters)
{                            // untuk menghitung kelembaban dan menampilkan hasilnya
    String inputString = ""; // String to hold incoming data
    while (1)
    {
        if (Serial.available() > 0)
        {
            inputString = Serial.readStringUntil('\n');
            Serial.print("Received string: ");
            Serial.println(inputString);
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
// void Light(void *pvParameters)
// { // untuk menghitung intensitas cahaya dan menampilkan hasilnya
//     while (1)
//     {
//         if (xSemaphoreTake(sem, portMAX_DELAY) == pdTRUE)
//         {
//             Serial.println("5000 lx");
//             xSemaphoreGive(sem); // untuk memberikan semaphore
//             vTaskDelay(pdMS_TO_TICKS(1000));
//             // float lux = lightMeter.readLightLevel();
//             // Serial.print("Light: ");
//             // Serial.print(lux);
//             // Serial.print("succesfuly giving sema");
//         }
//     }
// }

void readBlocking()
{
    String inputString = "";
    if (Serial.available() > 0)
    {
        inputString = Serial.readStringUntil('\n');
        Serial.print("Received string");
        Serial.println(inputString);
    }
    delay(500);
}
void writeBlocking()
{
    Serial.println("hello from ESP");
}