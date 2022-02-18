#include "Group.h"
#include <iostream>
using namespace std;

void Group::print(ostream& s){
    for (iterator it = begin(); it != end(); it++)
    {
        (*it)->print(s);
        s << ";";
    }    
};

void Group::play()
{
    for (iterator it = begin(); it != end(); it++)
        (*it)->play();
}
