#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "stm32f0xx_hal.h"

#define DEVICE_ADDRESS 208

extern I2C_HandleTypeDef hi2c1;

// Abstraction library to interface with the MPU6050 over I2C

bool kl_MPU_DATA_Transmit(uint8_t reg, uint8_t* val) {
  if (HAL_I2C_Master_Transmit(&hi2c1, reg, val, sizeof(val), HAL_MAX_DELAY) == HAL_OK) {
	  return 1;
  } else {
	  return 0;
  }
}

bool kl_MPU_DATA_Receive(uint8_t reg, uint8_t* val) {
  if (HAL_I2C_Master_Receive(&hi2c1, DEVICE_ADDRESS, val, sizeof(val), HAL_MAX_DELAY) == HAL_OK) {
	  return 1;
  } else {
	  return 0;
  }
}

bool kl_MPU_MEM_Write(uint8_t reg, uint8_t* val) {
  if (HAL_I2C_Mem_Write(&hi2c1, DEVICE_ADDRESS, reg, sizeof(reg), val, sizeof(val), HAL_MAX_DELAY) == HAL_OK) {
	  return true;
  } else {
	  return false;
  }
}

bool kl_MPU_MEM_READ(uint8_t reg, uint8_t* val) {
  if (HAL_I2C_Mem_Read(&hi2c1, DEVICE_ADDRESS, reg, sizeof(reg), val, sizeof(val), HAL_MAX_DELAY)== HAL_OK) {
	  return true;
  } else {
	  return false;
  }
}
