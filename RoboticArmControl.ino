#include <Servo.h>

// Create Servo objects
Servo base, shoulder, elbow, gripper;

// Define pins
const int basePin = 3;
const int shoulderPin = 5;
const int elbowPin = 6;
const int gripperPin = 9;

// Angle variable
int angle = 0;

void setup() {
  base.attach(basePin);
  shoulder.attach(shoulderPin);
  elbow.attach(elbowPin);
  gripper.attach(gripperPin);

  Serial.begin(9600);
  Serial.println("Robotic Arm Ready.");
  Serial.println("Select part: B (Base), S (Shoulder), E (Elbow), G (Gripper)");
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();

    switch (cmd) {
      case 'B':
        Serial.println("Moving Base...");
        moveServo(base, 0, 180);
        break;

      case 'S':
        Serial.println("Moving Shoulder...");
        moveServo(shoulder, 0, 180);
        break;

      case 'E':
        Serial.println("Moving Elbow...");
        moveServo(elbow, 0, 360);
        break;

      case 'G':
        Serial.println("Operating Gripper...");
        moveServo(gripper, 0, 90);
        break;

      default:
        Serial.println("Invalid command. Use B, S, E, or G.");
        break;
    }

    Serial.println("Ready for next command: B, S, E, or G");
  }
}

// Sweep servo from min to max and back
void moveServo(Servo &servo, int minAngle, int maxAngle) {
  for (angle = minAngle; angle <= maxAngle; angle += 5) {
    servo.write(angle);
    delay(20);
  }
  for (angle = maxAngle; angle >= minAngle; angle -= 5) {
    servo.write(angle);
    delay(20);
  }
}
