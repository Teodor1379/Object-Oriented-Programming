#include <cassert>

#include <limits>

#include <iostream>



int             readElem();
unsigned int    readSize();



unsigned int    findPowerTwo(unsigned int number);



int*    buildArray(                     const unsigned int& size,  const unsigned int& capacity );
void    clearArray(        int*& array                                                          );

void    inputArray(         int* array, const unsigned int& size,   const unsigned int& capacity );
void    printArray(const    int* array, const unsigned int& size,   const unsigned int& capacity );



bool    isEmpty(const int* array, const unsigned int& size, const unsigned int& capacity);



void    pushBack(int*& array, unsigned int& size, unsigned int& capacity, int element   );
void     popBack(int*& array, unsigned int& size, const unsigned int& capacity          );



void    resize(int*& array, const unsigned int& size, unsigned int& capacity);



int main() {
    unsigned int size       =   readSize    ()      ;
    unsigned int capacity   =   findPowerTwo(size)  ;


    int* array = buildArray(size, capacity);

    if (array == nullptr) {
        std::cout << "Allocating Memory... ERROR!" << std::endl;

        return 1;
    }

    
    std::cout << "Is Empty: " << isEmpty(array, size, capacity) << std::endl;


    pushBack(array, size, capacity, 1379);

    printArray(array, size, capacity);


    popBack(array, size, capacity);

    printArray(array, size, capacity);


    clearArray(array);


    return 0;
}



int readElem() {
    int element = 0;

    while (true) {
        std::cin >> element;

        if (std::cin.fail()) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            return element;
        }
    }
}

unsigned int readSize() {
    unsigned int size = 0;

    while (true) {
        std::cout << "Enter the size of the array: ";

        std::cin >> size;

        if (std::cin.fail()) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            if (size == 0) {
                continue;
            }

            return size;
        }
    }
}



unsigned int findPowerTwo(unsigned int number) {
    unsigned int power = 1;

    while (power < number) {
        power = power * 2;
    }

    return power;
}



int* buildArray(const unsigned int& size, const unsigned int& capacity) {
    assert(size     !=  0   );
    assert(capacity !=  0   );

    int* array = new (std::nothrow) int[capacity]();

    if (array != nullptr) {
        inputArray(array, size, capacity);
        printArray(array, size, capacity);
    }

    return array;
}

void clearArray(int*& array) {
    assert(array    !=  nullptr );

    delete[] array;

    array = nullptr;
}



void inputArray(int* array, const unsigned int& size, const unsigned int& capacity) {
    assert(array    !=  nullptr );
    assert(size     !=  0       );
    assert(capacity !=  0       );

    std::cout << "Enter the elements of the array: ";

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(const int* array, const unsigned int& size, const unsigned int& capacity) {
    assert(array    !=  nullptr );
    assert(size     !=  0       );
    assert(capacity !=  0       );

    std::cout << "The elements of the array are: ";

    for (unsigned int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }

    std::cout << std::endl;
}



bool isEmpty(const int* array, const unsigned int& size, const unsigned int& capacity) {
    assert(array    !=  nullptr );
    assert(capacity !=  0       );

    return size == 0;
}



void pushBack(int*& array, unsigned int& size, unsigned int& capacity, int element) {
    assert(array    !=  nullptr );
    assert(capacity !=  0       );

    if (size == capacity) {
        resize(array, size, capacity);

        if (size == capacity) {
            return;
        }
    }

    array[size] = element;

    size = size + 1;
}

void popBack(int*& array, unsigned int& size, const unsigned int& capacity) {
    // warning: unused parameter ‘array‘ [-Wunused-parameter]

    assert(array    !=  nullptr );
    assert(capacity !=  0       );

    if (size == 0) {
        std::cout << "Invalid POP operation!" << std::endl;

        return;
    }

    size = size - 1;
}



void resize(int*& array, const unsigned int& size, unsigned int& capacity) {
    assert(array    !=  nullptr );
    assert(size     !=  0       );
    assert(capacity !=  0       );

    int* temporary = new (std::nothrow) int[capacity * 2]();

    if (temporary == nullptr) {
        std::cout << "Invalid Resize Operation!" << std::endl;

        return;
    }

    for (unsigned int i = 0; i < size; ++i) {
        temporary[i] = array[i];
    }

    delete[] array;

    array = temporary;

    capacity = capacity * 2;
}
