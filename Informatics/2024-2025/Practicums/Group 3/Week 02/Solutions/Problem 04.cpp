#include <cassert>
#include <cstring>

#include <limits>

#include <iostream>



#define MAX 256



const unsigned int  minOption   =   1;
const unsigned int  maxOption   =   3;



enum class Belt {
    UNKNOWN = -1,
    WHITE   =  0,
    YELLOW  =  1,
    GREEN   =  2,
    RED     =  3,
    BROWN   =  4,
    BLACK   =  5,
    COUNT   =  6,
};

enum class Weapon {
    INVALID     = -1,
    NUNCHAKU    =  0,
    SAI         =  1,
    BOSTAFF     =  2,
    KATANA      =  3,
    KUSARIGAMA  =  4,
    CLAWS       =  5,
    NAGINATA    =  6,
    COUNT       =  7,
};



const char* belts   [static_cast<int>(Belt::COUNT)  ]   =   { "White", "Yellow", "Green", "Red", "Brown", "Black"                       };
const char* weapons [static_cast<int>(Weapon::COUNT)]   =   { "Nunchaku", "Sai", "BoStaff", "Katana", "Kusarigama", "Claws", "Naginata" };



struct Ninja {
    char    firstName[MAX];
    char    thirdName[MAX];

    Belt    belt    ;
    Weapon  weapon  ;

    bool    gender;

    // warning: padding struct size to alignment boundary with 3 bytes [-Wpadded]
};



unsigned int readSize();
unsigned int readOptn();



Ninja   buildNinja(                     );
void    printNinja(const Ninja& ninja   );



Belt    findBelt    (const char* string);
Weapon  findWeapon  (const char* string);



char*   buildString(                );
void    clearString(char*& string   );




Ninja*  buildArray(                 unsigned int size   );
void    clearArray(Ninja*& ninjas                       );



void    inputArray(         Ninja* ninjas, unsigned int size);
void    printArray(const    Ninja* ninjas, unsigned int size);



unsigned int    countNinjasBelt     (const Ninja* ninjas, unsigned int size,  Belt    belt    );
unsigned int    countNinjasWeapon   (const Ninja* ninjas, unsigned int size,  Weapon  weapon  );
unsigned int    countNinjasGender   (const Ninja* ninjas, unsigned int size,  bool    gender  );



Ninja*  filterNinjasBelt    (const Ninja* ninjas, unsigned int size, unsigned int& filteredSize,  Belt    belt    );
Ninja*  filterNinjasWeapon  (const Ninja* ninjas, unsigned int size, unsigned int& filteredSize,  Weapon  weapon  );
Ninja*  filterNinjasGender  (const Ninja* ninjas, unsigned int size, unsigned int& filteredSize,  bool    gender  );



int main() {
    unsigned int size = readSize();

    std::cout << std::endl;
    std::cout << std::endl;


    Ninja* ninjas = buildArray(size);


    if (ninjas == nullptr) {
        std::cout << "Allocating Memory... ERROR!" << std::endl;

        return 1;
    }


    unsigned int option = 0;

    do {
        std::cout << "\nEnter the filter of the ninjas:\n" << std::endl;

        std::cout << "1. Belt"      << std::endl;
        std::cout << "2. Weapon"    << std::endl;
        std::cout << "3. Gender"    << std::endl;

        std::cout << std::endl;

        option = readOptn();
    } while (option < minOption || option > maxOption);


    switch (option) {
        case 1: {
            std::cout << std::endl;

            char* belt = buildString();

            if (belt == nullptr) {
                std::cout << "Allocating Memory... ERROR!" << std::endl;

                return 1;
            }

            unsigned int anotherSize = 0;

            Ninja* filteredNinjas = filterNinjasBelt(ninjas, size, anotherSize, findBelt(belt));

            if (filteredNinjas == nullptr) {
                std::cout << "Applying Filter... ERROR!" << std::endl;

                clearString(belt);

                clearArray(ninjas);

                return 2;
            }

            printArray(filteredNinjas, anotherSize);

            clearString(belt);
            
            clearArray(filteredNinjas);
        }; break;

        case 2: {
            std::cout << std::endl;

            char* weapon = buildString();

            if (weapon == nullptr) {
                std::cout << "Allocating Memory... ERROR!" << std::endl;

                return 1;
            }

            unsigned int anotherSize = 0;

            Ninja* filteredNinjas = filterNinjasWeapon(ninjas, size, anotherSize, findWeapon(weapon));

            if (filteredNinjas == nullptr) {
                std::cout << "Applying Filter... ERROR!" << std::endl;

                clearString(weapon);

                clearArray(ninjas);

                return 2;
            }

            printArray(filteredNinjas, anotherSize);

            clearString(weapon);

            clearArray(filteredNinjas);
        }; break;

        case 3: {
            bool gender = false;

            std::cout << std::endl;

            std::cout << "Input the gender: ";

            std::cin >> gender;

            unsigned int filteredSize = 0;

            Ninja* filteredNinjas = filterNinjasGender(ninjas, size, filteredSize, gender);

            if (filteredNinjas == nullptr) {
                std::cout << "Applying Filter... ERROR!" << std::endl;

                clearArray(ninjas);

                return 2;
            }

            printArray(filteredNinjas, filteredSize);

            clearArray(filteredNinjas);
        }; break;

        default: ;
    }


    clearArray(ninjas);


    return 0;
}



unsigned int readSize() {
    unsigned int size = 0;

    while (true) {
        std::cout << "Enter the number of ninjas: ";

        std::cin >> size;

        if (std::cin.fail()) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return size;
        }
    }
}

unsigned int readOptn() {
    unsigned int option = 0;

    while (true) {
        std::cout << "Enter the option from the menu: ";

        std::cin >> option;

        if (std::cin.fail()) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return option;
        }
    }
}



Belt findBelt(const char* string) {
    assert(string   !=  nullptr);

    for (unsigned int i = 0; i < static_cast<int>(Belt::COUNT); ++i) {
        if (strcmp(string, belts[i]) == 0) {
            return static_cast<Belt>(i);
        }
    }

    return Belt::UNKNOWN;
}

Weapon findWeapon(const char* string) {
    assert(string   !=  nullptr);

    for (unsigned int i = 0; i < static_cast<int>(Weapon::COUNT); ++i) {
        if (strcmp(string, weapons[i]) == 0) {
            return static_cast<Weapon>(i);
        }
    }

    return Weapon::INVALID;
}



char* buildString() {
    char* string = new (std::nothrow) char[MAX];

    if (string != nullptr) {
        std::cout << "Input the string: ";

        std::cin.getline(string, MAX, '\n');
    }

    return string;
}

void clearString(char*& string) {
    assert(string != nullptr);

    delete[] string;

    string = nullptr;
}



Ninja buildNinja() {
    Ninja result = { "", "", Belt::UNKNOWN, Weapon::INVALID, false };


    char beltString     [MAX];
    char weaponString   [MAX];


    std::cout << "Enter the first name  of the ninja: ";    std::cin >> result.firstName;
    std::cout << "Enter the third name  of the ninja: ";    std::cin >> result.thirdName;
    std::cout << "Enter the belt        of the ninja: ";    std::cin >> beltString      ;
    std::cout << "Enter the weapon      of the ninja: ";    std::cin >> weaponString    ;
    std::cout << "Enter the gender      of the ninja: ";    std::cin >> result.gender   ;

    std::cout << std::endl;


    result.belt     = findBelt  (beltString     );
    result.weapon   = findWeapon(weaponString   );

    return result;

    // warning: function returns an aggregate [-Waggregate-return]
}



void printNinja(const Ninja& ninja) {
    int beltIndex   = static_cast<int>(ninja.belt   );
    int weaponIndex = static_cast<int>(ninja.weapon );

    std::cout << "The first name    of the ninja is: "  << ninja.firstName      << std::endl;
    std::cout << "The third name    of the ninja is: "  << ninja.thirdName      << std::endl;

    if (ninja.belt == Belt::UNKNOWN) {
        std::cout << "The belt          of the ninja is: "  << "UNKNOWN"            << std::endl;
    } else {
        std::cout << "The belt          of the ninja is: "  << belts[beltIndex]     << std::endl;
    }

    if (ninja.weapon == Weapon::INVALID) {
        std::cout << "The weapon        of the ninja is: "  << "INVALID"            << std::endl;
    } else {
        std::cout << "The weapon        of the ninja is: "  << weapons[weaponIndex] << std::endl;
    }
    
    if (ninja.gender) {
        std::cout << "The gender        of the ninja is: "  << "MALE"               << std::endl;
    } else {
        std::cout << "The gender        of the ninja is: "  << "FEMALE"             << std::endl;
    }

    std::cout << std::endl;
}



Ninja* buildArray(unsigned int size) {
    assert(size !=  0);

    Ninja* array = new (std::nothrow) Ninja[size];

    if (array != nullptr) {
        inputArray(array, size);
        printArray(array, size);
    }

    return array;
}

void clearArray(Ninja*& ninjas) {
    assert(ninjas   != nullptr);

    delete[] ninjas;

    ninjas = nullptr;
}



void inputArray(Ninja* ninjas, unsigned int size) {
    assert(ninjas   !=  nullptr );
    assert(size     !=  0       );
    
    std::cout << "Enter the ninjas in your program: " << std::endl;

    std::cout << std::endl;

    for (unsigned int i = 0; i < size; ++i) {
        ninjas[i] = buildNinja();

        // warning: function call has aggregate value [-Waggregate-return]
    }
}

void printArray(const Ninja* ninjas, unsigned int size) {
    assert(ninjas   !=  nullptr );
    assert(size     !=  0       );

    std::cout << std::endl;

    std::cout << "The ninjas in your program are: " << std::endl;

    std::cout << std::endl;

    for (unsigned int i = 0; i < size; ++i) {
        printNinja(ninjas[i]);
    }

    std::cout << std::endl;
}



unsigned int countNinjasBelt(const Ninja* ninjas, unsigned int size, Belt belt) {
    assert(ninjas   !=  nullptr         );
    assert(size     !=  0               );
    assert(belt     !=  Belt::UNKNOWN   );
    assert(belt     !=  Belt::COUNT     );

    unsigned int result = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (ninjas[i].belt == belt) {
            result = result + 1;
        }
    }

    return result;
}

unsigned int countNinjasWeapon(const Ninja* ninjas, unsigned int size, Weapon weapon) {
    assert(ninjas   !=  nullptr         );
    assert(size     !=  0               );
    assert(weapon   !=  Weapon::INVALID );
    assert(weapon   !=  Weapon::COUNT   );

    unsigned int result = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (ninjas[i].weapon == weapon) {
            result = result + 1;
        }
    }

    return result;
}

unsigned int countNinjasGender(const Ninja* ninjas, unsigned int size, bool gender) {
    assert(ninjas   !=  nullptr         );
    assert(size     !=  0               );

    unsigned int result = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (ninjas[i].gender == gender) {
            result = result + 1;
        }
    }

    return result;
}




Ninja* filterNinjasBelt(const Ninja* ninjas, unsigned int size, unsigned int& filteredSize, Belt belt) {
    assert(ninjas   !=  nullptr         );
    assert(size     !=  0               );
    assert(belt     !=  Belt::UNKNOWN   );
    assert(belt     !=  Belt::COUNT     );

    filteredSize = countNinjasBelt(ninjas, size, belt);

    if (filteredSize == 0) {
        filteredSize = 0;

        return nullptr;
    }

    Ninja* filteredNinjas = new (std::nothrow) Ninja[filteredSize]();

    if (filteredNinjas == nullptr) {
        filteredSize = 0;

        return nullptr;
    }

    unsigned int index = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (ninjas[i].belt == belt) {
            filteredNinjas[index] = ninjas[i];

            index = index + 1;
        }
    }

    return filteredNinjas;
}

Ninja* filterNinjasWeapon(const Ninja* ninjas, unsigned int size, unsigned int& filteredSize, Weapon weapon) {
    assert(ninjas   !=  nullptr         );
    assert(size     !=  0               );
    assert(weapon   !=  Weapon::INVALID );
    assert(weapon   !=  Weapon::COUNT   );

    filteredSize = countNinjasWeapon(ninjas, size, weapon);

    Ninja* filteredNinjas = new (std::nothrow) Ninja[filteredSize]();

    if (filteredNinjas == nullptr) {
        filteredSize = 0;

        return nullptr;
    }

    unsigned int index = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (ninjas[i].weapon == weapon) {
            filteredNinjas[index] = ninjas[i];

            index = index + 1;
        }
    }

    return filteredNinjas;
}

Ninja* filterNinjasGender(const Ninja* ninjas, unsigned int size, unsigned int& filteredSize, bool gender) {
    assert(ninjas   !=  nullptr         );
    assert(size     !=  0               );

    filteredSize = countNinjasGender(ninjas, size, gender);

    Ninja* filteredNinjas = new (std::nothrow) Ninja[filteredSize]();

    if (filteredNinjas == nullptr) {
        filteredSize = 0;

        return nullptr;
    }

    unsigned int index = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (ninjas[i].gender == gender) {
            filteredNinjas[index] = ninjas[i];

            index = index + 1;
        }
    }

    return filteredNinjas;
}
