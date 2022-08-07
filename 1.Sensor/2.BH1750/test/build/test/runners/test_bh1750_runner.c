/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "cmock.h"
#include "mock_i2c.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_function_bh1750_Reset(void);
extern void test_function_bh1750_PowerState(void);
extern void test_function_bh1750_SetMtreg(void);
extern void test_function_bh1750_SetMode();
extern void test_function_bh1750_ReadLight(void);
extern void test_function_bh1750_Init(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_i2c_Init();
}
static void CMock_Verify(void)
{
  mock_i2c_Verify();
}
static void CMock_Destroy(void)
{
  mock_i2c_Destroy();
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_bh1750.c");
  run_test(test_function_bh1750_Reset, "test_function_bh1750_Reset", 17);
  run_test(test_function_bh1750_PowerState, "test_function_bh1750_PowerState", 23);
  run_test(test_function_bh1750_SetMtreg, "test_function_bh1750_SetMtreg", 32);
  run_test(test_function_bh1750_SetMode, "test_function_bh1750_SetMode", 61);
  run_test(test_function_bh1750_ReadLight, "test_function_bh1750_ReadLight", 83);
  run_test(test_function_bh1750_Init, "test_function_bh1750_Init", 115);

  CMock_Guts_MemFreeFinal();
  return UnityEnd();
}