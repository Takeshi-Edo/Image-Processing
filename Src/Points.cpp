/*
+-----------------------------------------------------------------+
|     Projet : Aide à la maitenance en réalité augmentée     	  |
|	  Nom du Fichier : Points.cpp								  |
|     Personnes : Takfarinas Kebci, Yann Nebout					  |
|     Objectif(s) du programme : Définir un point d'une image     |
|	  Date de Début : 26 Février 2018							  |
|	  Date de la dernière modification : 21 Mars 2018			  |
+-----------------------------------------------------------------+
*/

#include "Points.hpp"

// Utilisation des espaces de noms std
using namespace std;

Points::Points(){
	x = 0;
	y = 0;
}

Points::Points(int l, int c){
	x = l;
	y = c;
}

Points::~Points(){}

int Points::getX(){ return x; }
int Points::getY(){ return y; }

void Points::setX(int l){ x = l; }
void Points::setY(int c){ y = c; }