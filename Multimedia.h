#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <string>

using namespace std;
class Multimedia {
    private:
        string _name;
        string _pathname;

    public:
        // Constructors
        Multimedia();
        Multimedia(string name, string pathname);

        // Destructor
        ~Multimedia();

        // Instance methods
        void setName(string name);
        void setPath(string pathname);

        string getName() { return _name; }
        string getPath() { return _pathname; }
};
#endif