#include "Arduino.h"
#include "CarControl.h" // Assume the wrapper is in a file named CarControl.h
#include "UltraSonic.h"
#include "ServoControl.h"
ServoControlWrapper servoControl;
// car.command 
// ultrasonicSensor.command
// servoControl.command
void setup() {
    delay(1000);
    servoControl.center();
    servoControl.sweep(0,180);
//     for (int i = 0; i < 180;i+=15){
//         servoControl.setAngle(i);
//     }
// }
}
void loop(){
}


// what is 180 divided by 400 degrees 