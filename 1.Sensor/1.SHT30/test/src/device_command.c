#include "device_command.h"

static void string_crc(char * destination);
static void string_cat(char *destination, const char * source);
static void string_copy(char * destination, const char * source);

static unsigned char string_length(const char *data);
static char* conver_unsigned_intTostr(const unsigned int _data_);

_comm_status_e comm_asktype(const _comm_port_number_e _port_number_, char* _arr_data_, unsigned char _size_arr_)
{
    if((_size_arr_ < 15)||(_port_number_ >= COMM_PortEnd))
    {
        return COMM_ERROR;
    }
    string_copy(_arr_data_, (char*)COMM_HEADER);
    string_cat(_arr_data_, ",");
    string_cat(_arr_data_, conver_unsigned_intTostr(COMM_AskType));
    string_cat(_arr_data_, ",");
    string_cat(_arr_data_, conver_unsigned_intTostr(_port_number_));
    string_cat(_arr_data_, ",");
    string_crc(_arr_data_);
    return COMM_OK;
}

_comm_status_e comm_answertype(const _comm_port_number_e _port_number_, const _comm_port_number_e _typed_sensor_, char* _arr_data_, unsigned char _size_arr_)
{
    if((_size_arr_ < 20)||(_port_number_ >= COMM_PortEnd))
    {
        return COMM_ERROR;
    }
    string_copy(_arr_data_, (char*)COMM_HEADER);
    string_cat(_arr_data_, ",");
    string_cat(_arr_data_, conver_unsigned_intTostr(COMM_AnswerType));
    string_cat(_arr_data_, ",");
    string_cat(_arr_data_, conver_unsigned_intTostr(_port_number_));
    string_cat(_arr_data_, ",");
    string_cat(_arr_data_, conver_unsigned_intTostr(_typed_sensor_));
    string_cat(_arr_data_, ",");
    string_crc(_arr_data_);
    return COMM_OK;
}

_comm_status_e comm_askdata(const _comm_port_number_e _port_number_, char* _arr_data_, unsigned char _size_arr_)
{
    if((_size_arr_ < 15)||(_port_number_ >= COMM_PortEnd))
    {
        return COMM_ERROR;
    }
    string_copy(_arr_data_, (char*)COMM_HEADER);
    string_cat(_arr_data_, ",");
    string_cat(_arr_data_, conver_unsigned_intTostr(COMM_AskData));
    string_cat(_arr_data_, ",");
    string_cat(_arr_data_, conver_unsigned_intTostr(_port_number_));
    string_cat(_arr_data_, ",");
    string_crc(_arr_data_);
    return COMM_OK;
}

static unsigned char string_length(const char *data)
{
    unsigned char count = 0;
    
    while(*(data+count) != '\0')
    {
        count++;
    }
    return count;
}

void string_copy(char *destination, const char *source)
{
    unsigned char lengt_source = string_length(source), i = 0;

    for(i=0; i<lengt_source; i++)
    {
        *(destination+i) = *(source+i);
    }
    *(destination+i) = '\0';
}

static void string_cat(char *destination, const char * source)
{
    while(*destination != '\0')
    {
        destination++;
    }

    while(*source != '\0')
    {
        *destination++ = *source++;
    }
    *destination = '\0';
}

static char* conver_unsigned_intTostr(const unsigned int _data_)
{
    static char arr[20];
    unsigned char i = 0;
    unsigned int tempdata = _data_, tempsum = 0;
    
    if(_data_ == 0)
    {
        arr[0] = '0';
        arr[1] = '\0';
        return arr;
    }

    while(tempdata)
    {
        tempsum =  (tempsum*10) + (tempdata%10);
        tempdata /= 10;
    }

    while(tempsum)
    {
        arr[i] = (tempsum%10) + '0';
        tempsum /= 10;
        i++;
    }

    arr[i] = '\0';
    return arr;
}

static void string_crc(char * destination)
{
    unsigned char temp_crc = 0;
    char *arr = destination;
    while(*arr != '\0')
    {
        //printf("%c", *arr);
        temp_crc ^= *arr++;
    }
    //printf("\n%d ", temp_crc);
    string_cat(destination, conver_unsigned_intTostr(temp_crc));
    string_cat(destination, "#");
}