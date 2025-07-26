#include <cassert>
#include <cstring>

#include <limits>

#include <fstream>
#include <iostream>



#define MAX 256



struct Person {
    char            name[MAX]   ;
    unsigned int    age         ;
    bool            gender      ;
};



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";
const char* ERROR_FILE_W = "Error while writing the file!";
const char* ERROR_FILE_S = "Error while seeking the file!";
const char* ERROR_FILE_D = "Error whole working the file!";

const char* ERROR_STATUS_E = "EMPTYFILE";
const char* ERROR_STATUS_C = "CORRUPTED";



void generator();



char* getFileName();



Person* buildPersons(                   unsigned int&   , const char*   );
void    writePersons(const  Person* ,   unsigned int    , const char*   );
void    clearPersons(       Person*&                                    );
void    printPersons(const  Person*,    unsigned int                    );



void    sortPersons(Person*, unsigned int);



int main() {
    // generator();

    char* filePath = getFileName();


    unsigned int size = 0;

    Person* persons = buildPersons(size, filePath);

    if (persons == nullptr) {
        std::cerr << "Building People... ERROR!" << std::endl;

        return 1;
    }

    printPersons(persons, size);


    sortPersons(persons, size);


    printPersons(persons, size);


    clearPersons(persons);


    delete[] filePath;

    filePath = nullptr;


    return 0;
}



void generator() {
    Person data1[3] = {
        { "Teo1", 19, 1, },
        { "Teo2", 20, 1, },
        { "Teo3", 21, 1, },
    };

    Person data2[7] = {
        { "Rick"    , 50, 1, },
        { "Daryl"   , 45, 1, },
        { "Morgan"  , 41, 1, },
        { "Negan"   , 52, 1, },
        { "Carol"   , 49, 0, },
        { "Maggie"  , 47, 0, },
        { "Glenn"   , 35, 1, },
    };

    Person data3[9] = {
        { "Leon"    ,   21, 1, },
        { "Ada"     ,   24, 0, },
        { "Chris"   ,   25, 1, },
        { "Claire"  ,   19, 0, },
        { "Jill"    ,   23, 0, },
        { "Albert"  ,   38, 1, },
        { "Carlos"  ,   21, 1, },
        { "Josh"    ,   28, 1, },
        { "Alice"   ,   25, 0, },
    };

    writePersons(data1, 3, "People1.bin");
    writePersons(data2, 7, "People2.bin");
    writePersons(data3, 9, "People3.bin");
}



char* getFileName() {
    char* buffer = new (std::nothrow) char[MAX];

    if (buffer == nullptr) {
        std::exit(EXIT_FAILURE);
    }

    std::cout << "Enter the file path: ";

    std::cin.getline(buffer, MAX, '\n');

    if (std::cin.fail() || buffer[0] == '\0') {
        std::cin.clear  ()                                                  ;
        std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

        delete[] buffer; buffer = nullptr;

        std::exit(EXIT_FAILURE);
    }

    return buffer;
}



Person* buildPersons(unsigned int& size, const char* filePath) {
    std::ifstream stream(filePath, std::ios::in | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        size = 0; return nullptr;
    }

    stream.seekg(0, std::ios_base::end);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        size = 0; return nullptr;
    }

    std::streamsize fileSize = stream.tellg();

    if (fileSize == 0) {
        std::cout << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        size = 0; return nullptr;
    }

    if (fileSize % sizeof(Person) != 0) {
        std::cout << ERROR_FILE_D << ' ' << ERROR_STATUS_C << std::endl;

        size = 0; return nullptr;
    }

    size = fileSize / sizeof(Person);

    Person* persons = new (std::nothrow) Person[size];

    if (persons == nullptr) {
        size = 0; return nullptr;
    }

    stream.seekg(0, std::ios_base::beg);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        delete[] persons; size = 0;

        return nullptr;
    }

    stream.read(reinterpret_cast<char*>(persons), size * sizeof(Person));

    if (stream.fail() || stream.gcount() != static_cast<std::streamsize>(size * sizeof(Person))) {
        std::cerr << ERROR_FILE_W << std::endl;

        delete[] persons; size = 0;
        
        return nullptr;
    }

    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        delete[] persons; size = 0;

        return nullptr;
    }

    return persons;
}

void writePersons(const Person* persons, unsigned int size, const char* filePath) {
    assert(persons  !=  nullptr );
    assert(size     !=  0       );
    assert(filePath !=  nullptr );

    std::ofstream stream(filePath, std::ios::out | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    stream.write(reinterpret_cast<const char*>(persons), size * sizeof(Person));

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

void clearPersons(Person*& persons) {
    assert(persons  !=  nullptr );

    delete[] persons;

    persons = nullptr;
}

void printPersons(const Person* persons, unsigned int size) {
    assert(persons  !=  nullptr );
    assert(size     !=  0       );

    std::cout << "The people are: " << std::endl;

    for (unsigned int i = 0; i < size; ++i) {
        std::cout << "Person: " << persons[i].name << "\t\t" << persons[i].age << std::endl;
    }
}



void sortPersons(Person* persons, unsigned int size) {
    assert(persons  !=  nullptr );
    assert(size     !=  0       );

    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            if (persons[i].gender < persons[j].gender) {
                std::swap(persons[i], persons[j]);
            } else if (persons[i].gender == persons[j].gender) {
                if (strcmp(persons[i].name, persons[j].name) > 0) {
                    std::swap(persons[i], persons[j]);
                } else if (strcmp(persons[i].name, persons[j].name) == 0) {
                    if (persons[i].age > persons[j].age) {
                        std::swap(persons[i], persons[j]);
                    }
                }
            }
        }
    }
}
