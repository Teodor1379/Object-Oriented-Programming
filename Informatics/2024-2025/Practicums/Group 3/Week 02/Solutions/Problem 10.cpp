#include <cstdint>

#include <limits>

#include <iostream>



union Flags {
    struct Bits {
        bool b1 :   1;
        bool b2 :   1;
        bool b3 :   1;
        bool b4 :   1;
        bool b5 :   1;
        bool b6 :   1;
        bool b7 :   1;
        bool b8 :   1;
    };

    Bits            form1;
    std::uint8_t    form2;
};



std::uint8_t readNumber();



Flags buildForm1Flags(std::uint8_t);
Flags buildForm2Flags(std::uint8_t);



void printForm1Flags(const Flags&);
void printForm2Flags(const Flags&);



int main() {
    std::uint8_t number = readNumber();

    std::cout << std::endl;


    printForm1Flags(buildForm1Flags(number));
    printForm2Flags(buildForm2Flags(number));


    return 0;
}



std::uint8_t readNumber() {
    std::uint8_t number = 0;

    while (true) {
        std::cout << "Enter the number: ";

        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return number;
        }
    }
}



Flags buildForm1Flags(std::uint8_t number) {
    Flags result;

    result.form1.b1 = (number >> 0) & 1;
    result.form1.b2 = (number >> 1) & 1;
    result.form1.b3 = (number >> 2) & 1;
    result.form1.b4 = (number >> 3) & 1;
    result.form1.b5 = (number >> 4) & 1;
    result.form1.b6 = (number >> 5) & 1;
    result.form1.b7 = (number >> 6) & 1;
    result.form1.b8 = (number >> 7) & 1;

    return result;
}

Flags buildForm2Flags(std::uint8_t number) {
    Flags result;

    result.form2 = number;

    return result;
}



void printForm1Flags(const Flags& flags) {
    std::cout << "The number is: ";

    std::cout << static_cast<bool>(flags.form1.b1);
    std::cout << static_cast<bool>(flags.form1.b2);
    std::cout << static_cast<bool>(flags.form1.b3);
    std::cout << static_cast<bool>(flags.form1.b4);
    std::cout << static_cast<bool>(flags.form1.b5);
    std::cout << static_cast<bool>(flags.form1.b6);
    std::cout << static_cast<bool>(flags.form1.b7);
    std::cout << static_cast<bool>(flags.form1.b8);

    std::cout << std::endl;
}

void printForm2Flags(const Flags& flags) {
    std::cout << "The number is: ";

    std::cout << flags.form2;

    std::cout << std::endl;
}
