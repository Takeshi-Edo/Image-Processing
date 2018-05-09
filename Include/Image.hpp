/*
+-------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			  |
|	  Nom du Fichier : Image.hpp										  |
|     Personnes : Takfarinas Kebci, Yann Nebout							  |
|     Objectif(s) du programme : Réaliser l'enregistrement de l'image     |
|	  Date de Début : 26 Février 2018									  |
|	  Date de la dernière modification : 15 Mars 2018					  |
+-------------------------------------------------------------------------+
*/

#ifndef Image_HPP
#define Image_HPP

	#include "util.hpp"

	class Image{

		public:
		/*
		+------------------------------------------+
  		|     Constructeurs de la classe Image     |
	  	+------------------------------------------+
		*/
	  		/////////////////////////////////////
	  		//     Constructeur par défaut     //
	  		/////////////////////////////////////
	  		Image();

	  		////////////////////////////////////////////////////////////////////////////////
	  		//     Constructeur 						  								  //
	  		//		Input : 									  		   				  //
	  		//			im (Mat) : Image à récupérer     								  //
	  		//			type (int) : variable disant si l'image est en rgb ou en gris     //
	  		////////////////////////////////////////////////////////////////////////////////
	  		Image(cv::Mat im, int type);

	  		/////////////////////////////////////////////////////////
	  		//     Constructeur 						  		   //
	  		//		Input : 									   //
	  		//			l (int) : nombre de ligne de l'image	   //
	  		//			c (int) : nombre de colonne de l'image 	   //
	  		/////////////////////////////////////////////////////////
	  		Image(int l, int c);

	  		/////////////////////////////////////////////////////////////////
	  		//     Constructeur par copie						  		   //
	  		//		Input : 									  		   //
	  		//			im (Image &) : addresse sur une variable Image     //
	  		/////////////////////////////////////////////////////////////////
	  		Image(const Image& im);
		
		/*
		+----------------------------------------+
  		|     Destructeur de la classe Image     |
	  	+----------------------------------------+
		*/
	  		~Image();

		/*
		+------------------------------------+
  		|     Getters de la classe Image     |
	  	+------------------------------------+
		*/
			//////////////////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur d'un pixel en fonction de sa couleur     			//
	  		//		Input : 									  			 						//
	  		//			i (int) : numéro de la ligne     					 						//
	  		//			j (int) : numéro de la colonne 	  					 						//
	  		//			rgb (int) : valeur de la couleur primaire 	  					 			//
	  		//		Output : 									  			 						//
	  		//			image_rgb[i][j][rgb] (double) : valeur du pixel (i,j) et de couleur rgb     //
	  		//////////////////////////////////////////////////////////////////////////////////////////
	  		double getValeurRGB(int i, int j, int rgb) const;

	  		///////////////////////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur d'un pixel en nuance de gris     //
	  		//		Input : 									  			 	 //
	  		//			i (int) : numéro de la ligne     					 	 //
	  		//			j (int) : numéro de la colonne 	  					 	 //
	  		//		Output : 									  			 	 //
	  		//			image_gray[i][j] (double) : valeur de la case (i,j)      //
	  		///////////////////////////////////////////////////////////////////////
	  		double getValeurGRAY(int i, int j) const;

	  		/////////////////////////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui copie une image dans une Mat pour l'affichage						       //
	  		//		Input : 									  			 							   //
	  		//			rgb (bool) : variable disant si l'image à afficher dois être en couleur ou non     //
	  		//		Output : 									  			 							   //
	  		//			im (Mat) : Variable Mat pour l'affichage     									   //
	  		/////////////////////////////////////////////////////////////////////////////////////////////////
	  		cv::Mat getImage(bool rgb) const;

	  		////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui calcul l'histogramme d'une couleur de l'image     //
	  		//		Input : 									  				  //
	  		//			gray (bool) : Dit si l'image est en couleur ou non		  //
	  		//			rgb (int) : couleur rgb si l'image est en couleur		  //
	  		////////////////////////////////////////////////////////////////////////
	  		std::vector<std::vector<int> > getHisto(bool gray, int rgb);

			//////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur de la ligne     //
	  		//		Output : 									//
	  		//			ligne (double) : valeur de la ligne     //
	  		//////////////////////////////////////////////////////
	  		int getLigne() const;

			//////////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur de la colonne     	//
	  		//		Output : 										//
	  		//			colonne (double) : valeur de la colonne     //
	  		//////////////////////////////////////////////////////////
	  		int getColonne() const;

	  	/*
		+------------------------------------+
  		|     Setters de la classe Image     |
	  	+------------------------------------+
		*/
			///////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur d'un pixel en fonction de sa couleur     //
	  		//		Input : 									  			 			 //
	  		//			i (int) : numéro de la ligne     					 			 //
	  		//			j (int) : numéro de la colonne 	  					 			 //
	  		//			vah (double) : valeur de la couleur      	  					 //
	  		///////////////////////////////////////////////////////////////////////////////
			void setValeur(int i, int j, double val);

	  	/*
		+--------------------------------------+
  		|     Fonctions de la classe Image     |
	  	+--------------------------------------+
		*/
			////////////////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui crée une image en nuance de gris à partir d'une image couleur     //
	  		////////////////////////////////////////////////////////////////////////////////////////
	  		void RGBtoGRAY();

	  		//////////////////////////////////////////////////////////
	  		//     Fonction qui copie une image rgb de type Mat     //
	  		//		Input : 										//
	  		//			im (Mat) : Image Opencv						//
	  		//////////////////////////////////////////////////////////
	  		void recupeRGBvalue(cv::Mat im);

	  		/////////////////////////////////////////////////////////////////////
	  		//     Fonction qui copie une image en nuance gris de type Mat     //
	  		//		Input : 												   //
	  		//			im (Mat) : Image Opencv								   //
	  		/////////////////////////////////////////////////////////////////////
	  		void recupeGRAYvalue(cv::Mat im);

	  		////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui calcul l'histogramme d'une couleur de l'image     //
	  		//		Input : 									  				  //
	  		//			gray (bool) : Dit si l'image est en couleur ou non		  //
	  		//			rgb (int) : couleur rgb si l'image est en couleur		  //
	  		////////////////////////////////////////////////////////////////////////
	  		void histo(bool gray, int rgb);

		protected:

			int ligne;		//  Nombre de ligne
			int colonne;	// 	Nombre de colonne
			std::vector<std::vector<std::vector<double> > > image_rgb;	// 	Image couleur
			std::vector<std::vector<double> > image_gray;				// 	Image en nuance de gris
			std::vector<std::vector<int> > histogramme;					//	Histogramme
	};

#endif