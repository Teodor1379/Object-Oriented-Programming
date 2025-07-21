#include "Song.hpp"



Song::Song() {
    try {
        this->title     =   this->buildString("");
        this->artist    =   this->buildString("");
    } catch (std::bad_alloc& exception) {
        this->destroyString(this->title);

        throw exception;
    }

    this->duration  =   0;
}

Song::Song(const char* title, const char* artist, unsigned int duration) {
    if (
        this->validateTitle     (title      )   == false    ||
        this->validateArtist    (artist     )   == false    ||
        this->validateDuration  (duration   )   == false
    ) {
        throw std::invalid_argument("Invalid Constructor Arguments!");
    }

    try {
        this->title     =   this->buildString(title );
        this->artist    =   this->buildString(artist);
    } catch (std::bad_alloc& exception) {
        this->destroyString(this->title);

        throw exception;
    }

    this->duration  =   duration;
}

Song::Song(const Song& instance) {
    try {
        this->title     =   this->buildString(instance.title    );
        this->artist    =   this->buildString(instance.artist   );
    } catch (std::bad_alloc& exception) {
        this->destroyString(this->title);

        throw exception;
    }

    this->duration  =   instance.duration;
}

Song::~Song() {
    this->destroyString(this->title );
    this->destroyString(this->artist);
}



Song& Song::operator=(const Song& instance) {
    if (this != &instance) {
        char* titleTemporary    = nullptr;
        char* artistTemporary   = nullptr;

        try {
            titleTemporary  =   this->buildString(instance.title    );
            artistTemporary =   this->buildString(instance.artist   );
        } catch (std::bad_alloc& exception) {
            this->destroyString(titleTemporary);

            throw exception;
        }

        this->destroyString(this->title );
        this->destroyString(this->artist);

        this->title     =   titleTemporary      ;
        this->artist    =   artistTemporary     ;
        this->duration  =   instance.duration   ;
    }

    return *this;
}



void Song::setTitle(const char* title) {
    if (this->validateTitle(title) == false) {
        throw std::invalid_argument("Invalid Title Argument!");
    }

    char* temporary = this->buildString(title);

    this->destroyString(this->title);

    this->title = temporary;
}

void Song::setArtist(const char* artist) {
    if (this->validateArtist(artist) == false) {
        throw std::invalid_argument("Invalid Artist Argument!");
    }

    char* temporary = this->buildString(artist);

    this->destroyString(this->artist);

    this->artist = temporary;
}

void Song::setDuration(unsigned int duration) {
    if (this->validateDuration(duration) == false) {
        throw std::invalid_argument("Invalid Duration Argument!");
    }

    this->duration  =   duration;
}



char* Song::buildString(const char* string) const {
    char* result = new char[strlen(string) + 1];

    strcpy(result, string);

    return result;
}

void Song::destroyString(char*& string) {
    delete[] string;

    string = nullptr;
}



void Song::print() const {
    std::cout << "Song: ";

    std::cout << "[ ";

    std::cout << "Title     : " << this->title      << ", " ;
    std::cout << "Artist    : " << this->artist     << ", " ;
    std::cout << "Duration  : " << this->duration           ;

    std::cout << " ]";

    std::cout << std::endl;
}



Song findMinDurationSong(const Song songs[MAX], unsigned int size) {
    if (size == 0 || size > MAX) {
        throw std::out_of_range("Invalid Index of Array!");
    }

    Song song = songs[0];

    for (unsigned int i = 1; i < size; ++i) {
        if (song.getDuration() > songs[i].getDuration()) {
            song = songs[i];
        }
    }

    return song;
}

Song findMaxDurationSong(const Song songs[MAX], unsigned int size) {
    if (size == 0 || size > MAX) {
        throw std::out_of_range("Invalid Index of Array!");
    }
    
    Song song = songs[0];

    for (unsigned int i = 1; i < size; ++i) {
        if (song.getDuration() < songs[i].getDuration()) {
            song = songs[i];
        }
    }

    return song;
}
