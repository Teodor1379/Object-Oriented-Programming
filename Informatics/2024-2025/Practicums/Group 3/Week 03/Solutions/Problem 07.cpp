#include <cassert>

#include <limits>

#include <fstream>
#include <iostream>



#define MAX 256



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";
const char* ERROR_FILE_W = "Error while writing the file!";



char*   buildString(        );
void    clearString(char*&  );



unsigned int readSize();



int*    buildArray(unsigned int );
void    clearArray(int*&        );

void    inputArray(         int*,   unsigned int);
void    printArray(const    int*,   unsigned int);



int*    rArray(const char*  ,                   unsigned int&   );
void    wArray(const char*  ,   const   int*,   unsigned int    );



int main() {
    std::cout << "Enter the file path: ";

    char* filePath = buildString();

    if (filePath == nullptr) {
        std::cerr << "Allocating Memory... ERROR!" << std::endl;

        return 1;
    }

    unsigned int size = readSize();

    int* data = buildArray(size);

    if (data == nullptr) {
        std::cerr << "Allocating Memory... ERROR!" << std::endl;

        clearString(filePath);

        return 2;
    }

    wArray(filePath, data, size);

    int* result = rArray(filePath, size);

    if (result == nullptr) {
        std::cerr << "Allocating Memory... ERROR!" << std::endl;

        clearString(filePath);
        
        clearArray(result);
    }

    printArray(result, size);


    clearString(filePath);

    clearArray(data     );
    clearArray(result   );

    return 0;
}



unsigned int readSize() {
    unsigned int size = 0;

    while (true) {
        std::cout << "Enter the size: ";

        std::cin >> size;

        if (std::cin.fail() || size == 0) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return size;
        }
    }
}



char* buildString() {
    char* string = new (std::nothrow) char[MAX]();

    if (string != nullptr) {
        std::cin.getline(string, MAX, '\n');
    }

    return string;
}

void clearString(char*& string) {
    delete[] string;

    string = nullptr;
}



int* buildArray(unsigned int size) {
    assert(size     !=  0       );

    int* array = new (std::nothrow) int[size]();

    if (array != nullptr) {
        inputArray(array, size);
        printArray(array, size);
    }

    return array;
}

void clearArray(int*& array) {
    assert(array    !=  nullptr );
    
    delete[] array;

    array = nullptr;
}



void inputArray(int* array, unsigned int size) {
    assert(array    !=  nullptr );
    assert(size     !=  0       );

    std::cout << "Enter the elements of the array: ";

    for (unsigned int i = 0; i < size; ++i) {
        std::cin >> array[i];
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



int* rArray(const char* string, unsigned int& size) {
    assert(string   !=  nullptr );

    std::ifstream stream(string);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return nullptr;
    }

    stream >> size;

    if (stream.fail()) {
        std::cerr << ERROR_FILE_R << std::endl;

        size = 0; return nullptr;
    }

    int* array = new (std::nothrow) int[size]();

    if (array != nullptr) {
        unsigned int ind = 0;    
    
        while (stream.good()) {
            stream >> array[ind];

            ind = ind + 1;

            if (stream.eof()) {
                break;
            }

            if (stream.fail()) {
                std::cerr << ERROR_FILE_R << std::endl;

                clearArray(array); size = 0;
                
                return nullptr;
            }
        }
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        clearArray(array); size = 0;
        
        return nullptr;
    }

    return array;
}

void wArray(const char* string, const int* array, unsigned int size) {
    assert(string   !=  nullptr );
    assert(array    !=  nullptr );
    assert(size     !=  0       );

    std::ofstream stream(string);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    stream << size << ' ';

    if (stream.fail()) {
        std::cerr << ERROR_FILE_W << std::endl;

        return;
    }

    for (unsigned int i = 0; i < size; ++i) {
        stream << array[i] << ' ';

        if (stream.fail()) {
            std::cerr << ERROR_FILE_W << std::endl;

            return;
        }
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return;
    }
}
