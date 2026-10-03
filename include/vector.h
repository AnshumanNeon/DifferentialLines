#ifndef VECTOR_H

typedef struct {
  float x;
  float y;
  float z;
} Vector;

float Length(Vector* vec);
void NormVec(Vector* vec);

#define VECTOR_H
#endif
