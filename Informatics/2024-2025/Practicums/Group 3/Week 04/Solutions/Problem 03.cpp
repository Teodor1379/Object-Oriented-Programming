#include <cassert>

#include <cmath>

#include <iomanip>

#include <fstream>
#include <iostream>



#define MAX     256
#define EPSILON 1e-9



struct Item {
    double price    ;
    double quantity ;
};



const char* ERROR_FILE_R = "Error while reading from    the file!";
const char* ERROR_FILE_W = "Error while writing to      the file!";
const char* ERROR_FILE_O = "Error while opening         the file!";
const char* ERROR_FILE_D = "Error while operating with  the file!";

const char* ERROR_STATUS_E = "EMPTY"    ;
const char* ERROR_STATUS_C = "CORRUPTED";



void generator();


char* getFileName();



Item*   buildItems(             unsigned int&,  const char* );
void    writeItems(const Item*, unsigned int,   const char* );
void    clearItems(      Item*&                             );
void    printItems(const Item*, unsigned int                );



bool    validateItems(const Item*, unsigned int);



double findSumPrices(const Item*, unsigned int);



const Item* findMinPriceItem(const Item*, unsigned int);
const Item* findMaxPriceItem(const Item*, unsigned int);



int main() {
    // generator();

    char* filePath = getFileName();


    unsigned int size = 0;


    Item* items = buildItems(size, filePath);

    if (items == nullptr) {
        std::cout << "Building Items... ERROR!" << std::endl;
        
        return 1;
    }


    printItems(items, size);


    std::cout << "\nThe price of the items is: " << findSumPrices(items, size) << '\n' << std::endl;


    const Item* minItem = findMinPriceItem(items, size);
    const Item* maxItem = findMaxPriceItem(items, size);

    std::cout << std::fixed << std::setprecision(2) << "The Min Price Item Quantity is: " << (minItem != nullptr ? minItem->quantity : 0.0) << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "The Max Price Item Quantity is: " << (maxItem != nullptr ? maxItem->quantity : 0.0) << std::endl;


    clearItems(items);


    delete[] filePath;

    filePath = nullptr;


    return 0;
}



void generator() {
    const Item data1[3] = {
        Item { 1.5, 1.0 },
        Item { 1.0, 3.0 },
        Item { 3.0, 9.0 }
    };

    const Item data2[7] = {
        Item { 1.1, 1.0 },
        Item { 1.2, 2.0 },
        Item { 1.3, 3.0 },
        Item { 2.1, 1.0 },
        Item { 2.2, 2.0 },
        Item { 2.3, 3.0 },
        Item { 9.0, 9.0 }
    };

    const Item data3[9] = {
        Item { 1.0, 2.0 },
        Item { 2.0, 1.0 },
        Item { 3.0, 3.0 },
        Item { 1.0, 1.0 },
        Item { 2.0, 3.0 },
        Item { 3.0, 2.0 },
        Item { 1.0, 3.0 },
        Item { 2.0, 2.0 },
        Item { 3.0, 1.0 },
    };

    writeItems(data1, 3, "Items1.dat");
    writeItems(data2, 7, "Items2.dat");
    writeItems(data3, 9, "Items3.dat");
}



char* getFileName() {
    char* buffer = new (std::nothrow) char[MAX];

    if (buffer == nullptr) {
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter the file path: ";

    std::cin.getline(buffer, MAX, '\n');

    std::cout << std::endl;

    return buffer;
}



Item* buildItems(unsigned int& size, const char* filePath) {
    assert(filePath !=  nullptr );

    std::ifstream stream(filePath, std::ios::in | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        size = 0; return nullptr;
    }

    stream.seekg(0, std::ios_base::end);

    std::streamsize fileSize = stream.tellg();

    if (fileSize == 0) {
        std::cout << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        size = 0; return nullptr;
    }

    if (fileSize % sizeof(Item) != 0) {
        std::cout << ERROR_FILE_D << ' ' << ERROR_STATUS_C << std::endl;

        size = 0; return nullptr;
    }

    size = fileSize / sizeof(Item);

    Item* items = new (std::nothrow) Item[size];

    if (items == nullptr) {
        size = 0; return nullptr;
    }

    stream.seekg(0, std::ios_base::beg);

    stream.read(reinterpret_cast<char*>(items), size * sizeof(Item));

    if (stream.fail() || stream.gcount() != static_cast<std::streamsize>(size * sizeof(Item))) {
        std::cerr << ERROR_FILE_R << std::endl;

        delete[] items; size = 0;

        return nullptr;
    }

    stream.close();

    if (validateItems(items, size) == false) {
        delete[] items; size = 0;

        return nullptr;
    }

    return items;
}

void writeItems(const Item* items, unsigned int size, const char* filePath) {
    assert(items    !=  nullptr );
    assert(size     !=  0       );
    assert(filePath !=  nullptr );

    std::ofstream stream(filePath, std::ios::out | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    stream.write(reinterpret_cast<const char*>(items), size * sizeof(Item));

    if (stream.fail()) {
        std::cerr << ERROR_FILE_W << std::endl;

        return;
    }

    stream.close();

    if (stream.fail()) {
        std::cerr << ERROR_FILE_W << std::endl;

        return;
    }
}

void clearItems(Item*& items) {
    delete[] items;

    items = nullptr;
}

void printItems(const Item* items, unsigned int size) {
    assert(items    !=  nullptr );
    assert(size     !=  0       );

    std::cout << "The items content is: " << std::endl;

    for (unsigned int i = 0; i < size; ++i) {
        std::cout << std::fixed << std::setprecision(2) << "Item: " << items[i].price << ' ' << items[i].quantity << std::endl;
    }
}



bool validateItems(const Item* items, unsigned int size) {
    assert(items    !=  nullptr );
    assert(size     !=  0       );

    for (unsigned int i = 0; i < size; ++i) {
        if (std::fabs(items[i].price) < EPSILON) {
            return false;
        }
    }

    return true;
}



double findSumPrices(const Item* items, unsigned int size) {
    assert(items    !=  nullptr );
    assert(size     !=  0       );

    double price = 0.0;

    for (unsigned int i = 0; i < size; ++i) {
        price = price + items[i].price;
    }

    return price;
}



const Item* findMinPriceItem(const Item* items, unsigned int size) {
    assert(items    !=  nullptr );
    assert(size     !=  0       );

    const Item* result = &(items[0]);

    for (unsigned int i = 1; i < size; ++i) {
        if (result->price > items[i].price) {
            result = &(items[i]);
        } else {
            if (std::fabs(result->price - items[i].price) < EPSILON) {
                if (result->quantity > items[i].quantity) {
                    result = &(items[i]);
                }
            }
        }
    }

    return result;
}

const Item* findMaxPriceItem(const Item* items, unsigned int size) {
    assert(items    !=  nullptr );
    assert(size     !=  0       );

    const Item* result = &(items[0]);

    for (unsigned int i = 1; i < size; ++i) {
        if (result->price < items[i].price) {
            result = &(items[i]);
        } else {
            if (std::fabs(result->price - items[i].price) < EPSILON) {
                if (result->quantity < items[i].quantity) {
                    result = &(items[i]);
                }
            }
        }
    }

    return result;
}
