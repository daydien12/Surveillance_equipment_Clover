#include "dv_test.h"

void Dv_Test_Init(void)
{
  SHT30_Init();
  SHT30_isHeaterEnabled();
}

void Dv_Test_Run(void)
{
  Dv_Test_Sensor(1);
}

void Dv_Test_Sensor(uint8_t mode)
{
  if(mode == 1)
  {
    float a, b;
    SHT30_ReadTempHum(&a, &b);
    UART_Send_String("temp: ");
    UART_Send_String(Gw_Conver_FloatToStr(a, 3));
    UART_Send_String("Hum: ");
    UART_Send_String(Gw_Conver_FloatToStr(b, 3));
    UART_Send_String("\n");
  }
}

void Dv_Test_Rs485_Get(void)
{
  
}

void Dv_Test_Rs485_Send(char *data)
{
  
}
