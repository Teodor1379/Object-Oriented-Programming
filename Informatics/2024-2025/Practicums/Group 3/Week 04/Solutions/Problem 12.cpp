#include <cassert>

#include <cmath>

#include <iomanip>

#include <fstream>
#include <iostream>



#define MAX 256
#define PTS 3



struct Point {
    double x;
    double y;
};



const char* ERROR_FILE_R = "Error while reading from    the file!";
const char* ERROR_FILE_W = "Error while writing to      the file!";
const char* ERROR_FILE_O = "Error while opening         the file!";



void generator();



char* getFileName();



Point*  buildPoints(                unsigned int&,  const char* );
void    clearPoints(        Point*                              );
void    writePoints(const   Point*, unsigned int,   const char* );
void    printPoints(const   Point*, unsigned int                );



void swapPoints(Point&, Point&);



double findDistance(const Point&, const Point&);



Point   findMediCenter      (const  Point*, unsigned int                 );
Point*  findClosestPoints   (       Point*, unsigned int, unsigned int&  );



int main() {
    // generator();

    char* filePath = getFileName();

    unsigned int size = 0;


    Point* points = buildPoints(size, filePath);

    if (points == nullptr) {
        std::cerr << "Allocating Memory... ERROR!" << std::endl;

        return 1;
    }

    printPoints(points, size);


    Point mediCenter = findMediCenter(points, size);

    unsigned int closestSize = 0;

    Point* closest = findClosestPoints(points, size, closestSize);

    if (closest == nullptr) {
        std::cerr << "Allocating Memory... ERROR!" << std::endl;

        return 2;
    }


    std::cout << std::fixed << std::setprecision(3)
        << "The MediCenter Coordinates are: "
        << mediCenter.x << ' ' << mediCenter.y << std::endl;

    std::cout << std::endl;

    for (unsigned int i = 0; i < closestSize; ++i) {
        std::cout << std::fixed << std::setprecision(3)
            << "Closest Point " << i + 1 << " Coordinates are: "
            << closest[i].x << ' ' << closest[i].y << std::endl;
    }

    writePoints(closest, closestSize, "Result.bin");


    clearPoints(points  );
    clearPoints(closest );

    
    delete[] filePath;

    filePath = nullptr;


    return 0;
}



void generator() {
    Point data1[3] = {
        { 1.0, 1.0 },
        { 2.0, 2.0 },
        { 3.0, 3.0 },
    };

    Point data2[7] = {
        { 0.0, 3.0 },
        { 0.5, 2.5 },
        { 1.0, 2.0 },
        { 1.5, 1.5 },
        { 2.0, 1.0 },
        { 2.5, 0.5 },
        { 3.0, 0.0 },
    };

    Point data3[9] = {
        { 1.0, 1.0 },
        { 2.0, 2.0 },
        { 3.0, 3.0 },
        { 1.0, 1.0 },
        { 2.0, 2.0 },
        { 3.0, 3.0 },
        { 9.0, 9.0 },
        { 9.0, 9.0 },
        { 9.0, 9.0 },
    };

    writePoints(data1, 3, "Points1.bin");
    writePoints(data2, 7, "Points2.bin");
    writePoints(data3, 9, "Points3.bin");
}



char* getFileName() {
    char* buffer = new (std::nothrow) char[MAX];

    if (buffer == nullptr) {
        std::exit(EXIT_FAILURE);
    }

    std::cout << "Enter the file path: ";

    std::cin.getline(buffer, MAX, '\n');

    std::cout << std::endl;

    return buffer;
}



Point* buildPoints(unsigned int& size, const char* string) {
    assert(string   !=  nullptr );

    std::ifstream stream(string);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        size = 0; return nullptr;
    }

    stream.seekg(0, std::ios_base::end);

    unsigned int fileSize = stream.tellg();

    size = fileSize / sizeof(Point);

    if (size == 0) {
        std::cerr << "Empty File!" << std::endl;

        size = 0; return nullptr;
    }

    if (fileSize % sizeof(Point) != 0) {
        std::cerr << "Corrupted File!" << std::endl;

        size = 0; return nullptr;
    }

    stream.seekg(0, std::ios_base::beg);

    Point* points = new (std::nothrow) Point[size];

    if (points == nullptr) {
        size = 0; return nullptr;
    }

    stream.read(reinterpret_cast<char*>(points), size * sizeof(Point));

    if (stream.good() == false) {
        std::cerr << ERROR_FILE_R << std::endl;

        size = 0; return nullptr;
    }
    
    stream.close();

    return points;
}

void clearPoints(Point* points) {
    assert(points   !=  nullptr );

    delete[] points;

    points = nullptr;
}

void writePoints(const Point* points, unsigned int size, const char* string) {
    assert(points   !=  nullptr );
    assert(size     !=  0       );
    assert(string   !=  nullptr );

    std::ofstream stream(string);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    stream.write(reinterpret_cast<const char*>(points), size * sizeof(Point));

    if (stream.good() == false) {
        std::cerr << ERROR_FILE_W << std::endl;

        return;
    }

    stream.close();
}

void printPoints(const Point* points, unsigned int size) {
    assert(points   !=  nullptr );
    assert(size     !=  0       );

    std::cout << "The points are: " << std::endl;

    for (unsigned int i = 0; i < size; ++i) {
        std::cout << std::fixed << std::setprecision(3)
            << "Point: " << points[i].x << ' ' << points[i].y << std::endl;
    }

    std::cout << std::endl;
}



void swapPoints(Point& point1, Point& point2) {
    std::swap(point1.x, point2.x);
    std::swap(point1.y, point2.y);
}



double findDistance(const Point& point1, const Point& point2) {
    return std::sqrt(
        std::pow(point1.x - point2.x, 2)    +
        std::pow(point1.y - point2.y, 2)
    );
}



Point findMediCenter(const Point* points, unsigned int size) {
    Point result = { 0.0, 0.0 };

    for (unsigned int i = 0; i < size; ++i) {
        result.x = result.x + points[i].x;
        result.y = result.y + points[i].y;
    }

    result.x = result.x / static_cast<double>(size);
    result.y = result.y / static_cast<double>(size);

    return result;
}

Point* findClosestPoints(Point* points, unsigned int size, unsigned int& closestSize) {
    Point* closestPoints = new (std::nothrow) Point[PTS];

    if (closestPoints == nullptr) {
        return nullptr;
    }

    Point mediCenter = findMediCenter(points, size);

    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            double distance1 = findDistance(mediCenter, points[i]);
            double distance2 = findDistance(mediCenter, points[j]);

            if (distance1 > distance2) {
                swapPoints(points[i], points[j]);
            }
        }
    }

    if (size > 0) { closestPoints[0] = points[0]; closestSize = 1; }
    if (size > 1) { closestPoints[1] = points[1]; closestSize = 2; }
    if (size > 2) { closestPoints[2] = points[2]; closestSize = 3; }

    return closestPoints;
}
