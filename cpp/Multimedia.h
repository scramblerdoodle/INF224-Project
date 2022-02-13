#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <string>
#include <memory>

using namespace std;
class Multimedia 
{
    private:
        string _name;
        string _pathname;

    public:
        // Constructors
        Multimedia();
        Multimedia(string name, string pathname);

        // Destructor
        ~Multimedia() {};

        // Setters
        void setName(string name);
        void setPath(string pathname);

        // Getters
        string getName() { return _name; }
        string getPath() { return _pathname; }

        // Print
        virtual void print(ostream &s);

        // Methods
        virtual void play() {};
};
typedef shared_ptr<Multimedia> MediaPtr;
#endif