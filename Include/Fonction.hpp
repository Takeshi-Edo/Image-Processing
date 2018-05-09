/*
+-----------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     			|
|	  Nom du Fichier : Fonction.hpp										|
|     Personnes : Takfarinas Kebci, Yann Nebout							|
|     Objectif(s) du programme : mettre toutes les fonctions utiles     |
|	  Date de Début : 26 Février 2018									|
|	  Date de la dernière modification : 21 Mars 2018					|
+-----------------------------------------------------------------------+
*/

#ifndef FONCTION_HPP
#define FONCTION_HPP

	#include "Matrice.hpp"

	/*
	+----------------------------------------------------------------+
	|     Fonction qui réalise un produit de convolution discret     |
	|		Input : 												 |
	|			taille (int) : taille du noyau 						 |
	|			image[] (double) : mask de l'image à convoluer		 |
	|			noyau[] (double) : noyau car lequel on convolue		 |
	|		Output :												 |
	|			res (double) : résultat de la convolution			 |
	+----------------------------------------------------------------+
	*/
	double convolution(Matrice noyau, Matrice masque);

	/*
	+---------------------------------------------------------------+
	|     Fonction qui copie un tableau de nombre dans un autre     |
	|		Input : 												|
	|			taille (int) : taille des 2 tableaux				|
	|			dest[] (double) : tableau de destination			|
	|			src[] (double) : tableau source						|
	+---------------------------------------------------------------+
	*/
	void copieTab(int taille, double dest[], double src[]);

	/*
	+-------------------------------------------------------------------------+
	|     Fonction qui tri dans l'ordre coissant les valeurs d'un tableau     |
	|		Input : 														  |
	|			taille (int) : taille du tableaux							  |
	|			tab[] (double) : tableau à trier							  |
	+-------------------------------------------------------------------------+
	*/
	void tri(int taille, double tab[]);

#endif