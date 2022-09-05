#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
#include "src/ringbuffer.h"
#include "src/device_command.h"








void setUp(void)

{

}



void tearDown(void)

{

}



void test_function_command_asktype(void)

{



    _comm_data_struct_create_t struct_test_comm;

    struct_test_comm.port_number = COMM_Port8;

    struct_test_comm.type_msg = COMM_AskType;



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_create_command(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_OK)), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT8);

    printf("%s\n", struct_test_comm.datastr);





    struct_test_comm.port_number = COMM_PortEnd;

    struct_test_comm.type_msg = COMM_AskType;

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_create_command(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_ERROR)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT8);





    struct_test_comm.port_number = 10;

    struct_test_comm.type_msg = COMM_AskType;

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_create_command(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_ERROR)), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT8);

}



void test_function_command_answertype(void)

{



    _comm_data_struct_create_t struct_test_comm;

    struct_test_comm.port_number = COMM_Port8;

    struct_test_comm.type_msg = COMM_AnswerType;

    struct_test_comm.type_sensor = Sensor_1;



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_create_command(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_OK)), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT8);

    printf("%s\n", struct_test_comm.datastr);





    struct_test_comm.port_number = COMM_PortEnd;

    struct_test_comm.type_msg = COMM_AnswerType;

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_create_command(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_ERROR)), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT8);





    struct_test_comm.port_number = 10;

    struct_test_comm.type_msg = COMM_AnswerType;

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_create_command(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_ERROR)), (

   ((void *)0)

   ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT8);





    struct_test_comm.port_number = COMM_Port8;

    struct_test_comm.type_msg = COMM_AnswerType;

    struct_test_comm.type_sensor = Sensor_end;

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_create_command(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_ERROR)), (

   ((void *)0)

   ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT8);

}



void test_function_command_askdata(void)

{



    _comm_data_struct_create_t struct_test_comm;

    struct_test_comm.port_number = COMM_Port8;

    struct_test_comm.type_msg = COMM_AskData;



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_create_command(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_OK)), (

   ((void *)0)

   ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT8);

    printf("%s\n", struct_test_comm.datastr);





    struct_test_comm.port_number = COMM_PortEnd;

    struct_test_comm.type_msg = COMM_AskData;

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_create_command(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_ERROR)), (

   ((void *)0)

   ), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_INT8);





    struct_test_comm.port_number = 10;

    struct_test_comm.type_msg = COMM_AskData;

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_create_command(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_ERROR)), (

   ((void *)0)

   ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT8);

}



void test_function_command_detect_askdata(void)

{

    _comm_data_struct_create_t struct_test_comm;

    _comm_data_struct_detect_t struct_data_test;

    struct_test_comm.port_number = COMM_Port8;

    struct_test_comm.type_msg = COMM_AnswerType;

    struct_test_comm.type_sensor = Sensor_1;



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((comm_create_command(&struct_test_comm))), (UNITY_INT)(UNITY_INT8 )((COMM_OK)), (

   ((void *)0)

   ), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_INT8);

    printf("%s\n", struct_test_comm.datastr);



    comm_detect_command(struct_test_comm.datastr,sizeof(struct_test_comm.datastr), &struct_data_test);

}
