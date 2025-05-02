#include <iostream>



#define PI              3.141592
#define findSquare(x)   (x * x)



int main() {
    double radius = 3.0;

    double area = PI * findSquare(radius);

    std::cout << "Area is: " << area << std::endl;


    return 0;
}
