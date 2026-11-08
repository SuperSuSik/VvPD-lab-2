#include <stdio.h>

int main(void) {
    printf("=== 7.2. Управляющие последовательности ===\n");
    printf("AAA\tBBB\n");
    // \r возвращает каретку в начало строки, поэтому 'SECOND' заменит 'first'
    printf("first\rSECOND\n"); 
    // \0 (нулевой символ) обрывает строку для функций, работающих со строками
    printf("one\0two\n"); 
    printf("quote: \"C\" and slash: \\n\n");

    printf("\n=== 7.3. Ввод чисел ===\n");
    
    int number;
    printf("Введите целое число (int): ");
    if (scanf("%d", &number) != 1) {
        fprintf(stderr, "Ошибка: неверный ввод (ожидалось int)\n");
        return 1;
    }
    printf("Вы ввели: %d\n", number);

    unsigned int u_number;
    printf("Введите положительное число (unsigned int): ");
    if (scanf("%u", &u_number) != 1) {
        fprintf(stderr, "Ошибка: неверный ввод (ожидалось unsigned int)\n");
        return 1;
    }
    printf("Вы ввели: %u\n", u_number);

    double d_number;
    printf("Введите дробное число (double): ");
    if (scanf("%lf", &d_number) != 1) {
        fprintf(stderr, "Ошибка: неверный ввод (ожидалось double)\n");
        return 1;
    }
    printf("Вы ввели: %f\n", d_number);

    return 0;
}