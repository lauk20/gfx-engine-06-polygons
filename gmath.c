#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gmath.h"
#include "matrix.h"
#include "ml6.h"


//vector functions
//normalize vetor, should modify the parameter
void normalize( double *vector ) {
}

//Return the dot porduct of a . b
double dot_product( double *a, double *b ) {
  double result = 0;

  result = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];

  return  result;
}


//Calculate the surface normal for the triangle whose first
//point is located at index i in polygons
double *calculate_normal(struct matrix *polygons, int i) {
  double vector_a [3];
  double vector_b [3];

  vector_a[0] = (polygons->m[0][i + 2] - polygons->m[0][i + 1]);
  vector_a[1] = (polygons->m[1][i + 2] - polygons->m[1][i + 1]);
  vector_a[2] = (polygons->m[2][i + 2] - polygons->m[2][i + 1]);

  vector_b[0] = (polygons->m[0][i] - polygons->m[0][i + 1]);
  vector_b[1] = (polygons->m[1][i] - polygons->m[1][i + 1]);
  vector_b[2] = (polygons->m[2][i] - polygons->m[2][i + 1]);


  double * vector = calloc(sizeof(double), 3);

  vector[0] = vector_a[1] * vector_b[2] - vector_a[2] * vector_b[1];
  vector[1] = vector_a[2] * vector_b[0] - vector_a[0] * vector_b[2];
  vector[2] = vector_a[0] * vector_b[1] - vector_a[1] * vector_b[0];
  
  return vector;
}
