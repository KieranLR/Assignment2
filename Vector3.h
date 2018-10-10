//Vector3.h
//Class stores a vector, and is capable of many common
//vector operations
#include <string>

#ifndef VECTOR3_H_
#define VECTOR3_H_

class Vector3 {
	public:
		float x;
		float y;
		float z;

	//Constructor with coordinate
	Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
	//Constructor without coordinate
	Vector3() : x(0), y(0), z(0) {}

	//Calculates the dot product between two vectors
	float Dot(const Vector3& v);

	//Calculates the cross product between two vectors
	Vector3 Cross(const Vector3& v);

	//Linearly interpolates between two vectors
	Vector3 Lerp(const Vector3& v, float t);

	//Calculates length of the vector
	float Magnitude();

	//Calculates distance between two vectors
	float Distance(const Vector3& v);

	//Returns a normalized version of the vector
	Vector3 Normalized();

	//Returns a string containing the x, y, and z values of the vector
	std::string ToString();

	//Projects one vector onto another
	Vector3 Project(Vector3& v);

	//Projects one vector onto a plane
	Vector3 ProjectOntoPlane(Vector3& normal);

};

Vector3 operator+ (const Vector3& v1, const Vector3& v2);

Vector3 operator* (const Vector3& v, float f);

bool operator== (const Vector3& v1, const Vector3& v2);

Vector3 operator- (const Vector3& v1, const Vector3& v2);

#endif