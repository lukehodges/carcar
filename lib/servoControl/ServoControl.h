
#include "Arduino.h"
#include <avr/wdt.h>
#include "DeviceDriverSet_xxx0_ServoControl.h"
#include <arduino.h>
#include "math.h"
class ServoControlWrapper {
private:
    Servo myservo;
    int currentAngle;
    
    long timer = 350;

public:
    // Initialize the servo with a specific angle (defaults to center position)
    void init(unsigned int initialAngle = 90) {
        myservo.attach(PIN_Servo_z, 500, 2400);
        setAngle(initialAngle);
    }

    // Sweep the servo between two angles
    void sweep(int startAngle = 0, int endAngle = 180, int delayTime = 500) {
        float time = fabs((delayTime/1000)/(startAngle - endAngle));
        for (int angle = startAngle; angle <= endAngle; angle+=5) {
            setAngle(angle);
            delay(max(time,timer));
        }
        for (int angle = endAngle; angle >= startAngle; angle-=5) {
            setAngle(angle);
            delay(max(time,timer));
        }
    }

    // Set the servo to the center (90 degrees)
    void center() {
        setAngle(90);
    }

    // Get the current angle of the servo
    int getAngle() const {
        return currentAngle;
    }

    // Set the servo to a specific angle
    void setAngle(unsigned int Position_angle) {
        myservo.attach(PIN_Servo_z);
        myservo.write(Position_angle);
        delay(timer); // Optional: time for the servo to move
        currentAngle = Position_angle;
        myservo.detach();
    }

};
