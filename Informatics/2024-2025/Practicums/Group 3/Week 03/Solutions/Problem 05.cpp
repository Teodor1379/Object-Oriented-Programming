#include <cassert>
#include <cstring>

#include <limits>

#include <fstream>
#include <iostream>



#define MAXN  256
#define MAXF 1024



const char* ERROR_FILE_O = "Error while reading the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";
const char* ERROR_FILE_W = "Error while writing the file!";



char*   buildString(        );
void    clearString(char*&  );



unsigned int calculateRows(const char*);



char**  buildRows(const char*   , unsigned int& );
void    clearRows(char**&       , unsigned int  );



void sortRows(char**&,  unsigned int);



int main() {
    char* filePath1 = buildString();
    char* filePath2 = buildString();

    if (filePath1 == nullptr || filePath2 == nullptr) {
        clearString(filePath1);
        clearString(filePath2);

        std::cerr << "Allocating Memory... ERROR!" << std::endl;

        return 1;
    }

    unsigned int size = 0;

    char** rows = buildRows(filePath1, size);

    if (rows == nullptr) {
        std::cerr << "Allocating Memory... ERROR!" << std::endl;

        clearString(filePath1);
        clearString(filePath2);

        return 2;
    }

    std::ofstream stream(filePath2, std::ios::out);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        clearRows(rows, size);

        clearString(filePath1);
        clearString(filePath2);

        return 3;
    }

    sortRows(rows, size);

    for (unsigned int i = 0; i < size; ++i) {
        stream << rows[i] << '\n';

        if (stream.fail()) {
            std::cerr << ERROR_FILE_W << std::endl;

            clearRows(rows, size);

            clearString(filePath1);
            clearString(filePath2);

            return 4;
        }
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        clearRows(rows, size);

        clearString(filePath1);
        clearString(filePath2);

        return 5;
    }

    clearRows(rows, size);

    clearString(filePath1);
    clearString(filePath2);

    return 0;
}



char* buildString() {
    char* string = new (std::nothrow) char[MAXF]();

    if (string != nullptr) {
        std::cout << "Enter the file path: ";

        std::cin.getline(string, MAXN, '\n');

        if (std::cin.fail() || string[0] == '\0') {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            clearString(string);

            return nullptr;
        }
    }

    return string;
}

void clearString(char*& string) {
    delete[] string;

    string = nullptr;
}



unsigned int calculateRows(const char* string) {
    assert(string   !=  nullptr );

    std::ifstream stream(string, std::ios::in);

    unsigned int result = 0;

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 0;
    }

    while (stream.good()) {
        char c = stream.get();

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return 0;
        }

        if (c == '\n') {
            result = result + 1;
        }
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return 0;
    }

    return result;
}



char** buildRows(const char* filePath, unsigned int& size) {
    assert(filePath !=  nullptr );

    std::ifstream stream(filePath);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_R << std::endl;

        return nullptr;
    }

    size = calculateRows(filePath);

    char** rows = new (std::nothrow) char*[size];

    if (rows == nullptr) {
        size = 0; return nullptr;
    }

    unsigned int index = 0;

    while (stream.good() && index < size) {
        rows[index] = new (std::nothrow) char[MAXF]();

        if (rows[index] == nullptr) {
            clearRows(rows, index);

            size = 0; return nullptr;
        }

        stream.getline(rows[index], MAXF, '\n');

        std::cout << rows[index];

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            clearRows(rows, index);

            size = 0; return nullptr;
        }

        index = index + 1;
    }

    return rows;
}

void clearRows(char**& rows, unsigned int size) {
    assert(size !=  0       );

    for (unsigned int i = 0; i < size; ++i) {
        delete[] rows[i];
    }

    delete[] rows;
}



void sortRows(char**& rows, unsigned int size) {
    assert(rows !=  nullptr );
    assert(size !=  0       );

    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            if (strcmp(rows[i], rows[j]) > 0) {
                char* buffer1 = new (std::nothrow) char[strlen(rows[i]) + 1]();
                char* buffer2 = new (std::nothrow) char[strlen(rows[j]) + 1]();

                if (buffer1 == nullptr || buffer2 == nullptr) {
                    clearString(buffer1);
                    clearString(buffer2);
                }

                strcpy(buffer1, rows[i]);
                strcpy(buffer2, rows[j]);

                clearString(rows[i]);
                clearString(rows[j]);

                rows[i] = buffer2;
                rows[j] = buffer1;
            }
        }
    }
}
