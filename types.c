#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(void) {
    printf("=== 4.1. Размеры типов ===\n");
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(short) = %zu\n", sizeof(short));
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(long) = %zu\n", sizeof(long));
    printf("sizeof(long long) = %zu\n", sizeof(long long));
    printf("sizeof(float) = %zu\n", sizeof(float));
    printf("sizeof(double) = %zu\n", sizeof(double));
    printf("sizeof(long double) = %zu\n", sizeof(long double));
    printf("sizeof(void *) = %zu\n", sizeof(void *));
    printf("sizeof(size_t) = %zu\n", sizeof(size_t));
    printf("sizeof(uint32_t) = %zu\n", sizeof(uint32_t));
    printf("sizeof(uint64_t) = %zu\n", sizeof(uint64_t));

    printf("\n=== Границы (limits.h / stdint.h) ===\n");
    printf("INT_MIN = %d, INT_MAX = %d\n", INT_MIN, INT_MAX);
    printf("UINT_MAX = %u\n", UINT_MAX);
    printf("UINT8_MAX = %u\n", UINT8_MAX);
    printf("UINT32_MAX = %llu\n", (unsigned long long)UINT32_MAX);

    printf("\n=== 4.2. Число 304 ===\n");
    int a = 304;
    int b = 0460;   /* octal */
    int c = 0x130;  /* hexadecimal */
    // int d = 0b100110000; // C23, пока закомментируем

    printf("dec=%d oct=%o hex=%X\n", a, a, a);
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    printf("Равны ли a, b и c? %s\n", (a == b && b == c) ? "Да" : "Нет");

    printf("\n=== 4.3. Степени двойки 2^0 ... 2^20 ===\n");
    for (int i = 0; i <= 20; ++i) {
        unsigned long long val = 1ULL << i;
        printf("2^%-2d = %llu\n", i, val);
    }
    printf("2^32 = %llu\n", 1ULL << 32);
    printf("2^48 = %llu\n", 1ULL << 48);
    // 2^64 не помещается в unsigned long long (максимум 2^64 - 1)
    printf("2^64 - 1 = %llu (максимум для 64-бит)\n", UINT64_MAX);

    return 0;
}