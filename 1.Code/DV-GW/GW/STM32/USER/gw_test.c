#include "gw_test.h"
uint16_t GPIO_PORTB_Arr[6]  = {GET_GPIO_PORTB_1, GET_GPIO_PORTB_2, GET_GPIO_PORTB_3, GET_GPIO_PORTB_4, GET_GPIO_PORTB_5, GET_GPIO_PORTB_6};

void Gw_Test_Uart(void)
{
	Gw_Uart1_SendString("hello\n");
}

void Gw_Test_Gpio_Control(gpio_Control_en _stt_)
{
	switch(_stt_)
	{
		case GPIO_CONTROL_ENA_ALL:
				Gw_GPIO_Set_ON(0);
				Gw_GPIO_Set_ON(1);
				Gw_GPIO_Set_ON(2);
				Gw_GPIO_Set_ON(3);
				Gw_GPIO_Set_ON(4);
				Gw_GPIO_Set_ON(5);
			break;
		
		case GPIO_CONTROL_DIS_ALL:
				Gw_GPIO_Set_OFF(0);
				Gw_GPIO_Set_OFF(1);
				Gw_GPIO_Set_OFF(2);
				Gw_GPIO_Set_OFF(3);
				Gw_GPIO_Set_OFF(4);
				Gw_GPIO_Set_OFF(5);
			break;
	}
}

void Gw_Test_Gpio_ReadStt(uint8_t _mode_)
{
	uint8_t i = 0, arrget[6] = {0, 0, 0, 0, 0, 0};
	char arrchar[20];
	if(_mode_)
	{
		for(i=0; i<6; i++)
		{
			arrget[i] = GPIO_ReadInputDataBit(GPIOB, GPIO_PORTB_Arr[i]);
		}
		for(i=0; i<6; i++)
		{
			sprintf(arrchar,"Arr[%d]: %d\n", i, arrget[i]);
			Gw_Uart1_SendString(arrchar);
		}
		Gw_Uart1_SendString("-----------------------------------------\n");
	}
}

void Gw_Test_Rs485_Get(void)
{
	
}

void Gw_Test_Rs485_Send(char *data)
{
	Gw_Uart2_SendString(data);
	//Gw_Uart2_SendString("\n");
}

void Gw_Test_Run(void)
{
	//Gw_Test_Uart();
	Gw_Test_Gpio_Control(GPIO_CONTROL_ENA_ALL);
	//Gw_Test_Gpio_ReadStt(1);
	Gw_Test_Rs485_Send("xin chao!");
}