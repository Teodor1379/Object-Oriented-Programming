#include <iostream>



struct Node {
    int     number  ;
    Node*   next    ;
};

// warning: padding struct to align ‘Node::next’ [-Wpadded]



Node*   buildSequence(int number    );
void    clearSequence(Node*& head   );



void printSequence(const Node* head);



void addNode(Node* head, int number);



int sizSequence(const Node* head);
int sumSequence(const Node* head);



int main() {
    Node* sequence = nullptr;


    std::cout << "Enter the numbers: ";

    while (true) {
        int number = 0;

        std::cin >> number;

        if (number == 0) {
            break;
        }

        if (sequence == nullptr) {
            sequence = buildSequence(number);

            if (sequence == nullptr) {
                std::cout << "Allocating Memory... ERROR!" << std::endl;

                return 1;
            }
        } else {
            addNode(sequence, number);
        }
    }


    std::cout << std::endl;

    std::cout << "The SIZE  of the sequence is: "   << sizSequence(sequence) << std::endl;
    std::cout << "The SUM   of the sequence is: "   << sumSequence(sequence) << std::endl;

    std::cout << std::endl;

    printSequence(sequence);


    clearSequence(sequence);


    return 0;
}



Node* buildSequence(int number) {
    Node* sequence = new (std::nothrow) Node;

    if (sequence != nullptr) {
        sequence->number    = number    ;
        sequence->next      = nullptr   ;
    }

    return sequence;
}

void clearSequence(Node*& head) {
    while (head != nullptr) {
        Node* current = head;
        head = head->next;

        delete current;
        current = nullptr;
    }
}



void printSequence(const Node* head) {
    if (head == nullptr) {
        std::cout << "Empty sequence!" << std::endl;

        return;
    }

    std::cout << "The sequence is: ";

    while (head != nullptr) {
        std::cout << head->number << ' ';

        head = head->next;
    }

    std::cout << std::endl;
}



void addNode(Node* head, int number) {
    if (head == nullptr) {
        std::cout << "Adding Node... ERROR!" << std::endl;

        return;
    }

    while (head->next != nullptr) {
        head = head->next;
    }    

    head->next = new (std::nothrow) Node;

    if (head->next != nullptr) {
        head->next->number = number;
        head->next->next = nullptr;
    }
}



int sizSequence(const Node* head) {
    if (head == nullptr) {
        return 0;
    }

    int size = 0;

    while (head != nullptr) {
        size = size + 1;

        head = head->next;
    }

    return size;
}



int sumSequence(const Node* head) {
    if (head == nullptr) {
        std::cout << "The sequence is empty!" << std::endl;
        
        return 0;
    }

    int sum = 0;

    while (head != nullptr) {
        sum = sum + head->number;

        head = head->next;
    }

    return sum;
}
