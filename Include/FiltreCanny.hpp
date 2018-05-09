/*
+------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			 |
|	  Nom du Fichier : FiltreCanny.hpp									 |
|     Personnes : Takfarinas Kebci, Yann Nebout							 |
|     Objectif(s) du programme : Réalise les filtrages sur une image     |
|	  Date de Début : 26 Février 2018									 |
|	  Date de la dernière modification : 20 Mars 2018					 |
+------------------------------------------------------------------------+
*/

#ifndef FILTRECANNY_HPP
#define FILTRECANNY_HPP

	#include "FiltreGauss.hpp"
	#include "Gradient.hpp"

	class FiltreCanny : public Filtre{

		public:
		/*
		+-------------------------------------------+
  		|     Constructeurs de la classe Filtre     |
	  	+-------------------------------------------+
		*/
	  		/////////////////////////////////////
	  		//     Constructeur par défaut     //
	  		/////////////////////////////////////
	  		FiltreCanny();

	  		////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  //
	  		//		Input : 									  	  //
	  		//			image (Image) : image originale à filtrer     //
	  		////////////////////////////////////////////////////////////
	  		FiltreCanny(Image image);

	  		///////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  	 //
	  		//		Input : 									  	  	 //
	  		//			image (Image) : image originale à filtrer        //
	  		//			tailleF (int) : taille du noyau et du masque     //
	  		///////////////////////////////////////////////////////////////
	  		FiltreCanny(Image image, int tailleF);

	  		///////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  	 //
	  		//		Input : 									  	  	 //
	  		//			image (Image) : image originale à filtrer        //
	  		//			tailleF (int) : taille du noyau et du masque     //
	  		//			sigmaF (double) : écart type 			         //
	  		///////////////////////////////////////////////////////////////
	  		FiltreCanny(Image image, int tailleF, double sigmaF);

	  		///////////////////////////////////////////////////////////////
	  		//     Constructeur 						  			  	 //
	  		//		Input : 									  	  	 //
	  		//			image (Image) : image originale à filtrer        //
	  		//			tailleF (int) : taille du noyau et du masque     //
	  		//			sigmaF (double) : écart type 			         //
	  		//			seuilh (double) : seuil haut du filtre 		     //
	  		//			seuilb (double) : seuil bas du filtre 		     //
	  		///////////////////////////////////////////////////////////////
	  		FiltreCanny(Image image, int tailleF, double sigmaF, double seuilh, double seuilb);

	  		/////////////////////////////////////////////////
	  		//     Constructeur 						   //
	  		//		Input : 							   //
	  		//			f (Filtre &) : filtre à copier     //
	  		/////////////////////////////////////////////////
	  		FiltreCanny(const FiltreCanny& c);
		
		/*
		+-----------------------------------------+
  		|     Destructeur de la classe Filtre     |
	  	+-----------------------------------------+
		*/
	  		~FiltreCanny();

		/*
		+-------------------------------------+
  		|     Getters de la classe Filtre     |
	  	+-------------------------------------+
		*/
	  		//////////////////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur du seuil haut du filtre     //
	  		//		Output : 									  			//
	  		//			seuilH (double) : seuil haut du filtre			    //
	  		//////////////////////////////////////////////////////////////////
			double getSeuilHaut();

	  		/////////////////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur du seuil bas du filtre     //
	  		//		Output : 									  		   //
	  		//			seuilB (double) : seuil bas du filtre			   //
	  		/////////////////////////////////////////////////////////////////
			double getSeuilBas();

	  		////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur de l'écart type d'une gaussienne      //
	  		//		Output : 									  			 		  //
	  		//			sigma (double) : écart type de l'éventuel filtre gaussien     //
	  		////////////////////////////////////////////////////////////////////////////
			double getSigma();

	  	/*
		+-------------------------------------+
  		|     Setters de la classe Filtre     |
	  	+-------------------------------------+
		*/
	  		///////////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui affecte les seuils du seuillage par hystérésis du filtre     //
	  		//		Input : 									   				      		 //
	  		//			seuilh (double) : valeur désirée du seuil haut du filtre      		 //
	  		//			seuilb (double) : valeur désirée du seuil bas du filtre      		 //
	  		///////////////////////////////////////////////////////////////////////////////////
			void setSeuil(double seuilh, double seuilb);

	  		//////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui affecte un écart type pour une gaussienne    		  	//
	  		//		Input : 									   				        //
	  		//			sigmaF (double) : affecte un écart type pour une gaussienne     //
	  		//////////////////////////////////////////////////////////////////////////////
			void setSigma(double sigmaF);

	  	/*
		+---------------------------------------+
  		|     Fonctions de la classe Filtre     |
	  	+---------------------------------------+
		*/		
	  		//////////////////////////////////////////////
	  		//     Fonction qui réalise le filtrage     //
	  		//////////////////////////////////////////////
	  		void canny();

	  		////////////////////////////////////////////////////
	  		//     Fonction qui détermine les non maximas     //
	  		////////////////////////////////////////////////////
	  		void nonMaxima();

	  		//////////////////////////////////////////////
	  		//     Fonction qui réalise le filtrage     //
	  		//////////////////////////////////////////////
	  		void hysteresis();

	  		///////////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui donne la valeur positive de l'argument     					 //
	  		//	   (si -45° ramené à 135° par exemple)					   					 //
	  		//			i (int) : valeur de la ligne      		 							 //
	  		//			j (int) : valeur de la colonne      		 						 //
	  		///////////////////////////////////////////////////////////////////////////////////
	  		void normArg(int i, int j);

	  		//////////////////////////////////////////////////////////////////////////////
	  		//     Fonctions qui ramène l'argument d'un pixel à une valeur positive     //
	  		//		Input : 									   				      	//
	  		//			i (int) : valeur de la ligne      		 						//
	  		//			j (int) : valeur de  la colonne 				     		 	//
	  		//////////////////////////////////////////////////////////////////////////////
			void cmp0(int i, int j); 	// 	Si 180° -> arg=0°
			void cmp45(int i, int j);	//	Si -135° -> arg=45°
			void cmp90(int i, int j);	//	Si -90° -> arg=90°
			void cmp135(int i, int j);	//	Si -45° -> arg=135°

	  		///////////////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui compare les valeurs du gradient en fonction de l'orientation     //
	  		//		Input : 									   				      			 //
	  		//			i (int) : valeur de la ligne      		 								 //
	  		//			j (int) : valeur de  la colonne 				     		 			 //
	  		///////////////////////////////////////////////////////////////////////////////////////
			void comparaisonNorme(int i, int j);

	  		///////////////////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui compare les valeurs du gradient en fonction de la place du pixel     //
	  		//		Input : 									   				      			 	 //
	  		//			i (int) : valeur de la ligne      		 								 	 //
	  		//			j (int) : valeur de  la colonne 				     		 			 	 //
	  		///////////////////////////////////////////////////////////////////////////////////////////
			void hysteresisCoin(int i, int j);	//	Comparaison si coin
			void hysteresisBord(int i, int j);	//	Comparaison si bord
			void hysteresisAutre(int i, int j);	//	Comparaison autre cas

			//////////////////////////////////////////////////////////////////////////////////////////
	  		//     Fonction qui initialise le tableau des arguments du gradient de chaque pixel     //
	  		//////////////////////////////////////////////////////////////////////////////////////////
			void initArgument();

		protected:
			FiltreGauss fg;		//	Filtre Gaussien pour lisser
			Image image_gauss;	//	Image issue du filtre de gauss
			Image grad;			//	Image issue du filtre gradient
			double seuilH;		//	Seuil haut du seuillage par hystérésis
			double seuilB;		//	Seuil bas du seuillage par hystérésis
			double sigma;		//	Ecart type du filtre de gauss
			std::vector<std::vector<double> > argument;		//	Tableau d'argument du gradient de chaque pixel
	};

#endif