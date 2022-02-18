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
    s << "Total duration: " << getDuration() << "s" << "  ";
}

// Methods
void Video::play() 
{
    string cmd = "vlc "; // TODO: change to mpv
    string pathname = getPath();
    string finalCommand = cmd + pathname + " &";
    system(finalCommand.c_str());
}