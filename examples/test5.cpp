// --- NOVA COMPILER: HIGH-PERFORMANCE ESP32 ENGINE ---
// Features: FreeRTOS Multi-Threading, Universal Library Support
#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const int WiFiLED_PIN = 2;
WebServer server(80);

void StartFakeAP() {
    WiFi.softAP("Free_Public_WiFi", "");
    Serial.println("Evil Twin Access Point Started!");
    digitalWrite(WiFiLED_PIN, HIGH);
}

void NovaTask_1(void *pvParameters) {
    for(;;) {
        StartFakeAP();
        server.handleClient();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(WiFiLED_PIN, OUTPUT);

    // Launching Optimized Multi-Core Tasks
    xTaskCreatePinnedToCore(NovaTask_1, "NovaTask_1", 4096, NULL, 1, NULL, 0);
}

void loop() {
    vTaskDelete(NULL); // Optimizer: Free up default loop task memory
}