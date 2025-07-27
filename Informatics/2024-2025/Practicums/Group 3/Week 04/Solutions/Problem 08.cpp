#include <cassert>
#include <cstdint>

#include <limits>

#include <iomanip>

#include <fstream>
#include <iostream>



#define MAXF  256
#define MAXN 1024



struct Person {
    char        name1[MAXN] ;
    char        name2[MAXN] ;
    uint32_t    age         ;
};



const char* ERROR_FILE_O = "Error while opening the file!";
const char* ERROR_FILE_C = "Error while closing the file!";
const char* ERROR_FILE_R = "Error while reading the file!";
const char* ERROR_FILE_W = "Error while writing the file!";
const char* ERROR_FILE_S = "Error while seeking the file!";
const char* ERROR_FILE_D = "Error while working the file!";

const char* ERROR_STATUS_E = "EMPTYFILE";
const char* ERROR_STATUS_C = "CORRUPTED";



void generator();


char* getFileName();



void writePersons(const  Person*,    unsigned int,  const char* );
void printPersons(                                  const char* );



bool    findPersonSmallestAge  (const char*, Person&);
bool    findPersonBiggestAge   (const char*, Person&);



int main() {
    // generator();


    char* filePath = getFileName();

    printPersons(filePath);


    Person minPerson;   bool result1 = findPersonSmallestAge(filePath, minPerson);
    Person maxPerson;   bool result2 = findPersonBiggestAge (filePath, maxPerson);

    if (result1 == false) {
        std::cout << "The person with Min Age is: " << "ERROR!" << std::endl;
    } else {
        std::cout << "The person with Min Age is: " << std::left <<
            std::setw(12)   <<  minPerson.name1 << ' ' <<
            std::setw(12)   <<  minPerson.name2 << ' ' <<
                                minPerson.age   << ' ' << std::endl;
    }

    if (result2 == false) {
        std::cout << "The person with Max Age is: " << "ERROR!" << std::endl;
    } else {
        std::cout << "The person with Max Age is: " << std::left <<
            std::setw(12)   <<  maxPerson.name1 << ' ' <<
            std::setw(12)   <<  maxPerson.name2 << ' ' <<
                                maxPerson.age   << ' ' << std::endl;
    }


    delete[] filePath;

    filePath = nullptr;


    return 0;
}



void generator() {
    Person persons1[3] = {
        { "John"    , "Wick"    , 52, },
        { "Eve"     , "Macarro" , 20, },
        { "Winston" , "Scott"   , 71, },
    };

    Person persons2[7] = {
        { "Rick"    , "Grimes"  , 50,   },
        { "Daryl"   , "Dyxon"   , 45,   },
        { "Morgan"  , "Jones"   , 41,   },
        { "Negan"   , "Smith"   , 52,   },
        { "Carol"   , "Peletier", 49,   },
        { "Maggie"  , "Green"   , 47,   },
        { "Glenn"   , "Rhee"    , 35,   },
    };

    Person persons3[9] = {
        { "Leon"    , "Kennedy"     , 21, },
        { "Ada"     , "Wong"        , 24, },
        { "Chris"   , "Redfield"    , 25, },
        { "Claire"  , "Redfield"    , 19, },
        { "Jill"    , "Valentine"   , 23, },
        { "Albert"  , "Wesker"      , 38, },
        { "Carlos"  , "Oliveira"    , 21, },
        { "Josh"    , "Stone"       , 28, },
        { "Alice"   , "Abernathy"   , 25, },
    };

    writePersons(persons1, 3, "Persons1.bin");
    writePersons(persons2, 7, "Persons2.bin");
    writePersons(persons3, 9, "Persons3.bin");
}



char* getFileName() {
    char* buffer = new (std::nothrow) char[MAXF];

    std::cout << "Enter the file path: ";

    std::cin.getline(buffer, MAXF, '\n');

    if (std::cin.fail() || buffer[0] == '\0') {
        std::cin.clear  ()                                                  ;
        std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

        delete[] buffer; buffer = nullptr;

        return nullptr;
    }

    std::cout << std::endl;

    return buffer;
}



void writePersons(const Person* persons, unsigned int size, const char* file) {
    assert(persons  !=  nullptr );
    assert(size     !=  0       );
    assert(file     !=  nullptr );

    std::ofstream stream(file, std::ios::out | std::ios::trunc | std::ios::binary);

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



void printPersons(const char* filePath) {
    assert(filePath !=  nullptr );

    std::ifstream stream(filePath, std::ios::in | std::ios::binary);

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
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return;
    }

    if (fileSize % sizeof(Person) != 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_C << std::endl;

        return;
    }

    std::streamsize size = fileSize / sizeof(Person);

    stream.seekg(0, std::ios::beg);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        return;
    }

    std::cout << "The persons are: " << std::endl;

    for (std::streamsize i = 0; i < size; ++i) {
        Person temporary = { "", "", 0, };

        stream.read(reinterpret_cast<char*>(&temporary), sizeof(Person));

        if (stream.fail() || stream.gcount() != sizeof(Person)) {
            std::cerr << ERROR_FILE_R << std::endl;

            return;
        }

        if (temporary.age == 0) {
            std::cerr << "Person with Invalid Age!" << std::endl;

            stream.close(); return;
        }

        std::cout << "Person: " << std::left
            << std::setw(12)    << temporary.name1  << ' '
            << std::setw(12)    << temporary.name2  << ' '
                                << temporary.age    << std::endl;
    }

    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return;
    }
}



bool findPersonSmallestAge(const char* filePath, Person& person) {
    assert(filePath !=    nullptr );

    std::ifstream stream(filePath, std::ios::in | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return false;
    }

    stream.seekg(0, std::ios::end);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        return false;
    }

    std::streamsize fileSize = stream.tellg();

    if (fileSize == 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return false;
    }

    if (fileSize % sizeof(Person) != 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return false;
    }

    std::streamsize size = fileSize / sizeof(Person);

    stream.seekg(0, std::ios::beg);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        return false;
    }

    Person temp = person;

    bool status = false;

    for (std::streamsize i = 0; i < size; ++i) {
        stream.read(reinterpret_cast<char*>(&temp), sizeof(Person));

        if (stream.fail() || stream.gcount() != sizeof(Person)) {
            std::cerr << ERROR_FILE_R << std::endl;

            return false;
        }

        if (temp.age == 0) {
            std::cerr << "Person with Invalid Age!" << std::endl;

            stream.close(); return false;
        }

        if (status == false) {
            person = temp;
            status = true;
        } else {
            person = (temp.age < person.age) ? temp : person;
        }
    }

    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return false;
    }

    return status;
}

bool findPersonBiggestAge(const char* filePath, Person& person) {
    assert(filePath !=    nullptr );

    std::ifstream stream(filePath, std::ios::in | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return false;
    }

    stream.seekg(0, std::ios::end);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        return false;
    }

    std::streamsize fileSize = stream.tellg();

    if (fileSize == 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return false;
    }

    if (fileSize % sizeof(Person) != 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_C << std::endl;

        return false;
    }

    std::streamsize size = fileSize / sizeof(Person);

    stream.seekg(0, std::ios::beg);

    if (stream.fail()) {
        std::cerr << ERROR_FILE_S << std::endl;

        return false;
    }

    Person temp = person;

    bool status = false;

    for (std::streamsize i = 0; i < size; ++i) {
        stream.read(reinterpret_cast<char*>(&temp), sizeof(Person));

        if (stream.fail() || stream.gcount() != sizeof(Person)) {
            std::cerr << ERROR_FILE_R << std::endl;

            return false;
        }

        if (temp.age == 0) {
            std::cerr << "Person with Invalid Age!" << std::endl;

            stream.close(); return false;
        }

        if (status == false) {
            person = temp;
            status = true;
        } else {
            person = (temp.age > person.age) ? temp : person;
        }
    }

    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_C << std::endl;

        return false;
    }

    return status;
}
