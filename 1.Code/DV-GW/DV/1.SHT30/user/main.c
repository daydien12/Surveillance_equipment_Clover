#include "dv_sys.h"

//D6-rx
//D5-tx

int main( void )
{
  Dv_Sys_Init();
  while (1)
  {
   Dv_Sys_Run();
  }
}
