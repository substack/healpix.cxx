#include <healpix.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv) {
  double phi = atof(argv[1]) / 180 * M_PI;
  double theta = atof(argv[2]) / 180 * M_PI;
  double xy[2];
  healpix hp(4,3);
  hp.ang2xy(xy, phi, theta);
  printf("%f %f\n", xy[0], xy[1]);
}
