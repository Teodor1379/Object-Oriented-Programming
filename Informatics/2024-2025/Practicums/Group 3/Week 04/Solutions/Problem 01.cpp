#include <fstream>
#include <iostream>



const char* FILE_PATH = "Numbers.dat";



const char* ERROR_FILE_R = "Error while reading from    the file!";
const char* ERROR_FILE_W = "Error while writing to      the file!";
const char* ERROR_FILE_O = "Error while opening         the file!";



void writeNumbers();



void printNumbers(std::ifstream&);



bool findMinNumber(std::ifstream&, int& );
bool findMaxNumber(std::ifstream&, int& );



int main() {
    writeNumbers();

    std::ifstream stream(FILE_PATH, std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 1;
    }

    printNumbers(stream);

    std::cout << std::endl;

    int minValue = 0;
    int maxValue = 0;

    std::cout << "Min Number is: " << (findMinNumber(stream, minValue) ? minValue : 0) << std::endl;
    std::cout << "Max Number is: " << (findMaxNumber(stream, maxValue) ? maxValue : 0) << std::endl;

    stream.close();

    return 0;
}



void writeNumbers() {
    std::ofstream stream(FILE_PATH, std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    std::cout << "Enter numbers: ";

    while (true) {
        int number = 0;

        std::cin >> number;

        if (number == 0) {
            break;
        }

        stream.write(reinterpret_cast<const char*>(&number), sizeof(int));

        if (stream.good() == false) {
            std::cerr << ERROR_FILE_W << std::endl;

            break;
        }
    }

    stream.close();
}



void printNumbers(std::ifstream& stream) {
    stream.clear();

    stream.seekg(0, std::ios_base::beg);

    std::cout << "The numbers are: ";

    int number = 0; bool success = false;

    while (stream.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        std::cout << number << ' ';

        success = true;        
    }

    if (stream.eof() == false) {
        std::cerr << ERROR_FILE_R << std::endl;
    } else if (success == false) {
        std::cout << "No Numbers!";
    }

    std::cout << std::endl;
}



bool findMinNumber(std::ifstream& stream, int& minNumber) {
    stream.clear();

    stream.seekg(0, std::ios_base::beg);

    int result = 0; bool success = false;

    while (stream.read(reinterpret_cast<char*>(&result), sizeof(int))) {
        if (success == false) {
            minNumber = result;

            success = true;
        } else {
            minNumber = std::min(minNumber, result);
        }
    }

    if (stream.eof() == false && success == false) {
        std::cerr << ERROR_FILE_R << std::endl;

        return false;
    }

    return success;
}

bool findMaxNumber(std::ifstream& stream, int& maxNumber) {
    stream.clear();

    stream.seekg(0, std::ios_base::beg);

    int result = 0; bool success = false;

    while (stream.read(reinterpret_cast<char*>(&result), sizeof(int))) {
        if (success == false) {
            maxNumber = result;

            success = true;
        } else {
            maxNumber = std::max(maxNumber, result);
        }
    }

    if (stream.eof() == false && success == false) {
        std::cerr << ERROR_FILE_R << std::endl;

        return false;
    }

    return success;
}
