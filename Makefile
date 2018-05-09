#####################################################################
#     Projet : Aide à la maitenance en réalité augmentée     	    #
#     Nom du Fichier : Makefile									 	#
#     Personnes : Takfarinas Kebci, Yann Nebout						#
#     Objectif(s) du programme : utiliser la caméra avec OpenCV     #
#	  Date de Début : 26 Février 2018								#
#	  Date de la dernière modification : 15 Mars 2018				#
#####################################################################

CC=gcc
PP=g++

SRCDIR=Src
HEADDIR=Include
# Option de compilation : 
#	 Wall : affiche les warnings
#	 Werror : warning = erreur
#	 Wextra : Ajoute des warning specifique en plus a Wall
#	 g : analyse gdb & valgrind
CXXFLAGS= -I$(HEADDIR) -Wall -cpp
LIBS= -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_video -lopencv_objdetect

# Executable
EXEC = test

# Où trouver les différents sources *.cpp qu'il faudra compiler pour créer les objets correspondants
SRC= $(wildcard $(SRCDIR)/*.cpp)
OBJ= $(SRC:$(SRCDIR)/%.cpp=%.o)

all: $(EXEC) .PHONY

test: test.o Image.o Filtre.o Gradient.o FiltreMedian.o FiltreMoyenneur.o FiltreGauss.o Laplace.o FiltreCanny.o Harris.o Moravec.o Points.o Matrice.o Fonction.o PointInteret.o
	$(PP) -o $@  $^ $(CXXFLAGS) $(LIBS)

# Création des différents *.o à partir des *.cpp
%.o: $(SRCDIR)/%.cpp
	$(PP) -o $@ -c $< $(CXXFLAGS) -std=c++0x
	
clean:
	rm -rf *.o *~
	
vclean:
	rm -rf $(EXEC)
	
.PHONY: clean
