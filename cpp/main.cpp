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

static void processRequest(string request, Map objects, ostream& output);


int main(int argc, const char* argv[])
{    
    Map objects("../media.txt");

    string request;
    stringstream output;

    mediaDict medias;
    groupDict groups;
    
    Initialize();
    std::cout << endl << "Type 'help' to list all available commands." << endl;
    
    while (1)
    {
        output = {};
        std::cout << "Choose a command: ";
        getline(cin, request);
        processRequest(request, objects, output);

        std::cout << output.str();
        if (output.str() == "quit") 
        {
            std::cout << '\n';
            break;
        }
    }

    return 0;
}

void processRequest(string request, Map objects, ostream& output)
{
    string word;
    vector<string> opts{};

    if (request.empty()) opts = {""};

    stringstream X (request);    
    while ( getline(X, word, ' ') )
        opts.push_back(word);

    switch (s_mapOptionValues[opts[0]])
    {
    case evHelp:
        output << "help: list commands" << endl;
        output << "nlist: show all media options" << endl;
        output << "print <option>: show info related to a chosen media file" << endl;
        output << "play <option>: play a media file" << endl;
        output << "search <pattern>: look for media starting with chosen pattern" << endl;
        output << "add <type, ...>" << endl;
        output << "remove <option>" << endl;
        output << "edit <option>" << endl;
        output << "save" << endl;
        output << "quit/q" << endl;
        break;

    case evList:
        output << "Medias:" << endl;
        for (auto it : objects.getAllMedias())
            output << it.first << endl;
        
        output << endl << "Groups:" << endl;
        for (auto it : objects.getAllGroups())
            output << it.first << endl;

        break;

    case evPrint:
        objects.print(opts[1], output);
        break;

    case evPlay:
        objects.play(opts[1]);
        break;

    case evSearch:
        output << "[Code to search media]" << endl;
        break;

    case evAdd:
        output << "[Code to add new media to obj]" << endl;
        break;

    case evRemove:
        output << "[Code to remove some media from obj]" << endl;
        break;

    case evEdit:
        output << "[Code to edit some item in the obj]" << endl;
        break;

    case evSave:
        output << "[Code to save the obj into the .txt file]" << endl;
        break;

    case evEnd:
        output << "quit";
        break;

    default:
        output << "Command " << opts[0] << " not found." << endl;
        break;
    }

}
