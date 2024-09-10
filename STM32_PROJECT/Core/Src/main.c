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
#include <ex3.h>

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
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int stateOfGroup1 = RED;
int countOfGroup1 = 5;
int stateOfGroup2 = GREEN;
int countOfGroup2 = 3;
void init_exercise3(){
	HAL_GPIO_WritePin(LED_1_GPIO_Port,LED_1_Pin,SET);
	HAL_GPIO_WritePin(LED_2_GPIO_Port,LED_2_Pin,SET);
	HAL_GPIO_WritePin(LED_3_GPIO_Port,LED_3_Pin,SET);
	HAL_GPIO_WritePin(LED_4_GPIO_Port,LED_4_Pin,SET);
	HAL_GPIO_WritePin(LED_5_GPIO_Port,LED_5_Pin,SET);
	HAL_GPIO_WritePin(LED_6_GPIO_Port,LED_6_Pin,SET);

	HAL_GPIO_TogglePin(LED_1_GPIO_Port,LED_1_Pin);
	HAL_GPIO_TogglePin(LED_2_GPIO_Port,LED_2_Pin);
	HAL_GPIO_TogglePin(LED_3_GPIO_Port,LED_3_Pin);
	HAL_GPIO_TogglePin(LED_4_GPIO_Port,LED_4_Pin);
	HAL_GPIO_TogglePin(LED_5_GPIO_Port,LED_5_Pin);
	HAL_GPIO_TogglePin(LED_6_GPIO_Port,LED_6_Pin);

}
void traffic1_run(){
		countOfGroup1--;
		switch(stateOfGroup1){
		case RED:
			if(countOfGroup1 == 0){
				stateOfGroup1 = GREEN;
				countOfGroup1 = 3;
			}
			HAL_GPIO_WritePin(LED_1_GPIO_Port,LED_1_Pin,SET);
			HAL_GPIO_WritePin(LED_2_GPIO_Port,LED_2_Pin,RESET);
			HAL_GPIO_WritePin(LED_3_GPIO_Port,LED_3_Pin,RESET);
			break;
		case YELLOW:
			if(countOfGroup1 == 0){
				stateOfGroup1 = RED;
				countOfGroup1 = 5;
			}
			HAL_GPIO_WritePin(LED_1_GPIO_Port,LED_1_Pin,RESET);
			HAL_GPIO_WritePin(LED_2_GPIO_Port,LED_2_Pin,SET);
			HAL_GPIO_WritePin(LED_3_GPIO_Port,LED_3_Pin,RESET);
			break;
		case GREEN:
			if(countOfGroup1 == 0){
				stateOfGroup1 = YELLOW;
				countOfGroup1 = 2;
			}
			HAL_GPIO_WritePin(LED_1_GPIO_Port,LED_1_Pin,RESET);
			HAL_GPIO_WritePin(LED_2_GPIO_Port,LED_2_Pin,RESET);
			HAL_GPIO_WritePin(LED_3_GPIO_Port,LED_3_Pin,SET);
			break;
		default:
			break;
		}
}
void traffic2_run(){
		countOfGroup2--;
		switch(stateOfGroup2){
		case RED:
			if(countOfGroup2 == 0){
					stateOfGroup2 = GREEN;
					countOfGroup2 = 3;
				}
				HAL_GPIO_WritePin(LED_4_GPIO_Port,LED_4_Pin,SET);
				HAL_GPIO_WritePin(LED_5_GPIO_Port,LED_5_Pin,RESET);
				HAL_GPIO_WritePin(LED_6_GPIO_Port,LED_6_Pin,RESET);
				break;
			case YELLOW:
				if(countOfGroup2 == 0){
					stateOfGroup2 = RED;
					countOfGroup2 = 5;
				}
				HAL_GPIO_WritePin(LED_4_GPIO_Port,LED_4_Pin,RESET);
				HAL_GPIO_WritePin(LED_5_GPIO_Port,LED_5_Pin,SET);
				HAL_GPIO_WritePin(LED_6_GPIO_Port,LED_6_Pin,RESET);
				break;
			case GREEN:
				if(countOfGroup1 == 0){
					stateOfGroup2 = YELLOW;
					countOfGroup2 = 2;
				}
				HAL_GPIO_WritePin(LED_4_GPIO_Port,LED_4_Pin,RESET);
				HAL_GPIO_WritePin(LED_5_GPIO_Port,LED_5_Pin,RESET);
				HAL_GPIO_WritePin(LED_6_GPIO_Port,LED_6_Pin,SET);
				break;
			default:
				break;
			}
}
void exercise3_run(){
	traffic1_run();
	traffic2_run();
}
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
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  init_exercise3();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
	  exercise3_run();
	  HAL_Delay(1000);
  }
  /* USER CODE END 3 */
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
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin|SEG_0_Pin|SEG_1_Pin
                          |SEG_2_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin
                          |SEG_6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_1_Pin|LED_2_Pin|LED_3_Pin|LED_11_Pin
                          |LED_12_Pin|LED_4_Pin|LED_5_Pin|LED_6_Pin
                          |LED_7_Pin|LED_8_Pin|LED_9_Pin|LED_10_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin LED_YELLOW_Pin SEG_0_Pin SEG_1_Pin
                           SEG_2_Pin SEG_3_Pin SEG_4_Pin SEG_5_Pin
                           SEG_6_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_YELLOW_Pin|SEG_0_Pin|SEG_1_Pin
                          |SEG_2_Pin|SEG_3_Pin|SEG_4_Pin|SEG_5_Pin
                          |SEG_6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_1_Pin LED_2_Pin LED_3_Pin LED_11_Pin
                           LED_12_Pin LED_4_Pin LED_5_Pin LED_6_Pin
                           LED_7_Pin LED_8_Pin LED_9_Pin LED_10_Pin */
  GPIO_InitStruct.Pin = LED_1_Pin|LED_2_Pin|LED_3_Pin|LED_11_Pin
                          |LED_12_Pin|LED_4_Pin|LED_5_Pin|LED_6_Pin
                          |LED_7_Pin|LED_8_Pin|LED_9_Pin|LED_10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
