#ifndef HEALPIX_H
#define HEALPIX_H

#include <math.h>

class healpix {
public:
  unsigned int H, K;
  double thetax;
  healpix (unsigned int h, unsigned int k) {
    H = h;
    K = k;
    thetax = asin((K-1)/K);
  }
  void ang2xy (double *out, double phi, double theta) {
    double sigma, phic, omega;
    omega = K % 2 == 1 || theta > 0 ? 1 : 0;
    if (fabs(theta) > thetax) { // polar
      sigma = sqrt(K*(1-fabs(sin(theta))));
      phic = -M_PI+(2*floor((phi+M_PI)*H/(2*M_PI)+(1-omega)/2)+omega)*M_PI/H;
      out[0] = phic + (phi - phic) * sigma;
      out[1] = (theta > 0 ? -1 : 1) * M_PI / H * ((K+1)/2 - sigma);
    } else { // equatorial
      out[0] = phi;
      out[1] = K*M_PI/(2*H)*sin(theta);
    }
  }
  void xy2ang (double *out, double x, double y) {
    double phi, theta, sigma, omega, xc;
    if (fabs(y) > M_PI/2*(K-1)/H) { // polar
      sigma = (K+1)/2 - fabs(y*H)/M_PI;
      theta = (y>0?1:-1) * asin(1-sigma*sigma/K);
      omega = K % 2 == 1 || theta > 0 ? 1 : 0;
      xc = -M_PI+(2*floor((x+M_PI)*H/(2*M_PI) + (1-omega)/2)+omega)*M_PI/H;
      phi = xc + (x - xc) / sigma;
    } else { // equatorial
      phi = x;
      theta = asin(y*H*2/(M_PI*K));
    }
    out[0] = phi;
    out[1] = theta;
  }
};
#endif
