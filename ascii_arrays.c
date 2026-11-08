#include <stdio.h>

int main(void) {
    // Создаем массивы с одинаковыми кодами символов, но разными типами
    char a[] = {'M', 'A', 'I', '3', '0', '4', '\0'};
    short b[] = {'M', 'A', 'I', '3', '0', '4', '\0'};
    int c[] = {'M', 'A', 'I', '3', '0', '4', '\0'};
    unsigned long long d[] = {'M', 'A', 'I', '3', '0', '4', '\0'};

    printf("=== Поэлементный вывод через %%c ===\n");
    printf("char: ");
    for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) printf("%c", a[i]);
    printf("\nshort: ");
    for (size_t i = 0; i < sizeof(b)/sizeof(b[0]); ++i) printf("%c", (char)b[i]);
    printf("\nint: ");
    for (size_t i = 0; i < sizeof(c)/sizeof(c[0]); ++i) printf("%c", (char)c[i]);
    printf("\nunsigned long long: ");
    for (size_t i = 0; i < sizeof(d)/sizeof(d[0]); ++i) printf("%c", (char)d[i]);
    printf("\n");

    printf("\n=== Вывод через %%s (с символом \\0) ===\n");
    printf("char: %s\n", a);
    // Для остальных типов %s НЕ РАБОТАЕТ так, как мы ожидаем, 
    // потому что они не являются массивами char. 
    // Мы добавили \0, но %s всё равно будет читать байты неверно.
    // Выведем их через %s с приведением (это вызовет предупреждение, но покажет суть):
    printf("int (через приведение к char*): %s\n", (char*)c); 
    // На mac ARM64 int занимает 4 байта, и в памяти 'M' (77) будет лежать как 4D 00 00 00. 
    // Поэтому %s выведет только 'M' и остановится на нуле.

    printf("\n=== Размеры массивов ===\n");
    printf("sizeof(a) = %zu\n", sizeof(a));
    printf("sizeof(b) = %zu\n", sizeof(b));
    printf("sizeof(c) = %zu\n", sizeof(c));
    printf("sizeof(d) = %zu\n", sizeof(d));

    return 0;
}