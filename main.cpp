#include <iostream>
#include "Image.h"
#include "Multimedia.h"
using namespace std;

int main(int argc, const char* argv[])
{
    Image * image = new Image("customname", "custompath", 1920, 1080);
    Image * imageDefault = new Image();
    
    Multimedia * media = new Multimedia();
    cout << "Multimedia" << endl;
    media->print(cout);
    cout << endl;

    image->print(cout);
    imageDefault->print(cout);


    return 0;
}
