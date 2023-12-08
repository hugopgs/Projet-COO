#pragma once //Permet d'éviter d'inclure plusieurs fois un même fichier

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "InterpolationDefault.h"
#include "SimilariteDefault.h"
#include "Similarite.h"
#include "Interpolation.h"
#include "nr3.h"
#include "amoeba.h"
#include "Cout.h"

using namespace std;


class Recalage {
public:
	NRmatrix<double> lireImage(const string&); // Lire une image a partir du nom du fichier
	void construireFichier(const string&, const NRmatrix<double>) const; // ecrire une image depuis une matrice dans le fichier dont le nom est passé en entrée 
	void construireFichier(const string&, const NRmatrix<bool>) const; // ecrire une image depuis une matrice dans le fichier dont le nom est passé en entrée 
	
VecDoub getThetaMax(string f, string fRef, string fwrite, Similarite* sim = 0, Interpolation* interp = 0); // renvoie le vecteur de transformation qui minimise le cout
VecDoub getThetaMax(string f, string fRef, Similarite* sim = 0, Interpolation* interp = 0);
VecDoub getThetaMax(string f, string fRef, Interpolation* interp);
VecDoub getThetaMax(string f, string fRef, Similarite* sim);
VecDoub getThetaMax(string f, string fRef, string fwrite, Interpolation* interp);
VecDoub getThetaMax(string f, string fRef, string fwrite, Similarite* sim);
};
