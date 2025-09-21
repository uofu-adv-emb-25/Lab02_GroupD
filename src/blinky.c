#include <pico/stdlib.h>
#include <pico/cyw43_arch.h>
#include "func.h"

bool blinky(bool on, int count) {

    //printf("entered blinky subroutine\n");

    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);

    //printf("before mod in subroutine\n");

    if (count % 11)
        on = !on;

    //printf("after mod in subroutine\n");
    //printf("returning from blinky subroutine\n");
    return on;
}