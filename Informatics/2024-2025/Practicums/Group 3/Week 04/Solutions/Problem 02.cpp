#include <fstream>
#include <iostream>



#define MAX 256



int main() {
    char buffer[MAX] = { 0 };

    std::cout << "Enter the file path: ";

    std::cin.getline(buffer, MAX, '\n');


    std::ifstream stream(buffer, std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << "Error while opening the file!" << std::endl;

        return 1;
    }

    stream.seekg(0, std::ios_base::end);

    std::cout << "\nFile Size is: " << stream.tellg() << std::endl;

    stream.close();


    return 0;
}
