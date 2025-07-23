#include <cassert>
#include <cstdint>

#include <limits>

#include <iostream>



union Number {
    struct Form1 {
        std::int32_t part1  : 16;
        std::int32_t part2  : 16;
    };

    struct Form2 {
        std::int32_t mantissa   :   23;
        std::int32_t exponent   :    8;
        std::int32_t sign       :    1;
    };

    Form1 form1;
    Form2 form2;
};



std::int32_t readPart(const char*);



unsigned int findDigits(std::int32_t);



Number buildForm1Number(std::int32_t, std::int32_t);
Number buildForm2Number(std::int32_t, std::int32_t);



void printForm1Number(const Number&);
void printForm2Number(const Number&);



int main() {
    std::int32_t wholePart = readPart("Whole");
    std::int32_t fractPart = readPart("Fract");

    if (fractPart < 0) {
        std::cerr << "Invalid Fractional Part!" << std::endl;

        return 1;
    }


    printForm1Number(buildForm1Number(wholePart, fractPart));
    printForm2Number(buildForm2Number(wholePart, fractPart));


    return 0;
}



std::int32_t readPart(const char* string) {
    assert(string !=    nullptr );

    std::int32_t result = 0;

    while (true) {
        std::cout << "Enter the number - " << string << " Part: ";

        std::cin >> result;

        if (std::cin.fail()) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return result;
        }
    }
}



unsigned int findDigits(std::int32_t number) {
    number = std::abs(number);

    unsigned int result = 0;

    while (number > 0) {
        result = result + 1;
        number = number / 10;
    }

    return result;
}



Number buildForm1Number(std::int32_t wholePart, std::int32_t fractPart) {
    Number result;

    result.form1.part1 = wholePart;
    result.form1.part2 = fractPart;

    return result;
}

Number buildForm2Number(std::int32_t wholePart, std::int32_t fractPart) {
    Number result;

    if (wholePart < 0) {
        result.form2.sign = -1;
    } else {
        result.form2.sign =  0;
    }

    wholePart = std::abs(wholePart);

    unsigned int digitsWhole = findDigits(wholePart);
    unsigned int digitsFract = findDigits(fractPart);

    for (unsigned int i = 1; i <= digitsFract; ++i) {
        wholePart = wholePart * 10;
    }

    wholePart = wholePart + fractPart;

    result.form2.mantissa = wholePart       ;
    result.form2.exponent = digitsWhole - 1 ;

    return result;
}



void printForm1Number(const Number& number) {
    std::cout << "The number is: ";

    std::cout << number.form1.part1 << '.'  ;
    std::cout << number.form1.part2 << '\n' ;
}

void printForm2Number(const Number& number) {
    std::cout << "The number is: ";

    if (number.form2.sign == 0) {
        std::cout << '+';
    } else {
        std::cout << '-';
    }

    unsigned int digits = findDigits(number.form2.mantissa);

    unsigned int coefficient = 1;

    for (unsigned int i = 1; i < digits; ++i) {
        coefficient = coefficient * 10;
    }

    std::cout << number.form2.mantissa / coefficient << '.';
    std::cout << number.form2.mantissa % coefficient << 'e';
    
    std::cout << number.form2.exponent << '\n';
}
