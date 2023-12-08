#pragma once //Permet d'éviter d'inclure plusieurs fois un même fichier

#include "nr3.h"

class Interpolation {
public:
	virtual bool getInterpolation(double x, 
		double y, //coordonnées de l'image
		const NRmatrix<double>& Image, //image entrée
		double& val //sortie
		) = 0; // renvoie la valeur de l'interpolation en x,y
}; // classe abstraite pur pour les interpolations