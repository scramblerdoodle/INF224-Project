#ifndef FILM_H
#define FILM_H
#include "Video.h"

class Film : public Video 
{
    private:
        int * chapterDurations;
        unsigned int _numberChapters;
    
    public:

        // Constructors
        Film();
        Film(string name, string pathname, int duration, int* chapters);

        // Destructor
        ~Film() { delete[] chapterDurations; };

        // Setters
        void setChapters(int * chapters);

        // Getters
        int* getChapters() { return chapterDurations; };
        int getChapterCount() { return _numberChapters; };
        
        // Prints
        void print(ostream& s) override;

        // Methods
        void play(int chapter);
};
#endif