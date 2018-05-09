/*
+-------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			  |
|	  Nom du Fichier : Matrice.hpp										  |
|     Personnes : Takfarinas Kebci, Yann Nebout							  |
|     Objectif(s) du programme : réaliser les calculs sur une matrice     |
|	  Date de Début : 26 Février 2018									  |
|	  Date de la dernière modification : 15 Mars 2018					  |
+-------------------------------------------------------------------------+
*/

#ifndef MATRICE_HPP
#define MATRICE_HPP

	#include "util.hpp"

	class Matrice{

		public:
		/*
		+--------------------------------------------+
  		|     Constructeurs de la classe Matrice     |
	  	+--------------------------------------------+
		*/
	  		/////////////////////////////////////
	  		//     Constructeur par défaut     //
	  		/////////////////////////////////////
	  		Matrice();

	  		////////////////////////////////////////////////////////
	  		//     Constructeur     							  //
	  		//		Input : 									  //
	  		//			largeur (int) : largeur de la matrice     //
	  		//			hauteur (int) : hauteur de la matrice 	  //
	  		////////////////////////////////////////////////////////
			Matrice(int largeur, int hauteur);

	  		/////////////////////////////////////////////////////////////////////////////////////////
	  		//     Constructeur     							  								   //
	  		//		Input : 									  								   //
	  		//			mat (vector<vector<double> >) : matrice dont on veut copié des valeurs     //
	  		/////////////////////////////////////////////////////////////////////////////////////////
			Matrice(std::vector<std::vector<double> > mat);

	  		////////////////////////////////////////////////////////////////////
	  		//     Constructeur par copie						  			  //
	  		//		Input : 							  		  			  //
	  		//			m (Matrice &) : addresse sur une variable Matrice     //
	  		////////////////////////////////////////////////////////////////////
			Matrice(const Matrice& m);

		/*
		+------------------------------------------+
  		|     Destructeur de la classe Matrice     |
	  	+------------------------------------------+
		*/
			~Matrice();

		/*
		+--------------------------------------+
  		|     Getters de la classe Matrice     |
	  	+--------------------------------------+
		*/
			///////////////////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur d'une case de la matrice     //
	  		//		Input : 									  			 //
	  		//			i (int) : numéro de la ligne     					 //
	  		//			j (int) : numéro de la colonne 	  					 //
	  		//		Output : 									  			 //
	  		//			matrice[i][j] (double) : valeur de la case (i,j)     //
	  		///////////////////////////////////////////////////////////////////
			double getValeur(int i, int j) const;

			////////////////////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur de la trace de la matrice     //
	  		//		Output : 									  			  //
	  		//			t (double) : valeur de la trace      				  //
	  		////////////////////////////////////////////////////////////////////
			double getTrace() const;

			///////////////////////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur du déterminant de la matrice     //
	  		//		Output : 									  			 	 //
	  		//			det (double) : valeur du déterminant				     //
	  		///////////////////////////////////////////////////////////////////////
			double getDeterminant() const;

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
		+--------------------------------------+
  		|     Setters de la classe Matrice     |
	  	+--------------------------------------+
		*/
			//////////////////////////////////////////////////////////////////////
	  		//     Fonction qui affecte une valeur à une case de la matrice     //
	  		//		Input : 									  				//
	  		//			i (int) : ligne de la matrice     						//
	  		//			j (int) : colonne de la matrice 	  					//
	  		//			val (double) : valeur de la case à copier 	  			//
	  		//////////////////////////////////////////////////////////////////////
			void setValeur(int i, int j, double val);

			///////////////////////////////////////////////////////////////
	  		//     Fonction qui affecte des dimensions à une matrice     //
	  		//		Input : 											 //
	  		//			largeur (int) : largeur de la matrice     		 //
	  		//			hauteur (int) : hauteur de la matrice 	  		 //
	  		///////////////////////////////////////////////////////////////
			void setDimension(int hauteur, int largeur);

		/*
		+----------------------------------------+
  		|     Fonctions de la classe Matrice     |
	  	+----------------------------------------+
		*/
			///////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui test si la matrice est carrée ou non     			 //
	  		//		Output : 									  					 //
	  		//			carre (bool) : variable qui dit si la matrice est carrée     //
	  		///////////////////////////////////////////////////////////////////////////
			bool estCarre();

			//////////////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui copie une partie de la matrice pour calculer le déterminant     //
	  		//		Input : 									  								//
	  		//			taille (int) : taille du morceau de la matrice							//
	  		//			dest (Matrice&) : addresse vers le morceau de la matrice				//
	  		//			l (int) : numéro de la colonne à sauter									//
	  		//////////////////////////////////////////////////////////////////////////////////////
			void copiemMatrice(int taille, Matrice &dest, int l);

			////////////////////////////////////////////////
	  		//     Fonction qui calcul le déterminant     //
	  		////////////////////////////////////////////////
			void calculDeterminant();

			//////////////////////////////////////////
	  		//     Fonction qui calcul la trace     //
	  		//////////////////////////////////////////
			void calculTrace();

		protected:

			int ligne;				// Nombre de ligne
			int colonne;			// Nombre de colonne
			double trace;			// Trace de la matrice
			double determinant;		// Déterminant de la matrice
			bool carre;				// Booléen sur la taille pour dire si la matrice est carrée ou non
			std::vector<std::vector<double> > matrice;	// Matrice contenant le valeur (Matrice à proprement parlée)
	};

#endif