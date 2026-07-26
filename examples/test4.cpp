// --- NOVA COMPILER: HIGH-PERFORMANCE ESP32 ENGINE ---
// Features: FreeRTOS Multi-Threading, Non-Blocking Delays, Semantic Normalization
#include <Arduino.h>

const int RelayLock_PIN = 5;
const int AlarmBuzzer_PIN = 21;
String MasterPass = "7321";
String UserInput = "7321";
float Attempts = 0;

void CheckLock() {
    if (UserInput == MasterPass) {
        Serial.println("Vault Unlocked!");
        digitalWrite(RelayLock_PIN, HIGH);
        Attempts = 0;
    }
    else {
        Serial.println("Access Denied!");
        digitalWrite(AlarmBuzzer_PIN, HIGH);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Non-blocking wait
        digitalWrite(AlarmBuzzer_PIN, LOW);
        Attempts = Attempts + 1;
    }
}

void NovaTask_1(void *pvParameters) {
    for(;;) {
        if (Attempts > 3) {
            Serial.println("System Locked! Intruder Alert!");
            digitalWrite(AlarmBuzzer_PIN, HIGH);
            vTaskDelay(10000 / portTICK_PERIOD_MS); // Non-blocking wait
        }
        else {
            CheckLock();
            vTaskDelay(2000 / portTICK_PERIOD_MS); // Non-blocking wait
        }
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(RelayLock_PIN, OUTPUT);
    pinMode(AlarmBuzzer_PIN, OUTPUT);

    // Launching Optimized Multi-Core Tasks
    xTaskCreatePinnedToCore(NovaTask_1, "NovaTask_1", 4096, NULL, 1, NULL, 0);
}

void loop() {
    vTaskDelete(NULL); // Optimizer: Free up default loop task memory
}