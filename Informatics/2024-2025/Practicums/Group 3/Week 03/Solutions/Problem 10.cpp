#include <fstream>
#include <iostream>



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";



unsigned int countChars(const char*);
unsigned int countWords(const char*);
unsigned int countLines(const char*);



int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cerr << "The name of the file is not given!" << std::endl;

        return 1;
    }

    std::cout << "Number of chars is: " << countChars(argv[1]) << std::endl;
    std::cout << "Number of words is: " << countWords(argv[1]) << std::endl;
    std::cout << "Number of lines is: " << countLines(argv[1]) << std::endl;

    return 0;
}



unsigned int countChars(const char* filePath) {
    if (filePath == nullptr) {
        return 0;
    }

    unsigned int chars = 0;

    std::ifstream stream(filePath, std::ios::in);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 0;
    }

    while (stream.good()) {
        stream.get();

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return 0;
        }

        chars = chars + 1;
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return 0;
    }

    return chars;
}

unsigned int countWords(const char* filePath) {
    if (filePath == nullptr) {
        return 0;
    }

    unsigned int words = 0;

    std::ifstream stream(filePath, std::ios::in);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 0;
    }

    char c = 0;

    while (stream.good()) {
        stream.get(c);

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return 0;
        }

        if (std::isspace(c) == false) {
            words = words + 1;

            while (stream.good() && std::isspace(c) == false) {
                stream.get(c);

                if (stream.eof()) {
                    break;
                }

                if (stream.fail()) {
                    std::cerr << ERROR_FILE_R << std::endl;

                    return 0;
                }
            }
        }
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return 0;
    }

    return words;
}

unsigned int countLines(const char* filePath) {
    if (filePath == nullptr) {
        return 0;
    }

    unsigned int lines = 0;

    std::ifstream stream(filePath);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 0;
    }

    char c = 0;

    while (stream.good()) {
        stream.get(c);

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return 0;
        }

        if (c == '\n') {
            lines = lines + 1;
        }
    }

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return 0;
    }

    return lines;
}
