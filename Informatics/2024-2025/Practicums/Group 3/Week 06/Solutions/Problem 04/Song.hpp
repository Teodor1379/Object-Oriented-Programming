#ifndef _SONG_HEADER_INCLUDED_
#define _SONG_HEADER_INCLUDED_



#include <cstring>

#include <exception>
#include <stdexcept>

#include <iostream>



#define MAX 13



class Song {
public:
    Song(                                       );
    Song(const char*, const char*, unsigned int );
    Song(const Song&                            );

    ~Song();



public:
    Song& operator=(const Song&);



public:
    inline  const char*     getTitle    ()  const   { return this->title    ;   }
    inline  const char*     getArtist   ()  const   { return this->artist   ;   }
    inline  unsigned int    getDuration ()  const   { return this->duration ;   }



public:
    void setTitle   (const char*    );
    void setArtist  (const char*    );
    void setDuration(unsigned int   );



public:
    void print() const;



private:
    inline  bool    validateTitle   (const char*    title   )   const   { return title  != nullptr && title [0] != '\0' ;   }
    inline  bool    validateArtist  (const char*    artist  )   const   { return artist != nullptr && artist[0] != '\0' ;   }

    inline  bool    validateDuration(unsigned int   duration)   const   { return duration != 0                          ;   }



private:
    char*     buildString(const char*   )   const   ;
    void    destroyString(      char*&  )           ;



private:
    char*           title   ;
    char*           artist  ;
    unsigned int    duration;
};



Song    findMinDurationSong(const Song[MAX], unsigned int);
Song    findMaxDurationSong(const Song[MAX], unsigned int);



#endif
