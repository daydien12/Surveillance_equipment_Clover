
#ifndef __GW_TEST__H__
#define __GW_TEST__H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "gw_uart.h"
#include "gw_gpio.h"
#include "gw_test.h"
#include "gw_delay.h"
#include "gw_define.h" 
#include "stm32f10x.h"   
#include "gw_conver.h"
#include "gw_ringbuffer.h"
#include "gw_device_command.h"

typedef enum 
{
	GPIO_CONTROL_ENA_ALL =0,
	GPIO_CONTROL_DIS_ALL,
}gpio_Control_en;

void Gw_Test_Run(void);
void Gw_Test_Uart(void);
void Gw_Test_Gpio_ReadStt(uint8_t _mode_);
void Gw_Test_Gpio_Control(gpio_Control_en _stt_);

#ifdef __cplusplus
}
#endif

#endif

/********************************* END OF FILE ********************************/
/******************************************************************************/
