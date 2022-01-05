#include "Video.h"
#include <iostream>
using namespace std;

// Constructors
Video::Video() : Multimedia() {
    setDuration(0);
};

Video::Video(string name, string pathname, int duration) 
    : Multimedia(name, pathname) {
    setDuration(duration);
};

// Setters
void Video::setDuration(int duration) {
    _duration = duration;
};

// Prints
void Video::print(ostream &s) {
    Multimedia::print(s);
    s << this->getDuration() << "s" << endl;
}
