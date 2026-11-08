# Лабораторная работа №2. Язык С изнутри

## Структура проекта
- `types.c` — размеры типов, границы, степени двойки.
- `arrays.c` — эксперименты с неинициализированными массивами.
- `ascii_arrays.c` — массивы char/short/int/ull с одинаковыми кодами символов.
- `io_demo.c` — printf, scanf, управляющие последовательности (\n, \r, \0).
- `bits_and_tokens.c` — разбор a+++b, b---a и побитовый регистр устройства.
- `main.c` — прогресс-бар (\r), циклы, таймеры, флаги. (Сборка: `gcc -Wall -Wextra -Wpedantic -O0 main.c -o main_O0`)
- `main_multifile.c`, `device.c/h`, `timer.c/h` — многофайловый проект (extern, static).
- `standard_probe.c` — проверка __STDC_VERSION__.
- `auto_test.c` — проверка auto в C17 и C23.
- `foreach.cpp` — range-based for (аналог foreach).

## Сборка
Сборка через Make
make clean
make
make run

Сборка через CMake
cmake -S . -B build
cmake --build build
./build/vpd_lab2_multifile

### Ручная сборка
```bash
gcc -c device.c -o device.o
gcc -c timer.c -o timer.o
gcc -c main_multifile.c -o main_multifile.o
gcc main_multifile.o device.o timer.o -o vpd_lab2_multifile
./vpd_lab2_multifile