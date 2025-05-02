#include <iostream>



#define DEBUG
#define NUMBER  1379



int main() {
    #ifdef DEBUG
        std::cout << "Debug Mode is ON!" << std::endl;
    #else
        std::cout << "Debug Mode is OFF!" << std::endl;
    #endif

    #ifndef NUMBER
        std::cout << "Number is not defined!" << std::endl;
    #else
        std::cout << "Number is defined!" << std::endl;
    #endif


    #define VALUE 256

    std::cout << "VALUE is: " << VALUE << std::endl;

    #undef VALUE
    #define VALUE 128

    std::cout << "VALUE is: " << VALUE << std::endl;


    return 0;
}
