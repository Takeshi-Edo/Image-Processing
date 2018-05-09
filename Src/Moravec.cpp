/*
+------------------------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     							   |
|	  Nom du Fichier : Moravec.cpp														   |
|     Personnes : Takfarinas Kebci, Yann Nebout							  				   |
|     Objectif(s) du programme : réaliser le détecteur de points d'intérêts de Moravec     |
|	  Date de Début : 26 Février 2018									  				   |
|	  Date de la dernière modification : 21 Mars 2018					  				   |
+------------------------------------------------------------------------------------------+
*/

#include "Moravec.hpp"

using namespace std;

//	Constructeurs
Moravec::Moravec(){
	seuil = 0;
	masque = Matrice(5,5);
}

Moravec::Moravec(Image imageF){
	image = imageF;
	seuil = 0;
	masque = Matrice(5,5);
}

Moravec::Moravec(Image imageF, double seuilF){
	image = imageF;
	seuil = seuilF;
	masque = Matrice(5,5);
}

//	Destructeur
Moravec::~Moravec(){}

//	Getters
Points Moravec::getPointInt(int i){ return points[i]; }
vector<Points> Moravec::getPoint(){ return points; }
double Moravec::getSeuil (){ return seuil; }

//	Setters
void Moravec::setSeuil(double seuilF){ seuil = seuilF; }

// 	Fonctions
void Moravec::extractionMask(int l, int c){
	int t = (masque.getLigne()-1)/2;
	int a,b;

	for(a=l-t ; a<l+t+1 ; a++){
		for(b=c-t ; b<c+t+1 ; b++){
			masque.setValeur(a-(l-t),b-(c-t),image.getValeurGRAY(a,b));
		}
	}
}

double Moravec::calculE(int dx, int dy){
	double I,dI,IdI,E=0;
	int i, j;

	for (i=1; i<4; i++){
		for (j=1; j<4 ; j++){
			I = masque.getValeur(i,j)*masque.getValeur(i,j);
			dI = masque.getValeur(i+dx,j+dy)*masque.getValeur(i+dx,j+dy);
			IdI = 2*masque.getValeur(i+dx,j+dy)*masque.getValeur(i,j);

			E += I+dI-IdI;
		}
	}

	return E;
}

void Moravec::detection(){
	int i,j;
	Points p;

	for (i=2 ; i<image.getLigne()-2 ; i++){
		for (j=2 ; j<image.getColonne()-2 ; j++){
			extractionMask(i,j);
			if (estInteressant()==true){
				p = Points(i,j);
				points.push_back(p);
			}
		}
	}
}

bool Moravec::estInteressant(){
	bool pt_interet = true;
	double E[8];
	int i,j,k=0;

	for (i=-1 ; i<2 ; i++){
		for (j=-1 ; j<2 ; j++){
			if (i==0 && j==0)
				j++;
			E[k] = calculE(i,j);
			k++;
		}
	}

	for(k=0 ; k<8 ; k++){
		if(E[k]<seuil)
			pt_interet = false;
	}

	return pt_interet;
}
