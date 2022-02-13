#ifndef MAP_H
#define MAP_H

#include <map>
#include "Multimedia.h"
#include "Group.h"

using namespace std;

typedef map<string, MediaPtr> mediaDict;
typedef map<string, GroupPtr> groupDict;               

class Map
{
    private:
        mediaDict _medias;
        groupDict _groups;

    public:
        // Constructor
        Map() : _medias(), _groups() {};

        // "Destructor"
        void remove(string name);

        // Setters
        MediaPtr addImage(string name, string pathname, int size_x, int size_y);
        MediaPtr addVideo(string name, string pathname, int duration);
        MediaPtr addFilm(string name, string pathname, int duration, int* chapters);
        GroupPtr addGroup(string name);

        // Getters
        MediaPtr getMedia(string name);
        GroupPtr getGroup(string name);

        // Methods
        void print(string name, ostream& s);
        void play(string name);

};
#endif