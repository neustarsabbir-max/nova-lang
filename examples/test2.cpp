// --- NOVA COMPILER: HIGH-PERFORMANCE ESP32 ENGINE ---
// Features: FreeRTOS Multi-Threading, Non-Blocking Delays, Semantic Normalization
#include <Arduino.h>
#include <DHT.h>

DHT dht22_obj(15, DHT22);

void NovaTask_1(void *pvParameters) {
    for(;;) {
        float RoomTemp = dht22_obj.readTemperature();
        float HeatIndex = RoomTemp + 5.5;
        Serial.println(HeatIndex);
        vTaskDelay(2000 / portTICK_PERIOD_MS); // Non-blocking wait
    }
}

void setup() {
    Serial.begin(115200);
    dht22_obj.begin();

    // Launching Optimized Multi-Core Tasks
    xTaskCreatePinnedToCore(NovaTask_1, "NovaTask_1", 4096, NULL, 1, NULL, 0);
}

void loop() {
    vTaskDelete(NULL); // Optimizer: Free up default loop task memory
}