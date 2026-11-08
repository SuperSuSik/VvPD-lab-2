#include <stdio.h>
#include "timer.h"

#ifdef _WIN32
#include <windows.h>
double get_high_res_time(void) {
    LARGE_INTEGER counter, frequency;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&counter);
    return (double)counter.QuadPart / (double)frequency.QuadPart;
}
#else
#include <sys/time.h>
double get_high_res_time(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}
#endif

void print_time_diff(const char* label, double start, double end) {
    printf("%s: %.6f s\n", label, end - start);
}