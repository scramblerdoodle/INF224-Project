# INF224 Project
## Pedro ORLANDO
Project for Télécom Paris' course INF224 - Programmation Paradigms.  
To run the project, go into the `cpp` folder and run `make run` on a terminal to start the server-side. It's also possible to run `make run-client` to start the C++ client-side, or even `make run-local` to run the code locally rather than splitting it into server-side/client-side.

For the Java part, it's a GUI in Swing which acts as an interactive client-side application. To run it, one just needs to go into the `swing` folder and run `make run`.

As for the questions specified in the [TP page](https://perso.telecom-paristech.fr/elc/cpp/TP-C++.html), here is a quick description of what was done:
### Question 1
The code was entirely written in my personal computer, running an Ubuntu 20.04, using the VSCode IDE, and tested on Télécom Paris' computers after it was done.

### Question 2
The files `main.cpp` and `Makefile` were created, as well as the base class defined in `Multimedia.h`.

### Question 3
Well... the code was tested at literally every step of the way, so... yeah. Not much to say about this.

### Question 4
`Photo` and `Video` classes created, inherited from `Multimedia`. The main difference in the final code from this part and when I first wrote it is that I was using the `eog` and `vlc` commands to open Photos and Videos, respectivelly.

### Question 5
`Multimedia` list was created, containing the pointers to the specific `Photo` and `Video` objects, allowing for generic treatment of both (running, for example, a loop over the list of Multimedias and calling the `print()` or `play()` methods for each object thanks to polymorphism).  

### Question 6
`Film` subclass created, inheriting from `Video`. In order to properly allocate the memory for the `chapters` attribute, we need to deep-copy the list rather than just running a shallow copy on the pointer for the list.

### Question 7
Destructors were implemented (though they were already implemented when their respective classes were created). Extra attention was made to the classes that have their own objects as attributes (e.g. `Film`'s `chapters`)

### Question 8
`Group` class was implemented, containing a list of pointers to the objects in the `Group` without creating a deep copy of the objects, but rather just a shallow copy of them, to avoid future memory problems.

### Question 9
God bless smart pointers.

### Question 10
`Map` class was implemented (not the best name for the class, I realise that now, but at the time I couldn't think of a better name), whose objective is to have a general control over the `Multimedia` and `Group` maps, with methods allowing one to add a new multimedia (image, video, film) or group, print and play a specific multimedia object, or all elements in a group, as well as delete some saved object.

### Question 11
Client/server code adapted from the file given by the professor, allowing for printing/playing medias or groups. My idea was to also implement the commands to `search` objects, `add` a new object/group, `remove` some object/group and `edit` an existing object/group. As well as `save` these edits on a file (`media.txt`).  
P.S.: these commands can be a massive security problem without the proper care.

### Question 12
An external file was added (`media.txt`) containing a mutable database of the options in the program (for example we have `jolly.png` and `skeleton.mp4` files, and their respective references, details, etc to initialise them stored in `media.txt`). Again, the idea was for the user to be able to edit/overwrite the lines in this text file from the client-side.

### Question 13
No try/catch commands were added in the project, but rather I tried treating most of the edge cases during the process of creating the objects.
