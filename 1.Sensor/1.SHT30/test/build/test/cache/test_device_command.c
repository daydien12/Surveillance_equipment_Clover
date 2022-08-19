#include "src/ringbuffer.h"
#include "src/device_command.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




void setUp(void)

{

}



void tearDown(void)

{

}



void test_function_ringbuffer_init_successful(void)

{

    char array_test[100];

    comm_asktype(1, array_test);

    printf("%s", array_test);

}
