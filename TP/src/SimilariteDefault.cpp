#include "SimilariteDefault.h"
#include "Similarite.h"
#include "nr3.h"
#include "Deformation.h"
#include <math.h>

double SimilariteDefault::getSimilarite(const NRmatrix<double>& imgRef,
			     const NRmatrix<double>& imgDef,
        		     const NRmatrix<bool>& imgBin){
	double sim;
	int largeur= imgRef.nrows();
	int longueur = imgRef.ncols();
	int N = largeur * longueur;
	for (int i = 0; i < largeur ; i++){
		for (int j = 0; j < longueur; j++){
			if (imgBin[i][j]){
				sim = sim + pow(imgRef[i][j] - imgDef[i][j],2);
			}
		}
	}
	sim = sim/N;
	return sim;}
        
        
