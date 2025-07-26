#include <fstream>
#include <iostream>



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_W = "Error while writing the file!";



int main() {
    std::ofstream stream("Files/Message.txt", std::ios::out | std::ios::trunc);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 1;
    }

    stream << "John Wick" << '\n';

    if (stream.fail()) {
        std::cerr << ERROR_FILE_W << std::endl;

        return 2;
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return 3;
    }

    return 0;
}
