#include "Arduino.h"
#include "CarControl.h" // Assume the wrapper is in a file named CarControl.h
#include "UltraSonic.h"
#include "ServoControl.h"

// Create objects for controlling the car, ultrasonic sensor, and servo

ServoControlWrapper servoControl;

void setup() {
    car.setSpeed(50);
    // Initialize the servo and set the initial angle to a forward-facing position
    servoControl.init();
    servoControl.setAngle(90);  // Assume 90 is the forward-facing direction

    // Initialize the car system (could involve setting pins or initial configurations)
}

void loop() {


}
