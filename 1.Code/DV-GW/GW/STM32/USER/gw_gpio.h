/*
  ******************************************************************************
  * @file		gpio.h                                                     	       *
  * @author	Luu Ngoc Anh                                                       *
  * @date		30/11/2022                                                         *
  ******************************************************************************
*/
	
#ifndef __GW_GPIO_H__
#define __GW_GPIO_H__

#ifdef __cplusplus
 extern "C" {
#endif
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "gw_define.h"

typedef enum
{
	GET_GPIO_CONNECTED = 0,
	GET_GPIO_DISCONNECTED
}_status_port_plug_e;

void Gw_GPIO_Init(void);
void Gw_GPIO_Set_ON(int port);
void Gw_GPIO_Set_OFF(int port);

#ifdef __cplusplus
}
#endif

#endif

/********************************* END OF FILE ********************************/
/******************************************************************************/
