#include <limits>

#include <iostream>



#define MIN_AGE   1
#define MAX_AGE 101



enum Age {
    YOUNG   ,
    AVERAGE ,
    OLD     ,
    INVALID ,
};



const char* ageStrings[4] = { "Young", "Average", "Old", "Invalid"  };



int readAge();



int main() {
    Age age = static_cast<Age>(readAge() / 34);

    std::cout << "The interval is: " << ageStrings[age] << std::endl;
    
    return 0;
}



int readAge() {
    int age = 0;

    while (true) {
        std::cout << "Enter the age of the human: ";

        std::cin >> age;

        if (std::cin.fail()) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            if (age < MIN_AGE || age > MAX_AGE) {
                continue;
            }

            return age;
        }
    }
}
