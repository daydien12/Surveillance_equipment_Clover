#include "sys.h"

static char Temp_data_get_arr[100];
_status_port_plug_e Arr_port_plug[6] = {GET_GPIO_DISCONNECTED, GET_GPIO_DISCONNECTED, GET_GPIO_DISCONNECTED, GET_GPIO_DISCONNECTED, GET_GPIO_DISCONNECTED, GET_GPIO_DISCONNECTED};
uint16_t GET_GPIO_PORTB_Arr[6]  = {GET_GPIO_PORTB_1, GET_GPIO_PORTB_2, GET_GPIO_PORTB_3, GET_GPIO_PORTB_4, GET_GPIO_PORTB_5, GET_GPIO_PORTB_6};

void Fn_Sys_Init(void)
{
	INIT_UART_2(9600);
	INIT_UART_1(9600);	
	Fn_GPIO_Init();
	Delay_Init();
	printf("Quang Bien: \n");
	Fn_SET_GPIO_ON(3);
	Fn_SET_GPIO_ON(4);
	Fn_SET_GPIO_ON(5);

}
void Fn_Sys_Run(void)
{
	for(int i = 0; i < 6; i++)
	{
		printf("Port %d: %d\n", i, GPIO_ReadInputDataBit(GPIOB, GET_GPIO_PORTB_Arr[i]));
		Delay_Ms(10);
	}	
	printf("---------------------------\n");
}
