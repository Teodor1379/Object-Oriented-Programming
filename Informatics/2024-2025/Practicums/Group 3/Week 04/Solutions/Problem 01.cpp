#include <fstream>
#include <iostream>



const char* FILE_PATH = "Numbers.dat";



const char* ERROR_FILE_R = "Error while reading from    the file!";
const char* ERROR_FILE_W = "Error while writing to      the file!";
const char* ERROR_FILE_O = "Error while opening         the file!";



void writeNumbers();



void printNumbers(std::ifstream&);



int findMinNumber(std::ifstream&);
int findMaxNumber(std::ifstream&);



int main() {
    // writeNumbers();

    std::ifstream stream(FILE_PATH, std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 1;
    }

    printNumbers(stream);

    std::cout << std::endl;

    std::cout << "Min Number is: " << findMinNumber(stream) << std::endl;
    std::cout << "Max Number is: " << findMaxNumber(stream) << std::endl;

    stream.close();

    return 0;
}



void writeNumbers() {
    std::ofstream stream(FILE_PATH, std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    while (true) {
        int number = 0;

        std::cin >> number;

        if (number == 0) {
            break;
        }

        if (stream.good() == false) {
            std::cerr << ERROR_FILE_W << std::endl;

            break;
        }

        stream.write(reinterpret_cast<const char*>(&number), sizeof(int));
    }

    stream.close();
}



void printNumbers(std::ifstream& stream) {
    stream.clear();

    stream.seekg(std::ios_base::beg);

    std::cout << "The numbers are: ";

    while (true) {
        int number = 0;

        stream.read(reinterpret_cast<char*>(&number), sizeof(int));

        if (stream.eof()) {
            break;
        }

        if (stream.good() == false) {
            std::cerr << ERROR_FILE_R << std::endl;
        }

        std::cout << number << ' ';
    }

    std::cout << std::endl;
}



int findMinNumber(std::ifstream& stream) {
    stream.clear();

    stream.seekg(std::ios_base::beg);

    int result = 0;

    stream.read(reinterpret_cast<char*>(&result), sizeof(int));

    if (stream.good() == false) {
        std::cerr << ERROR_FILE_R << std::endl;

        return 0;
    }

    while (true) {
        int current = 0;

        stream.read(reinterpret_cast<char*>(&current), sizeof(int));

        if (stream.eof()) {
            break;
        }

        if (stream.good() == false) {
            std::cerr << ERROR_FILE_R << std::endl;

            break;
        }

        if (result > current) {
            result = current;   
        }
    }

    return result;
}

int findMaxNumber(std::ifstream& stream) {
    stream.clear();

    stream.seekg(std::ios_base::beg);

    int result = 0;

    stream.read(reinterpret_cast<char*>(&result), sizeof(int));

    if (stream.good() == false) {
        std::cerr << ERROR_FILE_R << std::endl;

        return 0;
    }

    while (true) {
        int current = 0;

        stream.read(reinterpret_cast<char*>(&current), sizeof(int));

        if (stream.eof()) {
            break;
        }

        if (stream.good() == false) {
            std::cerr << ERROR_FILE_R << std::endl;

            break;
        }

        if (result < current) {
            result = current;
        }
    }

    return result;
}
