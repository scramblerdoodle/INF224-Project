#ifndef VIDEO_H
#define VIDEO_H
#include "Multimedia.h"

class Video : public Multimedia {
    private:
        int _duration;
    
    public:

        // Constructors
        Video();
        Video(string name, string pathname, int duration);

        // Destructor
        ~Video() {};

        // Setters
        void setDuration(int duration);

        // Getters
        int getDuration() { return _duration; }
        
        // Prints
        void print(ostream& s) override;
};
#endif