#include <iostream>
#include <cstring>

class Balloon {
public:
    Balloon() {
        this->price = 0.0;
        strcpy(this->color, "");
    }

    Balloon(double price, const char *color) : price(0.0), color("") {
        if (price <= 0.0 || color == nullptr) {
            std::cout << "Invalid arguments for the balloon!" << std::endl;
            return;
        }

        this->price = price;
        strcpy(this->color, color);
    }

    double getPrice()       const { return this->price; }
    const char* getColor()  const { return this->color; }

    void setPrice(double price) {
        if (price <= 0.0) {
            std::cout << "Invalid price for the balloon!" << std::endl;
            return;
        }

        this->price = price;
    }

    void setColor(const char *color) {
        if (color == nullptr) {
            std::cout << "Invalid color for the balloon!" << std::endl;
            return;
        }

        strcpy(this->color, color);
    }

    void print() const {
        std::cout << std::endl;
        std::cout << "Balloon Information: " << std::endl;
        std::cout << "Price: " << this->price << std::endl;
        std::cout << "Color: " << this->color << std::endl;
        std::cout << std::endl;
    }

private:
    double price;
    char color[64];
};

int main() {
    return 0;
}