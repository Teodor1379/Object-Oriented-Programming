#include <limits>

#include <cstddef>
#include <cstdlib>

#include <cassert>

#include <iostream>



unsigned int    readNumb(                   );
unsigned int    revrNumb(unsigned int number);
std::size_t     readSize(const char* string );



unsigned int**  buildMatrix (                           std::size_t rows, std::size_t cols  );
void            clearMatrix (unsigned int**& matrix,    std::size_t rows                    );



void inputMatrix(       unsigned int**          matrix, std::size_t rows, std::size_t cols);
void printMatrix(const  unsigned int* const*    matrix, std::size_t rows, std::size_t cols);



bool    traverseMatrix(unsigned int number, unsigned int** matrix, bool** used, std::size_t rows, std::size_t cols, std::size_t i, std::size_t j);

bool    findElement(unsigned int number, unsigned int** matrix, std::size_t rows, std::size_t cols);



int main() {
    unsigned int number = readNumb();

    std::size_t rows = readSize("ROWS");
    std::size_t cols = readSize("COLS");


    unsigned int** matrix = buildMatrix(rows, cols);

    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);


    if (findElement(revrNumb(number), matrix, rows, cols)) {
        std::cout << "The path of the number WAS found!" << std::endl;
    } else {
        std::cout << "The path of the number WAS NOT found!" << std::endl;
    }


    clearMatrix(matrix, rows);

    return 0;
}



unsigned int readNumb() {
    unsigned int number = 0;

    while (true) {
        std::cout << "Enter the number: ";

        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return number;
        }
    }
}

unsigned int revrNumb(unsigned int number) {
    unsigned int result = 0;

    while (number != 0) {
        unsigned int digit = number % 10;
        result = result * 10 + digit;
        number = number / 10;
    }

    return result;
}

std::size_t readSize(const char* string) {
    std::size_t size = 0;

    while (true) {
        std::cout << "Enter the " << string << " size: ";

        std::cin >> size;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            if (size == 0) {
                continue;
            }

            return size;
        }
    }
}



unsigned int** buildMatrix(std::size_t rows, std::size_t cols) {
    assert(rows     !=  0       );
    assert(cols     !=  0       );

    unsigned int** matrix = new (std::nothrow) unsigned int*[rows];

    if (matrix != nullptr) {
        for (std::size_t i = 0; i < rows; ++i) {
            matrix[i] = new (std::nothrow) unsigned int[cols];

            if (matrix[i] == nullptr) {
                clearMatrix(matrix, i);

                return nullptr;
            }
        }
    }

    return matrix;
}

void clearMatrix(unsigned int**& matrix, std::size_t rows) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );

    for (std::size_t i = 0; i < rows; ++i) {
        delete[] matrix[i];

        // matrix[i] = nullptr;
    }

    delete[] matrix;

    matrix = nullptr;
}



void inputMatrix(unsigned int** matrix, std::size_t rows, std::size_t cols) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );
    
    std::cout << "Input the elements of the matrix: " << std::endl;

    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(const unsigned int* const* matrix, std::size_t rows, std::size_t cols) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );
    
    std::cout << "The elements of the matrix are: " << std::endl;

    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << ' ';
        }

        std::cout << std::endl;
    }
}



bool traverseMatrix(unsigned int number, unsigned int** matrix, bool** used, std::size_t rows, std::size_t cols, std::size_t i, std::size_t j) {
    assert(matrix   !=  nullptr );
    assert(used     !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );

    if (number == 0) {
        return true;
    }

    if (i >= rows || j >= cols) {
        return false;
    }

    if (used[i][j]) {
        return false;
    }

    if (number % 10 != matrix[i][j]) {
        return false;
    }

    used[i][j] = true;
    
    bool result =   traverseMatrix(number / 10, matrix, used, rows, cols, i - 1, j) ||
                    traverseMatrix(number / 10, matrix, used, rows, cols, i + 1, j) ||
                    traverseMatrix(number / 10, matrix, used, rows, cols, i, j - 1) ||
                    traverseMatrix(number / 10, matrix, used, rows, cols, i, j + 1);

    used[i][j] = false;

    return result;
}



bool findElement(unsigned int number, unsigned int** matrix, std::size_t rows, std::size_t cols) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );

    bool** used = new (std::nothrow) bool*[rows]();

    if (used == nullptr) {
        std::cout << "Allocating Memory... ERROR!" << std::endl;

        return false;
    }

    for (std::size_t i = 0; i < rows; ++i) {
        used[i] = new (std::nothrow) bool[cols]();

        if (used[i] == nullptr) {
            for (std::size_t k = 0; k < i; ++k) {
                delete[] used[k];
            }

            delete[] used;

            return false;
        }
    }

    bool result = false;

    for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            if (traverseMatrix(number, matrix, used, rows, cols, i, j)) {
                result = true;

                break;
            }
        }
    }

    for (std::size_t k = 0; k < rows; ++k) {
        delete[] used[k];
    }

    delete[] used;

    return result;
}
