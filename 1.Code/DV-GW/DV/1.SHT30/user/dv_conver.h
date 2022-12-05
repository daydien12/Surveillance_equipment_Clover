
	
#ifndef __GW_CONVER__H__
#define __GW_CONVER__H__

#ifdef __cplusplus
 extern "C" {
#endif
   
#include "stm8s.h"
   
char* Gw_Conver_IntToStr(const int32_t _data_, uint8_t d);
char* Gw_Conver_FloatToStr(const float _data_, uint8_t afterpoint);

int32_t Gw_Conver_StrToInt(const char *_data_);
float 	Gw_Conver_StrToFloat(const char *_data_);

#ifdef __cplusplus
}
#endif

#endif

/********************************* END OF FILE ********************************/
/******************************************************************************/
