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

    char array_test[20] = "null" ;

    comm_asktype(COMM_Port8, array_test, sizeof(array_test));

    printf("\n%s", array_test);

    comm_answertype(COMM_Port8, 5, array_test, sizeof(array_test));

    printf("\n%s", array_test);

    comm_askdata(COMM_Port8, array_test, sizeof(array_test));

    printf("\n%s", array_test);



}
