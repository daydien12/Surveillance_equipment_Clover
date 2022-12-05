#include "gw_sys.h"

int main()
{
	Gw_Sys_Init();
	while(1)
	{
		Gw_Sys_Run();
	}
}
