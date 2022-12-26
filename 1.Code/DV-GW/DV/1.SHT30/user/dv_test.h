/**
  ********************************************************************************
  * @file    stm8s_uart1.h
  * @author  Nguyen Quang Bien
  * @version 
  * @date    
  * @brief   
  *******************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DV_TEST_H__
#define __DV_TEST_H__

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "dv_i2c.h"
#include "dv_uart.h"
#include "dv_sht30.h"
#include "dv_delay.h"
#include "dv_conver.h"

void Dv_Test_Init(void);
void Dv_Test_Run(void);
void Dv_Test_Sensor(uint8_t mode);

void Dv_Test_Rs485_Get(void);
void Dv_Test_Rs485_Send(char *data);

#endif 

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/