
#ifndef __DIVICE_COMM_H__
#define __DIVICE_COMM_H__

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
    COMM_PortEnd
}_comm_port_number_e;

typedef enum 
{
    Sensor_1 = 0,
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
    _comm_port_number_e         port_number;
    _comm_type_command_e        type_msg;
    _comm_type_sensor_e         type_sensor;
    char                        datastr[50];
}_comm_data_struct_t;

_comm_status_e comm_asktype(_comm_data_struct_t *_data_struct_);
/*
_comm_status_e comm_asktype(const _comm_port_number_e _port_number_, char* _arr_data_, unsigned char _size_arr_);
_comm_status_e comm_answertype(const _comm_port_number_e _port_number_, const _comm_port_number_e _typed_sensor_, char* _arr_data_, unsigned char _size_arr_);
_comm_status_e comm_askdata(const _comm_port_number_e _port_number_, char* _arr_data_, unsigned char _size_arr_);
*/
//_comm_status_e comm_detectcommand(char* _arr_data_);

#ifdef __cplusplus
}
#endif

#endif