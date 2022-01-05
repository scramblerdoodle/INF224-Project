//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Multimedia.h"
using namespace std;

int main(int argc, const char* argv[])
{
    Multimedia media {"name", "path"};
    std::cout << media.getPath() << ':' << media.getName() << std::endl;
    return 0;
}
