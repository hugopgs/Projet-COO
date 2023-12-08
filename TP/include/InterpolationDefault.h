#pragma once

#include "Interpolation.h"

class InterpolationDefault : public Interpolation {
public:
    bool getInterpolation(double x,
        double y,
        const NRmatrix<double>& Image,
        double& val);
}; // classe pour l'interpolation par defaut


//La classe InterpolationDefault  hérite de la classe Interpolation, 
//hérite de ses attributs et méthodes publiques . 
//Comme Interpolation est classe abstraite avec une méthode virtuelle pure (getInterpolation), 
//InterpolationDefault est une spécialisation concrète de la classe abstraite Interpolation. 
 
//Fournit une implémentation spécifique pour cette méthode, qui peut être considérée comme une implémentation par défaut pour les classes dérivées.

//Les objets de type InterpolationDefault peuvent être utilisés partout où un objet de type Interpolation est attendu. 
