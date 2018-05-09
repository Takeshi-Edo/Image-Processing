/*
+------------------------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     							   |
|	  Nom du Fichier : Harris.hpp														   |
|     Personnes : Takfarinas Kebci, Yann Nebout							  				   |
|     Objectif(s) du programme : réaliser le détecteur de points d'intérêts de Moravec     |
|	  Date de Début : 26 Février 2018									  				   |
|	  Date de la dernière modification : 21 Mars 2018					  				   |
+------------------------------------------------------------------------------------------+
*/

#ifndef HARRIS_HPP
#define HARRIS_HPP

	#include "Image.hpp"
	#include "Points.hpp"
	#include "Matrice.hpp"

	class Harris{

		public:
		/*
		+-------------------------------------------+
  		|     Constructeurs de la classe Harris     |
	  	+-------------------------------------------+
		*/
	  		/////////////////////////////////////
	  		//     Constructeur par défaut     //
	  		/////////////////////////////////////
	  		Harris();

	  		////////////////////////////////////////////////////////////////////////////
	  		//     Constructeur     												  //
	  		//		Input :															  //
	  		//			imageF (Image) : image dont on veut les points d'intérêts     //
	  		////////////////////////////////////////////////////////////////////////////
	  		Harris(Image imageF);

	  		/////////////////////////////////////////////////////////////////////////////
	  		//     Constructeur     												   //
	  		//		Input :															   //
	  		//			imageF (Image) : image dont on veut les points d'intérêts      //
	  		//			seuil (double) : seuil d'acceptation comme point d'intérêt     //
	  		/////////////////////////////////////////////////////////////////////////////
	  		Harris(Image imageF, double seuilF);

	  		/////////////////////////////////////////////////////////////////////////////
	  		//     Constructeur     												   //
	  		//		Input :															   //
	  		//			imageF (Image) : image dont on veut les points d'intérêts      //
	  		//			seuil (double) : seuil d'acceptation comme point d'intérêt     //
	  		//			c (double) : Paramètre de calcul 						       //
	  		/////////////////////////////////////////////////////////////////////////////
	  		Harris(Image imageF, double seuilF, double c);

		/*
		+-----------------------------------------+
  		|     Destructeur de la classe Harris     |
	  	+-----------------------------------------+
		*/
			~Harris();

		/*
		+-------------------------------------+
  		|     Getters de la classe Harris     |
	  	+-------------------------------------+
		*/
	  		////////////////////////////////////////////////////////////
	  		//     Fonction qui donne un point d'intérêt     		  //
	  		//		Input :											  //
	  		//			i (int) : numéro du point d'intérêt     	  //
	  		//		Output :										  //
	  		//			points[i] (Points) : ième point d'intérêt     //
	  		////////////////////////////////////////////////////////////
			Points getPointInt(int i);

	  		////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui la liste des points d'intérêts 		  			  //
	  		//		Output :										  			  //
	  		//			points (vector<Points>) : liste des points d'intérêts     //
	  		////////////////////////////////////////////////////////////////////////
			std::vector<Points> getPoint();

	  		////////////////////////////////////////////////////////
	  		//     Fonction qui donne le seuil d'acceptation	  //
	  		//		Output :									  //
	  		//			seuil (double) : ième point d'intérêt     //
	  		////////////////////////////////////////////////////////
			double getSeuil ();

	  		///////////////////////////////////////////////////////
	  		//     Fonction qui donne le paramètre de calcul     //
	  		//		Output :									 //
	  		//			pc (double) : paramètre de calcul 	     //
	  		///////////////////////////////////////////////////////
			double getC ();
		/*
		+-------------------------------------+
  		|     Setters de la classe Harris     |
	  	+-------------------------------------+
		*/
	  		/////////////////////////////////////////////////////////
	  		//     Fonction qui affecte un paramètre de calcul     //
	  		//		Input :										   //
	  		//			c (double) : paramètre de calcul 	       //
	  		/////////////////////////////////////////////////////////
			void setC(double c);

	  		//////////////////////////////////////////////////////////
	  		//     Fonction qui affecte un seuil d'acceptation     	//
	  		//		Input :											//
	  		//			seuilF (double) : seuil d'acceptation      	//
	  		//////////////////////////////////////////////////////////
	  		void setSeuil(double seuilF);

		/*
		+---------------------------------------+
  		|     Fonctions de la classe Harris     |
	  	+---------------------------------------+
		*/
			/////////////////////////////////////////////////////////////////
	  		//     Fonction qui calcul la matrice hessienne d'un pixel     //
	  		/////////////////////////////////////////////////////////////////
			void hessienne();

	  		///////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui extrait un morceau de l'image qui formera un masque 	 //
	  		//		Input : 									   				      	 //
	  		//			l (int) : numéro de la ligne de la case centrale du masque    	 //
	  		//			c (int) : numéro de la colonne de la case centrale du masque     //
	  		///////////////////////////////////////////////////////////////////////////////
			void extractionMask(int l, int c);

	  		////////////////////////////////////////////////////////
	  		//     Fonction qui calcule la dissemblence     	  //
	  		//			H (double) : dissemblence du pixel     	  //
	  		////////////////////////////////////////////////////////
	  		double calculH();

	  		///////////////////////////////////////////////////////////////////
	  		//     Fonction qui réalise la détection de point d'intérêts     //
	  		///////////////////////////////////////////////////////////////////
			void detection();

	  		/////////////////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui dit si un point est un point d'intérêt 						       //
	  		//		Output :									  								   //
	  		//			pt_interet (bool) : variable disant si le point est un point d'intérêt     //
	  		/////////////////////////////////////////////////////////////////////////////////////////
			bool estInteressant();

		protected:
			double pc;			//	Paramètre du calcul généralement égale à 0.05
			double seuil;		//	Seuil d'acceptation comme point d'intérêts
			Image image;		//	Image dont on veut obtenir les points d'intérêts
			Matrice masque;		//	Morceau de l'image
			Matrice hess;		//	Matrice hessienne
			std::vector<Points> points;		//	Liste des points d'intérêts
	};

#endif