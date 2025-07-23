#include <cmath>

#include <cassert>
#include <cstring>

#include <limits>

#include <iomanip>

#include <iostream>



const unsigned int MAX = 256;



#define MIN_BOOKS  0
#define MAX_BOOKS 13
#define EPSILON 1e-9



struct Book {
    char*           title   ;
    char*           author  ;

    double          price   ;
    unsigned int    copies  ;
};

struct Library {
    char*           address     ;
    Book            books[13]   ;
    unsigned int    booksSize   ;
    unsigned int    readers     ;
};



unsigned int readSize();



double          readNumberD();
unsigned int    readNumberU();



char*   buildString(        );
void    clearString(char*&  );



Book    buildBook(      );
void    clearBook(Book& );



Library buildLibrary(           );
void    clearLibrary(Library&   );



double findAvgCostBooks(const Library&);
double findMinCostBooks(const Library&);
double findMaxCostBooks(const Library&);



const Book* findMinCopiesBook(const Library&);
const Book* findMaxCopiesBook(const Library&);

unsigned int findSumCopiesBook(const Library&);



int main() {
    Library library = buildLibrary();

    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(2) << "The avg price of the books in the library is: " << findAvgCostBooks(library) << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "The min price of the books in the library is: " << findMinCostBooks(library) << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "The max price of the books in the library is: " << findMaxCostBooks(library) << std::endl;

    std::cout << std::endl;

    std::cout << "The book with min copies is: " << findMinCopiesBook(library)->title << std::endl;
    std::cout << "The book with max copies is: " << findMaxCopiesBook(library)->title << std::endl;

    std::cout << std::endl;

    std::cout << "The number of copies in the library is: " << findSumCopiesBook(library) << std::endl;


    clearLibrary(library);


    return 0;
}



unsigned int readSize() {
    unsigned int size = 0;

    while (true) {
        std::cin >> size;

        if (std::cin.fail() || (size == MIN_BOOKS || size > MAX_BOOKS)) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return size;
        }
    }
}



double readNumberD() {
    double number = 0.0;

    while (true) {
        std::cin >> number;

        if (std::cin.fail() || std::fabs(number) < EPSILON) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return number;
        }
    }
}

unsigned int readNumberU() {
    unsigned int number = 0;

    while (true) {
        std::cin >> number;

        if (std::cin.fail() || number == 0) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return number;
        }
    }
}



char* buildString() {
    char* string = new char[MAX]();

    if (string != nullptr) {
        std::cin.getline(string, MAX, '\n');
    }

    return string;
}

void clearString(char*& string) {
    assert(string   !=  nullptr );

    delete[] string;

    string = nullptr;
}



Book buildBook() {
    Book book = { nullptr, nullptr, 0.0, 0 };

    std::cout << "\tEnter the title   of the book: "; book.title  = buildString();
    std::cout << "\tEnter the author  of the book: "; book.author = buildString();
    std::cout << "\tEnter the price   of the book: "; book.price  = readNumberD();
    std::cout << "\tEnter the copies  of the book: "; book.copies = readNumberU();

    return book;
}

void clearBook(Book& book) {
    clearString(book.title  );
    clearString(book.author );
}



Library buildLibrary() {
    Library library = { nullptr, {}, 0, 0 };

    std::cout << "Enter the address of the library: ";  library.address     =   buildString ();
    std::cout << "Enter the readers of the library: ";  library.readers     =   readNumberU ();
    std::cout << "Enter the size    of the library: ";  library.booksSize   =   readSize    ();

    std::cout << "Enter the information about the books:" << std::endl;

    for (unsigned int i = 0; i < library.booksSize; ++i) {
        std::cout << std::endl;

        library.books[i] = buildBook();
    }

    return library;
}

void clearLibrary(Library& library) {
    clearString(library.address);

    for (unsigned int i = 0; i < library.booksSize; ++i) {
        clearBook(library.books[i]);
    }
}



double findAvgCostBooks(const Library& library) {
    if (library.booksSize == 0) {
        return 0.0;
    }

    double sumPrice = 0.0;

    for (unsigned int i = 0; i < library.booksSize; ++i) {
        assert(std::isfinite(library.books[i].price));

        sumPrice = sumPrice + library.books[i].price;
    }

    return sumPrice / library.booksSize;
}

double findMinCostBooks(const Library& library) {
    if (library.booksSize == 0) {
        return 0.0;
    }

    double minPrice = library.books[0].price;

    for (unsigned int i = 0; i < library.booksSize; ++i) {
        assert(std::isfinite(library.books[i].price));

        minPrice = std::min(minPrice, library.books[i].price);
    }

    return minPrice;
}

double findMaxCostBooks(const Library& library) {
    if (library.booksSize == 0) {
        return 0.0;
    }

    double maxPrice = library.books[0].price;

    for (unsigned int i = 0; i < library.booksSize; ++i) {
        assert(std::isfinite(library.books[i].price));

        maxPrice = std::max(maxPrice, library.books[i].price);
    }

    return maxPrice;
}



const Book* findMinCopiesBook(const Library& library) {
    const Book* result = &(library.books[0]);

    for (unsigned int i = 1; i < library.booksSize; ++i) {
        if (result->copies > library.books[i].copies) {
            result = &(library.books[i]);
        }
    }

    return result;
}

const Book* findMaxCopiesBook(const Library& library) {
    const Book* result = &(library.books[0]);

    for (unsigned int i = 1; i < library.booksSize; ++i) {
        if (result->copies < library.books[i].copies) {
            result = &(library.books[i]);
        }
    }

    return result;
}



unsigned int findSumCopiesBook(const Library& library) {
    unsigned int sumCopies = 0;

    for (unsigned int i = 0; i < library.booksSize; ++i) {
        sumCopies = sumCopies + library.books[i].copies;
    }

    return sumCopies;
}
