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
//	bool ok;
	Transformation transfo;
	std::cout<< "ord=" << ord <<std::endl;
	std::cout<< "abs=" << abs <<std::endl;
	for (int i = 0; i<ord; i++){
		std::cout<< "i=" << i <<std::endl;
		for (int j = 0; j<abs; j++){
			std::cout<< "j=" << j <<std::endl;
			transfo.getNewpixels(j, i, THETA, xp, yp);
			std::cout<< "xp=" << xp <<std::endl;
			std::cout<< "yp=" << yp <<std::endl;
			if (interp->getInterpolation(xp, yp, I, valeur)){;
				std::cout<< "xp=" << xp <<std::endl;
				std::cout<< "yp=" << yp <<std::endl;
				Idef[i][j] = valeur;
				Ibin[i][j] = 1;}
			else{
				Ibin[i][j] = 0;}
		}
	}
}
	
			
