#include "DeviceDriverSet_xxx0_UltrasonicSensor.h"
#include <avr/wdt.h>
class UltrasonicSensorControl {
private:
    DeviceDriverSet_ULTRASONIC ultrasonicSensor;

public:
    UltrasonicSensorControl() {
        ultrasonicSensor.DeviceDriverSet_ULTRASONIC_Init();
    }

    unsigned int getDistance() {
        return ultrasonicSensor.DeviceDriverSet_ULTRASONIC_Get();
    }

    bool isObstacleDetected(unsigned int threshold) {
        return getDistance() < threshold;
    }

    // Helper method to convert distance to inches
    float getDistanceInches() {
        return getDistance() / 2.54; // Convert cm to inches
    }

    // Method to perform multiple readings and return average
    unsigned int getAverageDistance(int numReadings = 5, unsigned int delayBetweenReadings = 10) {
        unsigned long total = 0;
        for (int i = 0; i < numReadings; i++) {
            total += getDistance();
            delay(delayBetweenReadings);
        }
        return total / numReadings;
    }
};

// Global instance of UltrasonicSensorControl
UltrasonicSensorControl ultrasonicSensor;