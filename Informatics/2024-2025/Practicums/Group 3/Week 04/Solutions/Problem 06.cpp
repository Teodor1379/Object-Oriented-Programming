#include <cassert>

#include <fstream>
#include <iostream>



const char* FILE_PATH_ORDERS = "Orders.bin"     ;
const char* FILE_PATH_CSTMRS = "Customers.bin"  ;
const char* FILE_PATH_RESULT = "Results.bin"    ;



struct Order {
    int32_t id      ;
    double  price   ;
};



const char* ERROR_FILE_R = "Error while reading from    the file!";
const char* ERROR_FILE_W = "Error while writing to      the file!";
const char* ERROR_FILE_O = "Error while opening         the file!";
const char* ERROR_FILE_D = "Error while operating with  the file!";

const char* ERROR_STATUS_E = "EMPTY"    ;
const char* ERROR_STATUS_C = "CORRUPTED";



void generator();



void printOrders();
void printCstmrs();



void writeOrders(const Order*   , unsigned int);
void writeCstmrs(const int32_t* , unsigned int);



bool validateFiles();



bool findUserOrders(int32_t&, int32_t&);
bool findUserPrices(int32_t&, int32_t&);



bool findNonBuyers(unsigned int&);



int main() {
    generator();


    if (validateFiles() == false) {
        std::cerr << "Internal Error..." << std::endl;

        return 1;
    }


    printOrders();
    printCstmrs();


    int32_t minOrders = 0;
    int32_t maxOrders = 0;

    int32_t minPrices = 0;
    int32_t maxPrices = 0;

    unsigned int Nbuyers = 0;


    bool result1 = findUserOrders(minOrders, maxOrders);
    bool result2 = findUserPrices(minPrices, maxPrices);

    bool resultN = findNonBuyers(Nbuyers);


    if (result1) {
        std::cout << "Min Orders Customer is: " << minOrders << std::endl;
        std::cout << "Max Orders Customer is: " << maxOrders << std::endl;

        std::cout << std::endl;
    } else {
        std::cout << "ERROR!" << std::endl;

        return 2;
    }

    if (result2) {
        std::cout << "Min Prices Customer is: " << minPrices << std::endl;
        std::cout << "Max Prices Customer is: " << maxPrices << std::endl;

        std::cout << std::endl;
    } else {
        std::cout << "ERROR!" << std::endl;

        return 2;
    }

    if (resultN) {
        std::cout << "Not real Customers are: " << Nbuyers << std::endl;

        std::cout << std::endl;
    } else {
        std::cout << "ERROR!" << std::endl;

        return 3;
    }


    std::ofstream resultStream(FILE_PATH_RESULT);

    if (resultStream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return 4;
    }

    int32_t results[4] = { minOrders, maxOrders, minPrices, maxPrices };

    resultStream.write(reinterpret_cast<const char*>(results), 4 * sizeof(int32_t));

    if (resultStream.fail()) {
        std::cerr << ERROR_FILE_W << std::endl;

        return 5;
    }

    resultStream.close();

    if (resultStream.fail()) {
        std::cerr << ERROR_FILE_W << std::endl;

        return 5;
    }


    return 0;
}



void generator() {
    Order ordersData1[3] = {};
    
    ordersData1[0] = { 1, 1.0, };
    ordersData1[1] = { 2, 2.0, };
    ordersData1[2] = { 3, 3.0, };

    Order ordersData2[7] = {};
    
    ordersData2[0] = { 1, 1.0, };
    ordersData2[1] = { 2, 2.0, };
    ordersData2[2] = { 3, 3.0, };
    ordersData2[3] = { 4, 4.0, };
    ordersData2[4] = { 3, 3.0, };
    ordersData2[5] = { 2, 2.0, };
    ordersData2[6] = { 1, 1.0, };

    Order ordersData3[9] = {};

    ordersData3[0] = { 1, 1.0, };
    ordersData3[1] = { 2, 2.0, };
    ordersData3[2] = { 3, 3.0, };
    ordersData3[3] = { 1, 3.0, };
    ordersData3[4] = { 2, 2.0, };
    ordersData3[5] = { 3, 3.0, };
    ordersData3[6] = { 4, 1.0, };
    ordersData3[7] = { 4, 1.0, };
    ordersData3[8] = { 4, 1.0, };


    int32_t customersData1[9] = { 1, 2, 3, 0, 0, 0, 0, 0, 0, };
    int32_t customersData2[9] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, };
    int32_t customersData3[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, };

    writeOrders(ordersData1, 3);    writeCstmrs(customersData1, 3);
    writeOrders(ordersData2, 7);    writeCstmrs(customersData2, 7);
    writeOrders(ordersData3, 9);    writeCstmrs(customersData3, 9);
}



void printOrders() {
    std::ifstream stream(FILE_PATH_ORDERS, std::ios::in | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    Order currentOrder = { 0, 0.0 };

    std::cout << "The orders are: " << std::endl;

    while (stream.read(reinterpret_cast<char*>(&currentOrder), sizeof(Order))) {
        std::cout << "Order is: " << currentOrder.price << ' ' << currentOrder.id << std::endl;
    }

    std::cout << std::endl;

    stream.close();
}

void printCstmrs() {
    std::ifstream stream(FILE_PATH_CSTMRS, std::ios::in | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    int32_t currentIdentifier = 0;

    std::cout << "The identifiers are: ";

    while (stream.read(reinterpret_cast<char*>(&currentIdentifier), sizeof(int32_t))) {
        std::cout << currentIdentifier << ' ';
    }

    std::cout << std::endl;

    std::cout << std::endl;

    stream.close();
}



void writeOrders(const Order* orders, unsigned int size) {
    assert(orders   !=  nullptr );
    assert(size     !=  0       );

    std::ofstream stream(FILE_PATH_ORDERS, std::ios::out | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_W << std::endl;

        return;
    }

    stream.write(reinterpret_cast<const char*>(orders), size * sizeof(Order));

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

void writeCstmrs(const int32_t* cstmrs, unsigned int size) {
    assert(cstmrs   !=  nullptr );
    assert(size     !=  0       );

    std::ofstream stream(FILE_PATH_CSTMRS, std::ios::out | std::ios::binary);

    if (stream.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return;
    }

    stream.write(reinterpret_cast<const char*>(cstmrs), size * sizeof(int32_t));

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



bool validateFiles() {
    std::ifstream   streamOrders(FILE_PATH_ORDERS);

    if (streamOrders.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return false;
    }

    std::ifstream   streamCstmrs(FILE_PATH_CSTMRS);

    if (streamCstmrs.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return false;
    }

    streamOrders.seekg(0, std::ios::end);
    streamCstmrs.seekg(0, std::ios::end);

    std::streamsize fileSizeOrders = streamOrders.tellg();
    std::streamsize fileSizeCstmrs = streamCstmrs.tellg();

    if (fileSizeOrders == 0 || fileSizeCstmrs == 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return false;
    }

    if (
        fileSizeOrders % sizeof(Order   ) != 0  ||
        fileSizeCstmrs % sizeof(int32_t ) != 0
    ) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return false;
    }

    std::streamsize sizeOrders = fileSizeOrders / sizeof(Order  );
    std::streamsize sizeCstmrs = fileSizeCstmrs / sizeof(int32_t);

    Order currentOrder = { 0, 0.0 }; int32_t currentIdentifier = 0;

    for (std::streamsize i = 0; i < sizeOrders; ++i) {
        streamOrders.seekg(i * sizeof(Order), std::ios::beg);

        streamOrders.read(reinterpret_cast<char*>(&currentOrder), sizeof(Order));

        if (streamOrders.fail() || streamOrders.gcount() != sizeof(Order)) {
            std::cerr << ERROR_FILE_R << std::endl;

            return false;
        }

        bool foundIdentifier = false;
        
        for (std::streamsize j = 0; j < sizeCstmrs; ++j) {
            streamCstmrs.seekg(j * sizeof(int32_t), std::ios::beg);

            streamCstmrs.read(reinterpret_cast<char*>(&currentIdentifier), sizeof(int32_t));

            if (streamCstmrs.fail() || streamCstmrs.gcount() != sizeof(int32_t)) {
                std::cerr << ERROR_FILE_R << std::endl;

                return false;
            }

            if (currentOrder.id == currentIdentifier) {
                foundIdentifier = true;

                break;
            }
        }

        if (foundIdentifier == false) {
            return false;
        }
    }

    streamOrders.close();
    streamCstmrs.close();

    return true;
}



bool findUserOrders(int32_t& identifier1, int32_t& identifier2) {
    std::ifstream streamOrders  (FILE_PATH_ORDERS, std::ios::in | std::ios::binary);

    if (streamOrders.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return false;
    }

    std::ifstream streamCstmrs  (FILE_PATH_CSTMRS, std::ios::in | std::ios::binary);

    if (streamCstmrs.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return false;
    }

    streamOrders.seekg(0, std::ios::end);
    streamCstmrs.seekg(0, std::ios::end);

    std::streamsize fileSizeOrders  =   streamOrders.tellg();
    std::streamsize fileSizeCstmrs  =   streamCstmrs.tellg();
    
    if (fileSizeOrders == 0 || fileSizeCstmrs == 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return false;
    }

    if (
        fileSizeOrders % sizeof(Order   ) != 0  ||
        fileSizeCstmrs % sizeof(int32_t ) != 0
    ) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_C << std::endl;

        return false;
    }

    std::streamsize sizeOrders = fileSizeOrders / sizeof(Order  )   ;
    std::streamsize sizeCstmrs = fileSizeCstmrs / sizeof(int32_t)   ;

    streamOrders.seekg(0, std::ios::beg);
    streamCstmrs.seekg(0, std::ios::beg);

    bool status = false;

    unsigned int minCounter = 0;
    unsigned int maxCounter = 0;

    for (std::streamsize i = 0; i < sizeCstmrs; ++i) {
        streamCstmrs.seekg(i * sizeof(int32_t), std::ios::beg);

        int32_t currentIdentifier = 0;

        streamCstmrs.read(reinterpret_cast<char*>(&currentIdentifier), sizeof(int32_t));

        if (streamCstmrs.fail() || streamCstmrs.gcount() != sizeof(int32_t)) {
            std::cerr << ERROR_FILE_R << std::endl;

            return false;
        }

        unsigned int counter = 0;

        for (std::streamsize j = 0; j < sizeOrders; ++j) {
            streamOrders.seekg(j * sizeof(Order), std::ios::beg);

            Order buffer = { 0, 0.0 };

            streamOrders.read(reinterpret_cast<char*>(&buffer), sizeof(Order));

            if (streamOrders.fail() || streamOrders.gcount() != sizeof(Order)) {
                std::cerr << ERROR_FILE_R << std::endl;

                return false;
            }

            if (buffer.id == currentIdentifier) {
                counter = counter + 1;
            }
        }

        if (counter > 0) {
            if (status == false) {
                identifier1 = currentIdentifier;
                identifier2 = currentIdentifier;

                minCounter = counter;
                maxCounter = counter;

                status = true;
            } else {
                identifier1 = (minCounter <= counter) ? identifier1 : currentIdentifier;
                identifier2 = (maxCounter >= counter) ? identifier2 : currentIdentifier;

                minCounter = std::min(minCounter, counter);
                maxCounter = std::max(maxCounter, counter);
            }
        }
    }

    streamOrders.close();
    streamCstmrs.close();

    return true;
}


bool findUserPrices(int32_t& identifier1, int32_t& identifier2) {
    std::ifstream streamOrders  (FILE_PATH_ORDERS, std::ios::in | std::ios::binary);

    if (streamOrders.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return false;
    }

    std::ifstream streamCstmrs  (FILE_PATH_CSTMRS, std::ios::in | std::ios::binary);

    if (streamCstmrs.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return false;
    }

    streamOrders.seekg(0, std::ios::end);
    streamCstmrs.seekg(0, std::ios::end);

    std::streamsize fileSizeOrders  =   streamOrders.tellg();
    std::streamsize fileSizeCstmrs  =   streamCstmrs.tellg();

    if (fileSizeOrders == 0 || fileSizeCstmrs == 0) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return false;
    }

    if (
        fileSizeOrders % sizeof(Order   ) != 0  ||
        fileSizeCstmrs % sizeof(int32_t ) != 0
    ) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_C << std::endl;

        return false;
    }

    std::streamsize sizeOrders = fileSizeOrders / sizeof(Order  );
    std::streamsize sizeCstmrs = fileSizeCstmrs / sizeof(int32_t);

    streamOrders.seekg(0, std::ios::beg);
    streamCstmrs.seekg(0, std::ios::beg);

    bool status = false;

    double minPrice = 0.0;
    double maxPrice = 0.0;

    for (std::streamsize i = 0; i < sizeCstmrs; ++i) {
        streamCstmrs.seekg(i * sizeof(int32_t), std::ios::beg);

        int32_t currentIdentifier = 0;

        streamCstmrs.read(reinterpret_cast<char*>(&currentIdentifier), sizeof(int32_t));

        if (streamCstmrs.fail() || streamCstmrs.gcount() != sizeof(int32_t)) {
            std::cerr << ERROR_FILE_R << std::endl;

            return false;
        }

        double price = 0.0;

        for (std::streamsize j = 0; j < sizeOrders; ++j) {
            streamOrders.seekg(j * sizeof(Order), std::ios::beg);

            Order buffer = { 0, 0.0 };

            streamOrders.read(reinterpret_cast<char*>(&buffer), sizeof(Order));

            if (streamOrders.fail() || streamOrders.gcount() != sizeof(Order)) {
                std::cerr << ERROR_FILE_R << std::endl;

                return false;
            }

            if (buffer.id == currentIdentifier) {
                price = price + buffer.price;
            }
        }

        if (price > 0.0) {
            if (status == false) {
                identifier1 = currentIdentifier;
                identifier2 = currentIdentifier;

                minPrice = price;
                maxPrice = price;

                status = true;
            } else {
                identifier1 = (minPrice <= price) ? identifier1 : currentIdentifier;
                identifier2 = (maxPrice >= price) ? identifier2 : currentIdentifier;

                minPrice = std::min(minPrice, price);
                maxPrice = std::max(maxPrice, price);
            }
        }
    }

    streamOrders.close();
    streamCstmrs.close();

    return true;
}



bool findNonBuyers(unsigned int& result) {
    std::ifstream streamOrders  (FILE_PATH_ORDERS, std::ios::in | std::ios::binary);

    if (streamOrders.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return false;
    }

    std::ifstream streamCstmrs  (FILE_PATH_CSTMRS, std::ios::in | std::ios::binary);

    if (streamCstmrs.is_open() == false) {
        std::cerr << ERROR_FILE_O << std::endl;

        return false;
    }

    streamOrders.seekg(0, std::ios::end);
    streamCstmrs.seekg(0, std::ios::end);

    std::streamsize fileSizeOrders  =   streamOrders.tellg();
    std::streamsize fileSizeCstmrs  =   streamCstmrs.tellg();

    if (fileSizeOrders == 0 || fileSizeCstmrs == 0) {
        std::cout << ERROR_FILE_D << ' ' << ERROR_STATUS_E << std::endl;

        return false;
    }

    if (
        fileSizeOrders % sizeof(Order   ) != 0  ||
        fileSizeCstmrs % sizeof(int32_t ) != 0
    ) {
        std::cerr << ERROR_FILE_D << ' ' << ERROR_STATUS_C << std::endl;

        return false;
    }

    std::streamsize sizeOrders = fileSizeOrders / sizeof(Order  );
    std::streamsize sizeCstmrs = fileSizeCstmrs / sizeof(int32_t);

    streamOrders.seekg(0, std::ios::beg);
    streamCstmrs.seekg(0, std::ios::beg);

    for (std::streamsize i = 0; i < sizeCstmrs; ++i) {
        streamCstmrs.seekg(i * sizeof(int32_t), std::ios::beg);

        int32_t currentIdentifier = 0;

        streamCstmrs.read(reinterpret_cast<char*>(&currentIdentifier), sizeof(int32_t));

        if (streamCstmrs.fail() || streamCstmrs.gcount() != sizeof(int32_t)) {
            std::cerr << ERROR_FILE_R << std::endl;

            return false;
        }

        unsigned int counter = 0;

        for (unsigned int j = 0; j < sizeOrders; ++j) {
            streamOrders.seekg(j * sizeof(Order), std::ios::beg);

            Order buffer = { 0, 0.0 };

            streamOrders.read(reinterpret_cast<char*>(&buffer), sizeof(Order));

            if (streamOrders.fail() || streamOrders.gcount() != sizeof(Order)) {
                std::cerr << ERROR_FILE_R << std::endl;

                return false;
            }

            if (buffer.id == currentIdentifier) {
                counter = counter + 1;
            }
        }

        result = result + (counter == 0);
    }

    streamOrders.close();
    streamCstmrs.close();

    return true;
}
