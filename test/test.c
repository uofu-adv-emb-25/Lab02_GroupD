#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include "unity_config.h"
#include "func.h"

void setUp(void) {}

void tearDown(void) {}

void test_blinky()
{
    int count = 11;
    TEST_ASSERT_TRUE_MESSAGE(blinky(true, count)==false, "Test assert blinky should be off, is on with passed in count 11");
    TEST_ASSERT_TRUE_MESSAGE(blinky(false, count)==true, "Test assert blinky should be on, is off with passed in count 11");

    count = 22;
    TEST_ASSERT_TRUE_MESSAGE(blinky(true, count)==false, "Test assert blinky should be off, is on with passed in count 22");
    TEST_ASSERT_TRUE_MESSAGE(blinky(false, count)==true, "Test assert blinky should be on, is off with passed in count 22");

    count = 15;
    TEST_ASSERT_TRUE_MESSAGE(blinky(true, count)==true, "Test assert blinky should be on, is off with passed in count 15");
    TEST_ASSERT_TRUE_MESSAGE(blinky(false, count)==false, "Test assert blinky should be off, is on with passed in count 15");
    
}

void test_changeCase()
{
    TEST_ASSERT_TRUE_MESSAGE(changeCase('a')=='A', "Test assert failed, wrong char returned from changecase");
    TEST_ASSERT_TRUE_MESSAGE(changeCase('A')=='a', "Test assert failed, wrong char returned from changecase");
    TEST_ASSERT_TRUE_MESSAGE(changeCase('K')=='k', "Test assert failed, wrong char returned from changecase");
    TEST_ASSERT_TRUE_MESSAGE(changeCase('[')=='[', "Test assert failed, wrong char returned from changecase");

}

void test_variable_assignment()
{
    int x = 1;
    TEST_ASSERT_TRUE_MESSAGE(x == 1,"Variable assignment failed.");
}

void test_multiplication(void)
{
    int x = 30;
    int y = 6;
    int z = x / y;
    TEST_ASSERT_TRUE_MESSAGE(z == 5, "Multiplication of two integers returned incorrect value.");
}

int main (void)
{
    while(1) {
        stdio_init_all();
        sleep_ms(5000); // Give time for TTY to attach.
        printf("Start tests\n");
        UNITY_BEGIN();
        RUN_TEST(test_blinky);
        RUN_TEST(test_changeCase);
        sleep_ms(5000);
        UNITY_END();
    }
    return UNITY_END();
}
