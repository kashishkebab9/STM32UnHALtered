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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
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




  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    // Alternate Pin Mode
  GPIOA->MODER |= GPIO_MODER_MODER10_1;
  GPIOA->MODER &~ GPIO_MODER_MODER10_0;
  GPIOA->MODER |= GPIO_MODER_MODER9_1;
  GPIOA->MODER &~ GPIO_MODER_MODER9_0;

  // Actual Alternate Function Number (AF1) for both Pin 9 and 10
  GPIOA->AFR[1] = 0x00000000;
  GPIOA->AFR[1] |= (1 << 4);
  GPIOA->AFR[1] |= (1 << 8);
//  GPIOA->AFR[1] &= ~(0xF << 4);
//  GPIOA->AFR[1] &= ~(0xF << 8);
//
//  GPIOA->AFR[1] |= (0x1 << 4);
//  GPIOA->AFR[1] |= (0x1 << 8);

  // Program the M Bit in the USART CR1
  // 00 for 8 bit word length

  USART1->CR1 = 0x00000000;
  USART1->CR1 &~ (1 << 12);
  USART1->CR1 &~ (1 << 28);
  USART1->CR1 &~ (1 << 0);

  // BRR
  // Our Clock rate is 8MHz
  // We want to oversample by 16. Meaning the RX line will sample 16x more the baudrate
  // Baud = 115200
  // Clock = 8,000,000
  // USART_DIV = 8,000,000/115200
  // USART_DIV = 69.4 => 69
  // 69 in binary is 0000000001000101

  // USART1->BRR = 0x0000;
  uint32_t reg = USART1->BRR;
  reg |= 69;
  USART1->BRR = reg;

  // Program the Number of Stop Bits in USART CR2
  // minicom uses 1 stop bit by default

  // USART1->CR2 = 0x00;
  USART1->CR2 &~ USART_CR2_STOP_0;
  USART1->CR2 &~ USART_CR2_STOP_1;

  // Enable the USART by writing the UE bit in USART_CR1 register to 1
  USART1->CR1 |= (1<<0);

  // Set the TE bit in USART_CR1 to send an idle frame as first transmission.
  USART1->CR1 |= (1<<3);
  USART1->CR3 = 0x00;

  char tx2_buff[20] = "Hello Kash \n";
//
  int send = 0;

//  USART1->TDR = tx2_buff;



  while(1) {
	  if (send == sizeof(tx2_buff)){
		  send = 0;
	  }
	  USART1->TDR = tx2_buff[send++];
	  while(!(USART1->ISR & 1<<6));
//	  HAL_Delay(100);



  }

//  while(1) {
//	 GPIOC->BSRR |= GPIO_BSRR_BS_6;
//	 HAL_Delay(100);
//
//
//	 USART1->TDR = 'c';
//
//
//	 while(!(USART1->ISR & 1<<6));
//	 USART1->ISR &~ (1 << 6);
//	 GPIOC->BSRR |= GPIO_BSRR_BR_6;



//}

//	  HAL_Delay(1000);
//	  GPIOC->BSRR |= GPIO_BSRR_BR_6;
//	  HAL_Delay(1000);

  //}



//
//  GPIOC->BSRR |= GPIO_BSRR_BR_6;
//  while (1) {
//
//  	if (GPIOC->IDR & GPIO_IDR_7){
//  		GPIOC->BSRR |= GPIO_BSRR_BS_6;
//  	} else {
//  		GPIOC->BSRR |= GPIO_BSRR_BR_6;
//  	}
//  }


}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
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

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
