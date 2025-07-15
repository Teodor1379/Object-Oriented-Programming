#include <limits>

#include <iostream>



#define PERMISSIONS 7

#define PERM_R 4
#define PERM_W 2
#define PERM_X 1



enum class ReadPermissions {
    EMPTY   =   0,
    READ    =   1,
};

enum class WritePermissions {
    EMPTY   =   0,
    WRITE   =   1,
};

enum class ExecutePermissions {
    EMPTY   =   0,
    EXECUTE =   1,
};



unsigned int    readNumber();



ReadPermissions     getR(unsigned int number);
WritePermissions    getW(unsigned int number);
ExecutePermissions  getX(unsigned int number);



void printR(ReadPermissions     permissions);
void printW(WritePermissions    permissions);
void printX(ExecutePermissions  permissions);

void printPermissions(unsigned int permissions);



int main() {
    unsigned int number = readNumber();

    printPermissions(number);

    return 0;
}



unsigned int readNumber() {
    unsigned int number = 0;

    while (true) {
        std::cout << "Enter the number: ";

        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            if (number > PERMISSIONS) {
                continue;
            }

            return number;
        }
    }
}



ReadPermissions getR(unsigned int number) {
    unsigned int bit = number & PERM_R;

    return bit == 0 ? 
        ReadPermissions::EMPTY      :
        ReadPermissions::READ       ;
}

WritePermissions getW(unsigned int number) {
    unsigned int bit = number & PERM_W;

    return bit == 0 ?
        WritePermissions::EMPTY     :
        WritePermissions::WRITE     ;
}

ExecutePermissions getX(unsigned int number) {
    unsigned int bit = number & PERM_X;

    return bit == 0 ?
        ExecutePermissions::EMPTY   :
        ExecutePermissions::EXECUTE ;
}



void printR(ReadPermissions permissions) {
    if (permissions == ReadPermissions::READ) {
        std::cout << 'r';
    } else {
        std::cout << '-';
    }
}

void printW(WritePermissions permissions) {
    if (permissions == WritePermissions::WRITE) {
        std::cout << 'w';
    } else {
        std::cout << '-';
    }
}

void printX(ExecutePermissions permissions) {
    if (permissions == ExecutePermissions::EXECUTE) {
        std::cout << 'e';
    } else {
        std::cout << '-';
    }
}



void printPermissions(unsigned int permissions) {
    std::cout << "The permissions are: ";

    printR(getR(permissions));
    printW(getW(permissions));
    printX(getX(permissions));

    std::cout << std::endl;
}
