#ifdef TEST
#include "unity.h"
#include "device_command.h"
#include "ringbuffer.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_function_ringbuffer_init_successful(void)
{
    char array_test[20] = "null" ;
    comm_asktype(COMM_Port8, array_test, sizeof(array_test));
    printf("\n%s", array_test);
    comm_answertype(COMM_Port8, 5, array_test, sizeof(array_test));
    printf("\n%s", array_test);
    comm_askdata(COMM_Port8, array_test, sizeof(array_test));
    printf("\n%s", array_test);
    //printf("\n %d %d %d %d %d", COMM_Port1, COMM_Port2, COMM_Port3, COMM_Port4, COMM_PortEnd);
}



#endif // TEST
