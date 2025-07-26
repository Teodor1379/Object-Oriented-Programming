#include <fstream>
#include <iostream>



#define MAX 256



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_S = "Error while seeking the file!";



int main() {
    char buffer[MAX] = { 0 };

    std::cout << "Enter the file path: ";

    std::cin.getline(buffer, MAX, '\n');

    if (std::cin.fail() || buffer[0] == '\0') {
        std::cerr << "Invalid File Path!" << std::endl;

        return 4;
    }

    std::cout << std::endl;


    std::ifstream stream(buffer, std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 1;
    }

    stream.seekg(0, std::ios_base::end);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        return 3;
    }

    std::cout << "File Size is: " << stream.tellg() << std::endl;

    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return 2;
    }


    return 0;
}
