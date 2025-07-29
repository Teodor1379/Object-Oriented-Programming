#include "Word.hpp"



Word& Word::operator=(const Word& instance) {
    if (this != &instance) {
        char* temporary = this->buildString(instance.string);

        this->destroyString(temporary);

        this->string = temporary;
    }

    return *this;
}



std::istream& Word::readFrom(std::istream& stream) {
    char buffer[MAX] = { 0 };

    this->string    = this->buildString(buffer) ;
    this->size      = strlen(this->string)      ;

    return stream >> this->string;
}

std::ostream& Word::writeTo(std::ostream& stream) const {
    return stream << this->string;
}



Word Word::concatenate(const Word& word1, const Word& word2) const {
    char* concatenation = new char[word1.getSize() + word2.getSize() + 1]();

    strcpy(concatenation, word1.getString());
    strcat(concatenation, word2.getString());

    Word result(concatenation);

    delete[] concatenation;

    return result;
}



Word concatenateWords(const Word words[SIZ], unsigned int size) {
    assert(size !=  0   );
    assert(size <=  SIZ );

    Word result;

    for (unsigned int i = 0; i < size; ++i) {
        result = result.concatenate(result, words[i]);
    }
}
