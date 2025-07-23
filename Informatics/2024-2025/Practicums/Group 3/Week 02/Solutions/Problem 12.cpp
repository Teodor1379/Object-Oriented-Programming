#include <cmath>

#include <cassert>
#include <cstring>

#include <limits>

#include <iostream>



#define MAX 256

#define MIN_RATING  0.0
#define MAX_RATING 10.0



unsigned int readSize();



double          readNumberD();
unsigned int    readNumberU();



enum class Genre {
    UNKNOWN =   -1,
    POP     =    0,
    TECHNO  =    1,
    HOUSE   =    2,
    DUPSTEP =    3,
    COUNTER =    4,
};



const char* genres[4] = { "Pop", "Techno", "House", "Dupstep" };



Genre       getGenre(const char*    );
const char* getGenre(const Genre&   );



struct Song {
    char    name    [MAX];
    char    singer  [MAX];

    Genre           genre   ;
    double          rating  ;
    unsigned int    views   ;
};

struct Playlist {
    Song    songs[64];

    unsigned int    size    ;
    unsigned int    capacity;
};



Song buildSong(             );
void printSong(const Song&  );



Playlist    buildPlaylist(                  );
void        printPlaylist(const Playlist&   );

void sortPlaylist(Playlist&, bool (*)(const Song&, const Song&));



const Song* findSong(const Playlist&, bool (*)(const Song&));



inline bool filterSongMinViews(const Song& song)    { return song.views == 1    ;   }
inline bool filterSongMaxViews(const Song& song)    { return song.views == 1379 ;   }

inline bool compareRating   (const Song& song1, const Song& song2) { return song1.rating    < song2.rating  ;   }
inline bool compareViews    (const Song& song1, const Song& song2) { return song1.views     < song2.views   ;   }



int main() {
    Playlist playlist = buildPlaylist();


    sortPlaylist(playlist, compareRating);

    printPlaylist(playlist);


    const Song* minRatingSong   =   findSong(playlist, filterSongMinViews);
    const Song* maxRatingSong   =   findSong(playlist, filterSongMaxViews);

    std::cout << "The MIN Rating Song is: " << ((minRatingSong == nullptr) ? "UNKNOWN" : minRatingSong->name) << std::endl;
    std::cout << "The MAX Rating Song is: " << ((maxRatingSong == nullptr) ? "UNKNOWN" : maxRatingSong->name) << std::endl;


    return 0;
}



unsigned int readSize() {
    unsigned int size = 0;

    while (true) {
        std::cout << "Enter the size of the playlist: ";

        std::cin >> size;

        if (std::cin.fail() || size == 0) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return size;
        }
    }
}



double readNumberD() {
    double number = 0.0;

    while (true) {
        std::cin >> number;

        if (std::cin.fail() || (number < MIN_RATING || number > MAX_RATING)) {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;
        } else {
            std::cin.clear  ()                                                  ;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n') ;

            return number;
        }
    }
}

unsigned int readNumberU() {
    unsigned int number = 0;

    while (true) {
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



Genre getGenre(const char* string) {
    assert(string   !=  nullptr );

    for (unsigned int i = static_cast<int>(Genre::UNKNOWN) + 1; i < static_cast<int>(Genre::COUNTER); ++i) {
        if (strcmp(string, genres[i]) == 0) {
            return static_cast<Genre>(i);
        }
    }

    return Genre::UNKNOWN;
}

const char* getGenre(const Genre& genre) {
    assert(genre    !=  Genre::UNKNOWN);
    assert(genre    !=  Genre::COUNTER);

    for (unsigned int i = 0; i < static_cast<int>(Genre::COUNTER); ++i) {
        if (genre == static_cast<Genre>(i)) {
            return genres[i]; 
        }
    }

    return "";
}



Song buildSong() {
    Song song = { "", "", Genre::UNKNOWN, 0.0, 0 };

    char buffer[16] = { 0 };

    std::cout << "Enter the name    of the song: "; std::cin.getline(song.name,     MAX, '\n');
    std::cout << "Enter the singer  of the song: "; std::cin.getline(song.singer,   MAX, '\n');
    std::cout << "Enter the genre   of the song: "; std::cin.getline(buffer,        16,  '\n');
    std::cout << "Enter the rating  of the song: "; song.rating =   readNumberD();
    std::cout << "Enter the views   of the song: "; song.views  =   readNumberU();

    song.genre = getGenre(buffer);

    return song;
}

void printSong(const Song& song) {
    std::cout << "The name      of the song is: " << song.name              << std::endl;
    std::cout << "The singer    of the song is: " << song.singer            << std::endl;
    std::cout << "The genre     of the song is: " << getGenre(song.genre)   << std::endl;
    std::cout << "The rating    of the song is: " << song.rating            << std::endl;
    std::cout << "The views     of the song is: " << song.views             << std::endl;
}



Playlist buildPlaylist() {
    Playlist playlist = { {}, 0, 64 };

    playlist.size = readSize();

    std::cout << std::endl;

    for (unsigned int i = 0; i < playlist.size; ++i) {
        playlist.songs[i] = buildSong();

        std::cout << std::endl;
    }

    return playlist;
}

void printPlaylist(const Playlist& playlist) {
    std::cout << "The sorted playlist is: " << std::endl;

    std::cout << std::endl;

    for (unsigned int i = 0; i < playlist.size; ++i) {
        printSong(playlist.songs[i]);

        std::cout << std::endl;
    }
}



void sortPlaylist(Playlist& playlist, bool (*comparator)(const Song&, const Song&)) {
    for (unsigned int i = 0; i < playlist.size - 1; ++i) {
        for (unsigned int j = i + 1; j < playlist.size; ++j) {
            if (comparator(playlist.songs[i], playlist.songs[j]) == false) {
                std::swap(playlist.songs[i], playlist.songs[j]);
            }
        }
    }
}



const Song* findSong(const Playlist& playlist, bool (*predicate)(const Song&)) {
    for (unsigned int i = 0; i < playlist.size; ++i) {
        if (predicate(playlist.songs[i])) {
            return &(playlist.songs[i]);
        }
    }

    return nullptr;
}
