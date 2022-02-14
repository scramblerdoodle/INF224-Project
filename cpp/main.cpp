#include <iostream>
#include <vector>
#include <map>

#include "Image.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "Map.h"
using namespace std;

int main(int argc, const char* argv[])
{    

    Map objects("../media.txt");
    cout << endl << "Press q to quit." << endl;
    string name;
    do
    {
        cout << "Choose a media name: ";
        cin >> name;
        if (name != "q")
        {
            objects.print(name, cout);
            objects.play(name);
        }
    } while (name != "q");


    return 0;
}
