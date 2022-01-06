#include "Video.h"
#include <iostream>
using namespace std;

// Constructors
Video::Video() : Multimedia() 
{
    setDuration(0);
};

Video::Video(string name, string pathname, int duration) 
    : Multimedia(name, pathname) 
{
    setDuration(duration);
};

// Setters
void Video::setDuration(int duration) 
{
    _duration = duration;
};

// Prints
void Video::print(ostream &s) 
{
    Multimedia::print(s);
    s << "Total duration: " << getDuration() << "s" << endl;
}

// Methods
void Video::play() 
{
    string vlc = "vlc "; // CHANGE TO MPV
    string pathname = "'" + getPath() + "'"; // possibly might need to change these '
    string ampersand = " &";
    string finalCommand = vlc + pathname + ampersand;
    system(finalCommand.c_str());
}