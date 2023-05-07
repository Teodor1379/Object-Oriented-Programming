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

class Shisha {
public:
    Shisha() {
        this->price = 0.0;
        this->brand = nullptr;
        this->taste = nullptr;
    }

    Shisha(double price, const char *brand, const char *taste)
        : price(0.0), brand(nullptr), taste(nullptr) {
        if (price <= 0.0 || brand == nullptr || taste == nullptr) {
            std::cout << "Invalid arguments for the shisha!" << std::endl;
            return;
        }

        this->brand = new (std::nothrow) char[strlen(brand) + 1];

        if (this->brand == nullptr) {
            std::cout << "Problem with allocating memory!" << std::endl;
            return;
        }

        this->taste = new (std::nothrow) char[strlen(taste) + 1];

        if (this->taste == nullptr) {
            std::cout << "Problem with allocating memory!" << std::endl;
            delete[] this->brand; this->brand = nullptr; return;
        }

        this->price = price;
        strcpy(this->brand, brand);
        strcpy(this->taste, taste);
    }

    double getPrice()   const { return this->price; }
    char* getBrand()    const { return this->brand; }
    char* getTaste()    const { return this->taste; }

    void setPrice(double price) {
        if (price <= 0.0) {
            std::cout << "Invalid price for the shisha!" << std::endl;
            return;
        }

        this->price = price;
    }

    void setBrand(const char *brand) {
        if (brand == nullptr) {
            std::cout << "Invalid brand for the shisha!" << std::endl;
            return;
        }

        delete[] this->brand;

        this->brand = new (std::nothrow) char[strlen(brand) + 1];

        if (this->brand == nullptr) {
            std::cout << "Problem with allocating memory!" << std::endl;
            this->resetData(); return;
        }

        strcpy(this->brand, brand);
    }

    void setTaste(const char *taste) {
        if (taste == nullptr) {
            std::cout << "Invalid taste for the shisha!" << std::endl;
            this->resetData(); return;
        }

        delete[] this->taste;

        this->taste = new (std::nothrow) char[strlen(taste) + 1];

        if (this->taste == nullptr) {
            std::cout << "Problem with allocating memory!" << std::endl;
            return;
        }

        strcpy(this->taste, taste);
    }

    void print() const {
        if (this->brand == nullptr || this->taste == nullptr) {
            std::cout << "This shisha contains invalid data!" << std::endl;
            return;
        }

        std::cout << std::endl;
        std::cout << "Shisha Information: " << std::endl;
        std::cout << "Price: " << this->price << std::endl;
        std::cout << "Brand: " << this->brand << std::endl;
        std::cout << "Taste: " << this->taste << std::endl;
        std::cout << std::endl;
    }

    ~Shisha() {
        delete[] this->brand;
        delete[] this->taste;
    }

private:
    void resetData() {
        delete[] this->brand;
        delete[] this->taste;

        this->price = 0.0;
        this->brand = nullptr;
        this->taste = nullptr;
    }

    double price;
    char *brand;
    char *taste;
};

int main() {
    return 0;
}
