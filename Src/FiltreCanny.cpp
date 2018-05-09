/*
+-----------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			 	  |
|	  Nom du Fichier : FiltreCanny.cpp									 	  |
|     Personnes : Takfarinas Kebci, Yann Nebout							 	  |
|     Objectif(s) du programme : Réalise le filtre de Canny sur une image     |
|	  Date de Début : 26 Février 2018									 	  |
|	  Date de la dernière modification : 19 Mars 2018					 	  |
+-----------------------------------------------------------------------------+
*/

#include "FiltreCanny.hpp"

// Utilisation des espaces de noms std et opencv
using namespace std;
using namespace cv;

//	Constructeurs
FiltreCanny::FiltreCanny(){
	fg = FiltreGauss();

	seuilH = 0;
	seuilB = 0;
}

FiltreCanny::FiltreCanny(Image image){
	Image im = image;
	int taille = 3;
	seuilH = 240;
	seuilB = 10;

	fg = FiltreGauss(im,taille);
	image_gauss = Image(im.getLigne(),im.getColonne());
	grad = Image(im.getLigne(),im.getColonne());
	initArgument();
}

FiltreCanny::FiltreCanny(Image image, int tailleF){
	taille = tailleF;

	image_init = image;
	image_gauss = Image(image_init.getLigne(),image_init.getColonne());
	grad = Image(image_init.getLigne(),image_init.getColonne());
	image_filt = Image(image_init.getLigne(),image_init.getColonne());

	fg = FiltreGauss(image_init, taille);
	initArgument();

	noyau = Matrice(taille, taille);
	masque = Matrice(taille, taille);

	seuilH = 10;
	seuilB = 240;
}

FiltreCanny::FiltreCanny(Image image, int tailleF, double sigmaF){	
	taille = tailleF;
	sigma = sigmaF;

	image_init = image;
	fg = FiltreGauss(image_init,tailleF,sigma);
	image_gauss = Image(image_init.getLigne(),image_init.getColonne());
	grad = Image(image_init.getLigne(),image_init.getColonne());
	image_filt = Image(image_init.getLigne(),image_init.getColonne());

	noyau = Matrice(taille, taille);
	masque = Matrice(taille, taille);

	initArgument();


	seuilH = 0;
	seuilB = 0;
}

FiltreCanny::FiltreCanny(Image image, int tailleF, double sigmaF, double seuilh, double seuilb){	
	taille = tailleF;
	sigma = sigmaF;
	seuilH = seuilh;
	seuilB = seuilb;

	image_init = image;
	image_gauss = Image(image_init.getLigne(),image_init.getColonne());
	grad = Image(image_init.getLigne(),image_init.getColonne());
	image_filt = Image(image_init.getLigne(),image_init.getColonne());

	fg = FiltreGauss(image_init,taille,sigma);
	initArgument();

	noyau = Matrice(taille, taille);
	masque = Matrice(taille, taille);
}

FiltreCanny::FiltreCanny(const FiltreCanny& c){	
	sigma = c.sigma;
	seuilH = c.seuilH;
	seuilB = c.seuilB;

	fg = c.fg;
	image_gauss = c.image_gauss;
	grad = c.grad;

	argument = c.argument;
}

//	Destructeur
FiltreCanny::~FiltreCanny(){}

//	Getters
double FiltreCanny::getSeuilHaut(){ return seuilH; }
double FiltreCanny::getSeuilBas(){ return seuilB; }
double FiltreCanny::getSigma(){ return sigma; }

//	Setters
void FiltreCanny::setSeuil(double seuilh, double seuilb){
	seuilH = seuilh;
	seuilB = seuilb;
}
void FiltreCanny::setSigma(double sigmaF){ sigma = sigmaF; }

//	Fonctions
void FiltreCanny::canny(){
	fg.filtrage();
	image_gauss = fg.getImage();
	Gradient g(image_gauss,1);
	g.filtreGradient();
	grad = g.getImage();
	argument = g.getArgument();
	nonMaxima();
	hysteresis();
}

void FiltreCanny::normArg(int i, int j){
	if(abs(argument[i][j])<22.5 || abs(argument[i][j])>157.5){
		argument[i][j] = 0;
	}
	if((argument[i][j]>22.5 && argument[i][j]<67.5) || (argument[i][j]<-117.5 && argument[i][j]>-157.5)){
		argument[i][j] = 45;
	}
	if(abs(argument[i][j])>67.5 && abs(argument[i][j])<117.5){
		argument[i][j] = 90;
	}
	if((argument[i][j]>117.5 && argument[i][j]<157.5) || (argument[i][j]<-22.5 && argument[i][j]>-67.5)){
		argument[i][j] = 135;
	}
}

void FiltreCanny::cmp0(int i, int j){
	if (j>0){
		if (grad.getValeurGRAY(i,j) < grad.getValeurGRAY(i,j-1))
			grad.setValeur(i,j,0);
	}

	if (j<grad.getColonne()-1){
		if (grad.getValeurGRAY(i,j) < grad.getValeurGRAY(i,j+1))
			grad.setValeur(i,j,0);
	}
}

void FiltreCanny::cmp45(int i, int j){
	if (j>0 && i<grad.getLigne()-1){
		if (grad.getValeurGRAY(i,j) < grad.getValeurGRAY(i+1,j-1))
			grad.setValeur(i,j,0);
	}

	if (j<grad.getColonne()-1 && i>0){
		if (grad.getValeurGRAY(i,j) < grad.getValeurGRAY(i-1,j+1))
			grad.setValeur(i,j,0);
	}
}

void FiltreCanny::cmp90(int i, int j){
	if (i>0){
		if (grad.getValeurGRAY(i,j) < grad.getValeurGRAY(i-1,j))
			grad.setValeur(i,j,0);
	}

	if (i<grad.getLigne()-1){
		if (grad.getValeurGRAY(i,j) < grad.getValeurGRAY(i+1,j))
			grad.setValeur(i,j,0);
	}
}

void FiltreCanny::cmp135(int i, int j){
	if (j>0 && i>0){
		if (grad.getValeurGRAY(i,j)< grad.getValeurGRAY(i-1,j-1))
			grad.setValeur(i,j,0);
	}

	if (j<grad.getColonne()-1){
		if (grad.getValeurGRAY(i,j) < grad.getValeurGRAY(i,j+1))
			grad.setValeur(i,j,0);
	}
}

void FiltreCanny::comparaisonNorme(int i, int j){
	if (argument[i][j] == 0){
		cmp0(i,j);
	}
	if (argument[i][j] == 45){
		cmp45(i,j);
	}
	if (argument[i][j] == 90){
		cmp90(i,j);
	}
	if (argument[i][j] == 135){
		cmp135(i,j);
	}
}

void FiltreCanny::nonMaxima(){
	int i,j;

	for (i=0 ; i<grad.getLigne() ; i++){
		for (j=0 ; j<grad.getColonne() ; j++){
			normArg(i,j);
		}
	}
	for (i=0 ; i<grad.getLigne() ; i++){
		for (j=0 ; j<grad.getColonne() ; j++){
			comparaisonNorme(i,j);
		}
	}
}

void FiltreCanny::hysteresisCoin(int i, int j){
	if (i==0 && j==0){
		if (grad.getValeurGRAY(i+1,j)==0 && grad.getValeurGRAY(i+1,j+1)==0 && grad.getValeurGRAY(i+1,j)==0)
			grad.setValeur(i,j,0);
	}
	if (i==0 && j==grad.getColonne()-1){
		if (grad.getValeurGRAY(i,j-1)==0 && grad.getValeurGRAY(i+1,j-1)==0 && grad.getValeurGRAY(i+1,j)==0)
			grad.setValeur(i,j,0);
	}
	if (i==grad.getLigne()-1 && j==0){
		if (grad.getValeurGRAY(i-1,j)==0 && grad.getValeurGRAY(i-1,j+1)==0 && grad.getValeurGRAY(i,j+1)==0)
			grad.setValeur(i,j,0);
	}
	if (j==grad.getColonne()-1 && i==grad.getLigne()-1){
		if (grad.getValeurGRAY(i-1,j)==0 && grad.getValeurGRAY(i-1,j-1)==0 && grad.getValeurGRAY(i,j-1)==0)
			grad.setValeur(i,j,0);
	}
}

void FiltreCanny::hysteresisBord(int i, int j){
	if (i == 0){
		if (grad.getValeurGRAY(i,j-1)==0 && grad.getValeurGRAY(i+1,j-1)==0 && grad.getValeurGRAY(i+1,j)==0 && grad.getValeurGRAY(i+1,j+1)==0 && grad.getValeurGRAY(i,j+1)==0)
			grad.setValeur(i,j,0);
	}
	if (j == 0){
		if (grad.getValeurGRAY(i-1,j)==0 && grad.getValeurGRAY(i-1,j+1)==0 && grad.getValeurGRAY(i,j+1)==0 && grad.getValeurGRAY(i+1,j+1)==0 && grad.getValeurGRAY(i+1,j)==0)
			grad.setValeur(i,j,0);
	}
	if (i == grad.getLigne()){
		if (grad.getValeurGRAY(i,j-1)==0 && grad.getValeurGRAY(i-1,j-1)==0 && grad.getValeurGRAY(i-1,j)==0 && grad.getValeurGRAY(i-1,j+1)==0 && grad.getValeurGRAY(i,j+1)==0)
			grad.setValeur(i,j,0);
	}
	if (j == grad.getColonne()){
		if (grad.getValeurGRAY(i-1,j)==0 && grad.getValeurGRAY(i-1,j-1)==0 && grad.getValeurGRAY(i,j-1)==0 && grad.getValeurGRAY(i+1,j-1)==0 && grad.getValeurGRAY(i+1,j)==0)
			grad.setValeur(i,j,0);
	}
}

void FiltreCanny::hysteresisAutre(int i, int j){
	if (grad.getValeurGRAY(i,j+1)==0 && grad.getValeurGRAY(i+1,j+1)==0 && grad.getValeurGRAY(i-1,j+1)==0 && grad.getValeurGRAY(i-1,j)==0 && grad.getValeurGRAY(i-1,j-1)==0 && grad.getValeurGRAY(i,j-1)==0 && grad.getValeurGRAY(i+1,j-1)==0 && grad.getValeurGRAY(i+1,j)==0)
		grad.setValeur(i,j,0);
}

void FiltreCanny::hysteresis(){
	int i,j;
	for (i=0 ; i<grad.getLigne() ; i++){
		for (j=0 ; j<grad.getColonne() ; j++){
			if (seuilB < grad.getValeurGRAY(i,j))
				grad.setValeur(i,j,0);
			else if (seuilH > grad.getValeurGRAY(i,j))
				grad.setValeur(i,j,254);
			else{
				if ((i<1 && j<1) || (i<1 && j==grad.getColonne()-1) || (j<1 && i==grad.getLigne()-1) || (i==grad.getLigne()-1 && j==grad.getColonne()-1))
					hysteresisCoin(i,j);
				else if (i<1 || j<1 || j==grad.getColonne()-1 || i==grad.getLigne()-1)
					hysteresisBord(i,j);
				else
					hysteresisAutre(i,j);
			}
		}
	}
	image_filt = grad;
}

void FiltreCanny::initArgument(){
	int i,j;

	for(i=0 ; i<grad.getLigne() ; i++){
		vector<double> v;
		for(j=0 ; j<grad.getColonne() ; j++){
			v.push_back(0);
		}
		argument.push_back(v);
	}
}