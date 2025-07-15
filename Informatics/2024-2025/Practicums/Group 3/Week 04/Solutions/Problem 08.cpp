#include <cassert>

#include <cstdint>

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



const char* ERROR_FILE_R = "Error while reading from    the file!";
const char* ERROR_FILE_W = "Error while writing to      the file!";
const char* ERROR_FILE_O = "Error while opening         the file!";
const char* ERROR_FILE_D = "Error while operating with  the file!";

const char* ERROR_STATUS_E = "EMPTY"    ;
const char* ERROR_STATUS_C = "CORRUPTED";



char* getFileName();



void generator();



Person* buildPersons(                   unsigned int&,  const char* );
void    clearPersons(       Person*                                 );
void    writePersons(const  Person*,    unsigned int,   const char* );
void    printPersons(const  Person*,    unsigned int                );



const Person*   findPersonSmallestAge   (const Person*, unsigned int);
const Person*   findPersonBiggestAge    (const Person*, unsigned int);



void printPersons(const char*);



bool    findPersonSmallestAge  (const char*, Person&);
bool    findPersonBiggestAge   (const char*, Person&);



int main() {
    generator();


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


    /*
        unsigned int size = 0;
        
        Person* persons = buildPersons(size, filePath);

        if (persons == nullptr) {
            return 1;
        }

        printPersons(persons, size);


        const Person* minAgePerson = findPersonSmallestAge  (persons, size);
        const Person* maxAgePerson = findPersonBiggestAge   (persons, size);

        std::cout << "The person with Min Age is: " << std::left <<
            std::setw(12)   <<  minAgePerson->name1 << ' '  <<
            std::setw(12)   <<  minAgePerson->name2 << ' '  <<
                                minAgePerson->age   << ' '  << std::endl;

        std::cout << "The person with Max Age is: " << std::left <<
            std::setw(12)   <<  maxAgePerson->name1 << ' '  <<
            std::setw(12)   <<  maxAgePerson->name2 << ' '  <<
                                maxAgePerson->age   << ' '  << std::endl;


        clearPersons(persons);
    */


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

    std::cout << std::endl;

    return buffer;
}



Person* buildPersons(unsigned int& size, const char* file) {
    std::ifstream stream(file, std::ios::in | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        size = 0; return nullptr;
    }

    stream.seekg(0, std::ios_base::end);

    std::streamsize fileSize = stream.tellg();

    if (fileSize == 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        size = 0; return nullptr;
    }

    if (fileSize % sizeof(Person) != 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        size = 0; return nullptr;
    }

    size = fileSize / sizeof(Person);

    Person* persons = new (std::nothrow) Person[size];

    if (persons == nullptr) {
        size = 0; return nullptr;
    }

    stream.seekg(0, std::ios_base::beg);

    stream.read(reinterpret_cast<char*>(persons), size * sizeof(Person));

    if (stream.fail() || stream.gcount() != static_cast<std::streamsize>(size * sizeof(Person))) {
        std::cerr << ERROR_FILE_R << std::endl;

        stream.close();

        size = 0; return nullptr;
    }

    stream.close();

    for (unsigned int i = 0; i < size; ++i) {
        if (persons[i].age == 0) {
            delete[] persons;

            return nullptr;
        }
    }

    return persons;
}

void clearPersons(Person* persons) {
    assert(persons  !=  nullptr );

    delete[] persons;

    persons = nullptr;
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

        return;
    }
}

void printPersons(const Person* persons, unsigned int size) {
    assert(persons  !=  nullptr );
    assert(size     !=  0       );

    std::cout << "The persons are: " << std::endl;

    for (unsigned int i = 0; i < size; ++i) {
        std::cout << "Person:" << std::left
            << std::setw(12) << persons[i].name1    << ' '
            << std::setw(12) << persons[i].name2    << ' '
                             << persons[i].age      << std::endl;
    }
}



const Person* findPersonSmallestAge(const Person* persons, unsigned int size) {
    assert(persons  !=  nullptr );
    assert(size     !=  0       );

    const Person* result = &(persons[0]);

    for (unsigned int i = 1; i < size; ++i) {
        if (result->age > persons[i].age) {
            result = &(persons[i]);
        }
    }

    return result;
}

const Person* findPersonBiggestAge(const Person* persons, unsigned int size) {
    assert(persons  !=  nullptr );
    assert(size     !=  0       );

    const Person* result = &(persons[0]);

    for (unsigned int i = 1; i < size; ++i) {
        if (result->age < persons[i].age) {
            result = &(persons[i]);
        }
    }

    return result;
}



void printPersons(const char* filePath) {
    assert(filePath !=  nullptr );

    std::ifstream stream(filePath, std::ios::in | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    stream.seekg(0, std::ios::end);

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
}



bool findPersonSmallestAge(const char* filePath, Person& person) {
    assert(filePath !=    nullptr );

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

    if (fileSize % sizeof(Person) != 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return false;
    }

    std::streamsize size = fileSize / sizeof(Person);

    stream.seekg(0, std::ios::beg);

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

    return status;
}
