/*
========================================
Project Title:
Arduino Flame Sensor with Buzzer Alert

Description:
This beginner-friendly project uses a flame sensor to detect fire.
When a flame is detected, a buzzer will sound as an alert.
Perfect for basic fire detection and safety system projects.

Components List:
- Arduino Uno (or compatible)
- Flame Sensor Module (KY-026 or similar)
- Buzzer (Active Buzzer recommended)
- Jumper Wires
- Breadboard (optional)

Wiring:
Flame Sensor:
- VCC  -> 5V
- GND  -> GND
- DO   -> Pin 2

Buzzer:
- (+)  -> Pin 8
- (-)  -> GND

Notes:
- Flame sensor gives LOW signal when flame is detected
- Adjust sensitivity using potentiometer on the sensor module
========================================
*/

#define FLAME_PIN 2
#define BUZZER_PIN 8

void setup() {
  pinMode(FLAME_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Flame Sensor Test Started...");
}

void loop() {
  int flameState = digitalRead(FLAME_PIN);

  if (flameState == LOW) {
    // Flame detected
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("Flame Detected!");
  } else {
    // No flame
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("No Flame");
  }

  delay(200);
}