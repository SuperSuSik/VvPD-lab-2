#include <stdio.h>

int main(void) {
    auto int local_value = 304;
    printf("local_value = %d\n", local_value);
    
    // В C23 этот код скомпилируется, в C17 - выдаст ошибку
    auto inferred_value = 304.5; 
    printf("inferred_value = %f\n", inferred_value);
    
    return 0;
}