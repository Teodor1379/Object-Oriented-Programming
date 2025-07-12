#include <cassert>

#include <limits>

#include <iostream>



#define INITIALIZEC 2
#define RESIZE_STEP 2



unsigned int calledStats = 0;



struct Array {
    // Usually, the array has size and capacity.

    // Size     - the actual    size of the array space.
    // Capacity - the logical   size of the array space.

    unsigned int    size        =   0       ;
    unsigned int    capacity    =   0       ;
    int*            elements    =   nullptr ;
};



Array     initializeArray   (       );
void    deinitializeArray   (Array& );



void resizeArray(Array& array);



void pushBack   (Array&,    int );
void popBack    (Array&         );


unsigned int    getSize     (const Array&);
unsigned int    getCapacity (const Array&);



bool isEmpty(const Array&);



void printArray(const   Array&  );
void printInfor(const   Array&  );



int main() {
    Array array = initializeArray();

    printInfor(array);

    std::cout << "Enter the numbers: ";

    while (true) {
        int number = 0;

        std::cin >> number;

        if (number == 0) {
            break;
        }

        pushBack(array, number);
    }

    printInfor(array);

    for (unsigned int i = 1; i <= 3; ++i) {
        popBack(array);
    }

    printInfor(array);

    deinitializeArray(array);

    return 0;
}



Array initializeArray() { 
    Array result;

    result.elements = new (std::nothrow) int[INITIALIZEC]();

    if (result.elements != nullptr) {
        result.size     = 0             ;
        result.capacity = INITIALIZEC   ;
    } 

    return result;
}

void deinitializeArray(Array& array) {
    assert(array.capacity   !=  0       );
    assert(array.elements   !=  nullptr );

    delete[] array.elements;

    array.elements = nullptr;
}



void resizeArray(Array& array) {
    assert(array.capacity   !=  0       );
    assert(array.elements   !=  nullptr );

    int* temporary = new (std::nothrow) int[array.capacity * RESIZE_STEP]();

    if (temporary == nullptr) {
        std::cout << "Resizing Array... ERROR!" << std::endl;

        return;
    }

    for (unsigned int i = 0; i < array.size; ++i) {
        temporary[i] = array.elements[i];
    }

    delete[] array.elements;

    array.capacity  =   array.capacity * RESIZE_STEP;
    array.elements  =   temporary                   ;
}



void pushBack(Array& array, int element) {
    assert(array.capacity   !=  0       );
    assert(array.elements   !=  nullptr );

    if (array.size == array.capacity) {
        resizeArray(array);
    }

    array.elements[array.size] = element;

    array.size = array.size + 1;
}

void popBack(Array& array) {
    assert(array.capacity   !=  0       );
    assert(array.elements   !=  nullptr );

    if (array.size == 0) {
        std::cout << "The array is empty!" << std::endl;

        return;
    }
    
    array.size = array.size - 1;   
}



unsigned int getSize(const Array& array) {
    assert(array.capacity   !=  0       );
    assert(array.elements   !=  nullptr );

    return array.size;
}

unsigned int getCapacity(const Array& array) {
    assert(array.capacity   !=  0       );
    assert(array.elements   !=  nullptr );

    return array.capacity;
}



bool isEmpty(const Array& array) {
    assert(array.capacity   !=  0       );
    assert(array.elements   !=  nullptr );

    return array.size == 0;
}



void printArray(const Array& array) {
    assert(array.capacity   !=  0       );
    assert(array.elements   !=  nullptr );

    std::cout << "The elements of the array are: ";

    for (unsigned int i = 0; i < array.size; ++i) {
        std::cout << array.elements[i] << ' ';
    }

    std::cout << std::endl;
}

void printInfor(const Array& array) {
    assert(array.capacity   !=  0       );
    assert(array.elements   !=  nullptr );

    if (calledStats == 1) {
        std::cout << std::endl;
        std::cout << std::endl;
    }

    std::cout << "The SIZE      of the array is:    "   << getSize      (array) << std::endl;
    std::cout << "The CAPACITY  of the array is:    "   << getCapacity  (array) << std::endl;

    std::cout << "Is the array empty: " << std::boolalpha << isEmpty(array) << std::endl;

    if (isEmpty(array) == false) {
        std::cout << std::endl;

        printArray(array);
    }

    calledStats = calledStats + 1;

    if (calledStats < 3) {
        std::cout << std::endl;
        std::cout << std::endl;
    }
}
