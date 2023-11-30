// bdc_motor.h

#ifndef BDC_MOTOR_H
#define BDC_MOTOR_H

#include <stdint.h> // Include necessary headers for data types if needed

// Enumeration for BDC motor direction
typedef enum {
    FORWARD,
    REVERSE
} BDCMotorDirection;

// Function prototypes
void bdcMotorInit(void);
void setBDCMotorDirection(BDCMotorDirection direction);
void startBDCMotor(void);
void stopBDCMotor(void);

// Other declarations related to BDC motor control

#endif /* BDC_MOTOR_H */
