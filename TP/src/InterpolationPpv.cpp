#include "nr3.h"
#include "InterpolationPpv.h"
#include <stdio.h>
#include <math.h>

bool InterpolationPpv::getInterpolation(double x, double y, const NRmatrix<double>& Image, double& val) {
	double H = Image.nrows(), L = Image.ncols();
	if ( (x < 0) || (x > H - 1) || (y < 0) || (y > L-1)) {
	// On ne peut pas interpoler car le point n’est pas dans le support de l’image
	// Que faire?
	 	val = 0;
		return false;
	} else {
	
		unsigned int i1 = floor(x+0.5); //on arrondit à l'entier le plus proche
		unsigned int j1 = floor(y+0.5); //on arrondit à l'entier le plus proche

		val = Image[i1][j1]; //la valeur de I au point (x,y) est res
		return true; //on retourne true car le point est dans le support de l'image
	}
}