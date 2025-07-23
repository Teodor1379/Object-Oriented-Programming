#include <cassert>
#include <cstring>

#include <limits>

#include <iostream>



struct Cone {
    unsigned int identifier;

    union String {
        char sml[4];
        char big[4];
    };

    String size;
};



unsigned int readSize();



Cone*   buildCones(                     unsigned int);
void    printCones(const    Cone*   ,   unsigned int);
void    clearCones(         Cone*&                  );



unsigned int countSmlCones(const Cone*, unsigned int);
unsigned int countBigCones(const Cone*, unsigned int);



int main() {
    unsigned int size = readSize();

    std::cout << std::endl;


    Cone* cones = buildCones(size);

    if (cones == nullptr) {
        std::cerr << "Allocating Memory... ERROR!" << std::endl;

        return 1;
    }


    std::cout << "The number of SML cones are: " << countSmlCones(cones, size) << std::endl;
    std::cout << "The number of BIG cones are: " << countBigCones(cones, size) << std::endl;



    clearCones(cones);


    return 0;
}



unsigned int readSize() {
    unsigned int size = 0;

    while (true) {
        std::cout << "Enter the size of the basket: ";

        std::cin >> size;

        if (std::cin.fail() || size == 0) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return size;
        }
    }
}



Cone* buildCones(unsigned int size) {
    assert(size !=  0   );

    Cone* cones = new (std::nothrow) Cone[size];

    if (cones != nullptr) {
        for (unsigned int i = 0; i < size; ++i) {
            cones[i].identifier = i + 1;

            if ((i + 1) % 2 == 0) {
                strcpy(cones[i].size.sml, "SML");
            } else {
                strcpy(cones[i].size.big, "BIG");
            }
        }
    }

    return cones;
}

void printCones(const Cone* cones, unsigned int size) {
    assert(cones    !=  nullptr );
    assert(size     !=  0       );

    std::cout << "The cones are: " << std::endl;

    for (unsigned int i = 0; i < size; ++i) {
        // std::cout << "Cone " << cones[i].identifier << " - " << cones[i].size.sml << std::endl; 
        // std::cout << "Cone " << cones[i].identifier << " - " << cones[i].size.big << std::endl;
    }
}

void clearCones(Cone*& cones) {
    assert(cones    !=  nullptr );

    delete[] cones;

    cones = nullptr;
}



unsigned int countSmlCones(const Cone* cones, unsigned int size) {
    assert(cones    !=  nullptr );
    assert(size     !=  0       );

    unsigned int number = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (strcmp(cones[i].size.sml, "SML") == 0) {
            number = number + 1;
        }
    }

    return number;
}

unsigned int countBigCones(const Cone* cones, unsigned int size) {
    assert(cones    !=  nullptr );
    assert(size     !=  0       );
    
    unsigned int number = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (strcmp(cones[i].size.big, "BIG") == 0) {
            number = number + 1;
        }        
    }

    return number;
}
