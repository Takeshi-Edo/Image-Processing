/*
+---------------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     		  |
|	  Nom du Fichier : util.hpp										  |
|     Personnes : Takfarinas Kebci, Yann Nebout						  |
|     Objectif(s) du programme : intégrerles bibliothèques utiles     |
|	  Date de Début : 26 Février 2018								  |
|	  Date de la dernière modification : 19 Mars 2018				  |
+---------------------------------------------------------------------+
*/

#ifndef UTIL_HPP
#define UTIL_HPP

	// Bibliothèques de base du C++
    #include <iostream>		// Entrée sortie
	#include <fstream>		// Fichier
	#include <string>		// Ouvre la possibilité d'utilisé la classe String
	#include <cmath>		// Accès à la bibliothèque C math.h

	// Bibliothèques de base du C
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	// Bibliothèque OpenCV
	#include "opencv2/opencv.hpp"

	// Variables pour les filtres
	#define SIGMA 1
	#define SOBEL 0
	#define PREWITT 1
	#define LAPLACE1 0
	#define LAPLACE2 1

	// Variables pour l'algorithme SIFT
	#define THRESH 100
	#define MAXTHRESH 255

#endif