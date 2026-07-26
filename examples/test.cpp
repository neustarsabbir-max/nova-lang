// --- NOVA COMPILER: HIGH-PERFORMANCE ESP32 ENGINE ---
// Features: FreeRTOS Multi-Threading, Non-Blocking Delays, Semantic Normalization
#include <Arduino.h>

const int StatusLED_PIN = 2;

void NovaTask_1(void *pvParameters) {
    for(;;) {
        for(int i = 0; i < 3; i++) {
            digitalWrite(StatusLED_PIN, HIGH);
            vTaskDelay(200 / portTICK_PERIOD_MS); // Non-blocking wait
            digitalWrite(StatusLED_PIN, LOW);
            vTaskDelay(200 / portTICK_PERIOD_MS); // Non-blocking wait
        }
        vTaskDelay(2000 / portTICK_PERIOD_MS); // Non-blocking wait
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(StatusLED_PIN, OUTPUT);

    // Launching Optimized Multi-Core Tasks
    xTaskCreatePinnedToCore(NovaTask_1, "NovaTask_1", 4096, NULL, 1, NULL, 0);
}

void loop() {
    vTaskDelete(NULL); // Optimizer: Free up default loop task memory
}