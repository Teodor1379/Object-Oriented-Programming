#include <string>

#include <iostream>



#define MAX 1024



using namespace std;



void sample1();
void sample2();
void sample3();
void sample4();



int main() {
    sample1();
    sample2();
    sample3();
    sample4();

    return 0;
}



void sample1() {
    char name[MAX];

    cout << "Enter your name: ";

    cin >> name;

    cout << "Your name is: " << name << endl;
}

void sample2() {
    char name[10];

    cout << "Enter your name: ";

    cin.ignore();

    cin.getline(name, 10);

    cout << "Your name is: " << name << endl;
}

void sample3() {
    char name[10];

    cout << "Enter your name: ";

    cin.getline(name, 10, '\n');

    cout << "You name is: " << name << endl;
}

void sample4() {
    // Useful for projects...

    string name;

    cout << "Enter your name: ";

    getline(cin, name, '\n');

    cout << "Your name is: " << name << endl;
}
