#include "Deformation.h"
#include "Interpolation.h"
#include "Transformation.h"

void Deformation::getDeformation(const NRmatrix<double>& I,
  		const double* THETA,
	  	NRmatrix<bool>& Ibin,
	  	NRmatrix<double>& Idef,
		Interpolation* interp){
	int ord = I.nrows();
	int abs = I.ncols();
	double valeur = 0;
	double xp;
	double yp;
	Transformation transfo;
	for (int i = 0; i<ord; i++){
		for (int j = 0; j<abs; j++){
			transfo.getNewpixels(j, i, THETA, xp, yp);
			if (interp->getInterpolation(xp, yp, I, valeur)){;
				Idef[i][j] = valeur;
				Ibin[i][j] = 1;}
			else{
				Ibin[i][j] = 0;}
		}
	}
}
	
			
