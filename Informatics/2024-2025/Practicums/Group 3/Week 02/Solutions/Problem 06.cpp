#include <cassert>

#include <limits>

#include <iostream>



struct Matrix {
    unsigned int rows;
    unsigned int cols;

    int** data;
};



unsigned int readSize(const char*               );
unsigned int readIndx(unsigned int, unsigned int);



int* buildContainer(unsigned int);



Matrix    initializeMatrix(unsigned int, unsigned int   );
void    deinitializeMatrix(Matrix&                      );



void    buildMatrix(        Matrix&);
void    printMatrix(const   Matrix&);



void    addRow(Matrix&, int* row, unsigned int size);
void    addCol(Matrix&, int* col, unsigned int size);



void    removeRow(Matrix&,  unsigned int index);
void    removeCol(Matrix&,  unsigned int index);



bool    isEmpty(const Matrix&);



unsigned int    getRows(const Matrix&);
unsigned int    getCols(const Matrix&);



void printStats(const Matrix&);



int main() {
    unsigned int rows   =   readSize("ROWS");
    unsigned int cols   =   readSize("COLS");

    Matrix matrix = initializeMatrix(rows, cols);

    buildMatrix(matrix);
    printMatrix(matrix);

    int* row = buildContainer(matrix.cols); if (row == nullptr) { std::cout << "Allocating Container... ERROR!";    }
    int* col = buildContainer(matrix.rows); if (col == nullptr) { std::cout << "Allocating Container... ERROR!";    }

    addRow(matrix, row, matrix.cols);
    addCol(matrix, col, matrix.rows);

    deinitializeMatrix(matrix);

    return 0;
}



unsigned int readSize(const char* string) {
    assert(string != nullptr);

    unsigned int size = 0;

    while (true) {
        std::cout << "Enter the " << string << " size of the matrix: ";

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

unsigned int readIndx(unsigned int minNumber, unsigned int maxNumber) {
    unsigned int index = 0;

    while (true){
        std::cout << "Enter the index: ";

        std::cin >> index;

        if (std::cin.fail() || index < minNumber || index > maxNumber) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return index;
        }
    }
}



int* buildContainer(unsigned int size) {
    int* container = new int[size];

    if (container == nullptr) {
        return nullptr;
    }

    std::cout << "Enter the elements of the array: ";

    for (unsigned int i = 0; i < size; ++i) {
        std::cin >> container[i];
    }

    return container;
}



Matrix initializeMatrix(unsigned int rows, unsigned int cols) {
    assert(rows !=  0);
    assert(cols !=  0);

    Matrix matrix = { rows, cols, new (std::nothrow) int*[rows]() };

    if (matrix.data == nullptr) {
        std::cout << "Allocating Memory... ERROR!" << std::endl;

        return matrix;
    }

    for (unsigned int i = 0; i < cols; ++i) {
        matrix.data[i] = new (std::nothrow) int[cols]();

        if (matrix.data[i] == nullptr) {
            deinitializeMatrix(matrix);
        }
    }

    return matrix;
}

void deinitializeMatrix(Matrix& matrix) {
    for (unsigned int i = 0; i < matrix.rows; ++i) {
        delete[] matrix.data[i];
    }

    delete[] matrix.data;

    matrix.rows =   0;
    matrix.cols =   0;

    matrix.data =   nullptr;
}



void buildMatrix(Matrix& matrix) {
    assert(matrix.rows  !=  0       );
    assert(matrix.cols  !=  0       );
    assert(matrix.data  !=  nullptr );

    std::cout << "Enter the elements of the matrix: " << std::endl;

    for (unsigned int i = 0; i < matrix.rows; ++i) {
        for (unsigned int j = 0; j < matrix.cols; ++j) {
            std::cin >> matrix.data[i][j];
        }
    }
}

void printMatrix(const Matrix& matrix) {
    assert(matrix.rows  !=  0       );
    assert(matrix.cols  !=  0       );
    assert(matrix.data  !=  nullptr );

    std::cout << "The elements of the matrix are: " << std::endl;

    for (unsigned int i = 0; i < matrix.rows; ++i) {
        for (unsigned int j = 0; j < matrix.cols; ++j) {
            std::cout << matrix.data[i][j];
        }

        std::cout << std::endl;
    }
}



void addRow(Matrix& matrix, const int* row, unsigned int size) {
    assert(matrix.rows  !=  0       );
    assert(matrix.cols  !=  0       );
    assert(matrix.data  !=  nullptr );
    assert(matrix.cols  ==  size    );

    Matrix result = initializeMatrix(matrix.rows + 1, matrix.cols);

    for (unsigned int i = 0; i < matrix.rows; ++i) {
        for (unsigned int j = 0; j < matrix.cols; ++j) {
            result.data[i][j] = matrix.data[i][j];
        }
    }

    for (unsigned int j = 0; j < matrix.cols; ++j) {
        result.data[matrix.rows][j] = row[j];
    }

    deinitializeMatrix(matrix);

    matrix = result;
}

void addCol(Matrix& matrix, const int* col, unsigned int size) {
    assert(matrix.rows  !=  0       );
    assert(matrix.cols  !=  0       );
    assert(matrix.data  !=  nullptr );
    assert(matrix.rows  ==  size    );

    Matrix result = initializeMatrix(matrix.rows, matrix.cols + 1);

    for (unsigned int i = 0; i < matrix.rows; ++i) {
        for (unsigned int j = 0; j < matrix.cols; ++j) {
            result.data[i][j] = matrix.data[i][j];
        }

        result.data[i][matrix.cols] = col[i];
    }

    deinitializeMatrix(matrix);

    matrix = result;
}



void removeRow(Matrix& matrix, unsigned int index) {
    for (unsigned int i = index; i < matrix.rows - 1; ++i) {
        for (unsigned int j = 0; j < matrix.cols; ++j) {
            matrix.data[i][j] = matrix.data[i + 1][j];
        }
    }

    delete[] matrix.data[matrix.rows - 1];

    matrix.rows = matrix.rows - 1;
}

void removeCol(Matrix& matrix, unsigned int index) {
    for (unsigned int i = 0; i < matrix.rows; ++i) {
        int* temporary = new (std::nothrow) int[matrix.cols - 1];

        unsigned int counter = 0;

        for (unsigned int j = 0; j < matrix.cols; ++j) {
            if (j != index) {
                temporary[counter] = matrix.data[i][j]; 
            }

            counter = counter + 1;
        }

        delete[] matrix.data[i];

        matrix.data[i] = temporary;
    }

    matrix.cols = matrix.cols - 1;
}



bool isEmpty(const Matrix& matrix) {
    return matrix.data == nullptr;
}



unsigned int    getRows(const Matrix& matrix)   { return matrix.rows;   }
unsigned int    getCols(const Matrix& matrix)   { return matrix.cols;   }
