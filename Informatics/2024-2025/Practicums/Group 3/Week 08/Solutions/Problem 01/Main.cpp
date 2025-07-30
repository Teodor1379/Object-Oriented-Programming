#include <iostream>


#include "Date.hpp"



int main() {
    try {
        std::cout << std::boolalpha << "Result 1 is: "  << (Date(1, 10, 2022) == Date(1, 10, 2022)) << std::endl;
        std::cout << std::boolalpha << "Result 2 is: "  << (Date(3, 10, 2024) != Date(9, 10, 2024)) << std::endl;
    } catch (std::exception& exception) {
        std::cerr << exception.what() << std::endl;

        return 1;
    }


    return 0;
}
