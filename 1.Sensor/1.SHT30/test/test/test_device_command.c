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
    char array_test[100];
    comm_asktype(125, array_test);
    printf("%s", array_test);
}



#endif // TEST
