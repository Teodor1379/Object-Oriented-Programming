#include <iostream>



#define MAX_ROWS 255
#define MAX_COLS 255



struct Pixel {
    int red     =   0;
    int green   =   0;
    int blue    =   0;



    void initializeBlackPixel() {
        red     =   0;
        green   =   0;
        blue    =   0;
    }

    void initializeWhitePixel() {
        red     =   255;
        green   =   255;
        blue    =   255;
    }



    void printInformation() {
        std::cout << "R: "  << red      << std::endl;
        std::cout << "G: "  << green    << std::endl;
        std::cout << "B: "  << blue     << std::endl;
    }



    void increaseBrightness(int amount) {
        red     =   std::min(red    + amount, 255);
        green   =   std::min(green  + amount, 255);
        blue    =   std::min(blue   + amount, 255);
    }

    void decreaseBrightness(int amount) {
        red     =   std::max(red    - amount, 0);
        green   =   std::max(green  - amount, 0);
        blue    =   std::max(blue   - amount, 0);
    }
};



struct Canvas {
    unsigned int rows = 0;
    unsigned int cols = 0;

    Pixel pixels[MAX_ROWS][MAX_COLS];



    void initializeBlackCanvas() {
        rows    =   MAX_ROWS;
        cols    =   MAX_COLS;

        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                pixels[i][j].initializeBlackPixel();
            }
        }
    }

    void initializeWhiteCanvas() {
        rows    =   MAX_ROWS;
        cols    =   MAX_COLS;
        
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                pixels[i][j].initializeWhitePixel();
            }
        }
    }



    void printCanvas() {
        std::cout << "Canvas Data is: " << std::endl;

        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                pixels[i][j].printInformation();
            }
        }
    }
};



int main() {
    Canvas canvas1;
    Canvas canvas2;

    canvas1.initializeBlackCanvas();
    canvas2.initializeWhiteCanvas();

    canvas1.printCanvas();
    canvas2.printCanvas();


    return 0;
}
