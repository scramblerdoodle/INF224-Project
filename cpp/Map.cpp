#include "Map.h"
#include "Image.h"
#include "Video.h"
#include "Film.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

enum StringValue {  evNotDefined,
                    evImage,
                    evVideo,
                    evFilm,
                    evGroup,
                    evEnd };

// Map to associate the strings with the enum values
static std::map<std::string, StringValue> s_mapStringValues;

// Initialising the mapping for the switch cases when creating the Map object
static void Initialize()
{
    s_mapStringValues["image"] = evImage;
    s_mapStringValues["video"] = evVideo;
    s_mapStringValues["film"] = evFilm;
    s_mapStringValues["group"] = evGroup;
    s_mapStringValues["end"] = evEnd;
}

// Util function
void convertStrtoVect(string str, vector<int>* arr)
{
    int j = 0;
  
    // Traverse the string
    for (char &c : str) {
        if (c == '[' || c == ']' || c == ',')
            continue;
        if (c == ' ')
         {
            // Increment j to point to next array location
            j++;
            arr->push_back(0);
        }
        else {  
            // subtract c by '0' to convert it to int
            // Generate number by multiplying 10 and adding
            // (int)(c)
            arr->at(j) = arr->at(j) * 10 + (c - '0');
        }
    }
}

// Constructor
Map::Map(string filepath) : _medias(), _groups()
{
    ifstream mediaFile (filepath);
    string line, word, mediaType;
    vector<int> arr { 0 };

    Initialize();

    GroupPtr gr;

    if (mediaFile.is_open())
    {
        while ( getline(mediaFile, line, '\n') )
        {
            stringstream X (line);
            vector<string> wordArray;
            
            while ( getline(X, word, ';') )
                wordArray.push_back(word);
            
            mediaType = wordArray[0];
            wordArray.erase(wordArray.begin());

            switch (s_mapStringValues[mediaType])
            {
            case evImage:
                addImage(wordArray[0], wordArray[1], stoi(wordArray[2]), stoi(wordArray[3]));
                break;

            case evVideo:
                addVideo(wordArray[0], wordArray[1], stoi(wordArray[2]));
                break;

            case evFilm:
                convertStrtoVect(wordArray[3], &arr);
                addFilm(wordArray[0], wordArray[1], stoi(wordArray[2]), arr);
                break;

            case evGroup:
                addGroup(wordArray[0]);
                gr = getGroup(wordArray[0]);
                wordArray.erase(wordArray.begin());
                for (auto title : wordArray)    gr->push_back(getMedia(title));
                break;

            default:
                break;
            }
        }
    }
};

// "DESTRUCTOR"
void Map::remove(string name)
{
    if (_medias.find(name) != _medias.end()) _medias.erase(name);
    else if (_groups.find(name) != _groups.end()) _groups.erase(name);
    else { cout << "Keyword not found."; }
};

// SETTERS
MediaPtr Map::addImage(string name, string pathname, int size_x, int size_y)
{
    if (_medias.find(name) == _medias.end())
        _medias[name] = ImagePtr(new Image(name, pathname, size_x, size_y));
    else { cout << "ERROR: This keyword was already used."; }
    return _medias[name];
};

MediaPtr Map::addVideo(string name, string pathname, int duration)
{
    if (_medias.find(name) == _medias.end())
        _medias[name] = VideoPtr(new Video(name, pathname, duration));
    else { cout << "ERROR: This keyword was already used."; }
    return _medias[name];
};

MediaPtr Map::addFilm(string name, string pathname, int duration, vector<int> chapters)
{
    if (_medias.find(name) == _medias.end())
        _medias[name] = FilmPtr(new Film(name, pathname, duration, chapters));
    else { cout << "ERROR: This keyword was already used."; }
    return _medias[name];
};

GroupPtr Map::addGroup(string name)
{
    if (_groups.find(name) == _groups.end())
    {
        _groups[name] = GroupPtr(new Group(name));
    }
    else { cout << "ERROR: This keyword was already used."; }
    return _groups[name];
};

// GETTERS
MediaPtr const Map::getMedia(string name)
{
    auto media = _medias.find(name);
    if (media != _medias.end())
        return media->second;
    else 
        return nullptr;
};

GroupPtr const Map::getGroup(string name)
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
    else { s << "Keyword not found."; }
};

void Map::play(string name)
{
    auto media = getMedia(name);
    if (media != nullptr) media->play();
}
