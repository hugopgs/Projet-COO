#pragma once

#include "nr3.h"
#include "Deformation.h"
#include "Similarite.h"

class SimilariteMutualinformation : Similarite {
public:
		double getSimilarite(const NRmatrix<double>& imgRef, 
		const NRmatrix<double>& imgDef,
        const NRmatrix<bool>& imgBin
		); // retourne la similarite entre l'image de reference et l'image deforme
};
