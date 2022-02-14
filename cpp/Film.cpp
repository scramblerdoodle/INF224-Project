#include "Film.h"
#include <iostream>
using namespace std;

// Constructors
Film::Film() : Video()
{
    _numberChapters = 0;
    setChapters({});
};

Film::Film(string name, string pathname, int duration, vector<int> chapters) 
    : Video(name, pathname, duration) 
{
    _numberChapters = chapters.size();
    setChapters(chapters);
};

// Setters
void Film::setChapters(vector<int> chapters) 
{
    for (auto i : chapters)
        chapterDurations.push_back(i);
};

// Prints
void Film::print(ostream &s) 
{
    Video::print(s);
    s << "number of chapters: " << _numberChapters << "  ";

    int i = 0;
    for (auto c : chapterDurations)
        s << "Chapter " << ++i << ": " << c << "s" << "  ";

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