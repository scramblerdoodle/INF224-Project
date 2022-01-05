#include <iostream>
#include "Image.h"
#include "Multimedia.h"
using namespace std;

int main(int argc, const char* argv[])
{
    Image * im = new Image();
    Multimedia * media = new Multimedia();
    cout << "Multimedia" << endl;
    media->print(cout);
    cout << endl;

    cout << "Image" << endl;
    im->print(cout);


    return 0;
}
