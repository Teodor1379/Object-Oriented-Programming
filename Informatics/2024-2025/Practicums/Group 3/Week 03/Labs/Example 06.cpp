#include <fstream>
#include <iostream>



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";
const char* ERROR_FILE_S = "Error while seeking the file!";



int main() {
    std::ifstream stream("Files/Digits.txt", std::ios::in);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 1;
    }


    std::cout << "Order 1: " << std::endl;

    for (std::streampos i = 0; i < 9; i += 1) {
        stream.seekg(i, std::ios_base::beg);

        if (stream.fail()) {
            std::cerr << ERROR_FILE_S << std::endl;

            return 2;
        }

        std::cout << "Position " << stream.tellg();

        std::cout << ' ' << stream.get() << std::endl;

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return 3;
        }
    }

    std::cout << std::endl;


    std::cout << "Order 2: " << std::endl;

    for (std::streampos j = 2; j < 12; j += 1) {
        stream.seekg(-j, std::ios_base::end);

        if (stream.fail()) {
            std::cerr << ERROR_FILE_S << std::endl;

            return 2;
        }

        std::cout << "Position " << stream.tellg();

        std::cout << ' ' << stream.get() << std::endl;

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return 3;
        }
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
