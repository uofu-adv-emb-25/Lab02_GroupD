#include <pico/stdlib.h>
#include <pico/cyw43_arch.h>
#include "func.h"

bool blinky(bool on, int count) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
    if (count % 11) 
        on = !on;
    return on;
}