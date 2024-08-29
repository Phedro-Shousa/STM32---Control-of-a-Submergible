/**
  ****************************************************************************
  * File Name          : limitacao.c
  * Description        : This file provides code for the configuration
  *                      of the limitacao instances.
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

/* Includes ------------------------------------------------------------------*/
#include "limitacao.h"
#include "tim.h"
#include "controlo.h"


/* USER CODE BEGIN 0 */
#define VAL_MAX_LIMIT 3450
#define VAL_MIN_LIMIT 700
#define ESQUERDA 1
#define DIREITA 0
/* USER CODE END 0 */


volatile int stop;

/* USER CODE BEGIN 1 */
void limitacao_f(float valor_adc){
		
		if((valor_adc < VAL_MIN_LIMIT) && get_sentido()){
				htim2.Instance->CCR1 = 0;
				stop = 1;
		}
	
		else if((valor_adc > VAL_MAX_LIMIT) && (!get_sentido())  ){
			htim2.Instance->CCR1 = 0;
			stop = 1;
		}
		else{stop = 0;}

}

int get_stop(){
return stop;}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
