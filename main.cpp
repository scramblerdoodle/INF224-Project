#include <iostream>

#include "Image.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
using namespace std;

int main(int argc, const char* argv[])
{
    shared_ptr<Group> group(new Group("Group test"));
    
    int* chaptersSkeleton(new int[2]{0, 12});
    shared_ptr<Film> film(new Film("skeleton", "/media/orlando/Files/Videos/webm/attack helicopter invades peaceful skeleton realm.mp4", 23, chaptersSkeleton));
    delete [] chaptersSkeleton;

    shared_ptr<Image> image(new Image("jolly", "/media/orlando/Files/Pictures/157899859_284324719767687_2825453359009430038_n.jpg", 500, 500));

    group->push_back(film);
    group->push_back(image);
    for (auto& it : *group)
    {
        it->print(cout);
        // group[i]->play();
        cout << endl;
    }

    return 0;
}
