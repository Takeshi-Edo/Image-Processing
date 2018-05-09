/*
+-----------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			 	  |
|	  Nom du Fichier : FiltreGauss.cpp									 	  |
|     Personnes : Takfarinas Kebci, Yann Nebout							 	  |
|     Objectif(s) du programme : Réalise le filtre gaussien sur une image     |
|	  Date de Début : 26 Février 2018										  |
|	  Date de la dernière modification : 19 Mars 2018					 	  |
+-----------------------------------------------------------------------------+
*/

#include "FiltreGauss.hpp"

// Utilisation des espaces de noms std et opencv
using namespace std;
using namespace cv;

//	Constructeurs
FiltreGauss::FiltreGauss(){
	sigma = SIGMA;
	type = "Gauss";
}

FiltreGauss::FiltreGauss(Image image){
	type = "Gauss";
	image_init = image;
	image_filt = Image(image_init.getLigne(),image_init.getColonne());
	taille = 3;

	noyau = Matrice(3, 3);
	masque = Matrice(3, 3);

	noyauGauss();
}

FiltreGauss::FiltreGauss(Image image, int tailleF){
	type = "Gauss";
	taille = tailleF;

	image_init = image;
	image_filt = Image(image_init.getLigne(),image_init.getColonne());

	noyau = Matrice(taille, taille);
	masque = Matrice(taille, taille);

	noyauGauss();
}

FiltreGauss::FiltreGauss(Image image, int tailleF, double sigmaF){
	type = "Gauss";	
	taille = tailleF;
	sigma = sigmaF;

	ecartType();

	image_init = image;
	image_filt = Image(image_init.getLigne(),image_init.getColonne());

	noyau = Matrice(taille, taille);
	masque = Matrice(taille, taille);

	noyauGauss();
}

FiltreGauss::FiltreGauss(const FiltreGauss& g){
	type = g.type;
	taille = g.taille;
	sigma = g.sigma;
	image_init = g.image_init;
	image_filt = g.image_filt;
	noyau = g.noyau;
	masque = g.masque;
}

//	Destructeur
FiltreGauss::~FiltreGauss(){}

//	Getters
double FiltreGauss::getSigma() const{ return sigma; }


//	Setters
void FiltreGauss::setSigma(double sigmaF){ sigma = sigmaF; }

//	Fonctions
void FiltreGauss::ecartType(){
	if (sigma == 0) // si sigma est égal à 0 alors on prend un valeur prédéfinie
		sigma = SIGMA;
}

void FiltreGauss::noyauGauss(){
	int sous = (masque.getLigne()-1)/2;
	double denominateur;
	double val[masque.getLigne()][masque.getLigne()],sum=0;

	ecartType(); // Fonction de vérification de sigma
	denominateur = 2*sigma*sigma;

	for (int i=0 ; i<masque.getLigne() ; i++){
		for (int j=0 ; j<masque.getLigne() ; j++){
			val[i][j] = exp(-((i-sous)*(i-sous)+(j-sous)*(j-sous))/(denominateur))/(denominateur*M_PI); // Calcul de la valeur d'une case du noyau
			sum += val[i][j];
		}
	}

	// Normalisation (la somme des valeurs de la matrice doit être égale à 1)
	for (int i=0 ; i<masque.getLigne() ; i++){
		for (int j=0 ; j<masque.getLigne() ; j++){
			noyau.setValeur(i,j,val[i][j]/sum);
		}
	}
}

void FiltreGauss::filtrage(){
	int i,j;
	for (i=0 ; i<image_init.getLigne() ; i++){
		for (j=0 ; j<image_init.getColonne() ; j++){
			extractionMask(i,j);
			image_filt.setValeur(i,j,convolution(noyau,masque)); // Calcul du pixel (i,j) de l'image filtré
		}
	}
}