//Ray.h
//Class stores a Ray
#include <string>
#include "Vector3.h"

#ifndef RAY_H_
#define RAY_H_

class Ray {
public:
	Vector3 point;
	Vector3 direction;

	Ray(Vector3 p_, Vector3 d_) : point(p_), direction(d_.Normalized()) {}
};

#endif