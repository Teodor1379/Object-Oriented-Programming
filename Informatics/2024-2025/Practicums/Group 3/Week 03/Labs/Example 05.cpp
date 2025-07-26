#include <fstream>
#include <iostream>



void printStateBits(std::ifstream&);
void printStateFncs(std::ifstream&);



inline void setStateG(std::ifstream& stream) { stream.setstate(std::ios_base::goodbit   );  }
inline void setStateF(std::ifstream& stream) { stream.setstate(std::ios_base::failbit   );  }
inline void setStateB(std::ifstream& stream) { stream.setstate(std::ios_base::badbit    );  }
inline void setStateE(std::ifstream& stream) { stream.setstate(std::ios_base::eofbit    );  }



void scenarioGBit(std::ifstream&);
void scenarioFBit(std::ifstream&);
void scenarioBBit(std::ifstream&);
void scenarioEBit(std::ifstream&);



int main() {
    // State of Stream

    std::ifstream stream("../Files/Message.txt");

    printStateBits(stream);
    printStateFncs(stream);

    std::cout << std::endl;


    scenarioGBit(stream);
    scenarioFBit(stream);
    scenarioBBit(stream);
    scenarioEBit(stream);

    std::cout << std::endl;


    // Clear State of Stream

    stream.clear();

    printStateBits(stream);
    printStateFncs(stream);

    std::cout << std::endl;


    return 0;
}



void printStateBits(std::ifstream& stream) {
    std::cout << "Bits Information: " << std::endl;
    
    std::cout << "Good Bit: " << stream.goodbit << std::endl;
    std::cout << "Fail Bit: " << stream.failbit << std::endl;
    std::cout << "Bad  Bit: " << stream.badbit  << std::endl;
    std::cout << "EOF  Bit: " << stream.eofbit  << std::endl;
}

void printStateFncs(std::ifstream& stream) {
    std::cout << "Functions Information: " << std::endl;

    std::cout << "Good Bit: " << stream.good()  << std::endl;
    std::cout << "Fail Bit: " << stream.fail()  << std::endl;
    std::cout << "Bad  Bit: " << stream.bad ()  << std::endl;
    std::cout << "EOF  Bit: " << stream.eof ()  << std::endl;
}



void scenarioGBit(std::ifstream& stream) {
    setStateG(stream);

    printStateBits(stream);
    printStateFncs(stream);

    std::cout << std::endl;
}

void scenarioFBit(std::ifstream& stream) {
    setStateF(stream);

    printStateBits(stream);
    printStateFncs(stream);

    std::cout << std::endl;
}

void scenarioBBit(std::ifstream& stream) {
    setStateB(stream);

    printStateBits(stream);
    printStateFncs(stream);

    std::cout << std::endl;
}

void scenarioEBit(std::ifstream& stream) {
    setStateE(stream);

    printStateBits(stream);
    printStateFncs(stream);

    std::cout << std::endl;
}
