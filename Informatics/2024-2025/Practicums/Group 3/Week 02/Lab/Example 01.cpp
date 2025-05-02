#include <cassert>

#include <iostream>



const unsigned int  MAX_ROWS    =   65536;
const unsigned int  MAX_COLS    =   65536;



struct Pixel {
    int red     ;
    int green   ;
    int blue    ;
};



Pixel   buildPixelRed   ();
Pixel   buildPixelGreen ();
Pixel   buildPixelBlue  ();
Pixel   buildPixelWhite ();
Pixel   buildPixelBlack ();

Pixel   buildPixelColor (int red, int green, int blue);



void    increaseBrightnessPixelValue(Pixel pixel, int amount);
void    decreaseBrightnessPixelValue(Pixel pixel, int amount);

void    increaseBrightnessPixelName(Pixel& pixel, int amount);
void    decreaseBrightnessPixelName(Pixel& pixel, int amount);



void    printPixel(const Pixel& pixel);



void    initCanvasSD1   ();
void    initCanvasSD2   ();
void    initCanvasSD3   ();
void    initCanvasHD1   ();
void    initCanvasHD2   ();
void    initCanvas2KP   ();
void    initCanvas4KP   ();
void    initCanvas8KP   ();



void    printCanvas(const Pixel canvas[][MAX_COLS], unsigned int rows, unsigned int cols);



int main() {
    Pixel defaultPixel;

    // warning: unused variable ‘defaultPixel’ [-Wunused-variable]


    Pixel pixel { 128, 128, 128 };

    printPixel(pixel);


    Pixel pixel1 = { 128, 128, 128 };
    Pixel pixel2 = { 128, 128, 128 };

    increaseBrightnessPixelValue(pixel1, +1);   std::cout << "Pixel 1 Data is: " << std::endl;  printPixel(pixel1);
    decreaseBrightnessPixelValue(pixel2, -1);   std::cout << "Pixel 2 Data is: " << std::endl;  printPixel(pixel2);

    increaseBrightnessPixelName(pixel1, +1);    std::cout << "Pixel 1 Data is: " << std::endl;  printPixel(pixel1);
    decreaseBrightnessPixelName(pixel2, -1);    std::cout << "Pixel 2 Data is: " << std::endl;  printPixel(pixel2);


    // initCanvasSD1(); Stack Overflow
    // initCanvasSD2(); Stack Overflow
    // initCanvasSD3(); Stack Overflow
    // initCanvasHD1(); Stack Overflow
    // initCanvasHD2(); Stack Overflow
    // initCanvas2KP(); Stack Overflow
    // initCanvas4KP(); Stack Overflow
    // initCanvas8KP(); Stack Overflow


    return 0;
}



Pixel buildPixelRed() {
    Pixel pixel;

    pixel.red   =   255 ;
    pixel.green =   0   ;
    pixel.blue  =   0   ;

    return pixel;

    // warning: function returns an aggregate [-Waggregate-return]
}

Pixel buildPixelGreen() {
    Pixel pixel;

    pixel.red   =   0   ;
    pixel.green =   255 ;
    pixel.blue  =   0   ;

    return pixel;

    // warning: function returns an aggregate [-Waggregate-return]
}

Pixel buildPixelBlue() {
    Pixel pixel;

    pixel.red   =   0   ;
    pixel.green =   0   ;
    pixel.blue  =   255 ;

    return pixel;

    // warning: function returns an aggregate [-Waggregate-return]
}

Pixel buildPixelWhite() {
    Pixel pixel;

    pixel.red   =   255 ;
    pixel.green =   255 ;
    pixel.blue  =   255 ;

    return pixel;

    // warning: function returns an aggregate [-Waggregate-return]
}

Pixel buildPixelBlack() {
    Pixel pixel;

    pixel.red   =   0   ;
    pixel.green =   0   ;
    pixel.blue  =   0   ;

    return pixel;

    // warning: function returns an aggregate [-Waggregate-return]
}

Pixel buildPixelColor(int red, int green, int blue) {
    Pixel result { red, green, blue };

    return result;

    // warning: function returns an aggregate [-Waggregate-return]
}



void increaseBrightnessPixelValue(Pixel pixel, int amount) {
    if (amount <= 0) {
        std::cout << "Increasing Brightness... ERROR!" << std::endl;

        return;
    }

    pixel.red   =   std::min(pixel.red      + amount, 255);
    pixel.green =   std::min(pixel.green    + amount, 255);
    pixel.blue  =   std::min(pixel.blue     + amount, 255);
}

void decreaseBrightnessPixelValue(Pixel pixel, int amount) {
    if (amount >= 0) {
        std::cout << "Decreasing Brightness... ERROR!" << std::endl;

        return;
    }

    pixel.red   =   std::max(pixel.red      - amount, 0);
    pixel.green =   std::max(pixel.green    - amount, 0);
    pixel.blue  =   std::max(pixel.blue     - amount, 0);
}

void increaseBrightnessPixelName(Pixel& pixel, int amount) {
    if (amount <= 0) {
        std::cout << "Increasing Brightness... ERROR!" << std::endl;

        return;
    }
    
    pixel.red   =   std::min(pixel.red      + amount, 255);
    pixel.green =   std::min(pixel.green    + amount, 255);
    pixel.blue  =   std::min(pixel.blue     + amount, 255);
}

void decreaseBrightnessPixelName(Pixel& pixel, int amount) {
    if (amount >= 0) {
        std::cout << "Decreasing Brightness... ERROR!" << std::endl;

        return;
    }

    pixel.red   =   std::max(pixel.red      - amount, 0);
    pixel.green =   std::max(pixel.green    - amount, 0);
    pixel.blue  =   std::max(pixel.blue     - amount, 0);
}



void printPixel(const Pixel& pixel) {
    std::cout << "R: "  <<  pixel.red   << std::endl;
    std::cout << "G: "  <<  pixel.green << std::endl;
    std::cout << "B: "  <<  pixel.blue  << std::endl;
}



void initCanvasSD1() {
    constexpr unsigned int rows = 426   ;
    constexpr unsigned int cols = 240   ;

    Pixel canvas[MAX_COLS][MAX_ROWS];

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            canvas[i][j] = buildPixelWhite();
        }
    }

    printCanvas(canvas, rows, cols);
}

void initCanvasSD2() {
    constexpr unsigned int rows = 640   ;
    constexpr unsigned int cols = 360   ;

    Pixel canvas[MAX_ROWS][MAX_COLS];

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            canvas[i][j] = buildPixelBlack();

            // warning: function call has aggregate value [-Waggregate-value]
        }
    }

    printCanvas(canvas, rows, cols);
}

void initCanvasSD3() {
    constexpr unsigned int rows = 854   ;
    constexpr unsigned int cols = 480   ;

    Pixel canvas[MAX_ROWS][MAX_COLS];

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            canvas[i][j] = buildPixelRed();

            // warning: function call has aggregate value [-Waggregate-return]
        }
    }

    printCanvas(canvas, rows, cols);
}

void initCanvasHD1() {
    constexpr unsigned int rows = 1280  ;
    constexpr unsigned int cols =  720  ;

    Pixel canvas[MAX_ROWS][MAX_COLS];

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            canvas[i][j] = buildPixelGreen();

            // warning: function call has aggregate value [-Waggregate-return]
        }
    }

    printCanvas(canvas, rows, cols);
}

void initCanvasHD2() {
    constexpr unsigned int rows = 1920  ;
    constexpr unsigned int cols = 1080  ;

    Pixel canvas[MAX_ROWS][MAX_COLS];

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            canvas[i][j] = buildPixelBlue();

            // warning: function call has aggregate value [-Waggregate-return]
        }
    }

    printCanvas(canvas, rows, cols);
}

void initCanvas2KP() {
    constexpr unsigned int rows = 2560  ;
    constexpr unsigned int cols = 1440  ;

    Pixel canvas[MAX_ROWS][MAX_COLS];

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            canvas[i][j] = buildPixelColor(255, 255, 0);

            // warning: function call has aggregate value [-Waggregate-return]
        }
    }

    printCanvas(canvas, rows, cols);
}

void initCanvas4KP() {
    constexpr unsigned int rows = 3840  ;
    constexpr unsigned int cols = 2160  ;

    Pixel canvas[MAX_ROWS][MAX_COLS];

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            canvas[i][j] = buildPixelColor(0, 255, 255);

            // warning: function call has aggregate value [-Waggregate-return]
        }
    }

    printCanvas(canvas, rows, cols);
}

void initCanvas8KP() {
    constexpr unsigned int rows = 7680  ;
    constexpr unsigned int cols = 4320  ;

    Pixel canvas[MAX_ROWS][MAX_COLS];

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            canvas[i][j] = buildPixelColor(255, 0, 255);

            // warning: function call has aggregate value [-Waggregate-return]
        }
    }

    printCanvas(canvas, rows, cols);
}



void printCanvas(const Pixel canvas[][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows !=  0       );
    assert(cols !=  0       );
    assert(rows <=  MAX_ROWS);
    assert(cols <=  MAX_COLS);

    std::cout << "Canvas Data is: " << std::endl;

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            printPixel(canvas[i][j]);
        }
    }
}
