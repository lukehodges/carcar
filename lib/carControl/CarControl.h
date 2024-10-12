#include "DeviceDriverSet_xxx0_MotorControl.h"
#include "ApplicationFunctionSet_xxx0_MotorControl.cpp"
class CarControl {
private:
    uint8_t currentSpeed;

    void setMotion(SmartRobotCarMotionControl direction) {
        ApplicationFunctionSet_SmartRobotCarMotionControl(direction, currentSpeed);
    }

public:
    CarControl() : currentSpeed(100) {} // Default speed set to 100

    void forward() {
        setMotion(Forward);
    }

    void backward() {
        setMotion(Backward);
    }

    void left() {
        setMotion(Left);
    }

    void right() {
        setMotion(Right);
    }

    void leftForward() {
        setMotion(LeftForward);
    }

    void rightForward() {
        setMotion(RightForward);
    }

    void leftBackward() {
        setMotion(LeftBackward);
    }

    void rightBackward() {
        setMotion(RightBackward);
    }

    void stop() {
        setMotion(stop_it);
    }

    void setSpeed(uint8_t speed) {
        if (speed > 255) speed = 255;
        currentSpeed = speed;
    }

    uint8_t getSpeed() const {
        return currentSpeed;
    }
};

// Global instance of CarControl
CarControl car;