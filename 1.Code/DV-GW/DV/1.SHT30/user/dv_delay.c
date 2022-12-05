#include "dv_delay.H"


void Dv_Delay_Us(unsigned int _vrui_Delayus)
{
    unsigned short delay_loops;
    register unsigned short i;

    delay_loops = (_vrui_Delayus + 3) / 5 * CYCLES_PER_US; 

    for (i = 0; i < delay_loops; i++)
    {
        ;
    }
}


void Dv_Delay_Ms(unsigned int _vrui_Delayms)
{
    while (_vrui_Delayms--)
    {
        Dv_Delay_Us(1000);
    }
}