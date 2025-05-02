#include <iostream>



struct Flag {
    bool isAuthenticated    : 1;
    bool isAuthorized       : 1;
    bool isAdmin            : 1;
};



void printFlag(const Flag&);



int main() {
    Flag flag1 = { false, false, false };
    Flag flag2 = { true , false, false };
    Flag flag3 = { true , true , true  };


    printFlag(flag1);
    printFlag(flag2);
    printFlag(flag3);


    return 0;
}



void printFlag(const Flag& flag) {
    std::cout << std::boolalpha << "Authenticated   : " << flag.isAuthenticated << std::endl;
    std::cout << std::boolalpha << "Authorized      : " << flag.isAuthorized    << std::endl;
    std::cout << std::boolalpha << "Admin           : " << flag.isAdmin         << std::endl;
    
    std::cout << std::endl;
}
