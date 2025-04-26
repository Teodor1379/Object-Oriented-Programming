#include <iostream>



int main() {
    bool condition1 = true  ;
    bool condition2 = false ;

    std::cout << "Condition 1: " << condition1 << std::endl;
    std::cout << "Condition 2: " << condition2 << std::endl;

    std::cout << std::boolalpha << "Condition 1: " << condition1 << std::endl;
    std::cout << std::boolalpha << "Condition 2: " << condition2 << std::endl;

    std::cout << std::noboolalpha << "Condition 1: " << condition1 << std::endl;
    std::cout << std::noboolalpha << "Condition 2: " << condition2 << std::endl;

    
    std::cout << std::dec << 1379 << std::endl; // Decimal      Base
    std::cout << std::oct << 1379 << std::endl; // Octal        Base
    std::cout << std::hex << 1379 << std::endl; // Hexadecimal  Base


    return 0;
}
