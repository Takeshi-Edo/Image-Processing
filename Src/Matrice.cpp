/*
+-------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			  |
|	  Nom du Fichier : Matrice.cpp										  |
|     Personnes : Takfarinas Kebci, Yann Nebout							  |
|     Objectif(s) du programme : réaliser les calculs sur une matrice     |
|	  Date de Début : 26 Février 2018									  |
|	  Date de la dernière modification : 15s Mars 2018					  |
+-------------------------------------------------------------------------+
*/

//	Avec rajout du produit de matrice car potentiellement utile 

#include "Matrice.hpp"

// Utilisation des espaces de noms std et opencv
using namespace std;
using namespace cv;

// Constructeurs
Matrice::Matrice(){
	ligne = 0;
	colonne = 0;
	determinant = 0;
	trace = 0;
}

Matrice::Matrice(int largeur, int hauteur){
	ligne = hauteur;
	colonne = largeur;
	determinant = 0;
	trace = 0;

	if (ligne == colonne)
		carre = true;

	int i,j;
	for (i=0 ; i<ligne ; i++){
		vector<double > v;
		for (j=0 ; j<colonne ; j++){
			v.push_back(0);
		}
		matrice.push_back(v);
	}
}

Matrice::Matrice(vector<vector<double> > mat){
	ligne = mat.size();
	colonne = mat[0].size();
	determinant = 0;
	trace = 0;

	if (ligne == colonne)
		carre = true;

	int i,j;
	for (i=0 ; i<ligne ; i++){
		vector<double > v;
		for (j=0 ; j<colonne ; j++){
			v.push_back(mat[i][j]);
		}
		matrice.push_back(v);
	}
}

Matrice::Matrice(const Matrice& m){
	ligne = m.ligne;
	colonne = m.colonne;
	carre = m.carre;
	matrice = m.matrice;
	determinant = m.determinant;
	trace = m.trace;
}

// Destructeur
Matrice::~Matrice(){}

// Getters
double Matrice::getValeur(int i, int j) const{ return matrice[i][j]; }
double Matrice::getTrace() const{ return trace; }
double Matrice::getDeterminant() const{ return determinant; }
int Matrice::getLigne() const{ return ligne; }
int Matrice::getColonne() const{ return colonne; }

// Setters
void Matrice::setValeur(int i, int j, double val){ matrice[i][j] = val; }
void Matrice::setDimension(int hauteur, int largeur){ ligne = hauteur; colonne = largeur; }

// Fonctions
bool Matrice::estCarre(){
	if (carre==true)
		return true;
	else
		return false;
}

void Matrice::calculTrace(){
	int i,j;
	trace = 0;
	if (estCarre() == true){	// Test sur les dimensions de la matrice
		for (i=0 ; i< ligne ; i++){
			for (j=0 ; j< colonne ; j++){
				if (i == j)		// On prend les valeurs de la diagonale
					trace += matrice[i][j];
			}
		}
	}
}

void Matrice::copiemMatrice(int taille, Matrice &dest, int l){
	vector<vector<double> > m; // Tableau 2 dimensions intermédiaire pour le copiage
	int i,j;

	for (i=1 ; i<ligne ; i++){ // Récupération des valeurs d'une partie du tableau 
		vector<double> v;
		for (j=0 ; j<colonne ; j++){
			if(j!=l){
				v.push_back(matrice[i][j]);
			}
		}
		m.push_back(v);
	}

	int li = m.size(),co = m[0].size(); // Copiage dans la matrice de destination
	for(i=0 ; i<li ; i++){
		for(j=0 ; j<co ; j++){
			dest.setValeur(i,j,m[i][j]);
		}
	}
}

void Matrice::calculDeterminant(){
	int i,taille = ligne-1;
	double val;

	if (estCarre() == true) {	// Test sur les dimensions de la matrice
		Matrice destination(taille,taille);
		if (ligne == 2)		// Calcul du déterminant pour une matrice 2*2
			determinant = matrice[0][0]*matrice[1][1]-matrice[0][1]*matrice[1][0];
		else{	// Calcul du déterminant pour une matrice n*n
			for (i=0 ; i<colonne ; i++){
				copiemMatrice(taille, destination, i);	// On copie une partie de la matrice
				destination.calculDeterminant();	// Calcul du déterminant de la matrice (n-1)*(n-1)
				if (i%2==0)	// Test pour savoir si le signe du résultat est négatif ou positif
					val = matrice[0][i]*destination.getDeterminant();
				else
					val = -matrice[0][i]*destination.getDeterminant();
				determinant += val;
			}
		}
	}
}