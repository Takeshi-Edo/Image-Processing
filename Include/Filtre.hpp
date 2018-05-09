/*
+------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			 |
|	  Nom du Fichier : Filtre.hpp										 |
|     Personnes : Takfarinas Kebci, Yann Nebout							 |
|     Objectif(s) du programme : Réalise les filtrages sur une image     |
|	  Date de Début : 26 Février 2018									 |
|	  Date de la dernière modification : 19 Mars 2018					 |
+------------------------------------------------------------------------+
*/

#ifndef FILTRE_HPP
#define FILTRE_HPP

	#include "Image.hpp"
	#include "Matrice.hpp"
	#include "Fonction.hpp"

	class Filtre{

		public:
		/*
		+-------------------------------------------+
  		|     Constructeurs de la classe Filtre     |
	  	+-------------------------------------------+
		*/
	  		/////////////////////////////////////
	  		//     Constructeur par défaut     //
	  		/////////////////////////////////////
	  		Filtre();

	  		////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  //
	  		//		Input : 									  	  //
	  		//			image (Image) : image originale à filtrer     //
	  		////////////////////////////////////////////////////////////
	  		Filtre(Image image);


	  		////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  //
	  		//		Input : 									  	  //
	  		//			image (Image) : image originale à filtrer     //
	  		//			typeF (int) : type de filtre utilisé		  //
	  		////////////////////////////////////////////////////////////
	  		Filtre(Image image, int tailleF);


	  		/////////////////////////////////////////////////
	  		//     Constructeur 						   //
	  		//		Input : 							   //
	  		//			f (Filtre &) : filtre à copier     //
	  		/////////////////////////////////////////////////
	  		Filtre(const Filtre& f);
		
		/*
		+-----------------------------------------+
  		|     Destructeur de la classe Filtre     |
	  	+-----------------------------------------+
		*/
	  		~Filtre();

		/*
		+-------------------------------------+
  		|     Getters de la classe Filtre     |
	  	+-------------------------------------+
		*/
			/////////////////////////////////////////////////////
	  		//     Fonction qui renvoie l'image filtrée        //
	  		//		Output : 								   //
	  		//			image_filt (Image) : image filtrée     //
	  		/////////////////////////////////////////////////////
	  		Image getImage() const;

	  		/////////////////////////////////////////////////////////
	  		//     Fonction qui donne le nom du filtre utilisé     //
	  		//		Output : 									   //
	  		//			(string) : nom du filtre utilisé     	   //
	  		/////////////////////////////////////////////////////////
	  		std::string getType() const;
	  		
	  	/*
		+-------------------------------------+
  		|     Setters de la classe Filtre     |
	  	+-------------------------------------+
		*/
	  		/////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui affecte une image à la variable image_init    		   //
	  		//		Input : 									   					   //
	  		//			image (Image) : affecte une image à la variable image_init     //
	  		/////////////////////////////////////////////////////////////////////////////
	  		void setImage(Image image);

	  	/*
		+---------------------------------------+
  		|     Fonctions de la classe Filtre     |
	  	+---------------------------------------+
		*/
	  		///////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui extrait un morceau de l'image qui formera un masque 	 //
	  		//		Input : 									   				      	 //
	  		//			l (int) : numéro de la ligne de la case centrale du masque    	 //
	  		//			c (int) : numéro de la colonne de la case centrale du masque     //
	  		///////////////////////////////////////////////////////////////////////////////
	  		void extractionMask(int l, int c);

	  		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui extrait un morceau de l'image qui formera un masque (cas particulier des coins de l'image)     //
	  		//		Input : 									   				      	 									   //
	  		//			l (int) : numéro de la ligne de la case centrale du masque    	 									   //
	  		//			c (int) : numéro de la colonne de la case centrale du masque     									   //
	  		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	  		void coin(int l, int c);

	  		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui extrait un morceau de l'image qui formera un masque (cas particulier des bords de l'image)     //
	  		//		Input : 									   				      	 									   //
	  		//			l (int) : numéro de la ligne de la case centrale du masque    	 									   //
	  		//			c (int) : numéro de la colonne de la case centrale du masque     									   //
	  		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	  		void bord(int l, int c);	  		

		protected:
			int taille;			//	Taille du noyau et du masque
			std::string type;	//	Nom du filtre

			Image image_init;	//	Image avant filtrage
			Image image_filt;	//	Image après filtrage

			Matrice noyau;		// 	Noyau du filtre
			Matrice masque;		//	Masque de convolution extrayant une partie de l'image
	};

#endif