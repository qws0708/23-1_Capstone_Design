#include <Servo.h>    // Servo library

Servo microServo;    // Servo object
const int servoPin = 3;    // Servo control pin

void setup() {
  Serial.begin(115200);
  microServo.attach(servoPin);    // Initialize the servo motor
}

void loop() {
  if (Serial.available() > 0) {    // Check if data is available in the serial buffer
    int angle = Serial.parseInt();    // Read the angle value from the serial monitor

    if (angle >= 0 && angle <= 180) {    // Check if the angle is within the valid range
      microServo.write(angle);    // Set the servo motor to the desired angle
      Serial.print("Moved to angle: ");
      Serial.println(angle);
    }
    else {
      Serial.println("Invalid angle. Please enter a value between 0 and 180.");
    }

    while (Serial.available()) {
      Serial.read();    // Clear any remaining characters in the serial buffer
    }
  }
}
