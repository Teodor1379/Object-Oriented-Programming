#include <cstdlib>

#include <fstream>
#include <iostream>



#define MAX 10



const char* FILE_PATH = "Numbers.dat";



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";
const char* ERROR_FILE_W = "Error while writing the file!";
const char* ERROR_FILE_S = "Error while seeking the file!";
const char* ERROR_FILE_D = "Error while working the file!";

const char* ERROR_STATUS_E = "EMPTYFILE";
const char* ERROR_STATUS_C = "CORRUPTED";



void generator(const int32_t[MAX], unsigned int);


void    readFile();
void    sortFile();



int main() {
    const int32_t data1[MAX] = { 1, 2, 3, 0, 0, 0, 0, 0, 0, 0 };
    const int32_t data2[MAX] = { 3, 4, 5, 6, 2, 1, 0, 0, 0, 0 };
    const int32_t data3[MAX] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

    generator(data1, 3);
    generator(data2, 6);
    generator(data3, 9);


    std::cout << "Before    Sorting: "; readFile();
                                        sortFile();
    std::cout << "After     Sorting: "; readFile();


    return 0;
}



void generator(const int32_t array[MAX], unsigned int size) {
    std::ofstream stream(FILE_PATH, std::ios::out | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    stream.write(reinterpret_cast<const char*>(array), size * sizeof(int32_t));

    if (stream.fail()) {
        std::cerr << ERROR_FILE_W << std::endl;

        return;
    }

    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_W << std::endl;
        std::cerr << ERROR_FILE_C << std::endl;

        return;
    }
}



void readFile() {
    std::ifstream stream(FILE_PATH, std::ios::in | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    stream.seekg(0, std::ios::end);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        return;
    }

    std::streamsize fileSize = stream.tellg();

    if (fileSize == 0) {
        std::cerr << ERROR_FILE_O << ' ' << ERROR_STATUS_E << std::endl;

        return;
    }

    if (fileSize % sizeof(int32_t) != 0) {
        std::cerr << ERROR_FILE_O << ' ' << ERROR_STATUS_C << std::endl;

        return;
    }

    unsigned int size = fileSize / sizeof(int32_t);

    stream.seekg(0, std::ios::beg);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        return;
    }

    for (unsigned int i = 0; i < size; ++i) {
        int32_t currentNumber = 0;

        stream.read(reinterpret_cast<char*>(&currentNumber), sizeof(int32_t));

        if (stream.fail() || stream.gcount() != sizeof(int32_t)) {
            std::cerr << ERROR_FILE_R << std::endl;

            stream.close(); return;
        }

        std::cout << currentNumber << ' ';
    }

    std::cout << std::endl;

    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;
    }
}

void sortFile() {
    std::fstream stream(FILE_PATH, std::ios::in | std::ios::out | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    stream.seekg(0, std::ios::end);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        return;
    }

    std::streampos fileSize = stream.tellg();

    if (fileSize == 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return;
    }

    if (fileSize % sizeof(int32_t) != 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_C << std::endl;

        return;
    }

    unsigned int size = fileSize / sizeof(int32_t);

    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            int32_t value1 = 0;
            int32_t value2 = 0;


            stream.seekg(i * sizeof(int32_t), std::ios::beg);

            if (stream.fail()) {
                std::cerr << ERROR_FILE_S << std::endl;

                stream.close(); return;
            }

            stream.read(reinterpret_cast<char*>(&value1), sizeof(int32_t));

            if (stream.fail() || stream.gcount() != sizeof(int32_t)) {
                std::cerr << ERROR_FILE_R << std::endl;

                stream.close(); return;
            }

            stream.seekg(j * sizeof(int32_t), std::ios::beg);

            if (stream.fail()) {
                std::cerr << ERROR_FILE_S << std::endl;

                stream.close(); return;
            }

            stream.read(reinterpret_cast<char*>(&value2), sizeof(int32_t));

            if (stream.fail() || stream.gcount() != sizeof(int32_t)) {
                std::cerr << ERROR_FILE_R << std::endl;

                stream.close(); return;
            }


            if (value1 > value2) {
                stream.seekp(i * sizeof(int32_t), std::ios::beg);

                if (stream.fail()) {
                    std::cerr << ERROR_FILE_S << std::endl;

                    stream.close(); return;
                }

                stream.write(reinterpret_cast<const char*>(&value2), sizeof(int32_t));

                if (stream.fail()) {
                    std::cerr << ERROR_FILE_W << std::endl;

                    stream.close(); return;
                }

                stream.seekp(j * sizeof(int32_t), std::ios::beg);

                if (stream.fail()) {
                    std::cerr << ERROR_FILE_S << std::endl;

                    stream.close(); return;
                }

                stream.write(reinterpret_cast<const char*>(&value1), sizeof(int32_t));

                if (stream.fail()) {
                    std::cerr << ERROR_FILE_W << std::endl;

                    stream.close(); return;
                }
            }
        }
    }

    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_W << std::endl;
        std::cerr << ERROR_FILE_C << std::endl;

        return;
    }
}
