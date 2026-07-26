// --- NOVA COMPILER: HIGH-PERFORMANCE ESP32 ENGINE ---
// Features: FreeRTOS Multi-Threading, Non-Blocking Delays, Semantic Normalization
#include <Arduino.h>

const int AlarmLED_PIN = 2;
const int PanicButton_PIN = 4;

void IRAM_ATTR ISR_PanicButton() {
    Serial.println("Emergency Mode Activated!");
    digitalWrite(AlarmLED_PIN, HIGH);
}

void NovaTask_1(void *pvParameters) {
    for(;;) {
        for(int i = 0; i < 5; i++) {
            digitalWrite(AlarmLED_PIN, HIGH);
            vTaskDelay(100 / portTICK_PERIOD_MS); // Non-blocking wait
            digitalWrite(AlarmLED_PIN, LOW);
            vTaskDelay(100 / portTICK_PERIOD_MS); // Non-blocking wait
        }
        vTaskDelay(5000 / portTICK_PERIOD_MS); // Non-blocking wait
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(AlarmLED_PIN, OUTPUT);
    pinMode(PanicButton_PIN, OUTPUT);
    pinMode(PanicButton_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(PanicButton_PIN), ISR_PanicButton, RISING);

    // Launching Optimized Multi-Core Tasks
    xTaskCreatePinnedToCore(NovaTask_1, "NovaTask_1", 4096, NULL, 1, NULL, 0);
}

void loop() {
    vTaskDelete(NULL); // Optimizer: Free up default loop task memory
}