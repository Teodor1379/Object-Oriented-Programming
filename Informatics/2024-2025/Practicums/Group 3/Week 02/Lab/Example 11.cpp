#include <iostream>



struct Point {
    double xCoordinate;
    double yCoordinate;
} globalPoint;



inline void resetPoint() { globalPoint = { 0.0, 0.0 }; }



inline void moveLeft   (double movement)   { globalPoint.xCoordinate = globalPoint.xCoordinate - movement; }
inline void moveRight  (double movement)   { globalPoint.xCoordinate = globalPoint.xCoordinate + movement; }
inline void moveDown   (double movement)   { globalPoint.yCoordinate = globalPoint.yCoordinate - movement; }
inline void moveUp     (double movement)   { globalPoint.yCoordinate = globalPoint.yCoordinate + movement; }



void printPoint(const Point& point);



void specialFunction();



int main() {
    moveLeft    (1);    printPoint(globalPoint);
    moveRight   (1);    printPoint(globalPoint);

    moveDown    (1);    printPoint(globalPoint);
    moveUp      (1);    printPoint(globalPoint);

    resetPoint();       printPoint(globalPoint);


    specialFunction();


    // Anonymous structure

    struct {
        int value1;
        int value2;
    } data;

    data.value1 = 0;
    data.value2 = 1;

    std::cout << "Data Value 1 is: "    << data.value1 << std::endl;
    std::cout << "Data Value 2 is: "    << data.value2 << std::endl;


    return 0;
}



void printPoint(const Point& point) {
    std::cout << "Point " " Data: " << std::endl;

    std::cout << "X: " << point.xCoordinate << std::endl;
    std::cout << "Y: " << point.yCoordinate << std::endl;

    std::cout << std::endl;
}



void specialFunction() {
    struct Color {
        unsigned int r = 0;
        unsigned int g = 0;
        unsigned int b = 0;
    } localColor;


    localColor.r = localColor.r + 255;
    localColor.g = localColor.g + 255;
    localColor.b = localColor.b + 255;


    std::cout << "Local Color Data: " << std::endl;

    std::cout << "R Channel Value: " << localColor.r << std::endl;
    std::cout << "G Channel Value: " << localColor.g << std::endl;
    std::cout << "B Channel Value: " << localColor.b << std::endl;

    std::cout << std::endl;
}
