#include <iostream>

#include "Video.h"
#include "Image.h"
using namespace std;

int main(int argc, const char* argv[])
{
    Video * video = new Video("skeleton", "/media/orlando/Files/Videos/webm/attack helicopter invades peaceful skeleton realm.mp4", 600);
    Image * image = new Image("jolly", "/media/orlando/Files/Pictures/157899859_284324719767687_2825453359009430038_n.jpg", 500, 500);
    
    video->print(cout);
    video->play();
    
    image->print(cout);
    image->open();

    return 0;
}
