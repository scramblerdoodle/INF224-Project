#include <iostream>
#include <vector>
#include <map>
#include <sstream>

#include "Group.h"
#include "Map.h"
using namespace std;

enum OptionValue {  evNotDefined,
                    evHelp,
                    evList,
                    evPrint,
                    evPlay,
                    evSearch,
                    evAdd,
                    evRemove,
                    evEdit,
                    evSave,
                    evEnd };

// Map to associate the strings with the enum values
static std::map<std::string, OptionValue> s_mapOptionValues;

// Initialising the mapping for the switch cases when creating the Map object
static void Initialize()
{
    s_mapOptionValues["help"] = evHelp;
    s_mapOptionValues["list"] = evList;
    s_mapOptionValues["print"] = evPrint;
    s_mapOptionValues["play"] = evPlay;
    s_mapOptionValues["search"] = evSearch;
    s_mapOptionValues["add"] = evAdd;
    s_mapOptionValues["remove"] = evRemove;
    s_mapOptionValues["edit"] = evEdit;
    s_mapOptionValues["save"] = evSave;
    s_mapOptionValues["quit"] = evEnd;
    s_mapOptionValues["q"] = evEnd;
}


int main(int argc, const char* argv[])
{    

    Map objects("../media.txt");

    string line, word;
    vector<string> opts;

    mediaDict medias;
    groupDict groups;
    
    Initialize();
    cout << endl << "Type 'help' to list all available commands." << endl;
    
    while (1)
    {
        opts = {};

        cout << "Choose a command: ";
        getline(cin, line);
        stringstream X (line);    
        while ( getline(X, word, ' ') )
            opts.push_back(word);

        switch (s_mapOptionValues[opts[0]])
        {
        case evHelp:
            cout << "help: list commands" << endl;
            cout << "nlist: show all media options" << endl;
            cout << "print <option>: show info related to a chosen media file" << endl;
            cout << "play <option>: play a media file" << endl;
            cout << "search <pattern>: look for media starting with chosen pattern" << endl;
            cout << "add <type, ...>" << endl;
            cout << "remove <option>" << endl;
            cout << "edit <option>" << endl;
            cout << "save" << endl;
            cout << "quit/q" << endl;
            break;

        case evList:
            medias = objects.getAllMedias();
            cout << "Medias:" << endl;
            for (auto it : medias)
                cout << it.first << endl;
            
            groups = objects.getAllGroups();
            cout << endl << "Groups:" << endl;
            for (auto it : groups)
                cout << it.first << endl;

            break;

        case evPrint:
            objects.print(opts[1], cout);
            break;

        case evPlay:
            objects.play(opts[1]);
            break;

        case evSearch:
            cout << "[Code to search media]" << endl;
            break;

        case evAdd:
            cout << "[Code to add new media to obj]" << endl;
            break;

        case evRemove:
            cout << "[Code to remove some media from obj]" << endl;
            break;

        case evEdit:
            cout << "[Code to edit some item in the obj]" << endl;
            break;

        case evSave:
            cout << "[Code to save the obj into the .txt file]" << endl;
            break;

        case evEnd:
            return 0;

        default:
            cout << "Command " << opts[0] << " not found." << endl;
            break;
        }

    }
}
