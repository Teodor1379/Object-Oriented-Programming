#include <iostream>



#define MAX 256



struct Person {
    char name1[MAX];
    char name2[MAX];
};

struct RelationShip {
    Person m;
    Person f;
};



typedef Person          P;
typedef RelationShip    R;



void printPersonInformation(const P& person) {
    std::cout << "Name 1: " << person.name1 << std::endl;
    std::cout << "Name 2: " << person.name2 << std::endl;

    std::cout << std::endl;
}

void printRelationShipInformation(const R& relationShip) {
    std::cout << "M Information:\n";    printPersonInformation(relationShip.m);
    std::cout << "F Information:\n";    printPersonInformation(relationShip.f);
}



int main() {
    P m = { "John"  , "Wick" };
    P f = { "Eve"   , "Macc" };

    R r = { m, f };


    std::cout << "Hello World!" << std::endl;


    printRelationShipInformation(r);


    return 0;
}
