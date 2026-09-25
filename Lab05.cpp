#include "binom.hpp"
#include <iostream>

int main() {
    std::cout << "First task" << std::endl;
    Binom b(10, 0.5);
    for (int i = 0; i < 10; i++) {
        std::cout << b.factorial(i) << std::endl;
    }
}