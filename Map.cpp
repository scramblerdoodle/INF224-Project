#include "Map.h"
#include "Image.h"
#include "Video.h"
#include "Film.h"
#include <iostream>

using namespace std;
// "DESTRUCTOR"
void Map::remove(string name)
{
    if (_medias.find(name) != _medias.end()) _medias.erase(name);
    else if (_groups.find(name) != _groups.end()) _groups.erase(name);
    else { cout << "Keyword not found." << endl; }
};

// SETTERS
MediaPtr Map::addImage(string name, string pathname, int size_x, int size_y)
{
    if (_medias.find(name) == _medias.end())
        _medias[name] = ImagePtr(new Image(name, pathname, size_x, size_y));
    else { cout << "ERROR: This keyword was already used." << endl; }
    return _medias[name];
};

MediaPtr Map::addVideo(string name, string pathname, int duration)
{
    if (_medias.find(name) == _medias.end())
        _medias[name] = VideoPtr(new Video(name, pathname, duration));
    else { cout << "ERROR: This keyword was already used." << endl; }
    return _medias[name];
};

MediaPtr Map::addFilm(string name, string pathname, int duration, int* chapters)
{
    if (_medias.find(name) == _medias.end())
        _medias[name] = FilmPtr(new Film(name, pathname, duration, chapters));
    else { cout << "ERROR: This keyword was already used." << endl; }
    return _medias[name];
};

GroupPtr Map::addGroup(string name)
{
    if (_groups.find(name) == _groups.end())
    {
        _groups[name] = GroupPtr(new Group(name));
    }
    else { cout << "ERROR: This keyword was already used." << endl; }
    return _groups[name];
};

// GETTERS
MediaPtr Map::getMedia(string name)
{
    auto media = _medias.find(name);
    if (media != _medias.end())
        return media->second;
    else 
        return nullptr;
};

GroupPtr Map::getGroup(string name)
{
    auto group = _groups.find(name);
    if (group != _groups.end())
        return group->second;
    else 
        return nullptr;
};

// METHODS
void Map::print(string name, ostream& s)
{
    auto media = getMedia(name);
    auto group = getGroup(name);
    if (media != nullptr) media->print(s);
    else if (group != nullptr) group->print(s);
    else { s << "Keyword not found." << endl; }
};

void Map::play(string name)
{
    auto media = getMedia(name);
    if (media != nullptr) media->play();
}
