#include "Multimedia.h"

using namespace std;

// Constructor
Multimedia::Multimedia(string name, string pathname) {
    setName(name);
    setPath(pathname);
};

// Public functions
void Multimedia::setName(string name) {
    _name = name;    
};

void Multimedia::setPath(string pathname) {
    _pathname = pathname;
}