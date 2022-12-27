#include "dv_sys.h"

void Dv_Sys_Init(void)
{
  UART_Init(9600);
  Dv_Test_Init();
}

void Dv_Sys_Run(void)
{
   Dv_Test_Run();
   //Dv_Delay_Ms(1000);
}