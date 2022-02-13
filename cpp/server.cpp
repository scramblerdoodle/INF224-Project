#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Map.h"

const int PORT = 3331;


int main(int argc, char* argv[])
{
    // Creates the mapping object and populates it with test data
    Map objects;

    // TODO: save these into a file or something which is stored in the server, making it simpler to edit/keep permanent non-hardcoded entries
    int* chaptersSkeleton(new int[2]{0, 12});
    objects.addFilm("skeleton", "/media/orlando/Files/Videos/webm/attack helicopter invades peaceful skeleton realm.mp4", 23, chaptersSkeleton);
    objects.addImage("jolly", "/media/orlando/Files/Pictures/157899859_284324719767687_2825453359009430038_n.jpg", 500, 500);
    objects.addGroup("group");

    GroupPtr gr = objects.getGroup("group");
    gr->push_back(objects.getMedia("skeleton"));
    gr->push_back(objects.getMedia("jolly"));

    delete [] chaptersSkeleton;


    // cree le TCPServer
    auto* server =
    new TCPServer( [&](std::string const& request, std::string& response) {

        // the request sent by the client to the server
        std::cout << "request: " << request << std::endl;

        // TODO: add new commands (print, play, list, search, add, remove, edit, etc)
        stringstream s;
        objects.print(request, s);
        objects.play(request);

        // the response that the server sends back to the client
        response = "RECEIVED: " + s.str();

        // return false would close the connection with the client
        return true;
    });


    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}
