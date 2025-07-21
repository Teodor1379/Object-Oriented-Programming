#include <iostream>


#include "Person.hpp"



int main() {
    try {
        Person person1("Dessita", "Alpha", 24, false);
        Person person2("Lidiq"  , "Alpha", 24, false);
        Person person3("Simona" , "Alpha", 23, false);

        findYoungest(person1, person2, person3).print();
        findOldest  (person1, person2, person3).print();
    } catch (std::exception& exception) {
        std::cerr << exception.what() << std::endl;

        return 1;
    }

    return 0;
}
