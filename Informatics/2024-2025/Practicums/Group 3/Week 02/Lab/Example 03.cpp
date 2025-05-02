#include <cassert>

#include <iostream>



#define MAX 256



enum Code {
    CODE_OK,
    CODE_ER,
};



struct Parser {
    int     number  ;
    Code    code    ;   
};



const char* codes[2] = { "OK", "ERROR", };



char*   buildString(                );
void    clearString(char*& string   );



Parser parse(const char* string);



int main() {
    char* string = buildString();

    if (string == nullptr) {
        std::cout << "Allocating Memory... ERROR!" << std::endl;

        return 1;
    }

    
    Parser parser = parse(string);  // warning: function call has aggregate value [-Waggregate-value]


    std::cout << "The number    from the operation is: " << parser.number       << std::endl;
    std::cout << "The code      from the operation is: " << codes[parser.code]  << std::endl;


    clearString(string);


    return 0;
}



char* buildString() {
    char* string = new (std::nothrow) char[MAX];

    if (string != nullptr) {
        std::cout << "Enter the string: ";

        std::cin.getline(string, '\n');
    }

    return string;
}

void clearString(char*& string) {
    assert(string != nullptr);

    delete[] string;

    string = nullptr;
}



Parser parse(const char* string) {
    assert(string != nullptr);

    Parser result = { 0, CODE_ER };

    int number = 0;

    for (unsigned int i = 0; string[i] != '\0'; ++i) {
        if (string[i] >= '0' && string[i] <= '9') {
            number = number * 10 + (string[i] - '0');

            result.number   = number    ;
            result.code     = CODE_OK   ;
        } else {
            result.number   = 0         ;
            result.code     = CODE_ER   ;

            break;
        }
    }

    return result;

    // warning: function returns an aggregate [-Waggregate-return]
}
