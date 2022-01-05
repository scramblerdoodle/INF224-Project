#include <iostream>
#include "Video.h"
#include "Multimedia.h"
using namespace std;

int main(int argc, const char* argv[])
{
    Video * video = new Video("customname", "custompath", 600);
    Video * videoDefault = new Video();
    
    Multimedia * media = new Multimedia();
    cout << "Multimedia" << endl;
    media->print(cout);
    cout << endl;

    video->print(cout);
    videoDefault->print(cout);


    return 0;
}
