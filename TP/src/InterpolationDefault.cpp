#include "InterpolationDefault.h"
#include "nr3.h"
#include <stdio.h>
#include <math.h>

bool InterpolationDefault::getInterpolation(double x, double y, const NRmatrix<double>& Image, double& val) {
	double H = Image.nrows(), L = Image.ncols();
	if ( (x < 0) || (x > H - 1) || (y < 0) || (y > L-1)) {
	// On ne peut pas interpoler car le point n’est pas dans le support de l’image
	// Que faire?
	 	val = 0;
		return false;
	} else {
		int i1, i2, j1, j2;
		double dx, dy, dfy, dfx, dfxy, res ;

		i1 = floor(x);
		j1 = floor(y);
		if (i1==H-1)
			i1--;
		if (j1==L-1)
			j1--;
		i2 = i1+1 ;
		j2 = j1+1 ;
		//Le point (x,y) est dans le carre defini par les points discrets (i1 , j1) ,( i1 ,j2) ,( i2 , j2) ,( i2 , j1) .

		dx = x - i1;
		dy = y - j1;
		dfx = Image[i2][j1] - Image[i1][j1];
		dfy = Image[i1][j2] - Image[i1][j1];
		dfxy = Image[i1][j1] + Image[i2][j2] - Image[i2][j1] - Image[i1][j2];
		res = Image[i1][j1] + dfx * dx + dfy * dy + dx*dy*dfxy;
		//la valeur de I au point (x,y) est res
		val = floor(res);
		return true;
	}
}