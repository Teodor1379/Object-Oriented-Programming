#include <cstring>

#include <limits>

#include <fstream>
#include <iostream>



#define MAX 50

#define MAGIC "TAAT"



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";
const char* ERROR_FILE_W = "Error while writing the file!";



char*   buildString(        );
void    clearString(char*&  );



int main() {
    std::cout << "Enter the file path: ";   char* filePath = buildString();
    std::cout << "Enter the subs word: ";   char* subsWord = buildString();
    std::cout << "Enter the subs file: ";   char* subsFile = buildString();

    if (filePath == nullptr || subsWord == nullptr || subsFile == nullptr) {
        clearString(filePath);
        clearString(subsWord);
        clearString(subsFile);

        std::cerr << "Allocating Mempory... ERROR!";

        return 1;
    }

    std::ifstream stream1(filePath, std::ios::in    );
    std::ofstream stream2(subsFile, std::ios::out   );

    if (stream1.is_open() == false || stream2.is_open() == false) {
        std::cerr << "Error while opening the file!";

        return 1;
    }

    char buffer[MAX] = { 0 };
    unsigned int ind =   0  ;

    while (stream1.good() && stream2.good()) {
        char c = stream1.get();

        if (stream1.eof()) {
            break;
        }

        if (stream1.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            clearString(filePath);
            clearString(subsWord);
            clearString(subsFile);

            return 2;
        }

        if (std::isspace(c)) {
            buffer[ind] = '\0';

            if (strcmp(buffer, subsWord) == 0) {
                stream2 << MAGIC;
            } else {
                stream2 << buffer;
            }

            stream2 << c;

            if (stream2.fail()) {
                std::cerr << ERROR_FILE_W << std::endl;

                clearString(filePath);
                clearString(subsWord);
                clearString(subsFile);

                return 3;
            }

            ind = 0;
        } else {
            buffer[ind] = c;

            ind = ind + 1;
        }
    }

    if (ind != 0) {
        if (strcmp(buffer, subsWord) == 0) {
            stream2 << MAGIC;
        } else {
            stream2 << buffer;
        }

        if (stream2.fail()) {
            std::cerr << ERROR_FILE_W << std::endl;

            clearString(filePath);
            clearString(subsWord);
            clearString(subsFile);

            return 3;
        }
    }

    stream1.clear();
    stream2.clear();

    stream1.close();
    stream2.close();

    if (stream1.fail() || stream2.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        clearString(filePath);
        clearString(subsWord);
        clearString(subsFile);

        return 4;
    }

    clearString(filePath);
    clearString(subsWord);
    clearString(subsFile);

    return 0;
}



char* buildString() {
    char* string = new (std::nothrow) char[50];

    if (string != nullptr) {
        std::cin.getline(string, '\n');

        if (std::cin.fail() || string[0] == '\0') {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            clearString(string);
        }
    }

    return string;
}

void clearString(char*& string) {
    delete[] string;

    string = nullptr;
}
