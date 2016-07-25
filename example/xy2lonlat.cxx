#include <healpix.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv) {
  double x = atof(argv[1]);
  double y = atof(argv[2]);
  double ang[2];
  healpix hp(4,3);
  hp.xy2ang(ang, x, y);
  printf("%.12f %.12f\n", ang[0]*180/M_PI, ang[1]*180/M_PI);
}
