#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stm32f0xx_hal.h"
//#include "main.h"

#define DEVICE_ADDRESS_ZERO 208
#define DEVICE_ADDRESS_ONE 209

uint8_t device_address = DEVICE_ADDRESS_ONE;



extern I2C_HandleTypeDef hi2c1;

// Abstraction library to interface with the MPU6050 over I2C

bool kl_MPU_DATA_Transmit(uint8_t* val) {
  if (HAL_I2C_Master_Transmit(&hi2c1, device_address, val, sizeof(val), HAL_MAX_DELAY) == HAL_OK) {
	  return true;
  } else {
	  return false;
  }
}

bool kl_MPU_DATA_Receive(uint8_t* val) {
  if (HAL_I2C_Master_Receive(&hi2c1, device_address, val, sizeof(val), HAL_MAX_DELAY) == HAL_OK) {
	  return true;
  } else {
	  return false;
  }
}

bool kl_MPU_MEM_Write(uint8_t reg, uint8_t* val) {
  if (HAL_I2C_Mem_Write(&hi2c1, device_address, reg, sizeof(reg), val, sizeof(val), HAL_MAX_DELAY) == HAL_OK) {
	  return true;
  } else {
	  return false;
  }
}

uint8_t* kl_MPU_MEM_READ(uint8_t reg, uint8_t* val) {
  if (HAL_I2C_Mem_Read(&hi2c1, device_address, reg, sizeof(reg), val, sizeof(val), HAL_MAX_DELAY)== HAL_OK) {
	  return val;
  } else {
	  return 0;
  }

}

void kl_MPU_Initialization() {

	uint8_t * val_ptr = (uint8_t*)malloc(sizeof(uint8_t));
	kl_MPU_MEM_READ(117, val_ptr );
	//kl_MPU_DATA_Receive(val_ptr);

}
