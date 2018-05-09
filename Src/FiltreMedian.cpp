/*
+---------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			    |
|	  Nom du Fichier : FiltreMedian.cpp									    |
|     Personnes : Takfarinas Kebci, Yann Nebout							    |
|     Objectif(s) du programme : Réalise le filtre median sur une image     |
|	  Date de Début : 26 Février 2018									    |
|	  Date de la dernière modification : 19 Mars 2018					    |
+---------------------------------------------------------------------------+
*/

// 	Le filtre de canny sera dans une nouvelle classe appelée Contour dans laquelle il y aura 2 filtres et que réalisera l'opérations de contours et de seuillage
// 	Une autre classe sera faite pour faire le traitement d'image avec comparaison des points d'intérêts

#include "FiltreMedian.hpp"

// Utilisation des espaces de noms std et opencv
using namespace std;
using namespace cv;

//	Constructeurs
FiltreMedian::FiltreMedian(){
	type = "Median";
}

FiltreMedian::FiltreMedian(Image image, int tailleF){
	type = "Median";
	image_init = image;
	image_filt = Image(image_init.getLigne(),image_init.getColonne());
	taille = tailleF;

	noyau = Matrice(taille, taille);
	masque = Matrice(taille, taille);
}

FiltreMedian::FiltreMedian(const FiltreMedian& m){
	type = m.type;
	taille = m.taille;

	image_init = m.image_init;
	image_filt = m.image_filt;

	masque = m.masque;
}

//	Destructeur	
FiltreMedian::~FiltreMedian(){}

//	Fonctions
void FiltreMedian::filtreMedian(){
	int i,j;
	double res;
	for (i=0 ; i<image_init.getLigne() ; i++){
		for (j=0 ; j<image_init.getColonne() ; j++){
			extractionMask(i,j);
			res = calculMedianne();
			image_filt.setValeur(i,j,res); // Calcul du pixel (i,j) de l'image filtré
		}
	}
}

double FiltreMedian::calculMedianne(){
	int i, j, l = masque.getLigne(), c = masque.getColonne();
	int taille = l*c;
	int moitie = (taille+1)/2; // Case du milieu car il y a un nombre impaire d'éléments
	double res, med[taille];
	for(i=0 ; i<l ; i++){
		for(j=0 ; j<c ; j++){
			med[i*l+j] = masque.getValeur(i,j);
		}
	}

	tri(taille,med); // Tri des valeurs dans l'ordre croissant

	res = med[moitie]; // Extraction de la valeur médianne

	return res;
}