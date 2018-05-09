/*
+-----------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			|
|	  Nom du Fichier : PointInteret.cpp									|
|     Personnes : Takfarinas Kebci, Yann Nebout							|
|     Objectif(s) du programme : Programme principale pour les test		|
|	  Date de Début : 26 Février 2018									|
|	  Date de la dernière modification : 12 Mars 2018					|
+-----------------------------------------------------------------------+
*/

#include "PointInteret.hpp"

// Utilisation des espaces de noms std et opencv
using namespace std;

//	Constructeurs
PointInteret::PointInteret(Image im1, Image im2, std::vector<Points> p1, std::vector<Points> p2){
	imageRef = im1;
	imageEtu = im2;
	pointsRef = p1;
	pointsEtu = p2;

	taille = 3;
	type = 1;

	masqueRef = Matrice(taille,taille);
	masqueEtu = Matrice(taille,taille);
}

PointInteret::PointInteret(Image im1, Image im2, std::vector<Points> p1, std::vector<Points> p2, int tailleF){
	imageRef = im1;
	imageEtu = im2;
	pointsRef = p1;
	pointsEtu = p2;

	taille = tailleF;
	type = 1;

	masqueRef = Matrice(taille,taille);
	masqueEtu = Matrice(taille,taille);
}

PointInteret::PointInteret(Image im1, Image im2, std::vector<Points> p1, std::vector<Points> p2, int tailleF, int typeF){
	imageRef = im1;
	imageEtu = im2;
	pointsRef = p1;
	pointsEtu = p2;

	taille = tailleF;
	type = typeF;

	masqueRef = Matrice(taille,taille);
	masqueEtu = Matrice(taille,taille);
}

//	Destructeur
PointInteret::~PointInteret(){}

//	Getters
vector<vector<Points> > PointInteret::getPointCorr(){ return pointsApparies; }
Points PointInteret::getPointCorrelation(int i, int j){ return  pointsApparies[i][j]; }

//	Fonctions
void PointInteret::assigneMasque(int mask, Points p){
	int k,l;

	if (mask == 1){
		for (k=0 ; k<taille ; k++){
			for (l=0 ; l<taille ; l++){
				masqueRef.setValeur(k,l,imageRef.getValeurGRAY(p.getX()-2+k,p.getY()-2+l));
			}
		}
	}
	if (mask == 2){
		for (k=0 ; k<taille ; k++){
			for (l=0 ; l<taille ; l++){
				masqueEtu.setValeur(k,l,imageEtu.getValeurGRAY(p.getX()-2+k,p.getY()-2+l));
			}
		}
	}
}

double PointInteret::moyenne(int mask){
	int i, j;
	double res = 0;

	for (i=0 ; i<taille ; i++){
		for (j=0 ; j<taille ; j++){
			if (mask == 1)
				res += masqueRef.getValeur(i,j)/double(taille*taille);
			if (mask == 2)
				res += masqueEtu.getValeur(i,j)/double(taille*taille);
		}
	}

	return res;
}

double PointInteret::somme(int moy, int mask){
	int i,j;
	double value=0;

	for (i=0 ; i<taille ; i++){
		for (j=0 ; j<taille ; j++){
			if (mask == 1)
				value += (masqueRef.getValeur(i,j)-moy)*(masqueRef.getValeur(i,j)-moy);
			if (mask == 2)
				value += (masqueEtu.getValeur(i,j)-moy)*(masqueEtu.getValeur(i,j)-moy);
		}
	}

	return value;
}

double PointInteret::norme(int mask, double moy){
	double n, value;

	value = somme(moy, mask);

	n = sqrt(value);

	return n;
}

double PointInteret::choixType(){
	switch (type){
		case 6:
			return ZNCC();
		case 5:
			return NCC();
		case 4:
			return ZSAD();
		case 3:
			return SAD();
		case 2:
			return ZSSD();
		case 1:
			return SSD();
		default :
			return SSD();
	}
}

void PointInteret::correlation(){
	uint i,j;
	double app = 0;

	for (i=0 ; i<pointsRef.size() ; i++){
		assigneMasque(1,pointsRef[i]);
		for (j=0 ; j<pointsEtu.size() ; j++){
			assigneMasque(2,pointsEtu[j]);
			appariement(i, j, &app);
		}
	}
}

void PointInteret::appariement(int i, int j, double *app){
	double corr;
	vector <Points> v;
	corr = choixType();

	if(pointsApparies.size() == 0){
		v.push_back(pointsRef[i]);
		v.push_back(pointsEtu[j]);
		pointsApparies.push_back(v);
		*app = corr;
	}
	else{
		if(i!=0 && *app==0){
			v.push_back(pointsRef[i]);
			v.push_back(pointsEtu[j]);
			pointsApparies.push_back(v);
			*app = corr;
		}
		if(*app<corr && *app!=0){
			v[1] = pointsEtu[j];
		}
	}
}

//	Algorithme d'appariement
double PointInteret::SSD(){
	double res;
	int i,j;

	//	calcul des coefficients de la division
	for(i=0 ; i<taille ; i++){
		for(j=0 ; j<taille ; j++){
			res += (masqueRef.getValeur(i,j)-masqueEtu.getValeur(i,j))*(masqueRef.getValeur(i,j)-masqueEtu.getValeur(i,j));
		}
	}

	return res;
}

double PointInteret::ZSSD(){
	double res, irm, iem;
	int i,j;

	//	calcul des moyennes
	irm = moyenne(1);
	iem = moyenne(2);

	//	calcul des coefficients de la division
	for(i=0 ; i<taille ; i++){
		for(j=0 ; j<taille ; j++){
			res += ((masqueRef.getValeur(i,j)-irm)-(masqueEtu.getValeur(i,j)-iem))*((masqueRef.getValeur(i,j)-irm)-(masqueEtu.getValeur(i,j)-iem));
		}
	}

	return res;
}

double PointInteret::SAD(){
	double res;
	int i,j;

	//	calcul des coefficients de la division
	for(i=0 ; i<taille ; i++){
		for(j=0 ; j<taille ; j++){
			res += abs(masqueRef.getValeur(i,j)-masqueEtu.getValeur(i,j));
		}
	}

	return res;
}

double PointInteret::ZSAD(){
	double res,iem,irm;
	int i,j;

	//	calcul des moyennes
	irm = moyenne(1);
	iem = moyenne(2);

	//	calcul des coefficients de la division
	for(i=0 ; i<taille ; i++){
		for(j=0 ; j<taille ; j++){
			res += abs(masqueRef.getValeur(i,j)-irm-masqueEtu.getValeur(i,j)+iem);
		}
	}

	return res;
}

double PointInteret::NCC(){
	double res,num=0,den1,den2,den;
	int i,j;

	//	calcul des coefficients de la division
	for(i=0 ; i<taille ; i++){
		for(j=0 ; j<taille ; j++){
			num += (masqueRef.getValeur(i,j))*(masqueEtu.getValeur(i,j));
		}
	}
	den1 = norme(1,0);
	den2 = norme(2,0);
	den = den1*den2;

	res = num/den;

	return res;
}

double PointInteret::ZNCC(){
	double res,iem,irm,num=0,den1,den2,den;
	int i,j;

	//	calcul des moyennes
	irm = moyenne(1);
	iem = moyenne(2);

	//	calcul des coefficients de la division
	for(i=0 ; i<taille ; i++){
		for(j=0 ; j<taille ; j++){
			num += (masqueRef.getValeur(i,j)-irm)*(masqueEtu.getValeur(i,j)-iem);
		}
	}
	den1 = norme(1,irm);
	den2 = norme(2,iem);
	den = den1*den2;

	res = num/den;

	return res;
}