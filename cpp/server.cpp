#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Map.h"

const int PORT = 3331;

enum OptionValue {  evNotDefined,
                    evHelp,
                    evList,
                    evPrint,
                    evPlay,
                    evSearch,
                    evAdd,
                    evRemove,
                    evEdit,
                    evSave };

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
}

static void processRequest(string request, Map objects, ostream& output);

int main(int argc, char* argv[])
{
    vector<string> opts;
    string word;

    stringstream output;

    // Creates the mapping object and populates it with data saved on the media.txt file
    Map objects("../media.txt");
    
    Initialize();

    // creates the TCPServer
    auto* server =
    new TCPServer( [&](std::string const& request, std::string& response) {

        // the request sent by the client to the server
        std::cout << "request: " << request << std::endl;
        
        // processing the request sent by the client and running the appropriate command
        output = {};
        processRequest(request, objects, output);

        // the response that the server sends back to the client
        response = output.str();

        // return false would close the connection with the client
        return true;
    });


    // starts the server's infinite loop
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // in case of an error
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
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
        output << ";";
        output << "help: list commands" << ";";
        output << "list: show all media options" << ";";
        output << "print <option>: show info related to a chosen media file" << ";";
        output << "play <option>: play a media file" << ";";
        output << "search <pattern>: look for media starting with chosen pattern" << ";";
        output << "add <type, ...>" << ";";
        output << "remove <option>" << ";";
        output << "edit <option>" << ";";
        output << "save" << ";";
        output << "quit";
        break;

    case evList:
        output << ";" << "Medias:" << ";";
        for (auto it : objects.getAllMedias())
            output << "\t" << it.first << ";";
        
        output << ";" << "Groups:" << ";";
        for (auto it : objects.getAllGroups())
            output << "\t" << it.first << ";";

        break;

    case evPrint:
        output << "Printing " << opts[1] << ";";
        objects.print(opts[1], output);
        break;

    case evPlay:
        output << "Playing " << opts[1];
        objects.play(opts[1]);
        break;

    case evSearch:
        output << "[Code to search media]";
        break;

    case evAdd:
        output << "[Code to add new media to obj]";
        break;

    case evRemove:
        output << "[Code to remove some media from obj]";
        break;

    case evEdit:
        output << "[Code to edit some item in the obj]";
        break;

    case evSave:
        output << "[Code to save the obj into the .txt file]";
        break;

    default:
        output << "Command " << opts[0] << " not found.";
        break;
    }

}
