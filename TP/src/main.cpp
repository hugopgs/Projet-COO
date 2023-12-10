#include <stdio.h>
#include <chrono>
#include "Recalage.h"
#include "Deformation.h"
#include "InterpolationPpv.h"

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

	u = r.getThetaMax(f, fRef, fDef, &sim, &interp);


	return 0;
}