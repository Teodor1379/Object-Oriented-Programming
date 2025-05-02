#include <cassert>

#include <iostream>



void mapArray(int* array, unsigned int size, int (*function)(int));



void printArray(const int* array, unsigned int size);



int main() {
    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    mapArray(array, 10, [](int number) { return number * 2; } );    printArray(array, 10);
    mapArray(array, 10, [](int number) { return number * 3; } );    printArray(array, 10);

    return 0;
}



void mapArray(int* array, unsigned int size, int (*function)(int)) {
    assert(array    !=  nullptr );
    assert(size     !=  0       );

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = function(array[i]);
    }
}



void printArray(const int* array, unsigned int size) {
    assert(array    !=  nullptr );
    assert(size     !=  0       );

    std::cout << "The elements of the array are: ";

    for (unsigned int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }

    std::cout << std::endl;
}
