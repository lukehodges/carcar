#include "DeviceDriverSet_xxx0_LineTracking.h"

class LineTrackingControl {
private:
    DeviceDriverSet_ITR20001 lineTrackingSensor;

public:
    LineTrackingControl() {
        lineTrackingSensor.DeviceDriverSet_ITR20001_Init();
    }

    struct SensorReadings {
        float left;
        float middle;
        float right;
    };

    SensorReadings readSensors() {
        SensorReadings readings;
        readings.left = lineTrackingSensor.DeviceDriverSet_ITR20001_getAnaloguexxx_L();
        readings.middle = lineTrackingSensor.DeviceDriverSet_ITR20001_getAnaloguexxx_M();
        readings.right = lineTrackingSensor.DeviceDriverSet_ITR20001_getAnaloguexxx_R();
        return readings;
    }

    bool isOnLine(float threshold = 500) {
        SensorReadings readings = readSensors();
        return (readings.left > threshold || readings.middle > threshold || readings.right > threshold);
    }

    enum LinePosition {
        LEFT,
        CENTER,
        RIGHT,
        UNKNOWN
    };

    LinePosition getLinePosition(float threshold = 500) {
        SensorReadings readings = readSensors();
        
        if (readings.middle > threshold) {
            return CENTER;
        } else if (readings.left > threshold) {
            return LEFT;
        } else if (readings.right > threshold) {
            return RIGHT;
        } else {
            return UNKNOWN;
        }
    }
};

// Global instance of LineTrackingControl
LineTrackingControl lineTracker;