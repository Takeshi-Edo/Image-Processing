/*
+------------------------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     							   |
|	  Nom du Fichier : Moravec.hpp														   |
|     Personnes : Takfarinas Kebci, Yann Nebout							  				   |
|     Objectif(s) du programme : réaliser le détecteur de points d'intérêts de Moravec     |
|	  Date de Début : 26 Février 2018									  				   |
|	  Date de la dernière modification : 21 Mars 2018					  				   |
+------------------------------------------------------------------------------------------+
*/

#ifndef MORAVEC_HPP
#define MORAVEC_HPP

	#include "Image.hpp"
	#include "Points.hpp"
	#include "Matrice.hpp"

	class Moravec{

		public:
		/*
		+--------------------------------------------+
  		|     Constructeurs de la classe Moravec     |
	  	+--------------------------------------------+
		*/
	  		/////////////////////////////////////
	  		//     Constructeur par défaut     //
	  		/////////////////////////////////////
	  		Moravec();

	  		////////////////////////////////////////////////////////////////////////////
	  		//     Constructeur     												  //
	  		//		Input :															  //
	  		//			imageF (Image) : image dont on veut les points d'intérêts     //
	  		////////////////////////////////////////////////////////////////////////////
	  		Moravec(Image imageF);

	  		/////////////////////////////////////////////////////////////////////////////
	  		//     Constructeur     												   //
	  		//		Input :															   //
	  		//			imageF (Image) : image dont on veut les points d'intérêts      //
	  		//			seuil (double) : seuil d'acceptation comme point d'intérêt     //
	  		/////////////////////////////////////////////////////////////////////////////
	  		Moravec(Image imageF, double seuilF);

		/*
		+------------------------------------------+
  		|     Destructeur de la classe Moravec     |
	  	+------------------------------------------+
		*/
			~Moravec();

		/*
		+--------------------------------------+
  		|     Getters de la classe Moravec     |
	  	+--------------------------------------+
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

		/*
		+--------------------------------------+
  		|     Setters de la classe Moravec     |
	  	+--------------------------------------+
		*/
	  		//////////////////////////////////////////////////////////
	  		//     Fonction qui affecte un seuil d'acceptation     	//
	  		//		Input :											//
	  		//			seuilF (double) : seuil d'acceptation      	//
	  		//////////////////////////////////////////////////////////
	  		void setSeuil(double seuilF);

		/*
		+----------------------------------------+
  		|     Fonctions de la classe Moravec     |
	  	+----------------------------------------+
		*/
	  		///////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui extrait un morceau de l'image qui formera un masque 	 //
	  		//		Input : 									   				      	 //
	  		//			l (int) : numéro de la ligne de la case centrale du masque    	 //
	  		//			c (int) : numéro de la colonne de la case centrale du masque     //
	  		///////////////////////////////////////////////////////////////////////////////
			void extractionMask(int l, int c);

	  		////////////////////////////////////////////////////////
	  		//     Fonction qui calcule la dissemblence     	  //
	  		//		Input :										  //
	  		//			dx (int) : variation selon la ligne       //
	  		//			dy (int) : variation selon la colonne     //
	  		//		Output :									  //
	  		//			E (double) : dissemblence du pixel     	  //
	  		////////////////////////////////////////////////////////
	  		double calculE(int dx, int dy);

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
			double seuil;		//	Seuil d'acceptation comme point d'intérêts
			Image image;		//	Image dont on veut obtenir les points d'intérêts
			Matrice masque;		//	Morceau de l'image
			std::vector<Points> points;		//	Liste des points d'intérêts
	};

#endif