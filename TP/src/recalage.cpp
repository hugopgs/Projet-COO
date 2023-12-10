#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>

#include "Recalage.h"
#include "Similarite.h"
#include "Interpolation.h"
#include "amoeba.h"
#include "Cout.h"

using namespace std;

NRmatrix<double> Recalage::lireImage(const string& nomFichier) {
	
	// Lire une image a partir du nom du fichier
	ifstream lecture(nomFichier); //on ouvre le fichier en lecture
	if (!lecture.fail()) {
		
		unsigned int U;
		char s[2];
		unsigned int i, j;
		lecture >> s; //on lit le premier caractère "P2"
		lecture >> i; //on lit la largeur de l'image
		lecture >> j; //on lit la hauteur de l'image
		lecture >> U; //on lit la valeur maximale des pixels
		NRmatrix<double> image(i, j); //on instancie une matrice de la taille de l'image
		for (unsigned int k = 0; k < i; k++)
			for (unsigned int l = 0; l < j; l++) { //on parcourt l'image
				lecture >> image[k][l]; //on lit la valeur du pixel
			}
		cout << "Ouverture du fichier " << nomFichier << " reussie" << endl; //on affiche un message de confirmation
		return image;
	} else {
		// NRmatrix<double> image(0, 0); 
		// cout << "Erreur lors de l'ouverture du fichier " << nomFichier << endl;
		// return image;
		throw invalid_argument("Erreur lors de l'ouverture du fichier " + nomFichier);
	}
}


void Recalage::construireFichier(const string& nomFichier, const NRmatrix<double> image) const {
	// ecrire une image depuis une matrice dans le fichier dont le nom est passé en entrée 
	ofstream flux(nomFichier); //on ouvre le fichier en écriture
	if (flux.fail()) {
		throw invalid_argument("Erreur lors de l'ouverture du fichier " + nomFichier);
		// cout << "Erreur lors de l'ouverture du fichier " << nomFichier << endl;
	} else {
		string U;
		int i, j;
		i = image.nrows();
		j = image.ncols();
		flux << "P2 " << i << " " << j << " 255" << endl;
		for (int k = 0; k < i; k++) {
			for (int l = 0; l < j; l++) //on parcourt l'image
				flux << image[k][l] << " "; //on écrit la valeur du pixel
			flux << endl; //on passe à la ligne
		}
		cout << "Ecriture du fichier " << nomFichier << " reussie" << endl; //on affiche un message de confirmation
	}
}

void Recalage::construireFichier(const string& nomFichier, const NRmatrix<bool> image) const {
	// ecrire une image depuis une matrice dans le fichier dont le nom est passé en entrée 
	ofstream flux(nomFichier);
	if (flux.fail()) {
		cout << "Erreur lors de l'ouverture du fichier " << nomFichier << endl;
	} else {
		string U;
		int i, j;
		i = image.nrows();
		j = image.ncols();
		flux << "P2 " << i << " " << j << " 255" << endl;
		for (int k = 0; k < i; k++) {
			for (int l = 0; l < j; l++)
				flux << image[k][l]*255 << " ";
			flux << endl;
		}
	}
}


VecDoub Recalage::getThetaMax(string f, string fRef, string fwrite, Similarite* sim, Interpolation* interp) {
	
	// On récupère les images
	NRmatrix<double> I = this->lireImage(f); // image à recaler
	NRmatrix<double> Iref = this->lireImage(fRef); // image de référence

	// On crée un objet Cout et un objet Amoeba
	Cout cout_(Iref, I, sim, interp);
	Amoeba amoeba(0.01);

	VecDoub ystart(3); // vecteur de départ
	ystart[0]=0;
	ystart[1]=0;
	ystart[2]=0;

	// On utilise la méthode amoeba pour trouver les paramètres de la transformation minimisant le cout
	VecDoub Thetamax(3);
	Thetamax = amoeba.minimize(ystart, 2., cout_);


	cout << "Voici ThetaMax : ";
	for (unsigned int i = 0; i<Thetamax.size(); i++) {
		cout << Thetamax[i] << " "; // on affiche les paramètres de la transformation
	}	cout << endl;

	// conversion des parametres de la transformation
	double* THETA = new double[3]; 
	THETA[0] = Thetamax[0];	
	THETA[1] = Thetamax[1];
	THETA[2] = Thetamax[2];

	// On recalcule l'image I à partir de Iref et de THETA
	Deformation def;

	// On applique la transformation à l'image
	NRmatrix<double> imageDef(I.ncols(), I.nrows());
	NRmatrix<bool> imageBin(I.ncols(), I.nrows());
	def.getDeformation(I, THETA, imageBin, imageDef, interp);
	cout << "Similarité pour ce Thetamax : " << sim->getSimilarite(I, imageDef, imageBin) << endl;
	
	}
	this->construireFichier(fwrite, imageDef); // on écrit l'image dans un fichier
	return Thetamax;
}

