
#include "gw_conver.h"
#include "gw_device_command.h"

static void string_crc(char * destination);
static void string_cat(char *destination, const char * source);
static void string_copy(char * destination, const char * source);
static char string_split(char destination[][20], const char *source);

static unsigned char string_length(const char *data);
static unsigned char string_cmp_len(const char *destination, const char * source, const unsigned char length);
static unsigned char checksum(const char *_data_str_);

_comm_status_e comm_create_command(_comm_data_struct_create_t *_data_struct_)
{
  if (_data_struct_->in2_port_number >= COMM_PortEnd)
  {
    return COMM_ERROR;
  }
	
	if (_data_struct_->in3_type_sensor >= Sensor_end)
	{
		return COMM_ERROR;
	}
	
  switch (_data_struct_->in1_type_msg)
  {
    case COMM_AskType:
      string_copy(_data_struct_->out_datastr, (char*)COMM_HEADER);
      string_cat(_data_struct_->out_datastr,  (char*)",");
      string_cat(_data_struct_->out_datastr, (char*)Gw_Conver_IntToStr(_data_struct_->in1_type_msg, 1));
      string_cat(_data_struct_->out_datastr,  (char*)",");
      string_cat(_data_struct_->out_datastr,  (char*)Gw_Conver_IntToStr(_data_struct_->in2_port_number, 1));
      string_cat(_data_struct_->out_datastr,  (char*)",");
      string_crc(_data_struct_->out_datastr);
      break;

    case COMM_AnswerType:
      string_copy(_data_struct_->out_datastr, (char*)COMM_HEADER);
      string_cat(_data_struct_->out_datastr, ",");
      string_cat(_data_struct_->out_datastr, Gw_Conver_IntToStr(_data_struct_->in1_type_msg, 1));
      string_cat(_data_struct_->out_datastr, ",");
      string_cat(_data_struct_->out_datastr, Gw_Conver_IntToStr(_data_struct_->in2_port_number, 1));
      string_cat(_data_struct_->out_datastr, ",");
      string_cat(_data_struct_->out_datastr, Gw_Conver_IntToStr(_data_struct_->in3_type_sensor, 1));
      string_cat(_data_struct_->out_datastr, ",");
      string_crc(_data_struct_->out_datastr);
      break;

    case COMM_AskData:
      string_copy(_data_struct_->out_datastr, (char*)COMM_HEADER);
      string_cat(_data_struct_->out_datastr, ",");
      string_cat(_data_struct_->out_datastr, Gw_Conver_IntToStr(_data_struct_->in1_type_msg, 1));
      string_cat(_data_struct_->out_datastr, ",");
      string_cat(_data_struct_->out_datastr, Gw_Conver_IntToStr(_data_struct_->in2_port_number, 1));
      string_cat(_data_struct_->out_datastr, ",");
      string_crc(_data_struct_->out_datastr);
      break;

    case COMM_AnswerData:
      string_copy(_data_struct_->out_datastr, (char*)COMM_HEADER);
      string_cat(_data_struct_->out_datastr, ",");
      string_cat(_data_struct_->out_datastr, Gw_Conver_IntToStr(_data_struct_->in1_type_msg, 1));
      string_cat(_data_struct_->out_datastr, ",");
      string_cat(_data_struct_->out_datastr, Gw_Conver_IntToStr(_data_struct_->in2_port_number, 1));
      string_cat(_data_struct_->out_datastr, ",");
      string_cat(_data_struct_->out_datastr, Gw_Conver_IntToStr(_data_struct_->in3_type_sensor, 1));
      string_cat(_data_struct_->out_datastr, ",");
      if (_data_struct_->in3_type_sensor == Sensor_SHT30)
      {
        string_cat(_data_struct_->out_datastr, Gw_Conver_FloatToStr(_data_struct_->in4_data_sensor.in1_data, 2));
        string_cat(_data_struct_->out_datastr, ",");
        string_cat(_data_struct_->out_datastr, Gw_Conver_FloatToStr(_data_struct_->in4_data_sensor.in2_data, 2));
        string_cat(_data_struct_->out_datastr, ",");
      }
      string_crc(_data_struct_->out_datastr);
      break;
  }
  return COMM_OK;
}

_comm_status_e comm_detect_command(const char *_str_datain_, _comm_data_struct_detect_t *_data_struct_)
{
	char temp_str[10][20];
	uint8_t vrui_status_error_flag = 0;
	
  if ((!string_cmp_len(_str_datain_, COMM_HEADER, 5)) || (_str_datain_[string_length(_str_datain_) - 1] != '#'))
  {
    return COMM_ERROR;
  }

  if (!string_split(temp_str, _str_datain_))
  {
    return COMM_ERROR;
  }

  _data_struct_->out1_type_msg =  (_comm_type_command_e)Gw_Conver_StrToInt(temp_str[1]);

  switch (_data_struct_->out1_type_msg)
  {
    case COMM_AskType:
      _data_struct_->out2_port_number =  (_comm_port_number_e)Gw_Conver_StrToInt(temp_str[2]);
      if (Gw_Conver_StrToInt(temp_str[3]) != checksum(_str_datain_))
      {
				vrui_status_error_flag = 1;
      }
      break;
    case COMM_AnswerType:

      _data_struct_->out2_port_number = (_comm_port_number_e)Gw_Conver_StrToInt(temp_str[2]);
      _data_struct_->out3_type_sensor = (_comm_type_sensor_e)Gw_Conver_StrToInt(temp_str[3]);
      if (Gw_Conver_StrToInt(temp_str[4]) != checksum(_str_datain_))
      {
				vrui_status_error_flag = 1;
      }
      break;
    case COMM_AskData:

      _data_struct_->out2_port_number =  (_comm_port_number_e)Gw_Conver_StrToInt(temp_str[2]);
      if (Gw_Conver_StrToInt(temp_str[3]) != checksum(_str_datain_))
      {
				vrui_status_error_flag = 1;
      }
      break;
    case COMM_AnswerData:

      _data_struct_->out2_port_number = (_comm_port_number_e)Gw_Conver_StrToInt(temp_str[2]);
      _data_struct_->out3_type_sensor =  (_comm_type_sensor_e)Gw_Conver_StrToInt(temp_str[3]);
      if (_data_struct_->out3_type_sensor == Sensor_SHT30)
      {
        _data_struct_->out4_data_sensor.in1_data = Gw_Conver_StrToFloat(temp_str[4]);
        _data_struct_->out4_data_sensor.in2_data = Gw_Conver_StrToFloat(temp_str[5]);
				if (Gw_Conver_StrToInt(temp_str[6]) != checksum(_str_datain_))
				{
					vrui_status_error_flag = 1;
				}
      }
      break;
  }
	
	if(vrui_status_error_flag)
	{
		return COMM_ERROR;
	}
	else
	{
		return COMM_OK;
	}
}

static unsigned char string_length(const char *data)
{
  unsigned char count = 0;

  while (*(data + count) != '\0')
  {
    count++;
  }
  return count;
}


void string_copy(char *destination, const char *source)
{
  unsigned char lengt_source = string_length(source), i = 0;

  for (i = 0; i < lengt_source; i++)
  {
    *(destination + i) = *(source + i);
  }
  *(destination + i) = '\0';
}

static void string_cat(char *destination, const char * source)
{
  while (*destination != '\0')
  {
    destination++;
  }

  while (*source != '\0')
  {
    *destination++ = *source++;
  }
  *destination = '\0';
}

static char string_split(char destination[][20], const char *source)
{
  unsigned char i = 0, row = 0, col = 0;

  while (source[i] != '#')
  {
    if (source[i] == ',')
    {
      destination[col][row] = '\0';
      col++;
      row = 0;
    }
    else
    {
      if (col >= 1)
      {

        if (((source[i] >= '0') && (source[i] <= '9')) || (source[i] == '.') || (source[i] == '-'))
        {
          destination[col][row] = source[i];
        }
        else
        {
          return 0;
        }
      }
      else
      {
        destination[col][row] = source[i];
      }
      row++;
    }
    i++;
  }
  destination[col][row] = '\0';
  return 1;
}


static unsigned char string_cmp_len(const char * destination, const char * source, const unsigned char length)
{
  int i = 0;
  for (i = 0; i < length; i++)
  {
    if (destination[i] != source[i])
    {
      return 0;
    }
  }
  return 1;
}

static void string_crc(char * destination)
{
  unsigned char temp_crc = 0;
  char *arr = destination;
  while (*arr != '\0')
  {
    temp_crc ^= *arr++;
  }
  string_cat(destination, Gw_Conver_IntToStr(temp_crc, 1));
  string_cat(destination, "#");
}

static unsigned char checksum(const char *_data_str_)
{
  unsigned char location, i = 0;
  static unsigned char tempcrc = 0;
  while (*(_data_str_ + i) != '\0')
  {
    if (*(_data_str_ + i) == ',')
    {
      location = i;
    }
    i++;
  }

  for (i = 0; i <= location; i++)
  {
    tempcrc ^= *(_data_str_ + i);
  }
  return tempcrc;
}
