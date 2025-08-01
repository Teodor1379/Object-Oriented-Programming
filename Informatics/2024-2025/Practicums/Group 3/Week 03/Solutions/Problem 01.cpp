#include <fstream>
#include <iostream>



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";



void printContentFile();



unsigned int calculateEveryLines();
unsigned int calculateEmptyLines();



unsigned int getFileSize();



int main() {
    printContentFile();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    unsigned int result1 = calculateEveryLines();
    unsigned int result2 = calculateEmptyLines();

    std::cout << "Number of EVERY   lines are:  "   << result1              << std::endl;
    std::cout << "Number of EMPTY   lines are:  "   << result2              << std::endl;
    std::cout << "Number of OTHER   lines are:  "   << result1 - result2    << std::endl;
    std::cout << "Number of FSIZE          is:  "   << getFileSize()        << std::endl;

    return 0;
}



void printContentFile() {
    std::ifstream stream(__FILE__, std::ios::in);

    if (stream.is_open() == false) {
        std::cout << ERROR_FILE_O << std::endl;

        std::exit(EXIT_FAILURE);
    }

    char c = '\0';

    while (stream.good()) {
        stream.get(c);

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            std::exit(EXIT_FAILURE);
        }

        std::cout.put(c);
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        std::exit(EXIT_FAILURE);
    }
}



unsigned int calculateEveryLines() {
    unsigned int counter = 0;

    std::ifstream stream(__FILE__, std::ios::in);

    if (stream.is_open() == false) {
        std::cout << ERROR_FILE_O << std::endl;

        std::exit(EXIT_FAILURE);
    }

    char c = '\0';

    while (stream.good()) {
        stream.get(c);

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            std::exit(EXIT_FAILURE);
        }

        if (c == '\n') {
            counter = counter + 1;
        }
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        std::exit(EXIT_FAILURE);
    }

    return counter;
}

unsigned int calculateEmptyLines() {
    unsigned int counter = 0;

    std::ifstream stream(__FILE__, std::ios::in);

    if (stream.is_open() == false) {
        std::cout << ERROR_FILE_O << std::endl;

        std::exit(EXIT_FAILURE);
    }

    char c1 = '\0';
    char c2 = '\0';

    while (stream.good()) {
        c1 = c2;

        stream.get(c2);

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            std::exit(EXIT_FAILURE);
        }

        if (c1 == '\n' && c1 == c2) {
            counter = counter + 1;
        }
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        std::exit(EXIT_FAILURE);
    }

    return counter;
}



unsigned int getFileSize() {
    unsigned int size = 0;

    std::ifstream stream(__FILE__, std::ios::in);

    if (stream.is_open() == false) {
        std::cout << ERROR_FILE_O << std::endl;

        std::exit(EXIT_FAILURE);
    }

    char c = '\0';

    while (stream.good()) {
        stream.get(c);

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            std::exit(EXIT_FAILURE);
        }

        size = size + 1;
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        std::exit(EXIT_FAILURE);
    }

    return size;
}
