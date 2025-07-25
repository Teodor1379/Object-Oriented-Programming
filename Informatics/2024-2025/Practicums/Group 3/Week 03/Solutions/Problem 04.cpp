#include <cassert>

#include <limits>

#include <fstream>
#include <iostream>



#define MAX 256



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";
const char* ERROR_FILE_S = "Error while seeking the file!";



struct Student {
    char            fnum[10];
    unsigned int    age     ;
    double          grade   ;
    char            name[50];
};



char*   buildString(        );
void    clearString(char*&  );



std::streampos* buildPositions(std::istream&    ,   unsigned int&   );
void            clearPositions(std::streampos*                      );



void    printStudents(std::ifstream&, const std::streampos*, unsigned int);



int main() {
    char* filePath = buildString();

    std::ifstream stream(filePath);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        clearString(filePath);

        return 1;
    }

    unsigned int students = 0;

    std::streampos* positions = buildPositions(stream, students);

    if (positions == nullptr) {
        std::cerr << "Allocating Memory... ERROR" << std::endl;

        clearString(filePath);

        return 3;
    }

    printStudents(stream, positions, students);

    clearPositions(positions);

    stream.clear();
    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        clearString(filePath);

        return 2;
    }

    clearString(filePath);

    return 0;
}



char* buildString() {
    char* string = new (std::nothrow) char[MAX];

    if (string != nullptr) {
        std::cout << "Enter the file path: ";

        std::cin.getline(string, MAX, '\n');

        if (std::cin.fail() || string[0] == '\0') {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            clearString(string);
        }
    }

    return string;
}

void clearString(char*& string) {
    delete[] string;

    string = nullptr;
}



std::streampos* buildPositions(std::istream& stream, unsigned int& students) {
    unsigned int records = 0;

    while (stream.good()) {
        char c = stream.get();

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            return nullptr;
        }

        if (c == ',') {
            records = records + 1;
        }
    }

    records = records / 3;

    stream.clear();

    stream.seekg(0, std::ios_base::beg);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        return nullptr;
    }

    std::streampos* positions = new (std::nothrow) std::streampos[records]();

    unsigned int index = 0;
    unsigned int count = 0;

    while (stream.good()) {
        char c = stream.get();

        if (stream.eof()) {
            break;
        }

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;

            clearPositions(positions);

            return nullptr;
        }

        if (c == ',') {
            if (count % 3 == 1) {
                positions[count / 3] = stream.tellg();

                index = index + 1;
            }

            count = count + 1;
        }
    }

    stream.clear();

    for (unsigned int i = 0; i < records - 1; ++i) {
        for (unsigned int j = i + 1; j < records; ++j) {
            double grade1 = 0.0;
            double grade2 = 0.0;

            stream.seekg(positions[i], std::ios_base::beg); stream >> grade1;
            stream.seekg(positions[j], std::ios_base::beg); stream >> grade2;

            if (stream.fail()) {
                std::cerr << ERROR_FILE_S << std::endl;

                clearPositions(positions);

                return nullptr;
            }

            if (grade1 > grade2) {
                std::swap(positions[i], positions[j]);
            }
        }
    }

    students = records;

    return positions;
}

void clearPositions(std::streampos* positions) {
    delete[] positions;

    positions = nullptr;
}



void printStudents(std::ifstream& stream, const std::streampos* positions, unsigned int size) {
    assert(positions    !=  nullptr );
    assert(size         !=  0       );

    char buffer[MAX] = { 0 };

    std::cout << "The list of students is: " << std::endl;

    for (unsigned int i = 0; i < size; ++i) {
        stream.seekg(positions[i], std::ios_base::beg);

        if (stream.fail()) {
            std::cerr << ERROR_FILE_S << std::endl;

            return;
        }

        stream.getline(buffer, MAX, ',');

        stream >> buffer;

        if (stream.fail()) {
            std::cerr << ERROR_FILE_R << std::endl;
            
            return;
        }

        std::cout << buffer << '\n';
    }
}
