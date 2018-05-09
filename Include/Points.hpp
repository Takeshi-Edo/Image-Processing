/*
+-----------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     	  |
|	  Nom du Fichier : Points.hpp								  |
|     Personnes : Takfarinas Kebci, Yann Nebout					  |
|     Objectif(s) du programme : Définir un point d'une image     |
|	  Date de Début : 26 Février 2018							  |
|	  Date de la dernière modification : 21 Mars 2018			  |
+-----------------------------------------------------------------+
*/

#ifndef POINTS_HPP
#define POINTS_HPP

	#include "util.hpp"

	class Points{

		public:
		/*
		+-------------------------------------------+
  		|     Constructeurs de la classe Points     |
	  	+-------------------------------------------+
		*/
	  		/////////////////////////////////////
	  		//     Constructeur par défaut     //
	  		/////////////////////////////////////
			Points();

	  		/////////////////////////////////////////////////
	  		//     Constructeur     					   //
	  		//		Input :								   //
	  		//			l (int) : numéro de la ligne	   //
	  		//			c (int) : numéro de la colonne     //
	  		/////////////////////////////////////////////////
			Points(int l, int c);

		/*
		+-----------------------------------------+
  		|     Destructeur de la classe Points     |
	  	+-----------------------------------------+
		*/
	  		~Points();

		/*
		+-------------------------------------+
  		|     Getters de la classe Points     |
	  	+-------------------------------------+
		*/
	  		//////////////////////////////////////////////////////
	  		//     Fonction qui donne le numéro de la ligne     //
	  		//		Output : 									//
	  		//			x (int) : numéro de la ligne			//
	  		//////////////////////////////////////////////////////
			int getX();

	  		////////////////////////////////////////////////////////
	  		//     Fonction qui donne le numéro de la colonne     //
	  		//		Output : 									  //
	  		//			y (int) : numéro de la colonne			  //
	  		////////////////////////////////////////////////////////
			int getY();

		/*
		+-------------------------------------+
  		|     Setters de la classe Points     |
	  	+-------------------------------------+
		*/
	  		////////////////////////////////////////////////////////
	  		//     Fonction qui affecte un numéro de la ligne     //
	  		//		Input : 									  //
	  		//			l (int) : numéro de la ligne			  //
	  		////////////////////////////////////////////////////////
	  		void setX(int l);

	  		//////////////////////////////////////////////////////////
	  		//     Fonction qui affecte un numéro de la colonne     //
	  		//		Input : 									  	//
	  		//			y (int) : numéro de la colonne			  	//
	  		//////////////////////////////////////////////////////////
	  		void setY(int c);

		protected:
			int x;
			int y;
	};

#endif