#include "nr3.h"
#include "Interpolation.h"
#include "Similarite.h"
#include "Deformation.h"

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
	NRmatrix<double> Idef;
	NRmatrix<bool> Ibin;
	double THETA[3] = {1,2,3};
	deform.getDeformation(I, THETA, Ibin, Idef, interp);
	double s;
	s = sim.getSimilarite(Iref, Idef, imgBin);
	
	
	
	

