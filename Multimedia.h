#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <string>

using namespace std;
class Multimedia {
    private:
        string _name;
        string _pathname;

    public:
        // Constructor
        Multimedia(string name, string pathname);

        // Instance methods
        void setName(string name);
        void setPath(string pathname);

        string getName() { return _name; }
        string getPath() { return _pathname; }
};
#endif