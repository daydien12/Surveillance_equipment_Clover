#include "stm8s.h"
#include "uart.h"
#include "i2c.h"
#include "sht30.h"
#include "sys.h"
//D6-rx
//D5-tx
void delay_ms(int a)
{
  for (int i = 0; i < a; i++)
    for (int index = 0; index < 400; index++);
}
void intTostr(uint32_t data, uint8_t *arr)
{
  uint32_t TempData = 0, count = 0;
  while(data)
  {
    TempData =  (TempData*10)+(data%10);
    data /= 10;
  }
  while(TempData)
  {
    arr[count] =  (TempData%10)+'0';
    TempData /= 10;
    count++;
  }
  arr[count] = 0;
}

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
    UART_Send_Number((int)a);
    UART_Send_String("Hum: ");
    UART_Send_Number((int)b);
    UART_Send_String("\n");
    delay_ms(1000);
  }
}
