#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <string>

using namespace std;
class Multimedia {
    private:
        string name;
        string pathname;

    public:
        Multimedia(string name, string pathname);

        void setName(string name);
        void setPath(string pathname);

        string getName() { return name; }
        string getPath() { return pathname; }
};
#endif