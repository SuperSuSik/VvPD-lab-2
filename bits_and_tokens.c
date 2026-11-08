#include <stdio.h>
#include <stdint.h>

// Раздел 9. Условный регистр
enum RegisterBit {
    REG_POWER = 1u << 0,
    REG_READY = 1u << 1,
    REG_ERROR = 1u << 2,
    REG_TX    = 1u << 3,
    REG_RX    = 1u << 4
};

static void print_binary8(uint8_t value) {
    for (int bit = 7; bit >= 0; --bit) {
        putchar((value & (1u << bit)) ? '1' : '0');
    }
}

int main(void) {
    printf("=== 8. Операторы и токены ===\n");
    
    // a+++b разбирается как (a++) + b
    int a = 5, b = 10;
    int res1 = a+++b;
    printf("a = 5, b = 10; a+++b = %d\n", res1);
    printf("После a+++b: a = %d, b = %d\n", a, b);

    // b---a разбирается как (b--) - a
    a = 5; b = 10;
    int res2 = b---a;
    printf("\na = 5, b = 10; b---a = %d\n", res2);
    printf("После b---a: a = %d, b = %d\n", a, b);

    // a = b++ + ++b; // UNDEFINED BEHAVIOR!
    // Стандарт C не гарантирует порядок вычислений, поэтому эта строка может дать разные результаты.
    printf("\n[!] Выражение a = b++ + ++b; содержит undefined behavior (изменение b дважды без sequence point).\n");
    
    printf("\n=== 9. Побитовые операции и регистр устройства ===\n");
    uint8_t reg = 0;
    printf("Исходный регистр: %u (0x%02X, bin: ", reg, reg); print_binary8(reg); printf(")\n");

    // Установить бит
    reg |= REG_POWER;
    reg |= REG_READY;
    printf("После POWER и READY: %u (0x%02X, bin: ", reg, reg); print_binary8(reg); printf(")\n");

    // Переключить бит
    reg ^= REG_TX;
    printf("После XOR TX: %u (0x%02X, bin: ", reg, reg); print_binary8(reg); printf(")\n");

    // Проверить бит
    if ((reg & REG_READY) != 0) {
        printf("Флаг READY установлен.\n");
    }

    // Сбросить бит
    reg &= ~REG_POWER;
    printf("После сброса POWER: %u (0x%02X, bin: ", reg, reg); print_binary8(reg); printf(")\n");

    return 0;
}