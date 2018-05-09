/*
+------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			 |
|	  Nom du Fichier : FiltreMedien.hpp									 |
|     Personnes : Takfarinas Kebci, Yann Nebout							 |
|     Objectif(s) du programme : Réalise les filtrages sur une image     |
|	  Date de Début : 26 Février 2018									 |
|	  Date de la dernière modification : 20 Mars 2018					 |
+------------------------------------------------------------------------+
*/

#ifndef FILTREMEDIAN_HPP
#define FILTREMEDIAN_HPP

	#include "Filtre.hpp"

	class FiltreMedian : public Filtre{

		public:
		/*
		+-------------------------------------------+
  		|     Constructeurs de la classe Filtre     |
	  	+-------------------------------------------+
		*/
	  		/////////////////////////////////////
	  		//     Constructeur par défaut     //
	  		/////////////////////////////////////
	  		FiltreMedian();

	  		////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  //
	  		//		Input : 									  	  //
	  		//			image (Image) : image originale à filtrer     //
	  		//			typeF (int) : type de filtre utilisé		  //
	  		////////////////////////////////////////////////////////////
	  		FiltreMedian(Image image, int tailleF);

	  		/////////////////////////////////////////////////
	  		//     Constructeur 						   //
	  		//		Input : 							   //
	  		//			f (Filtre &) : filtre à copier     //
	  		/////////////////////////////////////////////////
	  		FiltreMedian(const FiltreMedian& m);
		
		/*
		+-----------------------------------------+
  		|     Destructeur de la classe Filtre     |
	  	+-----------------------------------------+
		*/
	  		~FiltreMedian();

	  	/*
		+---------------------------------------+
  		|     Fonctions de la classe Filtre     |
	  	+---------------------------------------+
		*/
	  		///////////////////////////////////////////////////
	  		//     Fonction qui réalise le filtre médian     //
	  		///////////////////////////////////////////////////
	  		void filtreMedian();

	  		//////////////////////////////////////////////////////////////////
			//     Fonction qui trouve la médiane d'une suite de nombre     //
			//////////////////////////////////////////////////////////////////
			double calculMedianne();
	};

#endif