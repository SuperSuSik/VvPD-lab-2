#include <stdio.h>

int main(void) {
    // 1. Создаем массивы БЕЗ инициализации
    char chars[304];
    int integers[25];
    double reals[25];

    // ВНИМАНИЕ: Лаба просит поэкспериментировать с чтением неинициализированных массивов.
    // В реальном коде так делать НЕЛЬЗЯ (это Undefined Behavior).
    printf("=== Эксперимент с неинициализированными массивами ===\n");
    printf("chars[0] (мусор) = %d\n", chars[0]);
    printf("integers[0] (мусор) = %d\n", integers[0]);
    printf("reals[0] (мусор) = %f\n", reals[0]);

    // 2. Инициализируем нулями
    char chars_init[304] = {0};
    int integers_init[25] = {0};
    double reals_init[25] = {0};

    printf("\n=== Массивы после инициализации нулями ===\n");
    printf("chars_init[0] = %d\n", chars_init[0]);
    printf("integers_init[0] = %d\n", integers_init[0]);
    printf("reals_init[0] = %f\n", reals_init[0]);

    // 3. Заполняем осмысленными значениями
    for (int i = 0; i < 25; ++i) {
        integers[i] = i * i;      // Квадраты чисел
        reals[i] = i * 1.5;       // Дробные числа
    }
    for (int i = 0; i < 304; ++i) {
        chars[i] = (char)('A' + (i % 26)); // Заполняем буквами A-Z
    }
    
    // Добавим нулевой байт в конец для безопасного вывода
    chars[303] = '\0'; 

    printf("\n=== Вывод массивов ===\n");
    printf("integers (первые 5):\n");
    for (int i = 0; i < 5; ++i) printf("  integers[%d] = %d\n", i, integers[i]);
    
    printf("reals (первые 5):\n");
    for (int i = 0; i < 5; ++i) printf("  reals[%d] = %.1f\n", i, reals[i]);

    printf("chars (таблица 10x3):\n");
    for (int i = 0; i < 30; ++i) {
        printf("%c ", chars[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    // Вывод размеров
    printf("\n=== Размеры массивов ===\n");
    printf("sizeof(chars) = %zu\n", sizeof(chars));
    printf("sizeof(chars[0]) = %zu\n", sizeof(chars[0]));
    printf("Кол-во элементов chars = %zu\n", sizeof(chars) / sizeof(chars[0]));
    
    return 0;
}