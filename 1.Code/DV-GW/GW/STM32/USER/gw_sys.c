#include "gw_sys.h"

_status_port_plug_e Arr_port_plug[6] = {GET_GPIO_DISCONNECTED, GET_GPIO_DISCONNECTED, GET_GPIO_DISCONNECTED, GET_GPIO_DISCONNECTED, GET_GPIO_DISCONNECTED, GET_GPIO_DISCONNECTED};
uint16_t GET_GPIO_PORTB_Arr[6]  = {GET_GPIO_PORTB_1, GET_GPIO_PORTB_2, GET_GPIO_PORTB_3, GET_GPIO_PORTB_4, GET_GPIO_PORTB_5, GET_GPIO_PORTB_6};

void Gw_Sys_Init(void)
{
	uint8_t status = 0;
	Gw_Uart_Init2(9600);
	Gw_Uart_Init1(9600);
	
	Gw_GPIO_Init();
	Gw_DELAY_Init(72);
	
	Gw_GPIO_Set_ON(3);
	Gw_GPIO_Set_ON(4);
	Gw_GPIO_Set_ON(5);
	
	_comm_data_struct_create_t vrst_struct_create_;
	vrst_struct_create_.in1_type_msg = COMM_AnswerData;
	vrst_struct_create_.in2_port_number = COMM_Port1;
	vrst_struct_create_.in3_type_sensor = Sensor_SHT30;
	vrst_struct_create_.in4_data_sensor.in1_data = -12345.235;
	vrst_struct_create_.in4_data_sensor.in2_data = -0.235;
	status = comm_create_command(&vrst_struct_create_);
	if(status == COMM_OK)
	{
		Gw_Uart1_SendString(vrst_struct_create_.out_datastr);
		Gw_Uart1_SendString("\n");
	}
	
	_comm_data_struct_detect_t vrst_struct_detect_;
	status = comm_detect_command(vrst_struct_create_.out_datastr, &vrst_struct_detect_);
	if(status == COMM_OK)
	{
		Gw_Uart1_SendString(Gw_Conver_FloatToStr(vrst_struct_detect_.out4_data_sensor.in1_data, 3));
		Gw_Uart1_SendString(" ");
		Gw_Uart1_SendString(Gw_Conver_FloatToStr(vrst_struct_detect_.out4_data_sensor.in2_data, 3));
	}
}
void Gw_Sys_Run(void)
{
//	for(int i = 0; i < 6; i++)
//	{
//		printf("Port %d: %d\n", i, GPIO_ReadInputDataBit(GPIOB, GET_GPIO_PORTB_Arr[i]));
//		Delay_Ms(10);
//	}	
//	printf("---------------------------\n");
}
