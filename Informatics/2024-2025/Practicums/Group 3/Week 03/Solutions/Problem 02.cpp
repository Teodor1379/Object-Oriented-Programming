#include <limits>

#include <fstream>
#include <iostream>



#define MAX 256



char*   buildString(        );
void    clearString(char*&  );



int main() {
    std::cout << "Enter the file path   : ";    char* filePath = buildString();
    std::cout << "Enter the string      : ";    char* fileStrn = buildString();

    if (filePath == nullptr || fileStrn == nullptr) {
        clearString(filePath);
        clearString(fileStrn);

        std::cerr << "Allocating Memory... ERROR!" << std::endl;

        return 1;
    }


    std::ofstream stream(filePath, std::ios::out | std::ios::app);

    if (stream.is_open() == false) {
        std::cerr << "Error while opening the file!" << std::endl;

        clearString(filePath);
        clearString(fileStrn);

        return 2;
    }

    stream << fileStrn << '\n';

    if (stream.fail()) {
        std::cerr << "Error while writing to the file!" << std::endl;

        clearString(filePath);
        clearString(fileStrn);

        return 3;
    }

    stream.close();

    clearString(filePath);
    clearString(fileStrn);

    return 0;
}



char* buildString() {
    char* string = new (std::nothrow) char[MAX]();

    if (string != nullptr) {
        std::cin.getline(string, MAX, '\n');

        if (std::cin.fail()) {
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
