#pragma once //Permet d'éviter d'inclure plusieurs fois un même fichier

class Transformation {
public:
	void getNewpixels(double x, double y, //coord avant transformation
	const double* THETA,  //THETA=[tx,ty,theta]
	double& xp, double& yp //coord après transfo
	); // renvoie les coordonnees du pixel apres transformation
};
