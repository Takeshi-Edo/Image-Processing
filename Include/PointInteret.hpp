/*
+------------------------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     							   |
|	  Nom du Fichier : PointInteret.hpp													   |
|     Personnes : Takfarinas Kebci, Yann Nebout							  				   |
|     Objectif(s) du programme : réaliser le détecteur de points d'intérêts de Moravec     |
|	  Date de Début : 26 Février 2018									  				   |
|	  Date de la dernière modification : 21 Mars 2018					  				   |
+------------------------------------------------------------------------------------------+
*/

#ifndef POINTINTERET_HPP
#define POINTINTERET_HPP

	#include "Points.hpp"
	#include "Image.hpp"
	#include "Matrice.hpp"

	class PointInteret{

		public:
		/*
		+-------------------------------------------------+
  		|     Constructeurs de la classe PointInteret     |
	  	+-------------------------------------------------+
		*/
			//////////////////////////////////////////////////////////////////////////////////////////
			//     Constructeur     																//
			//		Input : 												 						//
			//			im1 (Image) : image de référence 											//
			//			im2 (Image) : image étudiée													//
			//			p1 (vector<Points>) : liste de point d'intérêts de l'image de référence     //
			//			p2 (vector<Points>) : liste de point d'intérêts de l'image de étudiée     	//
			//////////////////////////////////////////////////////////////////////////////////////////
			PointInteret(Image im1, Image im2, std::vector<Points> p1, std::vector<Points> p2);

			//////////////////////////////////////////////////////////////////////////////////////////
			//     Constructeur     																//
			//		Input : 												 						//
			//			im1 (Image) : image de référence 											//
			//			im2 (Image) : image étudiée													//
			//			p1 (vector<Points>) : liste de point d'intérêts de l'image de référence     //
			//			p2 (vector<Points>) : liste de point d'intérêts de l'image de étudiée     	//
			//			tailleF (int) : taille de la fenêtre 								     	//
			//////////////////////////////////////////////////////////////////////////////////////////
			PointInteret(Image im1, Image im2, std::vector<Points> p1, std::vector<Points> p2, int tailleF);

			//////////////////////////////////////////////////////////////////////////////////////////
			//     Constructeur     																//
			//		Input : 												 						//
			//			im1 (Image) : image de référence 											//
			//			im2 (Image) : image étudiée													//
			//			p1 (vector<Points>) : liste de point d'intérêts de l'image de référence     //
			//			p2 (vector<Points>) : liste de point d'intérêts de l'image de étudiée     	//
			//			tailleF (int) : taille de la fenêtre 								     	//
			//			typeF (int) : type de corrélation désirée							     	//
			//////////////////////////////////////////////////////////////////////////////////////////
			PointInteret(Image im1, Image im2, std::vector<Points> p1, std::vector<Points> p2, int tailleF, int typeF);

		/*
		+-----------------------------------------------+
  		|     Destructeur de la classe PointInteret     |
	  	+-----------------------------------------------+
		*/
			~PointInteret();

		/*
		+-------------------------------------------+
  		|     Getters de la classe PointInteret     |
	  	+-------------------------------------------+
		*/
			//////////////////////////////////////////////////////////////////////////////////////
			//     Fonction qui donne un tableau de points corrélés     				   		//
			//		Output :												 			   		//
			//			pointsApparies (vector<vector<Points> >) : liste de points appariés     //
			//////////////////////////////////////////////////////////////////////////////////////
			std::vector<std::vector<Points> > getPointCorr();

			////////////////////////////////////////////////////////////////////////
			//     Fonction qui donne un point corrélé     						  //
			//		Input : 												 	  //
			//			i (int) : numéro de la ligne							  //
			//			j (int) : numéro de la colonne							  //
			//		Output :												 	  //
			//			pointsApparies[i][j] (Points) : point qui est apparié     //
			////////////////////////////////////////////////////////////////////////
			Points getPointCorrelation(int i, int j);

		/*
		+---------------------------------------------+
  		|     Fonctions de la classe PointInteret     |
	  	+---------------------------------------------+
		*/
			//////////////////////////////////////////////////////////////////////
			//     Fonction qui donne un masque autour du point d'intérêt 		//
			//		Input : 												 	//
			//			mask (int) : masque de l'image considérée				//
			//			p (Points) : point autour duquel ont met le masque      //
			//////////////////////////////////////////////////////////////////////
			void assigneMasque(int mask, Points p);

			////////////////////////////////////////////////////////////
			//     Fonction qui calcule la moyenne du masque     	  //
			//		Input : 										  //
			//			mask (int) : masque de l'image considérée     //
			//		Output :										  //
			//			res (double) : moyenne du masque    		  //
			////////////////////////////////////////////////////////////
			double moyenne(int mask);

			////////////////////////////////////////////////////////////
			//     Fonction qui calcule une somme     				  //
			//		Input :											  //
			//			moy (int) : moyenne du masque 		    	  //
			//			mask (int) : masque de l'image considérée     //
			//		Output :										  //
			//			res (double) : résultat de la somme     	  //
			////////////////////////////////////////////////////////////
			double somme(int moy, int mask);

			//////////////////////////////////////////////////////////////////////////
			//     Fonction qui calcule la norme d'une matrice     					//
			//		Input : 												 		//
			//			mask (int) : masque de l'image considérée					//
			//			moy (double) : moyenne des valeurs des pixels du masque     //
			//		Output :												 		//
			//			n (double) : norme de la matrice			     			//
			//////////////////////////////////////////////////////////////////////////
			double norme(int mask, double moy);

			/////////////////////////////////////////////////////////
			//     Fonction qui choisit le type de corrélation     //
			/////////////////////////////////////////////////////////
			double choixType();

			//////////////////////////////////////////////////////////////////////////
			//     Fonction qui réalise l'appariement     							//
			//		Input : 												 		//
			//			i (int) : numéro du point de l'image de référence 			//
			//			j (int) : numéro du point de l'image de étudiée				//
			//			app (double*) : pointeur sur une variable intermédiaire     //
			//////////////////////////////////////////////////////////////////////////
			void appariement(int i, int j, double *app);
			
			/////////////////////////////////////////////////////////////////////
			//     Fonction qui calcul le corrélation de points d'intérêts     //
			/////////////////////////////////////////////////////////////////////
			void correlation();

			///////////////////////////////////////////////////////////////////////////
			//     Fonction qui réalise l'algorithme "Sum of Squared Difference"     //
			//		Output :												 		 //
			//			res (double) : resultat de la corrélation 	     			 //
			///////////////////////////////////////////////////////////////////////////
			double SSD();

			/////////////////////////////////////////////////////////////////////////////////////
			//     Fonction qui réalise l'algorithme "Zero mean Sum of Squared Difference"     //
			//		Output :												 		 		   //
			//			res (double) : resultat de la corrélation 	     			 		   //
			/////////////////////////////////////////////////////////////////////////////////////
			double ZSSD();

			///////////////////////////////////////////////////////////////////////////
			//     Fonction qui réalise l'algorithme "Sum of Absolue Difference"     //
			//		Output :												 		 //
			//			res (double) : resultat de la corrélation 	     			 //
			///////////////////////////////////////////////////////////////////////////
			double SAD();

			/////////////////////////////////////////////////////////////////////////////////////
			//     Fonction qui réalise l'algorithme "Zero mean Sum of Absolue Difference"     //
			//		Output :												 		 		   //
			//			res (double) : resultat de la corrélation 	     			 		   //
			/////////////////////////////////////////////////////////////////////////////////////
			double ZSAD();

			//////////////////////////////////////////////////////////////////////////////
			//     Fonction qui réalise l'algorithme "Normalized Cross-Correlation"     //
			//		Output :												 		 	//
			//			res (double) : resultat de la corrélation 	     			 	//
			//////////////////////////////////////////////////////////////////////////////
			double NCC();

			////////////////////////////////////////////////////////////////////////////////////////
			//     Fonction qui réalise l'algorithme "Zero Mean Normalized Cross-Correlation"     //
			//		Output :												 		 			  //
			//			res (double) : resultat de la corrélation 	     			 			  //
			////////////////////////////////////////////////////////////////////////////////////////
			double ZNCC();

		protected:
			int taille; 			//	Taille du masque
			int type;				//	Type de corrélation
			Image imageEtu;			//	Image étudiée
			Image imageRef;			//	Image de référence
			Matrice masqueEtu;		//	Morceau de l'image étudiée
			Matrice masqueRef;		//	Morceau de l'image de référence
			std::vector<Points> pointsEtu;		//	Liste des points d'intérêts
			std::vector<Points> pointsRef;		//	Liste des points d'intérêts
			std::vector<std::vector<Points> > pointsApparies;		//	Liste des points d'intérêts
	};

#endif