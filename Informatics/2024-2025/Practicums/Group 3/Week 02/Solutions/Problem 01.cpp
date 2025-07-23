#include <cmath>

#include <cassert>

#include <limits>

#include <iomanip>

#include <iostream>



#define EPSILON 1e-9



struct Point {
    double xCoordinate = 0.0;
    double yCoordinate = 0.0;
    double zCoordinate = 0.0;
};



double readCoordinate();



Point buildPoint();



bool validatePoint(const Point&);



bool arePointsSame      (const Point&, const Point&                 );
bool arePointsCollinear (const Point&, const Point&, const Point&   );
bool arePointsTriangle  (const Point&, const Point&, const Point&   );



double findDistance (const Point&, const Point&                 );
double findPerimeter(const Point&, const Point&, const Point&   );
double findArea     (const Point&, const Point&, const Point&   );



int main() {
    Point point1 = buildPoint();    // warning: function call has aggregate value [-Waggregate-return]
    Point point2 = buildPoint();    // warning: function call has aggregate value [-Waggregate-return]
    Point point3 = buildPoint();    // warning: function call has aggregate value [-Waggregate-return]

    std::cout << "The PERIMETER of the triangle is: "   << std::setprecision(6) << std::fixed << findPerimeter(point1, point2, point3) << std::endl;
    std::cout << "The AREA      of the triangle is: "   << std::setprecision(6) << std::fixed << findArea     (point1, point2, point3) << std::endl;
    
    return 0;
}



double readCoordinate() {
    double coordinate  = 0.0;

    while (true) {
        std::cin >> coordinate;

        if (std::cin.fail()) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            return coordinate;
        }
    }
}



Point buildPoint() {
    Point result;

    std::cout << "Enter the coordinates of the point: ";

    result.xCoordinate = readCoordinate();
    result.yCoordinate = readCoordinate();
    result.zCoordinate = readCoordinate();

    return result;

    // warning: function returns an aggregate [-Waggregate-return]
}



bool validatePoint(const Point& point) {
    return
        std::isnan(point.xCoordinate) == false && std::isinf(point.xCoordinate) == false    &&
        std::isnan(point.yCoordinate) == false && std::isinf(point.yCoordinate) == false    &&
        std::isnan(point.zCoordinate) == false && std::isinf(point.zCoordinate) == false;
}



bool arePointsSame(const Point& point1, const Point& point2) {
    assert(validatePoint(point1));
    assert(validatePoint(point2));

    return
        std::fabs(point1.xCoordinate - point2.xCoordinate) < EPSILON    &&
        std::fabs(point1.yCoordinate - point2.yCoordinate) < EPSILON    &&
        std::fabs(point1.zCoordinate - point2.zCoordinate) < EPSILON    ;
}

bool arePointsCollinear(const Point& point1, const Point& point2, const Point& point3) {
    assert(validatePoint(point1));
    assert(validatePoint(point2));
    assert(validatePoint(point3));

    return  std::fabs(
        (
            (point2.yCoordinate - point1.yCoordinate) * (point3.zCoordinate - point1.zCoordinate)   +
            (point2.xCoordinate - point1.xCoordinate) * (point3.yCoordinate - point1.yCoordinate)   +
            (point2.zCoordinate - point1.zCoordinate) * (point3.xCoordinate - point1.xCoordinate)
        ) -
        (
            (point2.yCoordinate - point1.yCoordinate) * (point3.xCoordinate - point1.xCoordinate)   +
            (point2.zCoordinate - point1.zCoordinate) * (point3.yCoordinate - point1.yCoordinate)   +
            (point2.xCoordinate - point1.xCoordinate) * (point3.zCoordinate - point1.zCoordinate)
        )
    ) < EPSILON;
}

bool arePointsTriangle(const Point& point1, const Point& point2, const Point& point3) {
    assert(validatePoint(point1));
    assert(validatePoint(point2));
    assert(validatePoint(point3));

    return
        arePointsSame(point1, point2) == false  &&
        arePointsSame(point2, point3) == false  &&
        arePointsSame(point3, point1) == false  &&

        arePointsCollinear(point1, point2, point3) == false;
}



double findDistance(const Point& point1, const Point& point2) {
    assert(validatePoint(point1));
    assert(validatePoint(point2));

    return std::sqrt(
        std::pow(point1.xCoordinate - point2.xCoordinate, 2)    +
        std::pow(point1.yCoordinate - point2.yCoordinate, 2)    +
        std::pow(point1.zCoordinate - point2.zCoordinate, 2)
    );
}

double findPerimeter(const Point& point1, const Point& point2, const Point& point3) {
    assert(validatePoint(point1));
    assert(validatePoint(point2));
    assert(validatePoint(point3));

    assert(arePointsTriangle(point1, point2, point3));

    double side1 = findDistance(point1, point2);
    double side2 = findDistance(point2, point3);
    double side3 = findDistance(point3, point1);

    return side1 + side2 + side3;
}

double findArea(const Point& point1, const Point& point2, const Point& point3) {
    assert(validatePoint(point1));
    assert(validatePoint(point2));
    assert(validatePoint(point3));

    assert(arePointsTriangle(point1, point2, point3));
    
    double side1 = findDistance(point1, point2);
    double side2 = findDistance(point2, point3);
    double side3 = findDistance(point3, point1);

    double halfPerimeter = findPerimeter(point1, point2, point3) / 2.0;

    return std::sqrt(
        halfPerimeter           *
        (halfPerimeter - side1) *
        (halfPerimeter - side2) *
        (halfPerimeter - side3)
    );
}
