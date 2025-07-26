#include <cassert>
#include <cstring>

#include <limits>

#include <fstream>
#include <iostream>



#define MAXN  256
#define MAXF 1024



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";



char*   buildString(        );
void    clearString(char*&  );



void    searchFile(const char*, const char*);



int main() {
    std::cout << "Enter the file path: ";   char* filePath = buildString();
    std::cout << "Enter the need word: ";   char* needWord = buildString();

    if (filePath == nullptr || needWord == nullptr) {
        clearString(filePath);
        clearString(needWord);
    }


    searchFile(filePath, needWord);


    clearString(filePath);
    clearString(needWord);


    return 0;
}



char* buildString() {
    char* string = new (std::nothrow) char[MAXN]();

    if (string != nullptr) {
        std::cin.getline(string, MAXN, '\n');

        if (std::cin.fail() || string[0] == '\0') {
            std::cin.clear  ()                                                      ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'  )   ;

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



void searchFile(const char* filePath, const char* needle) {
    assert(filePath !=  nullptr );
    assert(needle   !=  nullptr );

    std::ifstream stream(filePath, std::ios::in);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }


    char buffer[MAXF] = { 0 };

    while (stream.good()) {
        stream.getline(buffer, MAXF, '\n');
        
        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return;
        }

        if (strstr(buffer, needle) != nullptr) {
            std::cout << buffer << '\n';
        }
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return;
    }
}
