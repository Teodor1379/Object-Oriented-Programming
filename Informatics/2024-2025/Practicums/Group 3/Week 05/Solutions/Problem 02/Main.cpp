#include <iostream>

#include "Person.hpp"



int main() {
    Person person = Person("Teodor", "Dishanski", 21, true);
    
    person.printInformation();

    return 0;
}
