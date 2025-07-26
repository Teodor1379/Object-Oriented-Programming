#include <fstream>
#include <iostream>



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";
const char* ERROR_FILE_S = "Error while seeking the file!";




int main() {
    std::ifstream stream("Files/Numbers.txt");

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 1;
    }


    std::cout << "Order 1: ";

    for (std::streampos i = 0; i < 8; i += 1) {
        stream.seekg(i, std::ios::beg);

        if (stream.fail()) {
            std::cerr << ERROR_FILE_S << std::endl;

            return 2;
        }

        unsigned int number = 0;

        stream >> number;

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return 3;
        }

        std::cout << number << ' ';
    }

    std::cout << std::endl;

    std::cout << "Order 2: ";

    for (std::streampos j = 2; j < 11; j += 1) {
        stream.seekg(-j, std::ios::end);

        if (stream.fail()) {
            std::cerr << ERROR_FILE_S << std::endl;

            return 2;
        }

        unsigned int number = 0;

        stream >> number;

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return 3;
        }

        std::cout << number << ' ';
    }

    std::cout << std::endl;


    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return 4;
    }


    return 0;
}
