/*
+-------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			  |
|	  Nom du Fichier : Image.cpp										  |
|     Personnes : Takfarinas Kebci, Yann Nebout							  |
|     Objectif(s) du programme : Réaliser l'enregistrement de l'image     |
|	  Date de Début : 26 Février 2018									  |
|	  Date de la dernière modification : 15 Mars 2018					  |
+-------------------------------------------------------------------------+
*/

#include "Image.hpp"

// Utilisation des espaces de noms std et opencv
using namespace std;
using namespace cv;

//	Constucteurs
Image::Image(){
	ligne = 0;
	colonne = 0;
}

Image::Image(int l, int c){
	ligne = l;
	colonne = c;

	int i,j;

	for(i=0 ; i<ligne ; i++){
		vector<double> vecteur;
		for(j=0 ; j<colonne ; j++){
			vecteur.push_back(0);
		}
		image_gray.push_back(vecteur);
	}
}

Image::Image(Mat im, int type){
	ligne = im.rows;
	colonne = im.cols;
	if (type==0)
		recupeGRAYvalue(im);
	else
		recupeRGBvalue(im);

	int i,j;
	for (i=0 ; i<256 ; i++){
		vector<int> v;
		for (j=0 ; j<2 ; j++){
			v.push_back(i);
			v.push_back(0);
		}
		histogramme.push_back(v);
	}
}

Image::Image(const Image& im){
	ligne = im.ligne;
	colonne = im.colonne;

	image_rgb = im.image_rgb;
	image_gray = im.image_gray;

	histogramme = im.histogramme;
}

//	Destructeur
Image::~Image(){}

//	Getters
double Image::getValeurRGB(int i, int j, int rgb) const{ return image_rgb[i][j][rgb]; }
double Image::getValeurGRAY(int i, int j) const{ return image_gray[i][j]; }
vector<vector<int> > Image::getHisto(bool gray, int rgb) { histo(gray, rgb); return histogramme;}
int Image::getLigne() const{ return ligne; }
int Image::getColonne() const{ return colonne; }
Mat Image::getImage(bool rgb) const{
	int i,j;
	Mat im;

	if (rgb == true)
		im = Mat(ligne,colonne,CV_8UC3);
	else
		im = Mat(ligne,colonne,CV_8U);

	for (i=0 ; i<ligne ; i++){
		for(j=0 ; j<colonne ; j++){
			if (rgb == true){
				Vec3b c(image_rgb[i][j][0],image_rgb[i][j][1],image_rgb[i][j][2]);
				im.at<Vec3b>(i,j) = c;
			}
			else
				im.at<uchar>(i,j) = image_gray[i][j];
		}
	}
	return im;
}

//	Setters
void Image::setValeur(int i, int j, double val){ image_gray[i][j] = val; }

//	Fonction
void Image::RGBtoGRAY(){
	int i,j;
	double valeur = 0;

	for(i=0 ; i<ligne ; i++){
		vector<double> vecteur;
		for(j=0 ; j<colonne ; j++){
			valeur = (image_rgb[i][j][0]+image_rgb[i][j][1]+image_rgb[i][j][2])/3;
			vecteur.push_back(valeur);
		}
		image_gray.push_back(vecteur);
	}
}

void Image::recupeRGBvalue(Mat im){
	int i,j,k;
	double val;

	for(i=0 ; i<ligne ; i++){
		vector<vector<double> > v2;
		for(j=0 ; j<colonne ; j++){
			vector<double> v1;
			for(k=0 ; k<3 ; k++){
				val = im.at<Vec3b>(i,j)[k];
				v1.push_back(val);
			}
			v2.push_back(v1);
		}
		image_rgb.push_back(v2);
	}
}

void Image::recupeGRAYvalue(Mat im){
	int i,j;
	double valeur;

	for(i=0 ; i<ligne ; i++){
		vector<double> vecteur;
		for(j=0 ; j<colonne ; j++){
			valeur = im.at<uchar>(i,j);
			vecteur.push_back(valeur);
		}
		image_gray.push_back(vecteur);
	}
}

void Image::histo(bool gray, int rgb){
	int i,j;
	uint k;

	for (i=0 ; i<ligne ; i++){
		for (j=0 ; j<colonne ; j++){
			for (k=0 ; k<histogramme[0].size() ; k++){
				if (gray == true){
					if(histogramme[0][k] == image_gray[i][j]){
						histogramme[1][k]++;
					}
				}
				else{
					if(histogramme[0][k] == image_rgb[i][j][rgb]){
						histogramme[1][k]++;
					}
				}
			} 
		}
	}
}