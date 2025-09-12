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
    TEST_ASSERT_TRUE_MESSAGE(blinky(true, count)==true, "Test assert blinky should be off, is on with passed in count 11");
    TEST_ASSERT_TRUE_MESSAGE(blinky(false, count)==false, "Test assert blinky should be on, is off with passed in count 11");

    count = 22;
    TEST_ASSERT_TRUE_MESSAGE(blinky(true, count)==true, "Test assert blinky should be off, is on with passed in count 22");
    TEST_ASSERT_TRUE_MESSAGE(blinky(false, count)==false, "Test assert blinky should be on, is off with passed in count 22");

    count = 15;
    TEST_ASSERT_TRUE_MESSAGE(blinky(true, count)==false, "Test assert blinky should be on, is off with passed in count 15");
    TEST_ASSERT_TRUE_MESSAGE(blinky(false, count)==true, "Test assert blinky should be off, is on with passed in count 15");
    
    cyw243_archo_gpio_put(CYW43_WL_GPIO_LED_PIN,0);
    bool on = 0;
    for(int count = 0; count < 100 ; count++) {
        bool next_on = blinky(on,count);
        int gpioState = cyw243_archo_gpio_get(CYW43_WL_GPIO_LED_PIN);
        TEST_ASSERT_EQUAL_MESSAGE(on,gpioState,"GPIO state should be set to value of on");
        if(count % 11) {
            TEST_ASSERT_NOT_EQUAL_MESSAGE(on,next_on,"Should toggle when count is not a multiple of 11");
        } else {
            TEST_ASSERT_EQUAL_MESSAGE(on,next_on,"on should stay the same when count is multiple of 11.");
        }
        on = next_on;
    }
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
