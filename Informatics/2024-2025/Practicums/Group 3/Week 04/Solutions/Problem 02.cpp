#include <fstream>
#include <iostream>



#define MAX 256



const char* ERROR_FILE_O = "Error while opening         the file!";



int main() {
    char buffer[MAX] = { 0 };

    std::cout << "Enter the file path: ";

    std::cin.getline(buffer, MAX, '\n');

    std::cout << std::endl;


    std::ifstream stream(buffer, std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 1;
    }

    stream.seekg(0, std::ios_base::end);

    std::cout << "File Size is: " << stream.tellg() << std::endl;

    stream.close();


    return 0;
}
