//Sphere.h
//Class stores a sphere

#ifndef SPHERE_H_
#define SPHERE_H_

#include <stdint.h>
#include "Primitive.h"

class Sphere : public Primitive {
public:
	float r; // Radius of sphere
	Sphere(float x_, float y_, float z_, float r_) : Primitive(x_, y_, z_), r(r_) {}

	Intersection Primitive::Intersect(Ray ray) { //if a ray hits this sphere, return a pointer
												 //to this sphere, else return null.
		Vector3 p = ray.point;
		Vector3 d = ray.direction;
		// Ray = Point + Direction * t0
		// Sphere = (x - x1)^2 + (y - y1)^2 + (z - z1)^2 = r^2
		//Substitute Ray x,y,z into Sphere 3d equation, and solve for t. (Quadratic formula required)
		//Quadratic formula values:

		//if the ray direction was not normalized, it would look like this: float A = d.x  * d.x + d.y * d.y + d.z * d.z;
		//but since it is normalized, A is equal to 1
		
		
		Vector3 offset = p - v; // Offset sphere position from origin of ray (v is position of sphere, p is origin of Ray)
		float B = 2 * offset.Dot(d); 
		float C = offset.Dot(offset) - r * r;
		float disc = B * B - 4 * C;


		if (disc < 0) { // if discriminant is less than 0, the ray does not intersect the sphere.
			return Intersection();
		}
		float t0 = (-B + sqrt(disc)) / 2; //t0 and t1 are the two points of intersection of the ray		
		if (t0 > 0) {
			return Intersection(this, t0); //Return the smallest positive t value (first point of intersection)
		}
		else {
			float t1 = (-B - sqrt(disc)) / 2;
			if (t1 > 0) {
				return Intersection(this, t1);
			}
		}
	};
};


#endif
