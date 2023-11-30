// stepper_motor.c

#include "stepper_motor.h"

// Initialize GPIO pins used for stepper motor
void stepperMotorInit(void) {

     HAL_GPIO_Init(STEP_GPIO_PORT, &GPIO_InitStruct);
     HAL_GPIO_Init(DIR_GPIO_PORT, &GPIO_InitStruct);

}

//move the stepper motor in a direction for a certain number of steps
void moveStepperMotor(StepperDirection direction, uint16_t steps) {

    // Set DIR pin according to the specified direction
     HAL_GPIO_WritePin(DIR_GPIO_PORT, DIR_GPIO_PIN, (direction == CLOCKWISE) ? GPIO_PIN_SET : GPIO_PIN_RESET);
     for (uint16_t i = 0; i < steps; i++) {
         // Generate step pulses (toggle STEP pin)
         HAL_GPIO_WritePin(STEP_GPIO_PORT, STEP_GPIO_PIN, GPIO_PIN_SET);
         HAL_Delay(DELAY_BETWEEN_STEPS); // so it doesn't go to quick
         HAL_GPIO_WritePin(STEP_GPIO_PORT, STEP_GPIO_PIN, GPIO_PIN_RESET);
         HAL_Delay(DELAY_BETWEEN_STEPS);
     }
}
