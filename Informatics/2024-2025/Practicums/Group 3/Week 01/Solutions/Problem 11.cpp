#include <limits>

#include <cassert>

#include <iostream>



int             readNumb(                   );
int             readElem(                   );
unsigned int    readSize(const char* string );



int**   buildMatrix(                            unsigned int rows, unsigned int cols);
void    clearMatrix(           int**& matrix,   unsigned int rows                   );


void    inputMatrix(            int** matrix,   unsigned int rows, unsigned int cols);
void    printMatrix(const int* const* matrix,   unsigned int rows, unsigned int cols);



void    sortMatrixRow(int** matrix, unsigned int rows, unsigned int cols, unsigned int row);
void    sortMatrixCol(int** matrix, unsigned int rows, unsigned int cols, unsigned int col);

void    sortMatrixRows(int** matrix, unsigned int rows, unsigned int cols);
void    sortMatrixCols(int** matrix, unsigned int rows, unsigned int cols);



bool    binarySearchRow(const int* const* matrix, unsigned int rows, unsigned int cols, unsigned int row, int element);
bool    binarySearchCol(const int* const* matrix, unsigned int rows, unsigned int cols, unsigned int col, int element);



bool    findElementRows(const int* const* matrix, unsigned int rows, unsigned int cols, int element);
bool    findElementCols(const int* const* matrix, unsigned int rows, unsigned int cols, int element);



int main() {
    int element = readElem();

    std::cout << std::endl;


    unsigned int rows   =   readSize("ROWS");
    unsigned int cols   =   readSize("COLS");

    std::cout << std::endl;

    
    int** matrix = buildMatrix(rows, cols);

    if (matrix == nullptr) {
        std::cout << "Allocating Memory... ERROR!" << std::endl;

        return 1;
    }


    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    std::cout << std::endl;


    sortMatrixRows(matrix, rows, cols);

    if (findElementRows(matrix, rows, cols, element)) {
        std::cout << "The element WAS found!" << std::endl;
    } else {
        std::cout << "The element WAS NOT found!" << std::endl;
    }


    clearMatrix(matrix, rows);


    return 0;
}



int readNumb() {
    int number = 0;

    while (true) {
        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear  ();
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return number;
        }
    }
}

int readElem() {
    int element = 0;

    while (true) {
        std::cout << "Enter the element: ";

        std::cin >> element;

        if (std::cin.fail()) {
            std::cin.clear  ();
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return element;
        }
    }
}

unsigned int readSize(const char* string) {
    assert(string   !=  nullptr );

    unsigned int size   =   0;

    while (true) {
        std::cout << "Enter the " << string << " of the matrix: ";

        std::cin >> size;

        if (std::cin.fail()) {
            std::cin.clear  ();
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

            if (size == 0) {
                continue;
            }

            return size;
        }
    }
}



int** buildMatrix(unsigned int rows, unsigned int cols) {
    assert(rows !=  0       );
    assert(cols !=  0       );

    int** matrix = new (std::nothrow) int*[rows];

    if (matrix != nullptr) {
        for (unsigned int i = 0; i < rows; ++i) {
            matrix[i] = new (std::nothrow) int[cols];

            if (matrix[i] == nullptr) {
                clearMatrix(matrix, rows);

                return nullptr;
            }
        }
    }

    return matrix;
}

void clearMatrix(int**& matrix, unsigned int rows) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );

    for (unsigned int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;

    matrix = nullptr;
}



void inputMatrix(int** matrix, unsigned int rows, unsigned int cols) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );

    std::cout << "Enter the elements of the matrix: " << std::endl;

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            matrix[i][j] = readNumb();
        } 
    }
}

void printMatrix(const int* const* matrix, unsigned int rows, unsigned int cols) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );

    std::cout << "The elements of the matrix are: " << std::endl;

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << ' ';
        }

        std::cout << std::endl;
    }
}



void sortMatrixRow(int** matrix, unsigned int rows, unsigned int cols, unsigned int row) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );
    assert(row      <   rows    );
    
    for (unsigned int i = 0; i < cols - 1; ++i) {
        for (unsigned int j = i + 1; j < cols; ++j) {
            if (matrix[row][i] > matrix[row][j]) {
                std::swap(matrix[row][i], matrix[row][j]);
            }
        }
    }
}

void sortMatrixCol(int** matrix, unsigned int rows, unsigned int cols, unsigned int col) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );
    assert(col      <   cols    );

    for (unsigned int i = 0; i < rows - 1; ++i) {
        for (unsigned int j = i + 1; j < rows; ++j) {
            if (matrix[i][col] > matrix[j][col]) {
                std::swap(matrix[i][col], matrix[j][col]);
            }
        }
    }
}



void sortMatrixRows(int** matrix, unsigned int rows, unsigned int cols) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );

    for (unsigned int i = 0; i < rows; ++i) {
        sortMatrixRow(matrix, rows, cols, i);
    }
}

void sortMatrixCols(int** matrix, unsigned int rows, unsigned int cols) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );

    for (unsigned int j = 0; j < cols; ++j) {
        sortMatrixCol(matrix, rows, cols, j);
    }
}



bool binarySearchRow(const int* const* matrix, unsigned int rows, unsigned int cols, unsigned int row, int element) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );
    assert(row      <=  rows - 1);

    unsigned int left   =   0       ;
    unsigned int right  =   cols - 1;

    while (left <= right) {
        unsigned int middle = left + (right - left) / 2;

        if (matrix[row][middle] < element) {
            left    = left  + 1;
        } else if (matrix[row][middle] > element) {
            right   = right - 1;
        } else {
            return true;
        }
    }

    return false;
}

bool binarySearchCol(const int* const* matrix, unsigned int rows, unsigned int cols, unsigned int col, int element) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );
    assert(col      <=  cols - 1);

    unsigned int left   =   0       ;
    unsigned int right  =   rows - 1;

    while (left <= right) {
        unsigned int middle = left + (right - left) / 2;

        if (matrix[middle][col] < element) {
            left    = left  + 1;
        } else if (matrix[middle][col] > element) {
            right   = right - 1;
        } else {
            return true;
        }
    }

    return false;
}



bool findElementRows(const int* const* matrix, unsigned int rows, unsigned int cols, int element) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );

    for (unsigned int i = 0; i < rows; ++i) {
        if (binarySearchRow(matrix, rows, cols, i, element)) {
            return true;
        }
    }

    return false;
}

bool findElementCols(const int* const* matrix, unsigned int rows, unsigned int cols, int element) {
    assert(matrix   !=  nullptr );
    assert(rows     !=  0       );
    assert(cols     !=  0       );

    for (unsigned int j = 0; j < cols; ++j) {
        if (binarySearchCol(matrix, rows, cols, j, element)) {
            return true;
        }
    }

    return false;
}
