#include <fstream>
#include <iostream>



const char* FILE_PATH = "Numbers.dat";



const char* ERROR_FILE_R = "Error while reading the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_W = "Error while writing the file!";
const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_S = "Error while seeking the file!";



void writeNumbers();



void printNumbers(std::ifstream&);



bool findMinNumber(std::ifstream&, int& );
bool findMaxNumber(std::ifstream&, int& );



int main() {
    // writeNumbers();


    std::ifstream stream(FILE_PATH, std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 1;
    }

    printNumbers(stream);


    std::cout << std::endl;

    int32_t minValue = 0;
    int32_t maxValue = 0;

    std::cout << "Min Number is: " << (findMinNumber(stream, minValue) ? minValue : 0) << std::endl;
    std::cout << "Max Number is: " << (findMaxNumber(stream, maxValue) ? maxValue : 0) << std::endl;


    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return 2;
    }


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
        int32_t number = 0;

        std::cin >> number;

        if (number == 0) {
            break;
        }

        stream.write(reinterpret_cast<const char*>(&number), sizeof(int));

        if (stream.fail()) {
            std::cerr << ERROR_FILE_W << std::endl;

            return;
        }
    }

    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_W << std::endl;
        std::cerr << ERROR_FILE_C << std::endl;

        return;
    }
}



void printNumbers(std::ifstream& stream) {
    stream.clear();

    stream.seekg(0, std::ios_base::beg);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        return;
    }

    std::cout << "The numbers are: ";

    int32_t number = 0; bool success = false;

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

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        return false;
    }

    int32_t result = 0; bool success = false;

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

    stream.clear();

    return success;
}

bool findMaxNumber(std::ifstream& stream, int& maxNumber) {
    stream.clear();

    stream.seekg(0, std::ios_base::beg);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        return false;
    }

    int32_t result = 0; bool success = false;

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

    stream.clear();

    return success;
}
