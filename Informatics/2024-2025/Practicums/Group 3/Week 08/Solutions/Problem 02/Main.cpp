#include <iostream>


#include "Apple.hpp"

#include "Basket.hpp"



int main() {
    try {
        Basket basket;

        basket.add("Apple Name 1");
        basket.add("Apple Name 2");
        basket.add("Apple Name 3");

        basket.print();
    } catch (std::exception& exception) {
        std::cerr << exception.what() << std::endl;

        return 1;
    }


    return 0;
}
