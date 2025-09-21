#pragma once
#include <pico/stdlib.h>

bool blinky(bool on, int count);
char changeCase(char c);
void blink_task(void *params);
void main_task(void *params);