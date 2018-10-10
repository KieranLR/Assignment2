#include "Vector3.h"
#include <math.h>
#include <stdlib.h>
#include <sstream>

/**
* Vector3
**/
float Vector3::Dot(const Vector3& v) {
	return v.x * x + v.y * y + v.z * z;
}

Vector3 Vector3::Cross(const Vector3& v) {
	Vector3 result = Vector3();
	result.x = x * v.z - z * v.y;
	result.y = z * v.x - x * v.z;
	result.z = x * v.y - y * v.x;
	return result;
}

float Vector3::Magnitude() {
	return sqrt(x * x + y * y + z * z);
}

float Vector3::Distance(const Vector3& v) {
	float dist_x = v.x - x;
	float dist_y = v.y - y;
	float dist_z = v.z - z;
	return sqrt(dist_x * dist_x + dist_y * dist_y + dist_z * dist_z);
}

Vector3 Vector3::Lerp(const Vector3& v, float t) {
	Vector3 result = Vector3();
	result.x = (v.x - x) * t + x;
	result.y = (v.y - y) * t + y;
	result.z = (v.z - z) * t + z;
	return result;
}

Vector3 Vector3::Normalized() {
	Vector3 result = Vector3();
	float length = Magnitude();
	result.x = x / length;
	result.y = y / length;
	result.z = z / length;
	return result;
}

Vector3 Vector3::Project(Vector3& v) {
	float dot = Dot(v);
	float length = v.Magnitude();
	return v * (dot / (length * length));
}

Vector3 Vector3::ProjectOntoPlane(Vector3& normal) {
	float dot = Dot(normal);
	float dot2 = normal.Dot(normal);
	Vector3 thisvector = Vector3(x, y, z);
	return thisvector - normal * (dot / dot2);

}

std::string Vector3::ToString() {
	std::ostringstream ss;
	ss << x << " " << y << " " << z;
	return ss.str();
}

Vector3 operator* (const Vector3& v, float f) {
	return Vector3(
		f * v.x,
		f * v.y,
		f * v.z);
}

Vector3 operator- (const Vector3& v1, const Vector3& v2) {
	return Vector3(
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z);
}

Vector3 operator+ (const Vector3& v1, const Vector3& v2) {
	return Vector3(
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z);
}

bool operator== (const Vector3& v1, const Vector3& v2) {
	return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
}