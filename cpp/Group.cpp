#include "Group.h"
#include <iostream>
using namespace std;

void Group::print(ostream& s){
    for (iterator it = begin(); it != end(); it++)
    {
        (*it)->print(s);
        s << endl;
    }
    
};
