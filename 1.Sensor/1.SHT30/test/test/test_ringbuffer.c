#ifdef TEST
#include "unity.h"
#include "ringbuffer.h"

#define Size_ringbuffer 1000
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
    unsigned char Arrary_Test[Size_ringbuffer];

    Temp = ringbuffer_init(&ringbuffer_Test, Arrary_Test, Size_ringbuffer);
    TEST_ASSERT_EQUAL_INT8(Ringbuffer_OK, Temp);
    TEST_ASSERT_EQUAL_INT32(Init_value_head, ringbuffer_Test.head);
    TEST_ASSERT_EQUAL_INT32(Init_value_head, ringbuffer_Test.tail);
    TEST_ASSERT_EQUAL_INT64(Arrary_Test, ringbuffer_Test.data);
}

void test_function_ringbuffer_init_error(void)
{

    _ringbuffer_t ringbuffer_Test;
    _rb_status_ Temp = 0;

    const unsigned int Init_value_head = 0;
    const unsigned int Init_value_tail = 0;
    unsigned char Arrary_Test[Size_ringbuffer];

    Temp = ringbuffer_init(&ringbuffer_Test, Arrary_Test, 0);
    TEST_ASSERT_EQUAL_INT8(Ringbuffer_Error, Temp);
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


    TEST_ASSERT_EQUAL_INT64(Arrary_Test, ringbuffer_Test.data);             // check address
    TEST_ASSERT_EQUAL_INT32(Init_value_head, ringbuffer_Test.head);         // check khởi tạo head
    TEST_ASSERT_EQUAL_INT32(Init_value_head, ringbuffer_Test.tail);         // check khơi tạo tail
    TEST_ASSERT_EQUAL_INT32(Size_Array+1, ringbuffer_Test.buffer_length);   // check leng array
    
    for(i=0; i<Size_Array; i++)
    {
        unsigned char Temp_data = 0;
        if(ringbuffer_push(&ringbuffer_Test, i))
        {
            if(ringbuffer_pop(&ringbuffer_Test, &Temp_data) == Ringbuffer_pop_done)
            {
                TEST_ASSERT_EQUAL_INT32(Temp_data, i);
            }
        }
    }
    TEST_ASSERT_EQUAL_INT32(Size_Array, ringbuffer_Test.head);
    TEST_ASSERT_EQUAL_INT32(Size_Array, ringbuffer_Test.tail);
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


    TEST_ASSERT_EQUAL_INT64(Arrary_Test, ringbuffer_Test.data);             // check address
    TEST_ASSERT_EQUAL_INT32(Init_value_head, ringbuffer_Test.head);         // check khởi tạo head
    TEST_ASSERT_EQUAL_INT32(Init_value_head, ringbuffer_Test.tail);         // check khơi tạo tail
    TEST_ASSERT_EQUAL_INT32(Size_Array+1, ringbuffer_Test.buffer_length);   // check leng array
    
    for(i=0; i<Size_Array + circular_add_test; i++)
    {
        unsigned char Temp_data = 0;
        if(ringbuffer_push(&ringbuffer_Test, i))
        {
            if(ringbuffer_pop(&ringbuffer_Test, &Temp_data) == Ringbuffer_pop_done)
            {
                TEST_ASSERT_EQUAL_INT32(Temp_data, i);
            }
        }
    }
    TEST_ASSERT_EQUAL_INT32(circular_add_test - 1, ringbuffer_Test.head);
    TEST_ASSERT_EQUAL_INT32(circular_add_test - 1, ringbuffer_Test.tail);
}

#endif // TEST
