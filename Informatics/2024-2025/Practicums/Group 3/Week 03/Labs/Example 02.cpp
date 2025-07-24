#include <fstream>
#include <iostream>




const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";



int main() {
    std::ifstream stream;

    stream.open("Files/Digits.txt");

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 1;
    }


    while (stream.good()) {
        int d = stream.get();

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return 2;
        }

        std::cout.put(d);
    }


    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return 1;
    }


    return 0;
}
