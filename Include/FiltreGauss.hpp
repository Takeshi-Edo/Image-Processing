/*
+------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			 |
|	  Nom du Fichier : FiltreGauss.hpp									 |
|     Personnes : Takfarinas Kebci, Yann Nebout							 |
|     Objectif(s) du programme : Réalise les filtrages sur une image     |
|	  Date de Début : 26 Février 2018									 |
|	  Date de la dernière modification : 19 Mars 2018					 |
+------------------------------------------------------------------------+
*/

#ifndef FILTREGAUSS_HPP
#define FILTREGAUSS_HPP

	#include "Filtre.hpp"

	class FiltreGauss : public Filtre{

		public:
		/*
		+-------------------------------------------+
  		|     Constructeurs de la classe Filtre     |
	  	+-------------------------------------------+
		*/
	  		/////////////////////////////////////
	  		//     Constructeur par défaut     //
	  		/////////////////////////////////////
	  		FiltreGauss();

	  		////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  //
	  		//		Input : 									  	  //
	  		//			image (Image) : image originale à filtrer     //
	  		////////////////////////////////////////////////////////////
	  		FiltreGauss(Image image);

	  		////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  //
	  		//		Input : 									  	  //
	  		//			image (Image) : image originale à filtrer     //
	  		//			typeF (int) : type de filtre utilisé		  //
	  		////////////////////////////////////////////////////////////
	  		FiltreGauss(Image image, int tailleF);

	  		////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  //
	  		//		Input : 									  	  //
	  		//			image (Image) : image originale à filtrer     //
	  		//			typeF (int) : type de filtre utilisé		  //
	  		//			sigmaF (double) : écart type	 			  //
	  		////////////////////////////////////////////////////////////
	  		FiltreGauss(Image image, int tailleF, double sigmaF);

	  		//////////////////////////////////////////////////////
	  		//     Constructeur 						   		//
	  		//		Input : 							   		//
	  		//			f (FiltreGauss &) : filtre à copier     //
	  		//////////////////////////////////////////////////////
	  		FiltreGauss(const FiltreGauss& g);
		
		/*
		+-----------------------------------------+
  		|     Destructeur de la classe Filtre     |
	  	+-----------------------------------------+
		*/
	  		~FiltreGauss();

		/*
		+-------------------------------------+
  		|     Getters de la classe Filtre     |
	  	+-------------------------------------+
		*/
	  		////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur de l'écart type d'une gaussienne      //
	  		//		Output : 									  			 		  //
	  		//			sigma (double) : écart type de l'éventuel filtre gaussien     //
	  		////////////////////////////////////////////////////////////////////////////
	  		double getSigma() const;

	  	/*
		+-------------------------------------+
  		|     Setters de la classe Filtre     |
	  	+-------------------------------------+
		*/
	  		//////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui affecte un écart type pour une gaussienne    		    //
	  		//		Input : 									   				        //
	  		//			sigmaF (double) : affecte un écart type pour une gaussienne     //
	  		//////////////////////////////////////////////////////////////////////////////
	  		void setSigma(double sigmaF);

	  	/*
		+---------------------------------------+
  		|     Fonctions de la classe Filtre     |
	  	+---------------------------------------+
		*/ 
			//////////////////////////////////////////////////////////
			//     Fonction qui vérifie la validité de sigma		//
			//		Input : 										//
			//			sigma (double) : valeur de l'écart type     //
			//////////////////////////////////////////////////////////
			void ecartType();

	  		////////////////////////////////////////////////////
	  		//     Fonction qui calcule un noyau de gauss     //
	  		////////////////////////////////////////////////////
	  		void noyauGauss();

	  		//////////////////////////////////////////////
	  		//     Fonction qui réalise le filtrage     //
	  		//////////////////////////////////////////////
	  		void filtrage();

		protected:

			double sigma;	//	Ecart type
	};

#endif