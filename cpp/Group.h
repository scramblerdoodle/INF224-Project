#ifndef GROUP_H
#define GROUP_H

#include "Multimedia.h"
#include <list>

using namespace std;
class Group : public list<MediaPtr>
{
    private:
        string _name;
    
    public:

        // Constructors
        Group() : list<MediaPtr>() {};
        Group(string name) : list<MediaPtr>() { _name = name; };

        // Destructor
        ~Group() {};

        // Getters
        string getName() { return _name; };

        void print(ostream& s);
};
typedef shared_ptr<Group> GroupPtr;
#endif