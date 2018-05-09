/*
+------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			 |
|	  Nom du Fichier : FiltreMoyenneur.hpp								 |
|     Personnes : Takfarinas Kebci, Yann Nebout							 |
|     Objectif(s) du programme : Réalise les filtrages sur une image     |
|	  Date de Début : 26 Février 2018									 |
|	  Date de la dernière modification : 20 Mars 2018					 |
+------------------------------------------------------------------------+
*/

#ifndef FILTREMOYEN_HPP
#define FILTREMOYEN_HPP

	#include "Filtre.hpp"

	class FiltreMoyenneur : public Filtre{

		public:
		/*
		+-------------------------------------------+
  		|     Constructeurs de la classe Filtre     |
	  	+-------------------------------------------+
		*/
	  		/////////////////////////////////////
	  		//     Constructeur par défaut     //
	  		/////////////////////////////////////
	  		FiltreMoyenneur();

	  		////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  //
	  		//		Input : 									  	  //
	  		//			image (Image) : image originale à filtrer     //
	  		//			tailleF (int) : taille du masque			  //
	  		////////////////////////////////////////////////////////////
	  		FiltreMoyenneur(Image image, int tailleF);

	  		/////////////////////////////////////////////////
	  		//     Constructeur 						   //
	  		//		Input : 							   //
	  		//			f (Filtre &) : filtre à copier     //
	  		/////////////////////////////////////////////////
	  		FiltreMoyenneur(const FiltreMoyenneur& f);
		
		/*
		+-----------------------------------------+
  		|     Destructeur de la classe Filtre     |
	  	+-----------------------------------------+
		*/
	  		~FiltreMoyenneur();


	  	/*
		+-------------------------------------+
  		|     Getters de la classe Filtre     |
	  	+-------------------------------------+
		*/
	  		/////////////////////////////////////////////////////
	  		//     Fonction qui donne la moyenne du noyau      //
	  		//		Output : 								   //
	  		//     		moyenne (double) : moyenne du noyau    //
	  		/////////////////////////////////////////////////////
			double getMoyenne();

	  	/*
		+-------------------------------------+
  		|     Setters de la classe Filtre     |
	  	+-------------------------------------+
		*/
	  		///////////////////////////////////////////////////////
	  		//     Fonction qui affecte une moyenne au noyau     //
	  		//		input : 								     //
	  		//     		m (double) : moyenne 				     //
	  		///////////////////////////////////////////////////////
			void setMoyenne(double m);

	  	/*
		+---------------------------------------+
  		|     Fonctions de la classe Filtre     |
	  	+---------------------------------------+
		*/
	  		///////////////////////////////////////////////////
	  		//     Fonction qui donne un noyau moyenneur     //
	  		///////////////////////////////////////////////////
	  		void noyauMoyen();

	  		///////////////////////////////////////////////
	  		//     Fonction qui aréalise le filtrage     //
	  		///////////////////////////////////////////////
	  		void filtrage();

		protected:
			double moyenne;		//	Moyenne du filtre
	};

#endif