#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <string>

using namespace std;
class Multimedia {
    private:
        string m_name;
        string m_pathname;

    public:
        Multimedia(string name, string pathname);

        void setName(string name);
        void setPath(string pathname);

        string getName() { return m_name; }
        string getPath() { return m_pathname; }
};
#endif