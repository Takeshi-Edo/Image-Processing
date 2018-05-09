/*
+------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			 |
|	  Nom du Fichier : Gradient.hpp										 |
|     Personnes : Takfarinas Kebci, Yann Nebout							 |
|     Objectif(s) du programme : Réalise les filtrages sur une image     |
|	  Date de Début : 26 Février 2018									 |
|	  Date de la dernière modification : 19 Mars 2018					 |
+------------------------------------------------------------------------+
*/

#ifndef FILTREGRADIENT_HPP
#define FILTREGRADIENT_HPP

	#include "Filtre.hpp"

	class Gradient : public Filtre{

		public:
		/*
		+-------------------------------------------+
  		|     Constructeurs de la classe Filtre     |
	  	+-------------------------------------------+
		*/
	  		/////////////////////////////////////
	  		//     Constructeur par défaut     //
	  		/////////////////////////////////////
	  		Gradient();

	  		////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  //
	  		//		Input : 									  	  //
	  		//			image (Image) : image originale à filtrer     //
	  		//			typeF (int) : type de filtre utilisé		  //
	  		////////////////////////////////////////////////////////////
	  		Gradient(Image image, int typeF);

	  		////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  //
	  		//		Input : 									  	  //
	  		//			image (Image) : image originale à filtrer     //
	  		//			typeF (int) : type de filtre utilisé		  //
	  		//			seuilF (double) : seuil du filtre utilisé	  //
	  		////////////////////////////////////////////////////////////
	  		Gradient(Image image, int typeF, double seuilF);

	  		/////////////////////////////////////////////////
	  		//     Constructeur 						   //
	  		//		Input : 							   //
	  		//			f (Filtre &) : filtre à copier     //
	  		/////////////////////////////////////////////////
	  		Gradient(const Gradient& g);
		
		/*
		+-----------------------------------------+
  		|     Destructeur de la classe Filtre     |
	  	+-----------------------------------------+
		*/
	  		~Gradient();

		/*
		+-------------------------------------+
  		|     Getters de la classe Filtre     |
	  	+-------------------------------------+
		*/
	  		///////////////////////////////////////////////////
	  		//     Fonction qui donne le seuil du filtre     //
	  		//		Output : 							  	 //
	  		//			seuil (double) : seuil du filtre   	 //
	  		///////////////////////////////////////////////////
			double getSeuil();

	  		////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui donne l'argument du gradient d'un pixel		      //
	  		//		Input : 									   				  //
	  		//			i (int) : numero de la ligne     						  //
	  		//			j (int) : numero de la colonne     						  //
	  		//		Output : 									   				  //
	  		//			argume[i][j] (double) : valeur de l'argument un pixel     //
	  		////////////////////////////////////////////////////////////////////////
			double getCaseArgument(int i, int j);

	  		//////////////////////////////////////////////////////////////////////
	  		//     Fonction qui donne le tableau d'argument de l"image     		//
	  		//		Output : 									   				//
	  		//			argumet (vector<vector<double> >) : seuil du filtre	    //
	  		//////////////////////////////////////////////////////////////////////
			std::vector<std::vector<double> > getArgument();

	  	/*
		+-------------------------------------+
  		|     Setters de la classe Filtre     |
	  	+-------------------------------------+
		*/
	  		/////////////////////////////////////////////////////
	  		//     Fonction qui affecte un seuil au filtre     //
	  		//		Input : 								   //
	  		//			seuilF (double) : seuil du filtre      //
	  		/////////////////////////////////////////////////////
	  		void setSeuil(double seuilF);
			void setArg(int i, int j, double val);
	  	/*
		+---------------------------------------+
  		|     Fonctions de la classe Filtre     |
	  	+---------------------------------------+
		*/
	  		//////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui qui initialise le tableau d'argument de l'image     //
	  		//////////////////////////////////////////////////////////////////////////
			void initArg();
			
	  		/////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui choisit le noyau en fonction du type de filtre     //
	  		//		Input : 									   				   //
	  		//			typeF (int) : type de noyau     						   //
	  		/////////////////////////////////////////////////////////////////////////
	  		void choixNoyau(int typeF);

	  		////////////////////////////////////////////////////
	  		//     Fonction qui donne un noyau de prewitt     //
	  		////////////////////////////////////////////////////
	  		void noyauPrewitt();

	  		//////////////////////////////////////////////////
	  		//     Fonction qui donne un noyau de sobel     //
	  		//////////////////////////////////////////////////
	  		void noyauSobel();

	  		/////////////////////////////////////////////////////
	  		//     Fonction qui réalise le filtre gradient     //
	  		/////////////////////////////////////////////////////
	  		void filtreGradient();

	  		/////////////////////////////////////////////////////
	  		//     Fonction qui réalise le filtre gradient     //
	  		/////////////////////////////////////////////////////
	  		void seuillage();

		protected:
			double seuil;		//	Seuil du filtre
			Matrice noyau2;		//	Noyau 2 du filtre dans le cas du gradient

			std::vector<std::vector<double> > argument;	//	Tableau d'argument du gradient de chaque pixel
	};

#endif