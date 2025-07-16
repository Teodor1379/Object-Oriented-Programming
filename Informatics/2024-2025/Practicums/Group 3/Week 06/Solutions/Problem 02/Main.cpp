#include "Chocolate.hpp"



int main() {
    try {
        Chocolate chocolate("Chocolate Name", 9.0, 33.0);

        chocolate.print();
    } catch (std::exception& exception) {
        std::cerr << exception.what() << std::endl;

        return 1;
    }


    return 0;
}
