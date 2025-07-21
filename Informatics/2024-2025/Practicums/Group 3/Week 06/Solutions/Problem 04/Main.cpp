#include <iostream>


#include "Song.hpp"



int main() {
    try {
        Song data[MAX] = {
            Song("Ot kef da umiram" , "Dessita", 4  ),
            Song("GPS-a"            , "Dessita", 3  ),
            Song("Tvoyata zhena"    , "Dessita", 5  ),
        };

        findMinDurationSong(data, 3).print();
        findMaxDurationSong(data, 3).print();
    } catch (std::exception& exception) {
        std::cerr << exception.what() << std::endl;

        return 1;
    }


    return 0;
}
