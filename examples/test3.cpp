// --- NOVA COMPILER: HIGH-PERFORMANCE ESP32 ENGINE ---
// Features: FreeRTOS Multi-Threading, Non-Blocking Delays, Semantic Normalization
#include <Arduino.h>

const int MotorA_PIN = 18;
const int MotorB_PIN = 19;
float CycleCount = 0;

void NovaTask_1(void *pvParameters) {
    for(;;) {
        if (CycleCount < 5) {
            Serial.println("PLC Sequence Running...");
            digitalWrite(MotorA_PIN, HIGH);
            vTaskDelay(1000 / portTICK_PERIOD_MS); // Non-blocking wait
            digitalWrite(MotorA_PIN, LOW);
            digitalWrite(MotorB_PIN, HIGH);
            vTaskDelay(1000 / portTICK_PERIOD_MS); // Non-blocking wait
            digitalWrite(MotorB_PIN, LOW);
            CycleCount = CycleCount + 1;
            Serial.println(CycleCount);
        }
        else {
            Serial.println("PLC Sequence Complete. System Halting.");
            vTaskDelay(5000 / portTICK_PERIOD_MS); // Non-blocking wait
        }
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(MotorA_PIN, OUTPUT);
    pinMode(MotorB_PIN, OUTPUT);

    // Launching Optimized Multi-Core Tasks
    xTaskCreatePinnedToCore(NovaTask_1, "NovaTask_1", 4096, NULL, 1, NULL, 0);
}

void loop() {
    vTaskDelete(NULL); // Optimizer: Free up default loop task memory
}