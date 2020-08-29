#ifndef SNAKE_VECTOR_H
#define SNAKE_VECTOR_H

typedef struct vector_ {
	int x;
	int y;
} Vector;

Vector vector2_add(Vector v1, Vector v2);

Vector vector2_mul(Vector v1, Vector v2);

#endif //SNAKE_VECTOR_H
