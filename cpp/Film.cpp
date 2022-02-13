#include "Film.h"
#include <iostream>
using namespace std;

// Constructors
Film::Film() : Video()
{
    _numberChapters = 0;
    setChapters({});
};

Film::Film(string name, string pathname, int duration, int* chapters) 
    : Video(name, pathname, duration) 
{
    _numberChapters = sizeof &chapters/sizeof chapters[0];
    setChapters(chapters);
};

// Setters
void Film::setChapters(int* chapters) 
{
    chapterDurations = new int(_numberChapters);

    for (unsigned int i = 0; i < _numberChapters; i++)
    {
        chapterDurations[i] = chapters[i];
    }
};

// Prints
void Film::print(ostream &s) 
{
    Video::print(s);
    s << "number of chapters: " << _numberChapters << "  ";

    for (unsigned int i = 0; i < _numberChapters; i++)
        s << "Chapter " << i + 1 << ": " << chapterDurations[i] << "s" << "  ";

}

// Methods
void Film::play(int chapter) 
{
    string vlc = "vlc "; // CHANGE TO MPV
    string pathname = "'" + getPath() + "'"; // possibly might need to change these '
    string ampersand = " &";
    string finalCommand = vlc + pathname + ampersand;
    system(finalCommand.c_str());
}