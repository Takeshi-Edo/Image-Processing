/*
+------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			 |
|	  Nom du Fichier : Laplace.cpp										 |
|     Personnes : Takfarinas Kebci, Yann Nebout							 |
|     Objectif(s) du programme : Réalise les filtrages sur une image     |
|	  Date de Début : 26 Février 2018									 |
|	  Date de la dernière modification : 19 Mars 2018					 |
+------------------------------------------------------------------------+
*/

#include "Laplace.hpp"

// Utilisation des espaces de noms std et opencv
using namespace std;
using namespace cv;

//	Constructeurs
Laplace::Laplace(){
	seuil = 0;
	type = "Laplace";
}

Laplace::Laplace(Image image){
	taille = 3;
	seuil = 0;

	image_init = image;
	image_filt = Image(image_init.getLigne(),image_init.getColonne());

	noyau = Matrice(taille, taille);
	masque = Matrice(taille, taille);

	choixNoyau(0);
}

Laplace::Laplace(Image image, int typeF){
	taille = 3;
	seuil = 0;

	image_init = image;
	image_filt = Image(image_init.getLigne(),image_init.getColonne());

	noyau = Matrice(taille, taille);
	masque = Matrice(taille, taille);

	choixNoyau(typeF);
}

Laplace::Laplace(Image image, int typeF, double seuilF){
	taille = 3;
	seuil = seuilF;

	image_init = image;
	image_filt = Image(image_init.getLigne(),image_init.getColonne());

	noyau = Matrice(taille, taille);
	masque = Matrice(taille, taille);

	choixNoyau(typeF);
}

Laplace::Laplace(const Laplace& l){
	type = l.type;
	taille = l.taille;
	seuil = l.seuil;

	image_init = l.image_init;
	image_filt = l.image_filt;

	noyau = l.noyau;
	masque = l.masque;
}

//	Destructeur
Laplace::~Laplace(){}

//	Getters
double Laplace::getSeuil(){ return seuil; }

//	Setters
void Laplace::setSeuil(double seuilF){ seuil = seuilF; }

//	Fonctions
void Laplace::choixNoyau(int typeF){
	if (typeF==0){
		type = "Laplace -4";
		noyauLaplace1();
	}
	else{
		type = "Laplace -8";
		noyauLaplace2();		
	}
}

void Laplace::noyauLaplace1(){
	int i,j;

	for(i=0 ; i<3 ; i++){
		for(j=0 ; j<3 ; j++){
			if(i%2==0 && j%2==0)
				noyau.setValeur(i,j,0);
			else
				noyau.setValeur(i,j,1);

			if (i==1 && j==1)
				noyau.setValeur(i,j,-4);
		}
	}
}

void Laplace::noyauLaplace2(){
	int i,j;

	for(i=0 ; i<3 ; i++){
		for(j=0 ; j<3 ; j++){
			if(i==1 && j==1)
				noyau.setValeur(i,j,-8);
			else
				noyau.setValeur(i,j,1);
		}
	}
}

void Laplace::filtrage(){
	int i,j;
	for (i=0 ; i<image_init.getLigne() ; i++){
		for (j=0 ; j<image_init.getColonne() ; j++){
			extractionMask(i,j);
			image_filt.setValeur(i,j,convolution(noyau,masque)); // Calcul du pixel (i,j) de l'image filtré
		}
	}
}

void Laplace::seuillage(){
	int i,j;
	for (i=0 ; i<image_filt.getLigne() ; i++){
		for (j=0 ; j<image_filt.getColonne() ; j++){
			if (image_filt.getValeurGRAY(i,j)<seuil)
				image_filt.setValeur(i,j,0); // Calcul du pixel (i,j) de l'image filtré
		}
	}
}