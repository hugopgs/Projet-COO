#pragma once //Permet d'éviter d'inclure plusieurs fois un même fichier

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "InterpolationPpv.h"
#include "InterpolationDefault.h"
#include "SimilariteDefault.h"
#include "SimilariteMutualInformation.h
#include "Similarite.h"
#include "Interpolation.h"
#include "nr3.h"
#include "amoeba.h"
#include "Cout.h"

using namespace std;


int main() {

	Recalage r;
	string f="floating.pgm", fRef="reference.pgm", fppv = "imageDefPpv.pgm"; fDef = "imageDef.pgm"
	InterpolationPpv interpppv;
    	InterpolationDefault interpDef;
	Deformation d;
	SimilariteDefault sim;


	// string f, fRef;
	// cout << "Entrez le nom du fichier a recaler : ";
	// cin >> f;
	// cout << "Entrez le nom du fichier de reference : ";
	// cin >> fRef;

	cout << "---------------------Interp PPV---------------------" << endl;



	VecDoub u = r.getThetaMax(f, fRef, fppv, &sim, &interpppv);



	cout << "---------------------Interp Default---------------------" << endl;

	u = r.getThetaMax(f, fRef, fDef, &sim, &interpDef);


	return 0;
}
