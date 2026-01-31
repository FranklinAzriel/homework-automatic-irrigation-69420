#include <Arduino.h>

const int MOISTURE_SENSOR_PIN = A0; 
const int PUMP_RELAY_PIN = 8;       
const int STATUS_LED_PIN = 13;      

const int DRY_THRESHOLD = 550;      
String currentMode = "AUTO"; 

void setup() {
    Serial.begin(9600);
    pinMode(PUMP_RELAY_PIN, OUTPUT);
    pinMode(STATUS_LED_PIN, OUTPUT);
    
    digitalWrite(PUMP_RELAY_PIN, HIGH); 
    digitalWrite(STATUS_LED_PIN, HIGH); 
    
    Serial.println("\n[SYSTEM] Hybrid Logger Online. Ready for commands: ON, OFF, AUTO\n");
}

void loop() {
    // 1. Command Handling
    if (Serial.available() > 0) {
        String input = Serial.readStringUntil('\n');
        input.trim();
        input.toUpperCase();
        if (input == "ON") currentMode = "MANUAL_ON";
        else if (input == "OFF") currentMode = "MANUAL_OFF";
        else if (input == "AUTO") currentMode = "AUTO";
    }

    // 2. Data Logic
    int sensorValue = analogRead(MOISTURE_SENSOR_PIN);
    String pumpStatus;

    if (currentMode == "MANUAL_ON") {
        pumpStatus = "RUNNING";
        digitalWrite(PUMP_RELAY_PIN, LOW);
        digitalWrite(STATUS_LED_PIN, !digitalRead(STATUS_LED_PIN));
        delay(100);
    } 
    else if (currentMode == "MANUAL_OFF") {
        pumpStatus = "LOCKED";
        digitalWrite(PUMP_RELAY_PIN, HIGH);
        digitalWrite(STATUS_LED_PIN, LOW);
        delay(1000);
    } 
    else {
        if (sensorValue > DRY_THRESHOLD) {
            pumpStatus = "WATERING";
            digitalWrite(PUMP_RELAY_PIN, LOW);
            digitalWrite(STATUS_LED_PIN, HIGH);
            delay(200); digitalWrite(STATUS_LED_PIN, LOW); delay(200);
        } else {
            pumpStatus = "STANDBY";
            digitalWrite(PUMP_RELAY_PIN, HIGH);
            digitalWrite(STATUS_LED_PIN, HIGH);
            delay(1000);
        }
    }

    // 3. HYBRID LOGGING
    
    // A. THE JSON (Machine Readable - Hidden with prefix)
    Serial.print("JSON:{\"mode\":\""); Serial.print(currentMode);
    Serial.print("\",\"raw\":"); Serial.print(sensorValue);
    Serial.print(",\"pump\":\""); Serial.print(pumpStatus);
    Serial.println("\"}");

    // B. THE DASHBOARD (Human Readable - Beautiful)
    Serial.print(">>> ["); Serial.print(currentMode); Serial.print("]");
    Serial.print(" Moisture: "); Serial.print(sensorValue);
    if (pumpStatus == "WATERING" || pumpStatus == "RUNNING") {
        Serial.println(" | PUMP: ACTIVE  🌊");
    } else {
        Serial.println(" | PUMP: SLEEPING 💤");
    }
}