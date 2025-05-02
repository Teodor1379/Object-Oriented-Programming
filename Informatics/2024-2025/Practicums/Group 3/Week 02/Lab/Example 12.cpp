#include <cmath>

#include <iostream>



struct Book {
    double  price   ;   // 8
    int     copies  ;   // 4
    char    genre   ;   // 1
    bool    sold    ;   // 1
                        // 2 padding
};



Book initBook();



bool areBooksEqual(const Book&, const Book&);



void printBook(const Book&);



int main() {
    Book instance = { 10.0, 1000, 'F', false };

    printBook(instance);



    Book lichKing = initBook(); // warning: function call has aggregate value [-Waggregate-return]

    printBook(lichKing);


    bool equalBooks = areBooksEqual(instance, lichKing);

    std::cout << std::boolalpha << equalBooks << std::endl;


    return 0;
}



Book initBook() {
    Book result;

    std::cout << "Enter the price of the book: ";   std::cin >> result.price;
    std::cout << "Enter the copies of the book: ";  std::cin >> result.copies;
    std::cout << "Enter the genre of the book: ";   std::cin >> result.genre;
    std::cout << "Enter the sold of the book: ";    std::cin >> result.sold;

    return result;

    // warning: function returns an aggregate [-Waggregate-value]
}



bool areBooksEqual(const Book& book1, const Book& book2) {
    return
        std::fabs(book1.price - book2.price) < 1e-9 &&
        book1.copies == book2.copies                &&
        book1.genre  == book2.genre                 &&
        book1.sold   == book2.sold;
}



void printBook(const Book& book) {
    std::cout << "The price of the book is: "   << book.price   << std::endl;
    std::cout << "The copies of the book is: "  << book.copies  << std::endl;
    std::cout << "The genre of the book is: "   << book.genre   << std::endl;
    std::cout << "The sold of the book is: "    << book.sold    << std::endl;   
}
