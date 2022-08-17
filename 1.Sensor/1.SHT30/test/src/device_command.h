
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
}_command_line_mode_e;

typedef enum 
{
    COMM_OK,
    COMM_ERROR,
}_comm_status_e;

_comm_status_e comm_asktype(const unsigned char _port_number_, char* _arr_data_);

#ifdef __cplusplus
}
#endif

#endif