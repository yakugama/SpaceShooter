#pragma once
#include"iostream"

class Vector2D
{

public:
	float x;
	float y;

	Vector2D();
	Vector2D(float x, float y);

	Vector2D& Add(const Vector2D& other);
	Vector2D& Subtract(const Vector2D& other);
	Vector2D& Multiply(const Vector2D& other);
	Vector2D& Divide(const Vector2D& other);

	friend Vector2D& operator +(Vector2D& vec, const Vector2D& other);
	friend Vector2D& operator -(Vector2D& vec, const Vector2D& other);
	friend Vector2D& operator *(Vector2D& vec, const Vector2D& other);
	friend Vector2D& operator /(Vector2D& vec, const Vector2D& other);

	Vector2D& operator +=(const Vector2D& other);
	Vector2D& operator -=(const Vector2D& other);
	Vector2D& operator *=(const Vector2D& other);
	Vector2D& operator /=(const Vector2D& other);


	Vector2D& Add(const float& other);
	Vector2D& Subtract(const float& other);
	Vector2D& Multiply(const float& other);
	Vector2D& Divide(const float& other);

	friend Vector2D& operator +(Vector2D& vec, const float& other);
	friend Vector2D& operator -(Vector2D& vec, const float& other);
	friend Vector2D& operator *(Vector2D& vec, const float& other);
	friend Vector2D& operator /(Vector2D& vec, const float& other);

	Vector2D& operator +=(const float& other);
	Vector2D& operator -=(const float& other);
	Vector2D& operator *=(const float& other);
	Vector2D& operator /=(const float& other);

	friend std::ostream& operator<< (std::ostream& stream, Vector2D& vector);
};