/*
+------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			 |
|	  Nom du Fichier : Filtre.cpp										 |
|     Personnes : Takfarinas Kebci, Yann Nebout							 |
|     Objectif(s) du programme : Réalise les filtrages sur une image     |
|	  Date de Début : 26 Février 2018									 |
|	  Date de la dernière modification : 19 Mars 2018					 |
+------------------------------------------------------------------------+
*/

// 	Le filtre de canny sera dans une nouvelle classe appelée Contour dans laquelle il y aura 2 filtres et que réalisera l'opérations de contours et de seuillage
// 	Une autre classe sera faite pour faire le traitement d'image avec comparaison des points d'intérêts

#include "Filtre.hpp"

// Utilisation des espaces de noms std et opencv
using namespace std;
using namespace cv;

//	Constructeurs
Filtre::Filtre(){
	taille = 3;

	noyau = Matrice(3, 3);
	masque = Matrice(3, 3);
}

Filtre::Filtre(Image image){
	image_init = image;
	image_filt = Image(image_init.getLigne(),image_init.getColonne());
	taille = 3;

	noyau = Matrice(3, 3);
	masque = Matrice(3, 3);
}

Filtre::Filtre(Image image, int tailleF){
	image_init = image;
	image_filt = Image(image_init.getLigne(),image_init.getColonne());

	noyau = Matrice(tailleF, tailleF);
	masque = Matrice(tailleF, tailleF);
}

Filtre::Filtre(const Filtre& f){
	image_init = f.image_init;
	image_filt = f.image_filt;
	taille = f.taille;
	noyau = f.noyau;
	masque = f.masque;
}

//	Destructeur
Filtre::~Filtre(){}

//	Getters
Image Filtre::getImage() const{ return image_filt; }
std::string Filtre::getType() const{ return type; }

void Filtre::setImage(Image image){ image_init = image; }

void Filtre::extractionMask(int l, int c){
	int t = (masque.getLigne()-1)/2;
	int a,b;

	if (l>=t && c>=t && c<image_init.getColonne()-t && l<image_init.getLigne()-t){
		for(a=l-t ; a<l+t+1 ; a++){
			for(b=c-t ; b<c+t+1 ; b++){
				masque.setValeur(a-(l-t),b-(c-t),image_init.getValeurGRAY(a,b));
			}
		}
	}
	else{
		if (l<t && c<t)
			coin(l,c);
		else if (l<t && c>=image_init.getColonne()-t)
			coin(l,c);
		else if (l>=image_init.getLigne()-t && c<t)
			coin(l,c);
		else if (l>=image_init.getLigne()-t && c>=image_init.getColonne()-t )
			coin(l,c);
		else
			bord(l,c);
	}
}

void Filtre::coin(int l, int c){
	int t = (masque.getLigne()-1)/2, a,b, d=t-l, e=t-c ,f=t-1;
	
	for (a=0 ; a<masque.getLigne() ; a++){
		for (b=0 ; b<masque.getColonne() ; b++){
			if(l<t && c<t){
				if ( a<d || b<e )
					masque.setValeur(a,b,0);
				else
					masque.setValeur(a,b,image_init.getValeurGRAY(l-t+a,c-t+b));
			}
			if(l<t && c>=image_init.getColonne()-t){
				if (a<d || b>(image_init.getColonne()-c+f))
					masque.setValeur(a,b,0);
				else
					masque.setValeur(a,b,image_init.getValeurGRAY(l-t+a,c-t+b));
			}
			if(c<t && l>=image_init.getLigne()-t){
			 	if (b<e || a>(image_init.getLigne()-l+f))
			 		masque.setValeur(a,b,0);
			 	else
			 		masque.setValeur(a,b,image_init.getValeurGRAY(l-t+a,c-t+b));
			}
			if(c>=image_init.getColonne()-t && l>=image_init.getLigne()-t){
				if (b>(image_init.getColonne()-c+f) || a>(image_init.getLigne()-l+f))
					masque.setValeur(a,b,0);
				else
					masque.setValeur(a,b,image_init.getValeurGRAY(l-t+a,c-t+b));
			}
		}
	}
}

void Filtre::bord(int l, int c){
	int t = (masque.getLigne()-1)/2, a,b,d=t-l, e=t-c, f=t-1;
	
	for (a=0 ; a<masque.getLigne() ; a++){
		for (b=0 ; b<masque.getColonne() ; b++){
			if(l<t){
				if (a<d)
					masque.setValeur(a,b,0);
				else
					masque.setValeur(a,b,image_init.getValeurGRAY(l-t+a,c-t+b));
			}
			if(l>=image_init.getLigne()-t){
			 	if (a>(image_init.getLigne()-l+f))
			 		masque.setValeur(a,b,0);
			 	else
			 		masque.setValeur(a,b,image_init.getValeurGRAY(l-t+a,c-t+b));
			}
			if(c<t){
				if (b<e)
					masque.setValeur(a,b,0);
				else
					masque.setValeur(a,b,image_init.getValeurGRAY(l-t+a,c-t+b));
			}
			if(c>=image_init.getColonne()-t){
				if (b>(image_init.getColonne()-c+f))
					masque.setValeur(a,b,0);
				else
					masque.setValeur(a,b,image_init.getValeurGRAY(l-t+a,c-t+b));
			}
		}
	}
}