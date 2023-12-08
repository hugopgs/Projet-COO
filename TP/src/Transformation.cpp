#include "Transformation.h"
#include <math.h>

void Transformation ::getNewpixels(
    double x, double y,    // coord avant transformation
    const double *THETA,   // THETA=[tx,ty,theta]
    double &xp, double &yp // coord après transfo
    ) // renvoie les coordonnees du pixel apres transformation
{
  double theta = THETA[2];
  xp = cos(theta) * x - sin(theta) * y + THETA[0];
  yp = sin(theta) * x + cos(theta) * y + THETA[1];
}