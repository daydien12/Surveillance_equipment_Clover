#include "src/ringbuffer.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






void setUp(void)

{

}



void tearDown(void)

{

}



void test_function_ringbuffer_init_successful(void)

{

    _ringbuffer_t ringbuffer_Test;

    _rb_status_ Temp = 0;



    const unsigned int Init_value_head = 0;

    const unsigned int Init_value_tail = 0;

    unsigned char Arrary_Test[1000];



    Temp = ringbuffer_init(&ringbuffer_Test, Arrary_Test, 1000);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((Ringbuffer_OK)), (UNITY_INT)(UNITY_INT8 )((Temp)), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((Init_value_head)), (UNITY_INT)(UNITY_INT32)((ringbuffer_Test.head)), (

   ((void *)0)

   ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((Init_value_head)), (UNITY_INT)(UNITY_INT32)((ringbuffer_Test.tail)), (

   ((void *)0)

   ), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)((Arrary_Test)), (UNITY_INT)((ringbuffer_Test.data)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT64);

}



void test_function_ringbuffer_init_error(void)

{



    _ringbuffer_t ringbuffer_Test;

    _rb_status_ Temp = 0;



    const unsigned int Init_value_head = 0;

    const unsigned int Init_value_tail = 0;

    unsigned char Arrary_Test[1000];



    Temp = ringbuffer_init(&ringbuffer_Test, Arrary_Test, 0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((Ringbuffer_Error)), (UNITY_INT)(UNITY_INT8 )((Temp)), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT8);

}



void test_function_ringbuffer_push_pop(void)

{



    _ringbuffer_t ringbuffer_Test;

    _rb_status_ Temp = 0;



    const unsigned int Init_value_head = 0;

    const unsigned int Init_value_tail = 0;

    const unsigned int Size_Array = 50;

    unsigned char Arrary_Test[Size_Array], i;



    Temp = ringbuffer_init(&ringbuffer_Test, Arrary_Test, Size_Array);





    UnityAssertEqualNumber((UNITY_INT)((Arrary_Test)), (UNITY_INT)((ringbuffer_Test.data)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT64);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((Init_value_head)), (UNITY_INT)(UNITY_INT32)((ringbuffer_Test.head)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((Init_value_head)), (UNITY_INT)(UNITY_INT32)((ringbuffer_Test.tail)), (

   ((void *)0)

   ), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((Size_Array+1)), (UNITY_INT)(UNITY_INT32)((ringbuffer_Test.buffer_length)), (

   ((void *)0)

   ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT32);



    for(i=0; i<Size_Array; i++)

    {

        unsigned char Temp_data = 0;

        if(ringbuffer_push(&ringbuffer_Test, i))

        {

            if(ringbuffer_pop(&ringbuffer_Test, &Temp_data) == Ringbuffer_pop_done)

            {

                UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((Temp_data)), (UNITY_INT)(UNITY_INT32)((i)), (

               ((void *)0)

               ), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_INT32);

            }

        }

    }

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((Size_Array)), (UNITY_INT)(UNITY_INT32)((ringbuffer_Test.head)), (

   ((void *)0)

   ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((Size_Array)), (UNITY_INT)(UNITY_INT32)((ringbuffer_Test.tail)), (

   ((void *)0)

   ), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_INT32);

}



void test_function_ringbuffer_push_pop_circular (void)

{



    _ringbuffer_t ringbuffer_Test;

    _rb_status_ Temp = 0;



    const unsigned int Init_value_head = 0;

    const unsigned int Init_value_tail = 0;

    const unsigned int Size_Array = 50;

    unsigned char Arrary_Test[Size_Array], i;

    unsigned char circular_add_test = 20;

    Temp = ringbuffer_init(&ringbuffer_Test, Arrary_Test, Size_Array);





    UnityAssertEqualNumber((UNITY_INT)((Arrary_Test)), (UNITY_INT)((ringbuffer_Test.data)), (

   ((void *)0)

   ), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_INT64);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((Init_value_head)), (UNITY_INT)(UNITY_INT32)((ringbuffer_Test.head)), (

   ((void *)0)

   ), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((Init_value_head)), (UNITY_INT)(UNITY_INT32)((ringbuffer_Test.tail)), (

   ((void *)0)

   ), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((Size_Array+1)), (UNITY_INT)(UNITY_INT32)((ringbuffer_Test.buffer_length)), (

   ((void *)0)

   ), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_INT32);



    for(i=0; i<Size_Array + circular_add_test; i++)

    {

        unsigned char Temp_data = 0;

        if(ringbuffer_push(&ringbuffer_Test, i))

        {

            if(ringbuffer_pop(&ringbuffer_Test, &Temp_data) == Ringbuffer_pop_done)

            {

                UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((Temp_data)), (UNITY_INT)(UNITY_INT32)((i)), (

               ((void *)0)

               ), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_INT32);

            }

        }

    }

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((circular_add_test - 1)), (UNITY_INT)(UNITY_INT32)((ringbuffer_Test.head)), (

   ((void *)0)

   ), (UNITY_UINT)(108), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((circular_add_test - 1)), (UNITY_INT)(UNITY_INT32)((ringbuffer_Test.tail)), (

   ((void *)0)

   ), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_INT32);

}
