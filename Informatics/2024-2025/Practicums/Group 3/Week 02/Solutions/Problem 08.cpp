#include <cassert>
#include <cstring>

#include <limits>

#include <iostream>



#define MAX 256



#define SINGER1 "Dessita"
#define SINGER2 "Simona"
#define SINGER3 "Lidiq"



enum class WeekDay {
    INVALID     = -1,
    MONDAY      =  0,
    TUESDAY     =  1,
    WEDNESDAY   =  2,
    THURSDY     =  3,
    FRIDAY      =  4,
    SATURDAY    =  5,
    SUNDAY      =  6,
    COUNTER     =  7,
};



const char* days[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };



struct Event {
    char*   singer;
    char*   discoC;
    WeekDay dayOfW;
};



unsigned int readSize();



char*   buildString(        );
void    clearString(char*&  );



WeekDay buildDayOfW();



Event   buildEvent(                 );
void    printEvent(const    Event&  );
bool    checkEvent(const    Event&  );
void    clearEvent(         Event&  );



bool    compareLessThan(const Event&, const Event&);
bool    compareGrtrThan(const Event&, const Event&);



Event*  buildEvents(                    unsigned int);
void    printEvents(const   Event*  ,   unsigned int);
bool    checkEvents(const   Event*  ,   unsigned int);
void    clearEvents(        Event*& ,   unsigned int);



void    sortEvents(Event*, unsigned int);




int main() {
    unsigned int size = readSize();

    Event* events = buildEvents(size);

    if (events == nullptr) {
        std::cerr << "Allocating Memory... ERROR!" << std::endl;

        return 1;
    }


    if (checkEvents(events, size)) {
        sortEvents(events, size);

        std::cout << std::endl;
        
        printEvents(events, size);
    }


    clearEvents(events, size);


    return 0;
}



unsigned int readSize() {
    unsigned int number = 0;

    while (true) {
        std::cout << "Enter the number of events: ";

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



unsigned int readWeekDay() {
    unsigned int weekDay = 0;

    while (true) {
        std::cin >> weekDay;

        if (std::cin.fail()) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            if (
                weekDay < static_cast<unsigned int>(WeekDay::MONDAY)    ||
                weekDay > static_cast<unsigned int>(WeekDay::SUNDAY)
            ) {
                continue;
            }

            return weekDay;
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



WeekDay buildDayOfW() {
    unsigned int weekDay = readWeekDay();

    return static_cast<WeekDay>(weekDay);
}



Event buildEvent() {
    Event result;

    std::cout << "\tEnter the singer  of the event: "; result.singer = buildString();
    std::cout << "\tEnter the place   of the event: "; result.discoC = buildString();
    std::cout << "\tEnter the weekday of the event: "; result.dayOfW = buildDayOfW();

    return result;
}

void printEvent(const Event& event) {
    assert(event.singer !=  nullptr );
    assert(event.discoC !=  nullptr );

    std::cout << std::endl;

    std::cout << "\tEvent singer    is: "   << event.singer << std::endl;
    std::cout << "\tEvent place     is: "   << event.discoC << std::endl;

    std::cout << "\tEvent weekday   is: "   << days[static_cast<unsigned int>(event.dayOfW)] << std::endl;
}

bool checkEvent(const Event& event) {
    assert(event.singer !=  nullptr );
    assert(event.discoC !=  nullptr );

    if (
        event.dayOfW == WeekDay::SATURDAY   ||
        event.dayOfW == WeekDay::SUNDAY
    ) {
        return
            event.singer[0] == '\0' &&
            event.discoC[0] == '\0';
    }

    return event.discoC[0] != '\0'  &&
        (
            strcmp(event.singer, SINGER1)   ==  0   ||
            strcmp(event.singer, SINGER2)   ==  0   ||
            strcmp(event.singer, SINGER3)   ==  0
        );
}

void clearEvent(Event& event) {
    clearString(event.singer);
    clearString(event.discoC);
}



bool compareLessThan(const Event& event1, const Event& event2) {
    assert(checkEvent(event1));
    assert(checkEvent(event2));

    if (event1.dayOfW != event2.dayOfW) {
        return event1.dayOfW < event2.dayOfW;
    }

    unsigned int result1 = 0;
    unsigned int result2 = 0;

    result1 = result1 + (strcmp(event1.singer, SINGER1) == 0 ? 1 : 0);
    result1 = result1 + (strcmp(event1.singer, SINGER2) == 0 ? 2 : 0);
    result1 = result1 + (strcmp(event1.singer, SINGER3) == 0 ? 3 : 0);

    result2 = result2 + (strcmp(event1.singer, SINGER1) == 0 ? 1 : 0);
    result2 = result2 + (strcmp(event1.singer, SINGER2) == 0 ? 2 : 0);
    result2 = result2 + (strcmp(event1.singer, SINGER3) == 0 ? 3 : 0);

    return result1 < result2;
}

bool compareGrtrThan(const Event& event1, const Event& event2) {
    assert(checkEvent(event1));
    assert(checkEvent(event2));

    if (event1.dayOfW != event2.dayOfW) {
        return event1.dayOfW > event2.dayOfW;
    }

    unsigned int result1 = 0;
    unsigned int result2 = 0;

    result1 = result1 + (strcmp(event1.singer, SINGER1) == 0 ? 1 : 0);
    result1 = result1 + (strcmp(event1.singer, SINGER2) == 0 ? 2 : 0);
    result1 = result1 + (strcmp(event1.singer, SINGER3) == 0 ? 3 : 0);

    result2 = result2 + (strcmp(event2.singer, SINGER1) == 0 ? 1 : 0);
    result2 = result2 + (strcmp(event2.singer, SINGER2) == 0 ? 2 : 0);
    result2 = result2 + (strcmp(event2.singer, SINGER3) == 0 ? 3 : 0);

    return result1 > result2;
}



void swapEvents(Event& event1, Event& event2) {
    assert(event1.singer    !=  nullptr );
    assert(event2.singer    !=  nullptr );
    assert(event1.discoC    !=  nullptr );
    assert(event2.discoC    !=  nullptr );

    Event temporary1 = { nullptr, nullptr, WeekDay::INVALID };
    Event temporary2 = { nullptr, nullptr, WeekDay::INVALID };
    

    temporary1.singer = new (std::nothrow) char[strlen(event1.singer) + 1];
    temporary2.singer = new (std::nothrow) char[strlen(event2.singer) + 1];
    

    temporary1.discoC = new (std::nothrow) char[strlen(event1.discoC) + 1];
    temporary2.discoC = new (std::nothrow) char[strlen(event2.discoC) + 1];

    if (temporary1.singer == nullptr || temporary2.singer == nullptr) {
        delete[] temporary1.singer; temporary1.singer = nullptr;
        delete[] temporary2.singer; temporary2.singer = nullptr;

        return;
    }

    if (temporary1.discoC == nullptr || temporary2.discoC == nullptr) {
        delete[] temporary1.singer; temporary1.singer = nullptr;
        delete[] temporary2.singer; temporary2.singer = nullptr;

        delete[] temporary1.discoC; temporary1.discoC = nullptr;
        delete[] temporary2.discoC; temporary2.discoC = nullptr;

        return;
    }

    strcpy(temporary1.singer, event1.singer);
    strcpy(temporary2.singer, event2.singer);

    strcpy(temporary1.discoC, event1.discoC);
    strcpy(temporary2.discoC, event2.discoC);

    temporary1.dayOfW = event1.dayOfW;
    temporary2.dayOfW = event2.dayOfW;

    clearEvent(event1);
    clearEvent(event2);

    event1 = temporary2;
    event2 = temporary1;
}



Event* buildEvents(unsigned int size) {
    Event* events = new (std::nothrow) Event[size];

    if (events != nullptr) {
        for (unsigned int i = 0; i < size; ++i) {
            std::cout << std::endl;

            events[i] = buildEvent();
        }
    }

    return events;
}

void printEvents(const Event* events, unsigned int size) {
    assert(events   !=  nullptr );
    assert(size     !=  0       );

    std::cout << "The events are: " << std::endl;

    for (unsigned int i = 0; i < size; ++i) {
        printEvent(events[i]);
    }
}

bool checkEvents(const Event* events, unsigned int size) {
    assert(events   !=  nullptr );
    assert(size     !=  0       );

    for (unsigned int i = 0; i < size; ++i) {
        if (checkEvent(events[i]) == false) {
            return false;
        }
    }

    return true;
}

void clearEvents(Event*& events, unsigned int size) {
    assert(events   !=  nullptr );
    assert(size     !=  0       );

    for (unsigned int i = 0; i < size; ++i) {
        clearEvent(events[i]);
    }

    delete[] events;

    events = nullptr;
}



void sortEvents(Event* events, unsigned int size) {
    assert(events   !=  nullptr );
    assert(size     !=  0       );

    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            if (compareGrtrThan(events[i], events[j])) {
                swapEvents(events[i], events[j]);
            }
        }
    }
}
