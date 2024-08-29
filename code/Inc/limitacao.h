/**
  ****************************************************************************
  * File Name          : limitacao.h
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
  ****************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ****************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __limitacao_H
#define __limitacao_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */


/* USER CODE BEGIN Private defines */
extern volatile int stop;

/* USER CODE END Private defines */

/* USER CODE BEGIN Prototypes */
void limitacao_f(float);
int get_stop(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ limitacao_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
