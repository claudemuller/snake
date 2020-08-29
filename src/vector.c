#include "vector.h"

Vector vector2_add(Vector v1, Vector v2) {
	return (Vector) {
			.x = v1.x + v2.x,
			.y = v1.y + v2.y
	};
}

Vector vector2_mul(Vector v1, Vector v2) {
	return (Vector) {
			.x = v1.x * v2.x,
			.y = v1.y * v2.y
	};
}

