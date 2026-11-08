#include <stdio.h>
#include <stdint.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

enum LabStage {
    STAGE_FOR,
    STAGE_WHILE,
    STAGE_DO_WHILE,
    STAGE_DONE
};

enum LabFlag {
    FLAG_TYPES  = 1u << 0,
    FLAG_ARRAYS = 1u << 1,
    FLAG_BITS   = 1u << 2,
    FLAG_FOR    = 1u << 3,
    FLAG_WHILE  = 1u << 4,
    FLAG_DO     = 1u << 5
};

static void print_progress(const char *stage, unsigned percent) {
    const unsigned width = 30;
    unsigned filled = percent * width / 100;
    printf("\r%-12s [", stage);
    for (unsigned i = 0; i < width; ++i) {
        putchar(i < filled ? '#' : '-');
    }
    printf("] %3u%%", percent);
    fflush(stdout);
}

#ifndef _WIN32
static double high_res_seconds(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}
#else
static double high_res_seconds(void) {
    LARGE_INTEGER counter, frequency;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart / (double)frequency.QuadPart;
}
#endif

#define ITERATIONS_PER_STEP 1200000000ULL
static uint64_t do_workload(uint64_t count) {
    uint64_t checksum = 0;
    for (uint64_t i = 0; i < count; ++i) {
        checksum ^= i;
        checksum = (checksum << 1) | (checksum >> 63);
        checksum += 0x9e3779b97f4a7c15ULL;
    }
    return checksum;
}

int main(void) {
    unsigned completed = 0;
    uint64_t total_checksum = 0;
    
    time_t wall_start = time(NULL);
    clock_t cpu_start = clock();
    double hi_start = high_res_seconds();

    // STAGE_FOR
    printf("Stage: FOR\n");
    for (unsigned p = 0; p <= 100; p += 10) {
        // На каждой итерации делаем 1/10 часть работы
        total_checksum ^= do_workload(ITERATIONS_PER_STEP / 10);
        print_progress("STAGE_FOR", p);
    }
    printf("\n");
    completed |= FLAG_FOR;

    // STAGE_WHILE
    printf("Stage: WHILE\n");
    unsigned p = 0;
    while (p <= 100) {
        total_checksum ^= do_workload(ITERATIONS_PER_STEP / 10);
        print_progress("STAGE_WHILE", p);
        p += 10;
    }
    printf("\n");
    completed |= FLAG_WHILE;

    // STAGE_DO_WHILE
    printf("Stage: DO-WHILE\n");
    p = 0;
    do {
        total_checksum ^= do_workload(ITERATIONS_PER_STEP / 10);
        print_progress("STAGE_DO_WHILE", p);
        p += 10;
    } while (p <= 100);
    printf("\n");
    completed |= FLAG_DO;

    time_t wall_end = time(NULL);
    clock_t cpu_end = clock();
    double hi_end = high_res_seconds();

    printf("\n=== Результаты ===\n");
    printf("Итоговый checksum: %llu\n", (unsigned long long)total_checksum);
    
    printf("\n=== Измерение времени ===\n");
    printf("1. time/difftime: %.0f s\n", difftime(wall_end, wall_start));
    printf("2. clock/CLOCKS_PER_SEC: %.6f s\n", (double)(cpu_end - cpu_start) / CLOCKS_PER_SEC);
    printf("3. high-resolution time: %.6f s\n", hi_end - hi_start);

    printf("\n=== Маска завершенных флагов ===\n");
    printf("completed = 0x%02X (bin: ", completed);
    for (int bit = 7; bit >= 0; --bit) putchar((completed & (1u << bit)) ? '1' : '0');
    printf(")\n");

    // Проверка обязательных флагов
    if ((completed & (FLAG_FOR | FLAG_WHILE | FLAG_DO)) == (FLAG_FOR | FLAG_WHILE | FLAG_DO)) {
        printf("Все обязательные флаги (FOR, WHILE, DO) выставлены!\n");
    } else {
        printf("Внимание: не все флаги выставлены.\n");
    }

    return 0;
}