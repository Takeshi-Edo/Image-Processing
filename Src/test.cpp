/*
+-----------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			|
|	  Nom du Fichier : test.cpp											|
|     Personnes : Takfarinas Kebci, Yann Nebout							|
|     Objectif(s) du programme : Programme principale pour les test		|
|	  Date de Début : 26 Février 2018									|
|	  Date de la dernière modification : 12 Mars 2018					|
+-----------------------------------------------------------------------+
*/

#include "TraitementImage.hpp"

// Utilisation des espaces de noms std et opencv
using namespace std;
using namespace cv;

int main(){
	char key;

	//	Chargement de l'image
	Mat image;
	image = imread("image_test/qrcode1.png", CV_LOAD_IMAGE_COLOR);
	Mat imgr(image.rows, image.cols, CV_8U);
	Image im(image,1);
	//cvtColor(image, image, CV_BGR2GRAY);
	im.RGBtoGRAY();

	//	Filtrage
	FiltreCanny c(im,3,1,50,199);
	c.canny();
	Image imgray = c.getImage();
	imgr = imgray.getImage(false);

	//	Détection des points d'intérêts
	Harris moravec(imgray,1);
	moravec.detection();
	vector<Points> point;
	point = moravec.getPoint();
	cout << point.size() << endl;

	//	Définition des fenêtres
	cvNamedWindow("Origine", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("test", CV_WINDOW_AUTOSIZE);

	while(key != 'q' && key != 'Q'){
	
		if (point.size() != 0){
			for (int i=0;i<(int)point.size();i++){
				circle(image, Point(point[i].getY(),point[i].getX()), 5, Scalar(0,0,255));
			}
		}
		imshow("Origine",image);
		imshow("test",imgr);
		key = cvWaitKey(10);	// En attente que la touche q soit enfoncée
	}

	return 0;
}
