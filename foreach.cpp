#include <iostream>
#include <vector>

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5};
    
    // Range-based for (аналог foreach в C++)
    for (const auto value : values) {
        std::cout << value << '\n';
    }
    
    return 0;
}