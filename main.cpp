#include <iostream>

#include "Image.h"
#include "Video.h"
#include "Film.h"
using namespace std;

int main(int argc, const char* argv[])
{
    Multimedia ** mediaArray = new Multimedia * [2];
    
    int chaptersSkeleton[2] = {0, 12};
    
    unsigned int count = 0;
    mediaArray[count++] = new Film("skeleton", "/media/orlando/Files/Videos/webm/attack helicopter invades peaceful skeleton realm.mp4", 23, chaptersSkeleton);
    mediaArray[count++] = new Image("jolly", "/media/orlando/Files/Pictures/157899859_284324719767687_2825453359009430038_n.jpg", 500, 500);

    for (unsigned int i = 0; i < count; i++)
    {
        mediaArray[i]->print(cout);
        // mediaArray[i]->play();
        cout << endl;
    }

    return 0;
}
