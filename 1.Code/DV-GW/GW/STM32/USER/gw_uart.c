/*
  ******************************************************************************
    @file    uart.c
    @author Nguyen Quang Bien
    @date   11/11/2022
  ******************************************************************************
*/

#include "gw_uart.h"


struct __FILE
{
  int dummy;
};
FILE __stdout;
int fputc(int ch, FILE *f)
{
  Gw_Uart1_SendChar(ch);
  return ch;
}

char Flag1_Receive = 0;
char Array1_Receive[string_size];
char Count1_Data = 0;

char Flag2_Receive = 0;
char Array2_Receive[string_size];
char Count2_Data = 0;

char Flag3_Receive = 0;
char Array3_Receive[string_size];
char Count3_Data = 0;

_ringbuffer_t ringbuffer_Test;

static void Uart_Gpio_Control_RS485(void);

void Gw_Uart_Init(void)
{
  Gw_Uart_Init1(UART1_BAUDRATE);
  Gw_Uart_Init2(UART2_BAUDRATE);
  Gw_Uart_Init3(UART3_BAUDRATE);
}

void Gw_Uart_Init1(unsigned int BaudRates)
{
  RCC->APB2ENR |= 0x00000004;
  GPIOA->CRH |=  0x000004B0;
  RCC->APB2ENR |= 0x00004000;
  USART1->BRR = ((((SystemCoreClock / (BaudRates)) / 16) << 4) + ((SystemCoreClock / (BaudRates)) % 16));
  USART1->CR1 |= (USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE);
  NVIC_EnableIRQ(USART1_IRQn);
  USART1->CR1 |= USART_CR1_UE;
}

void Gw_Uart1_SendChar(char data)
{
  USART1->DR = (data & 0x00FF);
  while ((USART1->SR & 0x0080) == RESET);
}

void Gw_Uart1_SendString(char *data)
{
  while (*data)
  {
    Gw_Uart1_SendChar(*data);
    data++;
  }
}

void Gw_Uart1_SendByte(uint8_t *data, uint8_t sizes)
{
  uint8_t i;
  for (i = 0; i < sizes; i++)
  {
    USART1->DR = (data[i] & 0x00FF);
    while ((USART1->SR & 0x0080) == RESET);
  }
}

void Gw_Uart_Init2(unsigned int BaudRates)
{
  ringbuffer_init(&ringbuffer_Test, Array2_Receive, string_size);
  RCC->APB2ENR |= 0x00000004;
  GPIOA->CRL  |= 0x00004B00;
  RCC->APB1ENR |= 0x00020000;
  USART2->BRR = ((((SystemCoreClock / (BaudRates * 2)) / 16) << 4) + ((SystemCoreClock / (BaudRates)) % 16));
  USART2->CR1 |= (USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE);
  NVIC_EnableIRQ(USART2_IRQn);
  USART2->CR1 |= USART_CR1_UE;
  Uart_Gpio_Control_RS485();
}

void Gw_Uart2_SendChar(char data)
{
  USART2->DR = (data & (uint16_t)0x01FF);
  while ((USART2->SR & 0x0080) == RESET);
}

void Gw_Uart2_SendString(char *data)
{
  GPIO_SetBits(PORT_CONTROL_RS485, GPIO_CONTROL_RS485);
  while (*data)
  {
    Gw_Uart2_SendChar(*data);
    data++;
  }
  Gw_Uart2_SendChar('\0');
   GPIO_ResetBits(PORT_CONTROL_RS485, GPIO_CONTROL_RS485);
}

void Gw_Uart2_SendByte(uint8_t *data, uint8_t sizes)
{
  uint8_t i;
  for (i = 0; i < sizes; i++)
  {
    USART2->DR = (data[i] & 0x00FF);
    while ((USART2->SR & 0x0080) == RESET);
  }
}

void Gw_Uart_Init3(unsigned int BaudRates)
{
  RCC->APB2ENR |= 0x00000008;
  GPIOB->CRH  |= 0x00004B00;
  RCC->APB1ENR |= 0x00040000;
  USART3->BRR = ((((SystemCoreClock / (BaudRates * 2)) / 16) << 4) + ((SystemCoreClock / (BaudRates)) % 16));
  USART3->CR1 |= (USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE);
  NVIC_EnableIRQ(USART3_IRQn);
  USART3->CR1 |= USART_CR1_UE;
}

void Gw_Uart3_SendString(char data)
{
  USART3->DR = (data & 0x00FF);
  while ((USART3->SR & 0x0080) == RESET);
}

void UART3_SendString(char *data)
{
  while (*data)
  {
    Gw_Uart2_SendChar(*data);
    data++;
  }
}

void USART1_IRQHandler(void)
{
  char temp_data;
  if ((USART1->SR & USART_SR_RXNE) != 0)
  {
    temp_data = USART1->DR;
    if (temp_data != '\n')
    {
      Array1_Receive[Count1_Data] = temp_data;
      Count1_Data++;
    }
    else
    {
      Array1_Receive[Count1_Data] = 0;
      Flag1_Receive = 1;
      Count1_Data = 0;
    }
  }
}

//void USART2_IRQHandler(void)
//{
//	char temp_data;
//  if ((USART2->SR & USART_SR_RXNE) != 0)
//  {
//    Flag2_Receive = 1;
//    temp_data = USART_ReceiveData(USART2);
//    ringbuffer_push(&ringbuffer_Test, temp_data);
//  }
//  USART_ClearITPendingBit(USART2, USART_SR_RXNE);
//}

void USART2_IRQHandler(void) {
  char temp_data = 0;
  if ((USART2->SR & USART_SR_RXNE) != 0)
  {
    temp_data = USART_ReceiveData(USART2);
    if (temp_data != '!')
    {
      Array2_Receive[Count2_Data] = temp_data;
      Count2_Data++;
    }
    else
    {
      Array2_Receive[Count2_Data] = 0;
      Flag2_Receive = 1;
      Count2_Data = 0;
    }
  }
	USART_ClearITPendingBit(USART2, USART_SR_RXNE);
}

void USART3_IRQHandler(void)
{
  char temp_data;
  if ((USART3->SR & USART_SR_RXNE) != 0)
  {
    temp_data = USART3->DR;
    if (temp_data != '\n')
    {
      Array3_Receive[Count3_Data] = temp_data;
      Count3_Data++;
    }
    else
    {
      Array3_Receive[Count3_Data] = 0;
      Flag3_Receive = 1;
      Count3_Data = 0;
    }
  }
}

static void Uart_Gpio_Control_RS485(void)
{
  GPIO_InitTypeDef vrst_gpio;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  vrst_gpio.GPIO_Mode = GPIO_Mode_Out_PP;
  vrst_gpio.GPIO_Pin  = GPIO_CONTROL_RS485;
  vrst_gpio.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(PORT_CONTROL_RS485, &vrst_gpio);
  GPIO_ResetBits(PORT_CONTROL_RS485, GPIO_CONTROL_RS485);
}
/********************************* END OF FILE ********************************/
/******************************************************************************/
