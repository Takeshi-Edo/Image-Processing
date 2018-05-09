/*
+-----------------------------------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     									|
|	  Nom du Fichier : TraitementImage.hpp														|
|     Personnes : Takfarinas Kebci, Yann Nebout													|
|     Objectif(s) du programme : intégrer toute la bibliothèque de traitement d'image créée     |
|	  Date de Début : 26 Février 2018															|
|	  Date de la dernière modification : 21 Mars 2018											|
+-----------------------------------------------------------------------------------------------+
*/

#ifndef TRAITEMENTIMAGE_HPP
#define TRAITEMENTIMAGE_HPP

	//	Fichier ".hpp" de filtrage
	#include "FiltreMoyenneur.hpp"	//	Intègre la définition générale d'un Filtre et d'une Image
	#include "FiltreMedian.hpp"	//	Intègre la définition générale d'un Filtre et d'une Image

	//	Fichier ".hpp" de détection de contour
	#include "FiltreCanny.hpp"	//	Intègre le filtre de gauss et le gradient
	#include "Laplace.hpp"	//	Intègre la définition générale d'un Filtre et d'une Image

	//	Fichier ".hpp" de détection de points d'intérêts
	#include "Moravec.hpp"	//	Intègre la définition d'une image et d'un point
	#include "Harris.hpp"	//	Intègre la définition d'une image et d'un point
	#include "PointInteret.hpp"	//	Réalise la corrélation entre deux listes de points d'intérêts

#endif