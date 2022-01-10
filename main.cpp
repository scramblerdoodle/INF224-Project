#include <iostream>

#include "Image.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "Map.h"
using namespace std;

int main(int argc, const char* argv[])
{    
    int* chaptersSkeleton(new int[2]{0, 12});

    Map objects;
    objects.addFilm("skeleton", "/media/orlando/Files/Videos/webm/attack helicopter invades peaceful skeleton realm.mp4", 23, chaptersSkeleton);
    objects.addImage("jolly", "/media/orlando/Files/Pictures/157899859_284324719767687_2825453359009430038_n.jpg", 500, 500);
    objects.addGroup("group");


    GroupPtr gr = objects.getGroup("group");
    FilmPtr film(new Film("skeleton", "/media/orlando/Files/Videos/webm/attack helicopter invades peaceful skeleton realm.mp4", 23, chaptersSkeleton));
    ImagePtr image(new Image("jolly", "/media/orlando/Files/Pictures/157899859_284324719767687_2825453359009430038_n.jpg", 500, 500));
    gr->push_back(film);
    gr->push_back(image);

    delete [] chaptersSkeleton;

    cout << endl << "Press q to quit." << endl;
    string name;
    do
    {
        cout << "Choose a media name: ";
        cin >> name;
        if (name != "q")
        {
            objects.print(name, cout);
            objects.play(name);
        }
    } while (name != "q");

    objects.remove("jolly");
    objects.remove("skeleton");
    objects.remove("group");

    return 0;
}
