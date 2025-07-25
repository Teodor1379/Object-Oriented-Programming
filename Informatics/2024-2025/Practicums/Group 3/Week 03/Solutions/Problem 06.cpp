#include <cassert>

#include <limits>

#include <fstream>
#include <iostream>



#define MAX 256



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";
const char* ERROR_FILE_W = "Error while writing the file!";



unsigned int readSize();



char*   buildString(        );
void    clearString(char*&  );



void    printContent(const char*, std::ostream&);



int main() {
    unsigned int size = readSize();

    char* resultPath = buildString();

    if (resultPath == nullptr) {
        std::cerr << "Allocating Memory... ERROR!" << std::endl;

        return 1;
    }


    std::ofstream stream(resultPath);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 2;
    }


    for (unsigned int i = 0; i < size; ++i) {
        char* filePath = buildString();

        if (filePath == nullptr) {
            std::cerr << "Allocating Memory... ERROR!" << std::endl;

            return 1;
        }

        printContent(filePath, stream);

        clearString(filePath);
    }


    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        clearString(resultPath);

        return 3;
    }


    clearString(resultPath);


    return 0;
}



unsigned int readSize() {
    unsigned int size = 0;

    while (true) {
        std::cout << "Enter the size: ";

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



char* buildString() {
    char* string = new (std::nothrow) char[MAX]();

    if (string != nullptr) {
        std::cout << "Enter the file path: ";

        std::cin.getline(string, MAX, '\n');
    }

    return string;
}

void clearString(char*& string) {
    delete[] string;

    string = nullptr;
}



void printContent(const char* filePath, std::ostream& streamO) {
    assert(filePath !=  nullptr );

    std::ifstream streamI(filePath);

    if (streamI.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        std::exit(EXIT_FAILURE);
    }

    while (streamI.good()) {
        char c = streamI.get();
        
        if (streamI.eof()) {
            break;
        }

        if (streamI.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            std::exit(EXIT_FAILURE);
        }

        streamO.put(c);

        if (streamO.fail()) {
            std::cerr << ERROR_FILE_W << std::endl;

            std::exit(EXIT_FAILURE);
        }
    }

    streamI.clear();
    streamO.clear();

    streamI.close();

    if (streamI.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        std::exit(EXIT_FAILURE);
    }
}
