#include "stm8s.h"
#include "dv_uart.h"
#include "dv_i2c.h"
#include "dv_sht30.h"
#include "dv_delay.h"
#include "dv_conver.h"
//D6-rx
//D5-tx

int main( void )
{
 
  UART_Init(9600);
  UART_Send_String("xin chao");
  SHT30_Init();
  UART_Send_Number(SHT30_isHeaterEnabled());
  while (1)
  {
    float a, b;
    SHT30_ReadTempHum(&a, &b);
    UART_Send_String("temp: ");
    UART_Send_String(Gw_Conver_FloatToStr(a, 3));
    UART_Send_String("Hum: ");
    UART_Send_String(Gw_Conver_FloatToStr(b, 3));
    UART_Send_String("\n");
   Dv_Delay_Ms(1000);
  }
}
