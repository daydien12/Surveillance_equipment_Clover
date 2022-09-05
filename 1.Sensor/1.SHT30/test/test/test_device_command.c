

#include "device_command.h"
#include "ringbuffer.h"
#include "unity.h"

#ifdef TEST


void setUp(void)
{
}

void tearDown(void)
{
}

void test_function_ringbuffer_asktype(void)
{
    _comm_data_struct_t struct_test_comm;
    struct_test_comm.port_number = COMM_Port8;
    struct_test_comm.type_msg = COMM_AskType;
    
    TEST_ASSERT_EQUAL_INT8(comm_asktype(&struct_test_comm), COMM_OK);
    printf("\n%s", struct_test_comm.datastr);

    struct_test_comm.port_number = COMM_PortEnd;
    struct_test_comm.type_msg = COMM_AskType;
    TEST_ASSERT_EQUAL_INT8(comm_asktype(&struct_test_comm), COMM_ERROR);

    struct_test_comm.port_number = 10;
    struct_test_comm.type_msg = COMM_AskType;
    TEST_ASSERT_EQUAL_INT8(comm_asktype(&struct_test_comm), COMM_ERROR);
}



#endif // TEST
