/*
+------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			 |
|	  Nom du Fichier : Laplace.hpp										 |
|     Personnes : Takfarinas Kebci, Yann Nebout							 |
|     Objectif(s) du programme : Réalise les filtrages sur une image     |
|	  Date de Début : 26 Février 2018									 |
|	  Date de la dernière modification : 20 Mars 2018					 |
+------------------------------------------------------------------------+
*/

#ifndef LAPLACE_HPP
#define LAPLACE_HPP

	#include "Filtre.hpp"

	class Laplace : public Filtre{

		public:
		/*
		+-------------------------------------------+
  		|     Constructeurs de la classe Filtre     |
	  	+-------------------------------------------+
		*/
	  		/////////////////////////////////////
	  		//     Constructeur par défaut     //
	  		/////////////////////////////////////
	  		Laplace();

	  		////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  //
	  		//		Input : 									  	  //
	  		//			image (Image) : image originale à filtrer     //
	  		////////////////////////////////////////////////////////////
	  		Laplace(Image image);

	  		////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  //
	  		//		Input : 									  	  //
	  		//			image (Image) : image originale à filtrer     //
	  		//			typeF (int) : type de filtre utilisé		  //
	  		////////////////////////////////////////////////////////////
	  		Laplace(Image image, int typeF);

	  		////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  //
	  		//		Input : 									  	  //
	  		//			image (Image) : image originale à filtrer     //
	  		//			typeF (int) : type de filtre utilisé		  //
	  		//			seuilF (int) : seuil du filtre utilisé		  //
	  		////////////////////////////////////////////////////////////
	  		Laplace(Image image, int typeF, double seuilF);

	  		/////////////////////////////////////////////////
	  		//     Constructeur 						   //
	  		//		Input : 							   //
	  		//			f (Filtre &) : filtre à copier     //
	  		/////////////////////////////////////////////////
	  		Laplace(const Laplace& l);
		
		/*
		+-----------------------------------------+
  		|     Destructeur de la classe Filtre     |
	  	+-----------------------------------------+
		*/
	  		~Laplace();

	  	/*
		+-------------------------------------+
  		|     Getters de la classe Filtre     |
	  	+-------------------------------------+
		*/
	  		/////////////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur au seuil du filtre     //
	  		//		Output :								  	       //
	  		//			seuil (double) : seuil du filtre 	 		   //
	  		/////////////////////////////////////////////////////////////
	  		double getSeuil();

	  	/*
		+-------------------------------------+
  		|     Setters de la classe Filtre     |
	  	+-------------------------------------+
		*/
	  		////////////////////////////////////////////////////////////////
	  		//     Fonction qui affecte une valeur au seuil du filtre     //
	  		//		Input :									  	 	      //
	  		//			seuilF (double) : seuil du filtre 	 			  //
	  		////////////////////////////////////////////////////////////////
			void setSeuil(double seuilF);

	  	/*
		+---------------------------------------+
  		|     Fonctions de la classe Filtre     |
	  	+---------------------------------------+
		*/  		
	  		////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui choisit le noyau en foncton du type de filtre     //
	  		//		Input :													 	  //
	  		//			typeF (int) : détermine le noyau utilisé			 	  //
	  		////////////////////////////////////////////////////////////////////////
	  		void choixNoyau(int typeF);

	  		/////////////////////////////////////////////////////
	  		//     Fonction qui donne un noyau laplacien 4     //
	  		/////////////////////////////////////////////////////
	  		void noyauLaplace1();

	  		/////////////////////////////////////////////////////
	  		//     Fonction qui donne un noyau laplacien 8     //
	  		/////////////////////////////////////////////////////
	  		void noyauLaplace2();

	  		/////////////////////////////////////////////////////////
	  		//     Fonction qui aréalise le filtrage Laplacien     //
	  		/////////////////////////////////////////////////////////
	  		void filtrage();

	  		///////////////////////////////////////////////////////////
	  		//     Fonction qui réalise un seuillage sur l'image     //
	  		///////////////////////////////////////////////////////////
	  		void seuillage();

		protected:
			double seuil;	//	Seuil du filtre
	};

#endif