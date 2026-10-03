#include "vector.h"
#include <math.h>

float Length(Vector* vec) {
  return sqrtf((vec->x * vec->x) + (vec->y * vec->y));
}

void NormVec(Vector* vec) {
  float l = Length(vec);
  vec->x = vec->x / l;
  vec->y = vec->y / l;
  return;
}
