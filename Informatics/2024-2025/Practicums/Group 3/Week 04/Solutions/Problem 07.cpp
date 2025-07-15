#include <cassert>
#include <cstring>
#include <cstdint>

#include <limits>

#include <iomanip>

#include <fstream>
#include <iostream>



#define MAXF  256
#define MAXN 1024



struct Human {
    char        name1[MAXN] ;
    char        name2[MAXN] ;
    uint32_t    age         ;     
};



const char* ERROR_FILE_R = "Error while reading from    the file!";
const char* ERROR_FILE_W = "Error while writing to      the file!";
const char* ERROR_FILE_O = "Error while opening         the file!";
const char* ERROR_FILE_D = "Error while operating with  the file!";

const char* ERROR_STATUS_E = "EMPTY"    ;
const char* ERROR_STATUS_C = "CORRUPTED";



unsigned int readSize();



char* getFileName();



void writePerson(std::ofstream&, const Human&);


void readData   (const char*                );
void writeData  (const char*,   unsigned int);



bool findHumanShortestName  (const char*, Human&);
bool findHumanLongestName   (const char*, Human&);



int main() {
    unsigned int size = readSize();

    char* filePath = getFileName();


    writeData(filePath, size);


    Human minName = { };
    Human maxName = { };

    bool result1 = findHumanShortestName    (filePath, minName);
    bool result2 = findHumanLongestName     (filePath, maxName);

    if (result1) {
        std::cout << "Min Name Human is: " << std::left <<
            std::setw(12)   <<  minName.name1   << ' ' <<
            std::setw(12)   <<  minName.name2   << ' ' <<
                                minName.age     << std::endl;
    } else {
        std::cout << "Min Name Human is: ERROR!" << std::endl; 
    }

    if (result2) {
        std::cout << "Max Name Human is: " << std::left <<
            std::setw(12)   <<  maxName.name1   << ' ' <<
            std::setw(12)   <<  maxName.name2   << ' ' <<
                                maxName.age     << std::endl;
    } else {
        std::cout << "Max Name Human is: ERROR!" << std::endl;
    }


    delete[] filePath;

    filePath = nullptr;


    return 0;
}



unsigned int readSize() {
    unsigned int size = 0;

    while (true) {
        std::cout << "Enter the size: ";

        std::cin >> size;

        if (std::cin.fail() || size == 0) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            std::cout << std::endl;

            return size;
        }
    }
}



char* getFileName() {
    char* buffer = new (std::nothrow) char[MAXF];

    if (buffer == nullptr) {
        std::exit(EXIT_FAILURE);
    }

    std::cout << "Enter the file path: ";

    std::cin.getline(buffer, MAXF, '\n');

    std::cout << std::endl;

    return buffer;
}



void writePerson(std::ofstream& stream, const Human& human) {
    stream.write(reinterpret_cast<const char*>(&human), sizeof(Human));

    if (stream.fail()) {
        std::cerr << ERROR_FILE_W << std::endl;

        return;
    }
}



void readData(const char* filePath) {
    std::ifstream stream(filePath, std::ios::in | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    Human current = { "", "", 0 };

    while (stream.read(reinterpret_cast<char*>(&current), sizeof(Human))) {
        std::cout << "Human is: " << std::left  <<
            std::setw(12) <<    current.name1   << ' ' <<
            std::setw(12) <<    current.name2   << ' ' <<
                                current.age     << std::endl;
    }

    stream.close();
}

void writeData(const char* filePath, unsigned int size) {
    std::ofstream stream(filePath, std::ios::out | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    Human human = { };

    for (unsigned int i = 0; i < size; ++i) {
        std::cout << "Enter Name 1: ";  std::cin >> human.name1 ;
        std::cout << "Enter Name 2: ";  std::cin >> human.name2 ;
        std::cout << "Enter the Age: "; std::cin >> human.age   ;

        std::cout << std::endl;

        stream.write(reinterpret_cast<const char*>(&human), sizeof(Human));

        if (stream.fail()) {
            std::cerr << ERROR_FILE_W << std::endl;

            return;
        }
    }

    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_W << std::endl;

        return;
    }
}



bool findHumanShortestName(const char* filePath, Human& human) {
    std::ifstream stream(filePath, std::ios::in | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_R << std::endl;

        return false;
    }

    stream.seekg(0, std::ios::end);

    std::streamsize fileSize = stream.tellg();

    if (fileSize == 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return false;
    }

    if (fileSize % sizeof(Human)) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_C << std::endl;

        return false;
    }

    std::streamsize size = fileSize / sizeof(Human);

    stream.seekg(0, std::ios::beg);

    bool status = false;

    Human currentHuman = { "", "", 0 };

    for (std::streamsize i = 0; i < size; ++i) {
        stream.read(reinterpret_cast<char*>(&currentHuman), sizeof(Human));

        if (stream.fail() || stream.gcount() != sizeof(Human)) {
            std::cerr << ERROR_FILE_R << std::endl;

            return false;
        }

        if (status == false) {
            human = currentHuman;

            status = true;
        } else {
            unsigned int len1 = strlen(human.name1          )   + strlen(human.name2        );
            unsigned int len2 = strlen(currentHuman.name1   )   + strlen(currentHuman.name2 );

            if (len1 > len2) {
                human = currentHuman;
            }
        }
    }

    stream.close();

    return true;
}

bool findHumanLongestName(const char* filePath, Human& human) {
    std::ifstream stream(filePath, std::ios::in | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return false;
    }

    stream.seekg(0, std::ios::end);

    std::streamsize fileSize = stream.tellg();

    if (fileSize == 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return false;
    }

    if (fileSize % sizeof(Human) != 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return false;
    }

    std::streamsize size = fileSize / sizeof(Human);

    stream.seekg(0, std::ios::beg);

    bool status = false;

    Human currentHuman = { "", "", 0 };

    for (std::streamsize i = 0; i < size; ++i) {
        stream.read(reinterpret_cast<char*>(&currentHuman), sizeof(Human));

        if (stream.fail() || stream.gcount() != sizeof(Human)) {
            std::cerr << ERROR_FILE_R << std::endl;

            return false;
        }

        if (status == false) {
            human = currentHuman;

            status = true;
        } else {
            unsigned int len1 = strlen(human.name1          )   + strlen(human.name2        );
            unsigned int len2 = strlen(currentHuman.name1   )   + strlen(currentHuman.name2 );

            if (len1 < len2) {
                human = currentHuman;
            } 
        }
    }

    stream.close();

    return true;
}
