#include "nr3.h"
#include "Interpolation.h"
#include "InterpolationDefault.h"
#include "Similarite.h"
#include "Deformation.h"
#include "Cout.h"

Cout::Cout(NRmatrix<double> Iref1, 
		NRmatrix<double> I1,
		Similarite* sim1,
		Interpolation* interp1){
	Iref = Iref1;
	I = I1;
	sim = sim1;
	interp = interp1;}
	

	
double Cout::getCout(const double* THETA) const {
	Deformation deform;
	NRmatrix<double> Idef(I.ncols(),I.nrows());
	NRmatrix<bool> Ibin(I.ncols(),I.nrows());
	deform.getDeformation(I, THETA, Ibin, Idef, interp);
	std::cout<< 2 <<std::endl;
	double s;
	s = sim->getSimilarite(Iref, Idef, Ibin);
	return s;}
	
	
	
	

