#include <fstream>
#include <iostream>



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";



int main() {
    std::ifstream stream("Files/Alphabet.txt");

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 1;
    }

    char letters[27] = { 0 };

    stream >> letters;

    if (stream.fail()) {
        std::cerr << ERROR_FILE_R << std::endl;

        return 2;
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return 3;
    }

    std::cout << letters << '\n';

    return 0;
}
