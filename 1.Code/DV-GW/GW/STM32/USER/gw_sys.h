
#ifndef __GW_SYS__H__
#define __GW_SYS__H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "gw_uart.h"
#include "gw_gpio.h"
#include "gw_delay.h"
#include "gw_define.h" 
#include "stm32f10x.h"   
#include "gw_conver.h"
#include "gw_ringbuffer.h"
#include "gw_device_command.h"

void Gw_Sys_Init(void);
void Gw_Sys_Run(void);

#ifdef __cplusplus
}
#endif

#endif

/********************************* END OF FILE ********************************/
/******************************************************************************/
