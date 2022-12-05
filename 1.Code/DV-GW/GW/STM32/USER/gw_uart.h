 
/*
  ******************************************************************************
  * @file		Uart.h                                                              *
  * @author	Nguyen Quang Bien                                                  *
  * @date		00/00/0000                                                         *
  ******************************************************************************
*/
	
#ifndef __GW_UART_H__
#define __GW_UART_H__





#ifdef __cplusplus
 extern "C" {
#endif

#include "stdio.h"
#include "string.h"
#include "stm32f10x.h"    
#include "gw_ringbuffer.h"

#define  UART1_BAUDRATE (9600)
#define  UART2_BAUDRATE (9600)
#define  UART3_BAUDRATE (9600)
	 
#define string_size 50
#define GPIO_CONTROL_RS485 GPIO_Pin_4
#define PORT_CONTROL_RS485 GPIOA
extern char Flag1_Receive;
extern char Array1_Receive[];
extern char Count1_Data;

extern char Flag2_Receive;
extern char Array2_Receive[];
extern char Count2_Data;

extern char Flag3_Receive;
extern char Array3_Receive[];
extern char Count3_Data;

extern _ringbuffer_t ringbuffer_Test;	
	 
void Gw_Uart_Init(void);

void Gw_Uart_Init1(unsigned int BaudRates);
void Gw_Uart1_SendChar(char data);
void Gw_Uart1_SendString(char *data);
void Gw_Uart1_SendByte(uint8_t *data, uint8_t sizes); 

void Gw_Uart_Init2(unsigned int BaudRates);
void Gw_Uart2_SendChar(char data);
void Gw_Uart2_SendString(char *data);
void Gw_Uart2_SendByte(uint8_t *data, uint8_t sizes); 

void Gw_Uart_Init3(unsigned int BaudRates);
void Gw_Uart2_SendChar(char data);		 
void Gw_Uart2_SendString(char *data);

#ifdef __cplusplus
}
#endif

#endif

