/*
+-----------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			|
|	  Nom du Fichier : Fonction.hpp										|
|     Personnes : Takfarinas Kebci, Yann Nebout							|
|     Objectif(s) du programme : mettre toutes les fonctions utiles		|
|	  Date de Début : 21 Février 2018									|
|	  Date de la dernière modification : 14 Mars 2018					|
+-----------------------------------------------------------------------+
*/

#include "Fonction.hpp"

// Utilisation des espaces de noms std et opencv
using namespace std;
using namespace cv;

double convolution(Matrice noyau, Matrice masque){
	int i,j;
	double res=0;

	// Produit de convolution discret
	for(i=0 ; i<noyau.getLigne() ; i++){
		for(j=0 ; j<noyau.getColonne() ; j++){
			res += masque.getValeur(i,j)*noyau.getValeur(i,j);
		}
	}

	return res;
}

void copieTab(int taille, double dest[], double src[]){
	int i;

	for (i=0;i<taille;i++){ // Copiage d'un tableau dans un autre
		dest[i] = src[i];
	}
}

void tri(int taille, double tab[]){
	int i,l;
	double val;

	for (i=0;i<taille;i++){
		l=i;
		if (l!=0){
			while(tab[l]<tab[l-1] && l>0){ // On vérifie que la valeur l est inférieur à la valeur l-1
				val = tab[l-1];
				tab[l-1] = tab[l];
				tab[l] = val;
				l--;
			}	
		}
	}
}