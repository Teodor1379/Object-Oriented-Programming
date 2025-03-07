#include <iostream>



inline bool isDigit(const char& letter) { return letter >= '0' && letter <= '9';    }
inline bool isLower(const char& letter) { return letter >= 'a' && letter <= 'z';    }
inline bool isUpper(const char& letter) { return letter >= 'A' && letter <= 'Z';    }



int main() {
    char letter = '\0';

    std::cout << "Enter the letter: ";

    std::cin >> letter;


    if (isDigit(letter)) {
        std::cout << "The letter is digit!" << std::endl;
    } else if (isLower(letter)) {
        std::cout << "The letter is lower!" << std::endl;
    } else if (isUpper(letter)) {
        std::cout << "The letter is upper!" << std::endl;
    } else {
        std::cout << "The letter is other!" << std::endl;
    }


    return 0;
}
