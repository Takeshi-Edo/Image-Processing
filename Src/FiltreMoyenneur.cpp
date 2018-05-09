/*
+------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			 |
|	  Nom du Fichier : FiltreMoyenneur.cpp								 |
|     Personnes : Takfarinas Kebci, Yann Nebout							 |
|     Objectif(s) du programme : Réalise les filtrages sur une image     |
|	  Date de Début : 26 Février 2018									 |
|	  Date de la dernière modification : 19 Mars 2018					 |
+------------------------------------------------------------------------+
*/

// 	Le filtre de canny sera dans une nouvelle classe appelée Contour dans laquelle il y aura 2 filtres et que réalisera l'opérations de contours et de seuillage
// 	Une autre classe sera faite pour faire le traitement d'image avec comparaison des points d'intérêts

#include "FiltreMoyenneur.hpp"

// Utilisation des espaces de noms std et opencv
using namespace std;
using namespace cv;

//	Constructeurs
FiltreMoyenneur::FiltreMoyenneur(){
	moyenne = 0;
	taille = 3;
	type = "Moyenneur";
}

FiltreMoyenneur::FiltreMoyenneur(Image image, int tailleF){
	type = "Moyenneur";
	image_init = image;
	image_filt = Image(image_init.getLigne(),image_init.getColonne());
	taille = tailleF;
	moyenne = 1.0/double(taille*taille);

	cout << moyenne << endl;

	noyau = Matrice(taille, taille);
	masque = Matrice(taille, taille);

	noyauMoyen();
}

FiltreMoyenneur::FiltreMoyenneur(const FiltreMoyenneur& m){
	type = m.type;
	image_init = m.image_init;
	image_filt = m.image_filt;
	taille = m.taille;
	moyenne = m.moyenne;

	noyau = m.noyau;
	masque = m.masque;
}

//	Destructeur
FiltreMoyenneur::~FiltreMoyenneur(){}

//	Getters
double FiltreMoyenneur::getMoyenne(){ return moyenne; }

//	Setters
void FiltreMoyenneur::setMoyenne(double m){ moyenne = m; }

//	Fonctions
void FiltreMoyenneur::noyauMoyen(){
	int i,j;

	for(i=0 ; i<noyau.getLigne() ; i++){
		for(j=0 ; j<noyau.getLigne() ; j++){
			noyau.setValeur(i,j,moyenne);
		}
	}
}

void FiltreMoyenneur::filtrage(){
	int i,j;
	for (i=0 ; i<image_init.getLigne() ; i++){
		for (j=0 ; j<image_init.getColonne() ; j++){
			extractionMask(i,j);
			image_filt.setValeur(i,j,convolution(noyau,masque)); // Calcul du pixel (i,j) de l'image filtré
		}
	}
}