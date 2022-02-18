#include "Image.h"
#include <iostream>
using namespace std;

// Constructors
Image::Image() : Multimedia() 
{
    setWidth(0);
    setHeight(0);
};

Image::Image(string name, string pathname, int size_x, int size_y) 
    : Multimedia(name, pathname) 
{
    setWidth(size_x);
    setHeight(size_y);
};

// Setters
void Image::setWidth(int size_x) 
{
    _size_x = size_x;
};

void Image::setHeight(int size_y) 
{
    _size_y = size_y;
};

// Prints
void Image::print(ostream &s) 
{
    Multimedia::print(s);
    s << "Size: " << getWidth() << "x" << getHeight() << "  ";
}

// Methods
void Image::play() 
{
    string cmd = "eog "; // TODO: change to mpv
    string pathname = getPath();
    string finalCommand = cmd + pathname + " &";
    system(finalCommand.c_str());
}