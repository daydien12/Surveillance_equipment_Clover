#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "src/ringbuffer.h"
#include "src/device_command.h"












void setUp(void)

{

}



void tearDown(void)

{

}



void test_function_ringbuffer_init_successful(void)

{

    _comm_data_struct_t struct_test_comm;

    struct_test_comm.port_number = COMM_Port8;

    struct_test_comm.type_msg = COMM_AskType;



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_asktype(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_OK)), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT8);

    printf("\n%s", struct_test_comm.datastr);



    struct_test_comm.port_number = COMM_PortEnd;

    struct_test_comm.type_msg = COMM_AskType;

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_asktype(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_ERROR)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT8);



    struct_test_comm.port_number = 10;

    struct_test_comm.type_msg = COMM_AskType;

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_asktype(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_ERROR)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT8);

}
