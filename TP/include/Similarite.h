#pragma once //Permet d'éviter d'inclure plusieurs fois un même fichier

#include "nr3.h"
#include "Deformation.h"

class Similarite {
public:
	virtual double getSimilarite(const NRmatrix<double>& imgRef,
		const NRmatrix<double>& imgDef,
        const NRmatrix<bool>& imgBin //Image binaire informe sur les pixels qui ont un sens où non 
		) = 0; //methode virtuelle pur
};//retourne la similarite entre l'image de reference et l'image deforme
