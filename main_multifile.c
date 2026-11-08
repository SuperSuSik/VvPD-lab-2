#include <stdio.h>
#include "device.h"
#include "timer.h"

int main(void) {
    printf("=== 13.1. Глобальные и static переменные ===\n");
    
    // Обращаемся к глобальной переменной через extern из device.h
    printf("global_runs до вызовов: %lu\n", global_runs);
    
    // Вызываем функцию из device.c
    for (int i = 0; i < 5; ++i) {
        device_tick();
    }
    
    printf("global_runs после 5 вызовов: %lu\n", global_runs);
    printf("internal calls: %lu\n", device_internal_calls());
    
    // Обратиться к internal напрямую нельзя:
    // printf("%lu", internal); // Ошибка компиляции: undeclared identifier

    printf("\n=== 14. const и #define ===\n");
    #define BUFFER_SIZE 304
    const size_t buffer_size = 304;
    printf("BUFFER_SIZE = %d, buffer_size = %zu\n", BUFFER_SIZE, buffer_size);

    #define BAD_SQUARE(x) x * x
    #define GOOD_SQUARE(x) ((x) * (x))
    printf("BAD_SQUARE(2 + 3) = %d\n", BAD_SQUARE(2 + 3));   // 2 + 3 * 2 + 3 = 11
    printf("GOOD_SQUARE(2 + 3) = %d\n", GOOD_SQUARE(2 + 3)); // (2 + 3) * (2 + 3) = 25

    printf("\n=== 12. Измерение времени (высокоточный таймер) ===\n");
    double start = get_high_res_time();
    // Небольшая нагрузка для теста
    volatile int sum = 0;
    for (int i = 0; i < 10000000; ++i) sum += i;
    double end = get_high_res_time();
    print_time_diff("timer.c test", start, end);

    return 0;
}