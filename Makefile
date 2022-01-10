##########################################
#
#  Makefile
#  Pedro Orlando - Telecom Paris 2022
#  INF224 - TP C++ - http://www.telecom-paristech.fr/~elc/inf224
#
##########################################

#
# Nom du programme
#
PROG=local
CLIENT=client
SERVER=server
CLISERV=cliserv

#
# Fichiers sources (NE PAS METTRE les .h ni les .o seulement les .cpp)
#
SOURCES=Multimedia.cpp Image.cpp Video.cpp Film.cpp Group.cpp Map.cpp main.cpp
CLIENT_SOURCES=client.cpp ccsocket.cpp 
SERVER_SOURCES=server.cpp tcpserver.cpp ccsocket.cpp Multimedia.cpp Image.cpp Video.cpp Film.cpp Group.cpp Map.cpp
CLISERV_SOURCES=client.cpp server.cpp tcpserver.cpp ccsocket.cpp Makefile

#
# Fichiers objets (ne pas modifier sauf si l'extension n'est pas .cpp)
#
OBJETS = ${SOURCES:%.cpp=%.o}
CLIENT_OBJETS=${CLIENT_SOURCES:%.cpp=%.o}
SERVER_OBJETS=${SERVER_SOURCES:%.cpp=%.o}

#
# Compilateur C++
#
CXX = c++

#
# Options du compilateur C++
#   -g pour debugger, -O optimise, -Wall affiche les erreurs, -I pour les headers
#   -std=c++11 pour C++11
# Exemple: CXXFLAGS= -std=c++11 -Wall -O -I/usr/local/qt/include
#
CXXFLAGS = -std=c++11 -Wall -g

#
# Options de l'editeur de liens
#
LDFLAGS = 

#
# Librairies a utiliser
# Exemple: LDLIBS = -L/usr/local/qt/lib -lqt
#
LDLIBS= -lpthread 


##########################################
#
# Regles de construction/destruction des .o et de l'executable
# depend-${PROG} sera un fichier contenant les dependances
#

all: ${PROG} ${CLIENT} ${SERVER}

run-${PROG}: ${PROG}
	./${PROG}

run: ${SERVER}
	./${SERVER}

run-${CLIENT}: ${CLIENT}
	./${CLIENT}

${PROG}: depend-${PROG} ${OBJETS}
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} ${OBJETS} ${LDLIBS}

${CLIENT}: depend-${CLIENT} ${CLIENT_OBJETS}
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} ${CLIENT_OBJETS} ${LDLIBS}

${SERVER}: depend-${SERVER} ${SERVER_OBJETS}
	${CXX} -o $@ ${CXXFLAGS} ${LDFLAGS} ${SERVER_OBJETS} ${LDLIBS}

clean:
	-@$(RM) *.o depend-${PROG} depend-${CLIENT} depend-${SERVER} core 1>/dev/null 2>&1

clean-all: clean
	-@$(RM) ${PROG} -${CLIENT} -${SERVER} 1>/dev/null 2>&1
  
tar:
	tar cvf ${CLISERV}.tar.gz ${CLISERV_SOURCES}

# Gestion des dependances : creation automatique des dependances en utilisant 
# l'option -MM de g++ (attention tous les compilateurs n'ont pas cette option)
#
depend-${PROG}:
	${CXX} ${CXXFLAGS} -MM ${SOURCES} > depend-${PROG}

depend-${CLIENT}:
	${CXX} ${CXXFLAGS} -MM ${CLIENT_SOURCES} > depend-${CLIENT}

depend-${SERVER}:
	${CXX} ${CXXFLAGS} -MM ${SERVER_SOURCES} > depend-${SERVER}

###########################################
#
# Regles implicites
#

.SUFFIXES: .cpp .cxx .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c (CFLAGS) $(INCPATH) -o $@ $<


#############################################
#
# Inclusion du fichier des dependances
#
-include depend-${PROG}
-include depend-${CLIENT}
-include depend-${SERVER}
