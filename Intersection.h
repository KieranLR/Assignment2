//Intersection.h
//Class stores a object that can be drawn using the raytracer

#include <stdint.h>
#include "Ray.h"

#ifndef INTERSECTION_H_
#define INTERSECTION_H_

class Primitive; // Forward declare Primitive, as they are mutually dependent (Intersection uses Primitive, Primitive uses Intersection)

class Intersection { //Class holding the Primitive hit, and distance travelled by a Ray to hit the Primitive  
  public:
	Primitive* p;
	float t;
  
	Intersection(Primitive* p_, float t_) {
		p = p_;
		t = t;
	}
	Intersection() {
		p = nullptr;
		t = 0;
	}
};


#endif
