#include "Spider.hpp"



int main() {
    try {
        Spider spider("Spider Name", 33);

        spider.print();
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;

        return 1;
    }


    return 0;
}
