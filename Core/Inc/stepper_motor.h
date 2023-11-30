// stepper_motor.h

#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <stdint.h> // Include necessary headers for data types if needed

// Enumeration for stepper motor direction
typedef enum {
    CLOCKWISE,
    COUNTER_CLOCKWISE
} StepperDirection;

// Function prototypes
void stepperMotorInit(void);
void moveStepperMotor(StepperDirection direction, uint16_t steps);

// Other declarations related to the stepper motor control

#endif /* STEPPER_MOTOR_H */
