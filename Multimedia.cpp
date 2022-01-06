#include "Multimedia.h"
#include <iostream>

using namespace std;

// Default constructor
Multimedia::Multimedia() 
{
    setName("name");
    setPath("path");
};

// Constructor
Multimedia::Multimedia(string name, string pathname) 
{
    setName(name);
    setPath(pathname);
};

// Setters
void Multimedia::setName(string name) 
{
    _name = name;    
};

void Multimedia::setPath(string pathname) 
{
    _pathname = pathname;
}

// Print
void Multimedia::print(ostream &s) 
{
    s << "Name and Path: " <<  this->getName() << " @ " << this->getPath() << endl;
}