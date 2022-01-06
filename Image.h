#ifndef IMAGE_H
#define IMAGE_H
#include "Multimedia.h"

class Image : public Multimedia 
{
    private:
        int _size_x;
        int _size_y;
    
    public:

        // Constructors
        Image();
        Image(string name, string pathname, int size_x, int size_y);

        // Destructor
        ~Image() {};

        // Setters
        void setWidth(int size_y);
        void setHeight(int size_x);

        // Getters
        int getWidth() { return _size_x; }
        int getHeight() { return _size_y; }
        
        // Prints
        void print(ostream& s) override;

        // Methods
        void play() override;
};
#endif