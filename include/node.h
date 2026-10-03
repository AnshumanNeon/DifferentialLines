#ifndef NODE_H
#include "vector.h"

typedef struct {
  Vector2 pos;
  Node* next_node;
  Node* prev_node;
} Node;

#define NODE_H
#endif
