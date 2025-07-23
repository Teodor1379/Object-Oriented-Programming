#include <cmath>

#include <cassert>

#include <limits>

#include <iomanip>

#include <iostream>



const double EPSILON = 1E-9;



struct ComplexNumber {
    double realPart =   0.0;
    double imagPart =   0.0;
};



double  readNumber();



bool    validateComplexNumber(const    ComplexNumber&  );



ComplexNumber   buildComplexNumber();



bool    isRealNumber(const ComplexNumber&);
bool    isImagNumber(const ComplexNumber&);
bool    isZeroNumber(const ComplexNumber&);



void printComplexNumber(const ComplexNumber&);



ComplexNumber   sumComplexNumbers(const ComplexNumber&, const ComplexNumber&);
ComplexNumber   difComplexNumbers(const ComplexNumber&, const ComplexNumber&);
ComplexNumber   prdComplexNumbers(const ComplexNumber&, const ComplexNumber&);
ComplexNumber   divComplexNumbers(const ComplexNumber&, const ComplexNumber&);



void printComplexNumberKind(const ComplexNumber&);



int main() {
    std::cout << "Enter the data for Complex Number 1: ";   ComplexNumber number1 = buildComplexNumber();   // warning: function call has aggregate value [-Waggregate-return]
    std::cout << "Enter the data for Complex Number 2: ";   ComplexNumber number2 = buildComplexNumber();   // warning: function call has aggregate value [-Waggregate-return]
    std::cout << "Enter the data for Complex Number 3: ";   ComplexNumber number3 = buildComplexNumber();   // warning: function call has aggregate value [-Waggregate-return]
    std::cout << "Enter the data for Complex Number 4: ";   ComplexNumber number4 = buildComplexNumber();   // warning: function call has aggregate value [-Waggregate-return]


    printComplexNumber(sumComplexNumbers(number1, number2));    // warning: function call has aggregate value [-Waggregate-return]
    printComplexNumber(difComplexNumbers(number2, number3));    // warning: function call has aggregate value [-Waggregate-return]
    printComplexNumber(prdComplexNumbers(number3, number4));    // warning: function call has aggregate value [-Waggregate-return]
    printComplexNumber(divComplexNumbers(number4, number1));    // warning: function call has aggregate value [-Waggregate-return]


    std::cout << "The kind of Complex Number 1 is: ";   printComplexNumberKind(number1);    std::cout << std::endl;
    std::cout << "The kind of Complex Number 2 is: ";   printComplexNumberKind(number2);    std::cout << std::endl;
    std::cout << "The kind of Complex Number 3 is: ";   printComplexNumberKind(number3);    std::cout << std::endl;
    std::cout << "The kind of Complex Number 4 is: ";   printComplexNumberKind(number4);    std::cout << std::endl;


    return 0;
}



double readNumber() {
    double number = 0.0;

    while (true) {
        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            return number;
        }
    }
}



bool validateComplexNumber(const ComplexNumber& number) {
    return
        std::isfinite(number.realPart)  &&
        std::isfinite(number.imagPart);
}



ComplexNumber buildComplexNumber() {
    ComplexNumber complexNumber;

    complexNumber.realPart  =   readNumber();
    complexNumber.imagPart  =   readNumber();
    
    return complexNumber;

    // warning: function returns an aggregate [-Waggregate-return]
}



bool isRealNumber(const ComplexNumber& number) {
    assert(validateComplexNumber(number));

    return std::abs(number.imagPart) < EPSILON;
}

bool isImagNumber(const ComplexNumber& number) {
    assert(validateComplexNumber(number));

    return std::abs(number.realPart) < EPSILON;
}

bool isZeroNumber(const ComplexNumber& number) {
    assert(validateComplexNumber(number));

    return
        std::abs(number.realPart) < EPSILON &&
        std::abs(number.imagPart) < EPSILON;
}



void printComplexNumber(const ComplexNumber& number) {
    assert(validateComplexNumber(number));

    std::cout << "The complex number is: ";

    std::cout << '(' << ' ';

    std::cout << std::setprecision(3) << std::fixed << "Re: " << number.realPart << "; ";
    std::cout << std::setprecision(3) << std::fixed << "Im: " << number.imagPart << "; ";

    std::cout << ')' << ' ';

    std::cout << std::endl;
}



ComplexNumber sumComplexNumbers(const ComplexNumber& number1, const ComplexNumber& number2) {
    assert(validateComplexNumber(number1));
    assert(validateComplexNumber(number2));

    ComplexNumber result;

    result.realPart     =   number1.realPart    +   number2.realPart;
    result.imagPart     =   number1.imagPart    +   number2.imagPart;

    return result;

    // warning: function returns an aggregate [-Waggregate-return]
}

ComplexNumber difComplexNumbers(const ComplexNumber& number1, const ComplexNumber& number2) {
    assert(validateComplexNumber(number1));
    assert(validateComplexNumber(number2));

    ComplexNumber result;

    result.realPart     =   number1.realPart    -   number2.realPart;
    result.imagPart     =   number1.imagPart    -   number2.imagPart;

    return result;

    // warning; function returns an aggregate [-Waggregate-return]
}

ComplexNumber prdComplexNumbers(const ComplexNumber& number1, const ComplexNumber& number2) {
    assert(validateComplexNumber(number1));
    assert(validateComplexNumber(number2));

    ComplexNumber result;

    result.realPart =   number1.realPart * number2.realPart - number1.imagPart * number2.imagPart;
    result.imagPart =   number1.realPart * number2.imagPart + number1.imagPart * number2.realPart;

    return result;

    // warning: function returns an aggregate [-Waggregate-return]
}

ComplexNumber divComplexNumbers(const ComplexNumber& number1, const ComplexNumber& number2) {
    assert(validateComplexNumber(number1));
    assert(validateComplexNumber(number2));

    if (isZeroNumber(number2)) {
        std::cerr << "Division by 0!" << std::endl;

        std::exit(EXIT_FAILURE);
    }

    ComplexNumber result;

    double power1 = number2.realPart * number2.realPart;
    double power2 = number2.imagPart * number2.imagPart;
    
    result.realPart =   (number1.realPart * number2.realPart + number1.imagPart * number2.imagPart) / (power1 + power2);
    result.imagPart =   (number2.realPart * number1.imagPart - number1.realPart * number2.imagPart) / (power1 + power2);

    return result;

    // warning: function returns an aggregate [-Waggregate-return]
}



void printComplexNumberKind(const ComplexNumber& number) {
    assert(validateComplexNumber(number));

    if (isRealNumber(number)) {
        std::cout << "REAL";
    } else if (isImagNumber(number)) {
        std::cout << "IMAG";
    } else {
        std::cout << "CMPL";
    }
}
