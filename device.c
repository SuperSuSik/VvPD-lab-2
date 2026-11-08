#include "device.h"

unsigned long global_runs = 0; /* внешняя связь */
static unsigned long internal = 0; /* видима только в device.c */

void device_tick(void) {
    static unsigned long calls = 0; /* живет всю программу */
    ++global_runs;
    ++internal;
    ++calls;
}

unsigned long device_internal_calls(void) {
    return internal;
}