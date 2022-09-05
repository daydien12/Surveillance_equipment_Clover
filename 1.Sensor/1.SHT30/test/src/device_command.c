#include "device_command.h"

static void string_crc(char * destination);
static void string_cat(char *destination, const char * source);
static void string_copy(char * destination, const char * source);
static void string_split(char destination[][20], const char *source);
static unsigned char string_cmp_len(const char *destination, const char * source, const unsigned char length);

static unsigned char string_length(const char *data);
static char* conver_unsigned_intTostr(const unsigned int _data_);
static unsigned char conver_unsigned_strToint(const unsigned int _data_);


_comm_status_e comm_create_command(_comm_data_struct_create_t *_data_struct_)
{
    if(_data_struct_->port_number >= COMM_PortEnd)
    {
        return COMM_ERROR;
    }

    switch(_data_struct_->type_msg)
    {
        case COMM_AskType:
            string_copy(_data_struct_->datastr, (char*)COMM_HEADER);
            string_cat(_data_struct_->datastr, ",");
            string_cat(_data_struct_->datastr, conver_unsigned_intTostr(_data_struct_->type_msg));
            string_cat(_data_struct_->datastr, ",");
            string_cat(_data_struct_->datastr, conver_unsigned_intTostr(_data_struct_->port_number));
            string_cat(_data_struct_->datastr, ",");
            string_crc(_data_struct_->datastr);
        break;

        case COMM_AnswerType:
            if(_data_struct_->type_sensor >= Sensor_end)
            {
                return COMM_ERROR;
            }
            string_copy(_data_struct_->datastr, (char*)COMM_HEADER);
            string_cat(_data_struct_->datastr, ",");
            string_cat(_data_struct_->datastr, conver_unsigned_intTostr(_data_struct_->type_msg));
            string_cat(_data_struct_->datastr, ",");
            string_cat(_data_struct_->datastr, conver_unsigned_intTostr(_data_struct_->port_number));
            string_cat(_data_struct_->datastr, ",");
            string_cat(_data_struct_->datastr, conver_unsigned_intTostr(_data_struct_->type_sensor));
            string_cat(_data_struct_->datastr, ",");
            string_crc(_data_struct_->datastr);
        break;

        case COMM_AskData:
            string_copy(_data_struct_->datastr, (char*)COMM_HEADER);
            string_cat(_data_struct_->datastr, ",");
            string_cat(_data_struct_->datastr, conver_unsigned_intTostr(_data_struct_->type_msg));
            string_cat(_data_struct_->datastr, ",");
            string_cat(_data_struct_->datastr, conver_unsigned_intTostr(_data_struct_->port_number));
            string_cat(_data_struct_->datastr, ",");
            string_crc(_data_struct_->datastr);
            return COMM_OK;
        break;

        case COMM_AnswerData:

        break;
    }
   
    return COMM_OK;
}

_comm_status_e comm_detect_command(char *_str_datain_, unsigned char _size_datain_,_comm_data_struct_detect_t *_data_struct_)
{
    char temp_str[10][20], i;
    if((!string_cmp_len(_str_datain_, COMM_HEADER, 5))&&(_str_datain_[_size_datain_-1] == '#'))
    {
        return COMM_ERROR;
    }
    string_split(temp_str, _str_datain_);
    
    for(i=0; i<5; i++)
    {
        printf("(%s)\n", temp_str[i]);
    }
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

static void string_split(char destination[][20], const char *source)
{
    unsigned char i = 0, row = 0, col = 0;
    while(source[i]!='#')
    {
        if(source[i] == ',')
        {
            destination[col][row] = '\0';
            col++;
            row = 0;
        }
        else
        {
            destination[col][row] = source[i];
            row++;
        }
        i++;
    }
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

static unsigned char string_cmp_len(const char * destination, const char * source, const unsigned char length)
{
    int i=0;
    for(i=0; i<length; i++)
    {
        if(destination[i] != source[i])
        {
            return 0;
        }
        //printf("-%c-%c\n", destination[i], source[i]);
    }
    return 1;
}

static void string_crc(char * destination)
{
    unsigned char temp_crc = 0;
    char *arr = destination;
    while(*arr != '\0')
    {
        temp_crc ^= *arr++;
    }
    string_cat(destination, conver_unsigned_intTostr(temp_crc));
    string_cat(destination, "#");
}

