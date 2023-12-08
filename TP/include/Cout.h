#pragma once

#include "nr3.h"
#include "Interpolation.h"
#include "Similarite.h"
#include "Deformation.h"

class Cout {

private:
	NRmatrix<double> Iref, I; // images de reference et a transformer
	Similarite* sim; // fonction de similarite
	Interpolation* interp; // fonction d'interpolation


public:
	Cout(NRmatrix<double> Iref, 
		NRmatrix<double> I,
		Similarite* sim, // fonction de similarite si ca vaut zero on utilise la methode par defaut
		Interpolation* interp // fonction d'interpolation si ca vaut zero on utilise la methode par defaut
		); // constructeur + initialisation des attributs
	
	double getCout(const double* THETA) const; // calcul du cout pour une transformation donnee
	
	double operator() (const VecDoub& u) const
	{
		double* THETA = new double[u.size()];
		for (unsigned int i = 0; i < u.size(); i++) {
			THETA[i] = u[i];
		}
		return Cout::getCout(THETA);
	} // operateur () pour la classe NR3 (optimisation)
};
