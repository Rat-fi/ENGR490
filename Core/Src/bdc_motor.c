// BDC_motor.c

#include "BDC_motor.h"
#include "stm32g0xx_hal.h"


void BDCMotorInit(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    //enable a clock for motor control (see if we need later)
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // Configure GPIO pins for IN1/PH and IN2/EN (we may need to change depending on final config of the board)
    GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void setBDCMotorDirection(BDCMotorDirection direction) {

     if (direction == FORWARD) {
    	 // Set IN1/PH and IN2/EN for forward direction
         HAL_GPIO_WritePin(IN1_PH_GPIO_PORT, IN1_PH_GPIO_PIN, GPIO_PIN_SET);
         HAL_GPIO_WritePin(IN2_EN_GPIO_PORT, IN2_EN_GPIO_PIN, GPIO_PIN_RESET);
     } else {
    	 // Set IN1/PH and IN2/EN for reverse direction
         HAL_GPIO_WritePin(IN1_PH_GPIO_PORT, IN1_PH_GPIO_PIN, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(IN2_EN_GPIO_PORT, IN2_EN_GPIO_PIN, GPIO_PIN_SET);
     }

}

// Function to start the BDC motor
void startBDCMotor(void) {

     HAL_GPIO_WritePin(MODE_GPIO_PORT, MODE_GPIO_PIN, GPIO_PIN_SET); // Set MODE pin (if needed)
     HAL_GPIO_WritePin(SLEEP_GPIO_PORT, SLEEP_GPIO_PIN, GPIO_PIN_SET); // Wake up the driver from sleep mode

}

// Function to stop the BDC motor
void stopBDCMotor(void) {

     HAL_GPIO_WritePin(SLEEP_GPIO_PORT, SLEEP_GPIO_PIN, GPIO_PIN_RESET); // Put the driver in sleep mode

}

