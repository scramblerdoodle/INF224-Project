//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Multimedia.h"
using namespace std;

int main(int argc, const char* argv[])
{
    Multimedia * media = new Multimedia("customname", "custompath");
    Multimedia * media_default = new Multimedia();
    media->print(cout);
    media_default->print(cout);

    return 0;
}
