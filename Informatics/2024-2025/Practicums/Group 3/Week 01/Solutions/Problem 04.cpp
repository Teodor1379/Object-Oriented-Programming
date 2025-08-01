#include <cassert>

#include <limits>

#include <iostream>



int     inputSide1();
double  inputSide2();



int findPerimeter   (int a, int b);
int findArea        (int a, int b);



double findPerimeter(double a, double b);
double findArea     (double a, double b);



void    printData   (int    a,  int     b);
void    printData   (double a,  double  b);



int main() {
    int side11 = inputSide1();
    int side12 = inputSide1();

    printData(side11, side12);


    std::cout << std::endl;


    double side21 = inputSide2();
    double side22 = inputSide2();

    printData(side21, side22);


    return 0;
}



int inputSide1() {
    int side = 0;

    while (true) {
        std::cout << "Enter the side of the rectangle: ";

        std::cin >> side;

        if (std::cin.fail() || side <= 0) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return side;
        }
    }
}

double inputSide2() {
    double side = 0.0;

    while (true) {
        std::cout << "Enter the side of the rectangle: ";

        std::cin >> side;

        if (std::cin.fail() || side <= 0.0) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return side;
        }
    }
}



int findPerimeter(int a, int b) {
    assert(a > 0);
    assert(b > 0);

    return 2 * (a + b);
}

int findArea(int a, int b) {
    assert(a > 0);
    assert(b > 0);

    return a * b;
}



double findPerimeter(double a, double b) {
    assert(a > 0);
    assert(b > 0);

    return 2 * (a + b);
}

double findArea(double a, double b) {
    assert(a > 0);
    assert(b > 0);

    return a * b;
}



void printData(int a, int b) {
    assert(a > 0);
    assert(b > 0);

    int perimeter   =   findPerimeter   (a, b);
    int area        =   findArea        (a, b);

    std::cout << std::endl;

    std::cout << "The PERIMETER of the rectangle is: " << perimeter << std::endl;
    std::cout << "The AREA      of the rectangle is: " << area      << std::endl;
}

void printData(double a, double b) {
    assert(a > 0);
    assert(b > 0);

    double perimeter    =   findPerimeter   (a, b);
    double area         =   findArea        (a, b);

    std::cout << std::endl;

    std::cout << "The PERIMETER of the rectangle is: " << perimeter << std::endl;
    std::cout << "The AREA      of the rectangle is: " << area      << std::endl;
}
