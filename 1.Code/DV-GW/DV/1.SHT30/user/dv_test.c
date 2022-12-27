#include "dv_test.h"

void Dv_Test_Init(void)
{
  SHT30_Init();
  SHT30_isHeaterEnabled();
}

void Dv_Test_Run(void)
{
  //Dv_Test_Sensor(1);
  //Dv_Test_Rs485_Get();
  Dv_Test_Rs485_Send("Quang Bien \n!!");
  Dv_Delay_Ms(1000);

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
  if(UART_Flag())
  {
    UART_Send_Array_RX();
  }
}

void Dv_Test_Rs485_Send(char *data)
{
  UART_Send_String(data);
}
