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
#include "controlo.h"
#include "interface.h"
#include "usart.h"
#include "tim.h"
#include "adc.h"
#include "limitacao.h"

/* USER CODE BEGIN 0 */
#define VAL_MAX_LIMIT 5
#define VAL_MIN_LIMIT 0
#define ESQUERDA 1
#define DIREITA 0
/* USER CODE END 0 */


volatile int FW_RV;

int K_f;
int Kd_f;
int Kp_h;
int Ki_h;
int u_0;
int U_sat_a = 100;
int U_sat_b = -100;
volatile int aut;
volatile float u_d_ant;
volatile float u_d;
volatile float delta_u;
volatile float u;
volatile float y;
volatile float e;
volatile float e_ant;
volatile float sum_e_bkp;
volatile float sum_e;

/* USER CODE BEGIN 1 */
void output_t(int atuador){

		if(atuador>0){ //u above upper saturation
			FW_RV = 1;
			value = atuador;
}
		else if(atuador<0){ //u above upper saturation
			FW_RV = 0;
			value = atuador*(-1);
}
	
			if(atuador>0 && !get_stop()){ //u above upper saturation
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);		
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
				htim2.Instance->CCR1 = value;
}

			else if(atuador<0 && !get_stop()){ //u above upper saturation
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);	
				htim2.Instance->CCR1 = value;	
}
			
}


void controlador(uint8_t valor_ref, uint8_t valor_atual){

e=valor_ref-valor_atual;
			sum_e_bkp = sum_e; //error sum backup
			sum_e = sum_e+e+e_ant;
	
			if(sum_e>10){ //u above upper saturation
						sum_e = 10;
						}

			else if(sum_e<-10){ //u above upper saturation
						sum_e = -10;
						}
			
			u_d = ( Kd_f * (e-e_ant) )+ K_f*u_d_ant;	//u_d
			e_ant = e;
			u_d_ant = u_d;
			delta_u = Kp_h*e + ( Ki_h * sum_e )+ u_d;  //delta_u
			u = u_0 + delta_u;
				
			if(u>U_sat_a){ //u above upper saturation
						u=U_sat_a;
						sum_e=sum_e_bkp;	//sum of errors frozen,
															//back to last value
						}

			else if(u<U_sat_b){ //u below lower saturation
						u=U_sat_b;
						sum_e=sum_e_bkp; 	 //sum of errors frozen,
															//back to last value
						}
			output_t(u); //unsaturated u remains unchanged ------ A DEFINIR
						

e_ant=e;
					}

					
int get_sentido(){
return FW_RV;
}

int get_error(){
return (int)e;
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
