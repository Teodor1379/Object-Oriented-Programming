#include <cassert>
#include <cstring>

#include <limits>

#include <fstream>
#include <iostream>



#define MAX 256



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";



char*   buildString(        );
void    clearString(char*&  );



void    executeHead(const char*);
void    executeTail(const char*);



int main() {
    std::cout << "Enter the file path: "; char* filePath = buildString();
    std::cout << "Enter the argument : "; char* commdArg = buildString();

    if (filePath == nullptr || commdArg == nullptr) {
        clearString(filePath);
        clearString(commdArg);

        std::cerr << "Allocating Memory... ERROR!" << std::endl;

        return 1;
    }

    if (strcmp(commdArg, "head") == 0) {
        executeHead(filePath);
    } else if (strcmp(commdArg, "tail") == 0) {
        executeTail(filePath);
    } else {
        std::cerr << "Executing Command... ERROR!" << std::endl;

        clearString(filePath);
        clearString(commdArg);

        return 2;
    }

    clearString(filePath);
    clearString(commdArg);

    return 0;
}



char* buildString() {
    char* string = new (std::nothrow) char[MAX]();

    if (string != nullptr) {
        std::cin.getline(string, MAX, '\n');

        if (std::cin.fail() || string[0] == '\0') {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return string;
        }
    }

    return string;
}

void clearString(char*& string) {
    delete[] string;

    string = nullptr;
}



void executeHead(const char* filePath) {
    assert(filePath !=  nullptr );

    std::ifstream stream(filePath);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    unsigned int counter = 0;

    while (stream.good()) {
        char c = stream.get();

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return;
        }

        if (c == '\n') {
            counter = counter + 1;
        }

        if (counter == 10) {
            break;
        } else {
            std::cout.put(c);
        }
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return;
    }
}

void executeTail(const char* filePath) {
    assert(filePath != nullptr  );

    std::ifstream stream(filePath);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;
    }

    unsigned int counter = 0;

    while (stream.good()) {
        char c = stream.get();

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return;
        }

        if (c == '\n') {
            counter = counter + 1;
        }
    }

    stream.clear();

    stream.seekg(0, std::ios::beg);

    unsigned int liner = 0;

    while (stream.good()) {
        char c = stream.get();

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return;
        }

        if (c == '\n') {
            liner = liner + 1;
        }

        if (counter - liner > 10) {
            continue;
        } else {
            if (counter - liner == 10 && c == '\n') {
                continue;
            }

            std::cout.put(c);
        }
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return;
    }
}
