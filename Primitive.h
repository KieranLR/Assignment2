//Primitive.h
//Class stores a object that can be drawn using the raytracer



#include <stdint.h>
#include "Ray.h"
#include "Intersection.h"

#ifndef PRIMITIVE_H_
#define PRIMITIVE_H_
	class Primitive {
	public:

		float x; // Position of object in 3d space
		float y;
		float z;

		Vector3 v;

		Primitive(float x_, float y_, float z_) : x(x_), y(y_), z(z_), v(Vector3(x, y, z)) {}

		virtual Intersection Intersect(Ray ray) = 0;


	};


#endif
