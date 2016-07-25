# healpix.cxx

c++ code to transform [healpix][1] coordinates

[1]: http://web.ipac.caltech.edu/staff/fmasci/home/astro_refs/HEALPix_Calabretta.pdf

# example

## lonlat2xy

lon/lat to healpix x/x:

``` c++
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
  printf("%.12f %.12f\n", xy[0], xy[1]);
}
```

output:

```
$ ./lonlat2xy -148 65
-2.476485479234 -1.154404441650
```

## xy2lonlat

healpix x/y to lon/lat:

``` c++
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
```

output:

```
$ ./xy2lonlat -2.476485479234 -1.154404441650
-147.999999999978 -65.000000000001
```

# api

``` c++
#include <healpix.h>
```

## `healpix hp(unsigned int H, unsigned int K)`

Create a new healpix instance `hp` for a grid parameterized by `H,K`.

## `void hp.ang2xy(double *out, double phi, double theta)`

Convert `phi,theta` (lon/lat in radians) to `x,y`, written to out[0], out[1].

## `void hp.xy2ang(double *out, double x, double y)`

Convert `x,y` to `phi,theta`, written to out[0], out[1].

# license

BSD
