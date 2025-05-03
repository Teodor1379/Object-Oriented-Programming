#include <iostream>

#include "Person.hpp"



int main() {
    Person person = Person("Teodor", "Dishanski", 21, true);
    
    std::cout << person.getFirstName() << std::endl;
    std::cout << person.getThirdName() << std::endl;
    std::cout << person.getAge() << std::endl;
    std::cout << person.getSex() << std::endl;

    return 0;
}