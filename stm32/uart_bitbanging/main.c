/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "kl_helper.h"

void SystemClock_Config(void);
uint8_t high_or_low = 0;

uint8_t bit_index = 0;
char* input_char = "a";
char output_byte[9];
char* output_byte_string = &output_byte[0];

int main(void)
{

  HAL_Init();
  SystemClock_Config();


  RCC->AHBENR |= RCC_AHBENR_GPIOCEN;

  // GPIO
  // LED Output:
  // Mode Register

  RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
  // Mode Register
  GPIOC->MODER	|= GPIO_MODER_MODER6_0;
  GPIOC->MODER &~ GPIO_MODER_MODER6_1;
  // Output Type
  GPIOC->OTYPER &~ GPIO_OTYPER_OT_6;
  // Speed
  GPIOC->OSPEEDR &~ GPIO_OSPEEDER_OSPEEDR6_0;

  // pull up pull down
  GPIOC->PUPDR &~ GPIO_PUPDR_PUPDR6_0;
  GPIOC->PUPDR &~ GPIO_PUPDR_PUPDR6_1;

  // GPIOC->BSRR |= GPIO_BSRR_BS_6;

  //Set Button Pins to input mode:
  GPIOC->MODER &~ GPIO_MODER_MODER7_0;
  GPIOC->MODER &~ GPIO_MODER_MODER7_1;

  // Output Type Register
  // This register allows you to tell the MCU if the I/O type should be push-pull or open-drain types on this pin
  GPIOC->OTYPER &~ GPIO_OTYPER_OT_7;

  // Output Speed Register
  // This register allows you to tell the MCU if the output speed should be low, medium or high on this pin
  GPIOC->OSPEEDR &~ GPIO_OSPEEDER_OSPEEDR7_0;

  // Pull Up or Pull Down Register
  // This register allows you to tell the MCU whether or not you want to use an internal pull-up or pull-down register for this pin
  GPIOC->PUPDR &~ GPIO_PUPDR_PUPDR7_0;
  GPIOC->PUPDR &~ GPIO_PUPDR_PUPDR7_1;

  GPIOC->BSRR |= GPIO_BSRR_BR_6;



  //BIT-BANGING for UART
  //PA-10 and PA-9
  // PA-10 is RX
  // PA-9 is TX
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

  // Mode Register - Pin 9 to output mode since its TX
  GPIOA->MODER |= GPIO_MODER_MODER9_0;
  GPIOA->MODER &~ GPIO_MODER_MODER9_1;
  GPIOA->OTYPER &~ GPIO_OTYPER_OT_9;
  GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9_1;
  GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9_0;
  GPIOA->PUPDR &~ GPIO_PUPDR_PUPDR9_0;
  GPIOA->PUPDR &~ GPIO_PUPDR_PUPDR9_1;

  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
  TIM3->PSC = 0;
  TIM3->ARR = 139;
  TIM3->DIER |= TIM_DIER_UIE;

  kl_char_to_byte_string_lsb(input_char, output_byte_string);

  //idle frame
  GPIOA->BSRR |= GPIO_BSRR_BS_9;
  TIM3->CR1 |= TIM_CR1_CEN;
  while (1) {

  	if (GPIOC->IDR & GPIO_IDR_7){
  		IRQn_Type IRQn = TIM3_IRQn;
  		NVIC_EnableIRQ(TIM3_IRQn);
  		NVIC_SetPriority(TIM3_IRQn,0);

  	}
  }


}

void TIM3_IRQHandler(void) {
	//0 - send start bit, got to 1
	//1 - send 0th bit, go to 2
	//2 ...
	//3 ...
	//4 ...
	//5 ...
	//6 ...
	//7 ...
	//8 - send 8th bit, go to 9
	//9 - send stop bit, go to 0
	// 0 10000110 1

	if (TIM3->SR & TIM_SR_UIF) {
		TIM3->SR &= ~TIM_SR_UIF;

		if(bit_index == 0) {
			// Start Bit
			GPIOA->BSRR |= GPIO_BSRR_BR_9;
			bit_index++;
			return;

		} else if (bit_index == 9) {
			//Stop Bit
			GPIOA->BSRR |= GPIO_BSRR_BS_9;
			bit_index=0;
			return;

		} else {
			if (output_byte[bit_index-1] == '1') {
				GPIOA->BSRR |= GPIO_BSRR_BS_9;
			} else {
				GPIOA->BSRR |= GPIO_BSRR_BR_9;
			}
			bit_index++;
			return;
		}
	}
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif /* USE_FULL_ASSERT */
