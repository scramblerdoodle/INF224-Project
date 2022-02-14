#ifndef FILM_H
#define FILM_H
#include "Video.h"
#include <vector>

class Film : public Video 
{
    private:
        vector<int> chapterDurations{};
        unsigned int _numberChapters;
    
    public:

        // Constructors
        Film();
        Film(string name, string pathname, int duration, vector<int> chapters);

        // Destructor
        ~Film() {};

        // Setters
        void setChapters(vector<int> chapters);

        // Getters
        vector<int> const getChapters() { return chapterDurations; };
        int getChapterCount() { return _numberChapters; };
        
        // Prints
        void print(ostream& s) override;

        // Methods
        void play(int chapter);
};
typedef shared_ptr<Film> FilmPtr;
#endif