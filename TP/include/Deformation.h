#pragma once //Permet d'éviter d'inclure plusieurs fois un même fichier
#include "nr3.h"
#include "Transformation.h"
#include "Interpolation.h"
#include "InterpolationDefault.h"
  
class Deformation { 	
public:	
	void getDeformation(const NRmatrix<double>& I, //image à déformer
  		const double* THETA,
	  	NRmatrix<bool>& Ibin, //sortie, informe sur les pixels qui ont un sens où non  
	  	NRmatrix<double>& Idef, // Sortie
		Interpolation* interp // Si ca vaut zero on utilise la methode par defaut
		);
};