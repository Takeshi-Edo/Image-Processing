/*
+------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			 |
|	  Nom du Fichier : Gradient.cpp										 |
|     Personnes : Takfarinas Kebci, Yann Nebout							 |
|     Objectif(s) du programme : Réalise les filtrages sur une image     |
|	  Date de Début : 26 Février 2018									 |
|	  Date de la dernière modification : 20 Mars 2018					 |
+------------------------------------------------------------------------+
*/

#include "Gradient.hpp"

// Utilisation des espaces de noms std et opencv
using namespace std;
using namespace cv;

//	Constructeurs
Gradient::Gradient(){
	taille = 3;	
	seuil = 0;
	choixNoyau(0);
	initArg();
}

Gradient::Gradient(Image image, int typeF){
	image_init = image;
	image_filt = Image(image_init.getLigne(),image_init.getColonne());
	taille = 3;
	seuil = 0;

	noyau = Matrice(taille, taille);
	noyau2 = Matrice(taille, taille);
	masque = Matrice(taille, taille);

	choixNoyau(typeF);
	initArg();
}

Gradient::Gradient(Image image, int typeF, double seuilF){
	image_init = image;
	image_filt = Image(image_init.getLigne(),image_init.getColonne());
	taille = 3;
	seuil = seuilF;

	noyau = Matrice(taille, taille);
	noyau2 = Matrice(taille, taille);
	masque = Matrice(taille, taille);

	choixNoyau(typeF);
	initArg();
}

Gradient::Gradient(const Gradient& g){
	image_init = g.image_init;
	image_filt = g.image_filt;
	taille = g.taille;
	seuil = g.seuil;

	noyau = g.noyau;
	noyau2 = g.noyau2;
	masque = g.masque;

	type = g.type;
	argument = g.argument;
}

//	Destructeur
Gradient::~Gradient(){}

//	Getters
double Gradient::getSeuil(){ return seuil; }

double Gradient::getCaseArgument(int i, int j){ return argument[i][j]; }

vector<vector<double> > Gradient::getArgument(){ return argument; }

//	Setters
void Gradient::setSeuil(double seuilF){ seuil = seuilF; }
void Gradient::setArg(int i, int j, double val){ argument[i][j] = val; }

//	Fonctions
void Gradient::initArg(){
	int i,j;

	for(i=0 ; i<image_init.getLigne() ; i++){
		vector<double> v;
		for(j=0 ; j<image_init.getColonne() ; j++){
			v.push_back(0);
		}
		argument.push_back(v);
	}
}

void Gradient::choixNoyau(int typeF){
	if(typeF == 0){
		type = "prewitt";
		noyauPrewitt();
	}
	else{
		type = "sobel";
		noyauSobel();
	}
}

void Gradient::noyauPrewitt(){
	int i,j=0;

	for(i=0 ; i<3 ; i++){
		if (i%2 == 0){
			if (i==0){
				noyau.setValeur(i,0,-1);
				noyau.setValeur(i,1,-2);
				noyau.setValeur(i,2,-1);
			}
			else{
				noyau.setValeur(i,0,1);
				noyau.setValeur(i,1,2);
				noyau.setValeur(i,2,1);
			}
		}
	}

	for(j=0 ; j<3 ; j++){
		if (j%2 == 0){
			if (j==0){
				noyau2.setValeur(0,j,-1);
				noyau2.setValeur(1,j,-2);
				noyau2.setValeur(2,j,-1);
			}
			else{
				noyau2.setValeur(0,j,1);
				noyau2.setValeur(1,j,2);
				noyau2.setValeur(2,j,1);
			}
		}
	}
}

void Gradient::noyauSobel(){
	int i,j;

	for(i=0 ; i<3 ; i++){
		noyau.setValeur(i,0,-1);
		noyau.setValeur(i,2,1);
	}

	for(j=0 ; j<3 ; j++){
		noyau2.setValeur(0,j,-1);
		noyau2.setValeur(2,j,1);
	}
}

void Gradient::filtreGradient(){
	int i,j;
	double Gx, Gy, G;

	for (i=0 ; i<image_init.getLigne() ; i++){
		for (j=0 ; j<image_init.getColonne() ; j++){
			extractionMask(i,j);
			Gx = convolution(noyau,masque);
			Gy = convolution(noyau2,masque);
			G = sqrt(Gx*Gx+Gy*Gy);
			image_filt.setValeur(i,j,G); // Calcul du pixel (i,j) de l'image filtré
			argument[i][j] = atan2(Gy,Gx)*180/M_PI;
		}
	}
}

void Gradient::seuillage(){
	int i,j;

	for (i=0 ; i<image_filt.getLigne() ; i++){
		for (j=0 ; j<image_filt.getColonne() ; j++){
			if (image_filt.getValeurGRAY(i,j)<seuil)
				image_filt.setValeur(i,j,0); // Calcul du pixel (i,j) de l'image filtré
		}
	}
}