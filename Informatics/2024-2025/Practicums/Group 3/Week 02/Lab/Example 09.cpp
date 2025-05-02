#include <iostream>



int main() {
    #if defined(PI)
        std::cout << "Hello World!" << std::endl;
    #else
        #warning "PI is not defined!"
    #endif


    #if defined(PI)
        std::cout << "Hello World!" << std::endl;
    #else
        #error "PI is not defined!"
    #endif

    // warning: #warning "PI is not defined!" [-Wcpp]

    
    return 0;
}
