#pragma once

#include "Interpolation.h"

class InterpolationPpv : public Interpolation {
public:
	bool getInterpolation(double x,
		double y,
		const NRmatrix<double>& Image,
		double& val);
}; // classe pour l'interpolation par ppv (plus proches voisins)

//pareil qu'interpolationDefaults mais implementation différentes de la methode getinterpolation.