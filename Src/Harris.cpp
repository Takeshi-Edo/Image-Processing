/*
+-----------------------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     							  |
|	  Nom du Fichier : Harris.cpp														  |
|     Personnes : Takfarinas Kebci, Yann Nebout							  				  |
|     Objectif(s) du programme : réaliser le détecteur de points d'intérêts de Harris     |
|	  Date de Début : 26 Février 2018									  				  |
|	  Date de la dernière modification : 21 Mars 2018					  				  |
+-----------------------------------------------------------------------------------------+
*/

#include "Harris.hpp"

using namespace std;

//	Constructeurs
Harris::Harris(){
	seuil = 0;
	masque = Matrice(3,3);
	pc = 0.05;
	hess = Matrice(2,2);
}

Harris::Harris(Image imageF){
	image = imageF;
	seuil = 0;
	masque = Matrice(3,3);
	pc = 0.05;
	hess = Matrice(2,2);
}

Harris::Harris(Image imageF, double seuilF){
	image = imageF;
	seuil = seuilF;
	masque = Matrice(3,3);
	pc = 0.05;
	hess = Matrice(2,2);
}

Harris::Harris(Image imageF, double seuilF, double c){
	image = imageF;
	seuil = seuilF;
	masque = Matrice(3,3);
	pc = c;
	hess = Matrice(2,2);
}

//	Destructeur
Harris::~Harris(){}

//	Getters
Points Harris::getPointInt(int i){ return points[i]; }
vector<Points> Harris::getPoint(){ return points; }
double Harris::getSeuil (){ return seuil; }
double Harris::getC (){ return pc; }

//	Setters
void Harris::setSeuil(double seuilF){ seuil = seuilF; }
void Harris::setC(double c){ pc = c; }

// 	Fonctions

void Harris::hessienne(){	//	H est égale au multiplication des dérivées première soit pour Ix = I(x+1,y)-I(x,y), Iy = I(x,y+1)-I(x,y)
	hess.setValeur(0,0,(masque.getValeur(2,1)-masque.getValeur(1,1)*(masque.getValeur(2,1)-masque.getValeur(1,1))));
	hess.setValeur(1,0,(masque.getValeur(2,1)-masque.getValeur(1,1)*(masque.getValeur(1,2)-masque.getValeur(1,1))));
	hess.setValeur(0,1,(masque.getValeur(2,1)-masque.getValeur(1,1)*(masque.getValeur(1,2)-masque.getValeur(1,1))));
	hess.setValeur(1,1,(masque.getValeur(1,2)-masque.getValeur(1,1)*(masque.getValeur(1,2)-masque.getValeur(1,1))));
}

void Harris::extractionMask(int l, int c){
	int t = (masque.getLigne()-1)/2;
	int a,b;

	for(a=l-t ; a<l+t+1 ; a++){
		for(b=c-t ; b<c+t+1 ; b++){
			masque.setValeur(a-(l-t),b-(c-t),image.getValeurGRAY(a,b));
		}
	}
}

double Harris::calculH(){
	double H;
	hessienne();
	hess.calculDeterminant();
	hess.calculTrace();

	H = hess.getDeterminant() - pc*hess.getTrace()*hess.getTrace();

	return H;
}

void Harris::detection(){
	int i,j;
	Points p;
	for (i=1 ; i<image.getLigne()-1 ; i++){
		for (j=1 ; j<image.getColonne()-1 ; j++){
			extractionMask(i,j);
			if (estInteressant()==true){
				p = Points(i,j);
				points.push_back(p);
			}
		}
	}
}

bool Harris::estInteressant(){
	bool pt_interet = true;

	if(calculH()<seuil)
		pt_interet = false;

	return pt_interet;
}
