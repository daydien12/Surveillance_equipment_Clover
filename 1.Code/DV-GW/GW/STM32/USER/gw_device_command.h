
#ifndef __GW_DIVICE_COMM_H__
#define __GW_DIVICE_COMM_H__

#ifdef __cplusplus
extern "C" {
#endif

#define COMM_HEADER "$COMM"

typedef enum
{
    COMM_AskType              = 1,
    COMM_AnswerType           = 2,
    COMM_AskData              = 3,
    COMM_AnswerData           = 4,
}_comm_type_command_e;

typedef enum
{
    COMM_Port1 = 0,              
    COMM_Port2,          
    COMM_Port3,              
    COMM_Port4,  
    COMM_Port5,
    COMM_Port6,
    COMM_Port7,
    COMM_Port8,           
    COMM_PortEnd,
}_comm_port_number_e;

typedef enum 
{
    Sensor_SHT30 = 0,
    Sensor_2,
    Sensor_3,
    Sensor_end,
}_comm_type_sensor_e;

typedef enum 
{
    COMM_OK,
    COMM_ERROR,
}_comm_status_e;


typedef struct
{
    float in1_data;
    float in2_data;
    float in3_data;
    float in4_data;
}_comm_data_sensor_t;

typedef struct 
{
	  _comm_type_command_e        in1_type_msg;
    _comm_port_number_e         in2_port_number;
    _comm_type_sensor_e         in3_type_sensor;
    _comm_data_sensor_t         in4_data_sensor;
	  char                        out_datastr[50];
}_comm_data_struct_create_t;

typedef struct 
{
	  _comm_type_command_e        out1_type_msg;
    _comm_port_number_e         out2_port_number;
    _comm_type_sensor_e         out3_type_sensor;
    _comm_data_sensor_t         out4_data_sensor;
}_comm_data_struct_detect_t;

_comm_status_e comm_create_command(_comm_data_struct_create_t *_data_struct_);
_comm_status_e comm_detect_command(const char *_str_datain_, _comm_data_struct_detect_t *_data_struct_);

#ifdef __cplusplus
}
#endif

#endif
