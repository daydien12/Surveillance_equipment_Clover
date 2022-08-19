#include "device_command.h"

static void string_copy(char * destination, const char * source);
static unsigned char string_length(const char *data);
static void string_cat(char *destination, const char * source);
static char* conver_unsigned_intTostr(const unsigned int _data_);

_comm_status_e comm_asktype(const unsigned char _port_number_, char* _arr_data_)
{
    string_copy(_arr_data_, (char*)COMM_HEADER);
    string_cat(_arr_data_, ",");
    string_cat(_arr_data_, conver_unsigned_intTostr(_port_number_));
    string_cat(_arr_data_, "#");
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