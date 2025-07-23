#include <cmath>

#include <cassert>

#include <limits>

#include <iomanip>

#include <iostream>



struct Vector {
    double element1 = 0.0;
    double element2 = 0.0;
    double element3 = 0.0;
};



double  readNumber();



Vector initVector();



bool validateNumber(double          );
bool validateVector(const Vector&   );



void printVector(const Vector&);



Vector sumVectors       (const Vector&, const Vector&);
Vector productVectors   (const Vector&, const Vector&);
Vector scalarVector     (const Vector&, const double&);



int main() {    
    std::cout << "Enter the data for Vector 1: ";   Vector vector1 = initVector();  // warning: function call has aggregate value [-Waggregate-return]
    std::cout << "Enter the data for Vector 2: ";   Vector vector2 = initVector();  // warning: function call has aggregate value [-Waggregate-return]
    std::cout << "Enter the data for Vector 3: ";   Vector vector3 = initVector();  // warning: function call has aggregate value [-Waggregate-return]

    std::cout << std::endl;


    std::cout << "Enter the number: "; double numberV = readNumber();

    std::cout << std::endl;


    printVector(sumVectors      (vector1, vector2));    // warning: function call has aggregate value [-Waggregate-return]
    printVector(productVectors  (vector1, vector2));    // warning: function call has aggregate value [-Waggregate-return]
    printVector(scalarVector    (vector3, numberV));    // warning: function call has aggregate value [-Waggregate-return]


    return 0;
}



double readNumber() {
    double number = 0;

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



Vector initVector() {
    Vector vector;

    vector.element1 = readNumber();
    vector.element2 = readNumber();
    vector.element3 = readNumber();
    
    return vector;

    // warning: function returns an aggregate [-Waggregate-return]
}



bool validateNumber(double number) {
    return  std::isfinite(number);
}

bool validateVector(const Vector& vector) {
    return
        validateNumber(vector.element1) &&
        validateNumber(vector.element2) &&
        validateNumber(vector.element3);
}




void printVector(const Vector& vector) {
    assert(validateVector(vector));

    std::cout << "The vector is: ";

    std::cout << '(' << ' ';

    std::cout << std::setprecision(3) << std::fixed << "X: " << vector.element1 << "; ";
    std::cout << std::setprecision(3) << std::fixed << "Y: " << vector.element2 << "; ";
    std::cout << std::setprecision(3) << std::fixed << "Z: " << vector.element3 << "; ";

    std::cout << ')' << ' ';

    std::cout << std::endl;
}



Vector sumVectors(const Vector& vector1, const Vector& vector2) {
    assert(validateVector(vector1));
    assert(validateVector(vector2));

    Vector result;

    result.element1 = vector1.element1 + vector2.element1;
    result.element2 = vector1.element2 + vector2.element2;
    result.element3 = vector1.element3 + vector2.element3;

    return result;

    // warning: function returns an aggregate [-Waggregate-return]
}

Vector productVectors(const Vector& vector1, const Vector& vector2) {
    assert(validateVector(vector1));
    assert(validateVector(vector2));

    Vector result;

    result.element1 = vector1.element1 * vector2.element1;
    result.element2 = vector1.element2 * vector2.element2;
    result.element3 = vector1.element3 * vector2.element3;

    return result;

    // warning: function returns an aggregate [-Waggregate-return]
}

Vector scalarVector(const Vector& vector, const double& number) {
    assert(validateVector(vector));
    assert(validateNumber(number));

    Vector result;

    result.element1 = vector.element1 * number;
    result.element2 = vector.element2 * number;
    result.element3 = vector.element3 * number;

    return result;

    // warning: function returns an aggregate [-Waggregate-return]
}
