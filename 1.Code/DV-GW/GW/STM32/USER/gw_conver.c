
#include "gw_conver.h"
#include "math.h"
static void Conver_reverse(char* str, int len);
static uint8_t Conver_intToStr(int32_t x, char str[], uint8_t d, uint8_t negative);

static void Conver_reverse(char* str, int len)
{
  int i = 0, j = len - 1, temp;
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

char* Gw_Conver_IntToStr(const int32_t _data_, uint8_t d)
{
	uint8_t i = 0, negative = 0;
	int32_t vrui_tempdata = _data_;
	
	static char str[10];
	if(_data_ < 0)
	{
		negative = 1;
		vrui_tempdata *= -1;
	}
	
  while (vrui_tempdata) {
    str[i++] = (vrui_tempdata % 10) + '0';
    vrui_tempdata = vrui_tempdata / 10;
  }
	
  while (i < d)
	{
    str[i++] = '0';
	}
	
	if(negative == 1)
	{
		str[i++]= '-';
	}
  Conver_reverse(str, i);
  str[i] = '\0';
  return str;
}

static uint8_t Conver_intToStr(int32_t x, char str[], uint8_t d, uint8_t negative)
{
  uint8_t i = 0, vrui_negative = 0;
	if(x < 0)
	{
		vrui_negative = 1;
		x *= -1;
	}
  while (x) {
    str[i++] = (x % 10) + '0';
    x = x / 10;
  }
  while (i < d)
    str[i++] = '0';
	
	if((vrui_negative == 1)||(negative == 1))
	{
		str[i++]= '-';
	}
	
  Conver_reverse(str, i);
  str[i] = '\0';
  return i;
}

char* Gw_Conver_FloatToStr(const float _data_, uint8_t afterpoint)
{
	uint8_t i = 0, vrui_negative = 0;
	static char str[20];
	int ipart = (int)_data_;
  float fpart = _data_ - (float)ipart;
	if(_data_ < 0)
	{
		vrui_negative = 1;
	}
	if(fpart < 0)
	{
		fpart *= -1.0;
	}
  i = Conver_intToStr(ipart, str, 1, vrui_negative);
  if (afterpoint != 0) {
    str[i] = '.';
    fpart = fpart * pow(10, afterpoint);
    Conver_intToStr((int)fpart, str + i + 1, afterpoint, 0);
  }
	return str;
}


float Gw_Conver_StrToFloat(const char *_data_)
{
  float val = 0;
  int afterdot=0;
  float scale=1;
  int neg = 0; 

  if (*_data_ == '-') {
    _data_++;
    neg = 1;
  }
  while (*_data_) {
    if (afterdot) {
      scale = scale/10;
      val = val + (*_data_-'0')*scale;
    } else {
      if (*_data_ == '.') 
    afterdot++;
      else
    val = val * 10.0 + (*_data_ - '0');
    }
    _data_++;
  }
  if(neg) return -val;
  else    return  val;
}


int32_t Gw_Conver_StrToInt(const char *_data_)
{
  int32_t result = 0;
  int32_t puiss = 1;

  puiss = 1;
  while (('-' == (*_data_)) || ((*_data_) == '+'))
  {
      if (*_data_ == '-')
        puiss = puiss * -1;
      _data_++;
  }
  while ((*_data_ >= '0') && (*_data_ <= '9'))
  {
      result = (result * 10) + ((*_data_) - '0');
      _data_++;
  }
  return (result * puiss);
}
