#include <iostream>

#include <exception>
#include <stdexcept>

#include <cstring>

class Person {
public:
    Person() = delete;

    Person(unsigned int age, const char* id, const char* name) {
        assign(age, id, name);

        // try {
        //     this->name = new char[strlen(name) + 1];
        // } catch (std::exception& exception) {
        //     throw exception;
        // }

        // this->age = age;

        // strcpy(this->id,    id  );
        // strcpy(this->name,  name);
    }

    unsigned int getAge()   const { return this->age;   }
    const char* getName()   const { return this->name;  }

    void print() const {
        std::cout << "Person Information: " << std::endl;
        std::cout << "Age is: " << this->age << std::endl;
        std::cout << "ID is: " << this->id << std::endl;
        std::cout << "Name is: " << this->name << std::endl;

        std::cout << std::endl;
    }

    Person(const Person& other): Person(other.age, other.id, other.name) {
    }

    Person& operator=(const Person& other)
    {
        if(&other != this)
        {
            assign(other.age, other.id, other.name);
        }

        return *this;
    }

    ~Person() {
        delete[] name;
    }

    void celebrateBirthday()
    {
        this->age++;
    }

private:
    bool validateAge(unsigned int age)  const { return age != 0; }

    bool validateID(const char* id) const {
        if (id == nullptr || strlen(id) > 10) {
            return false;
        }

        for (unsigned int i = 0; id[i] != '\0'; ++i) {
            if (id[i] < '0' || id[i] > '9') {
                return false;
            }
        }

        return true;
    }

    bool validateName(const char* name) const {
        if (name == nullptr) {
            return false;
        }

        if (name[0] < 'A' || name[0] > 'Z') {
            return false;
        }

        for (unsigned int i = 0; name[i] != '\0'; ++i) {
            if (name[i] >= '0' && name[i] <= '9') {
                return false;
            }
        }

        return true;
    }

    void setAge(unsigned int age)
    {
        this->age = age;
    }

    void setId(const char* id)
    {
        strcpy(this->id, id);
    }

    void setName(const char* name)
    {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void assign(unsigned int age, const char* id, const char* name)
    {
        if (
            !validateAge(age)   ||
            !validateID(id)     ||
            !validateName(name)
        ) {
            throw "BIG ERROR!";
        }

        try {
            setAge(age);
            setId(id);
            setName(name);
        } catch (...) {
            throw;
        }
    }

private:
    unsigned int    age     ;
    char            id[11]  ;
    char*           name    ;
};

int main() {
    try {
        Person person = Person(18, "1111110001", "Ninja");

        Person instance(person);

        Person newPerson(15, "1234567890", "Ivan");
        instance = newPerson;

        person.print();
        
        std::cout << "-------------------" << std::endl;

        instance.print();

        std::cout << "Current age: " << person.getAge() << std::endl;
        person.celebrateBirthday();
        std::cout << "Age after birthday: " << person.getAge() << std::endl;
    } catch (const char* message) {
        std::cout << message << std::endl;
    }

    return 0;
}