/**
  ********************************************************************************
  * @file    stm8s_uart1.h
  * @author  Nguyen Quang Bien
  * @version 
  * @date    
  * @brief   
  *******************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DV_SYS_H__
#define __DV_SYS_H__

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "dv_i2c.h"
#include "dv_test.h"
#include "dv_uart.h"
#include "dv_sht30.h"
#include "dv_delay.h"
#include "dv_conver.h"

void Dv_Sys_Init(void);
void Dv_Sys_Run(void);

#endif 

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/