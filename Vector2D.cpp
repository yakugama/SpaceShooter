#include "Vector2D.h"

Vector2D::Vector2D()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2D & Vector2D::Add(const Vector2D & other)
{
	this->x += other.x;
	this->y += other.y;

	return *this;
}

Vector2D & Vector2D::Subtract(const Vector2D & other)
{
	this->x -= other.x;
	this->y -= other.y;

	return *this;
}

Vector2D & Vector2D::Multiply(const Vector2D & other)
{
	this->x *= other.x;
	this->y *= other.y;

	return *this;
}

Vector2D & Vector2D::Divide(const Vector2D & other)
{
	this->x /= other.x;
	this->y /= other.y;

	return *this;
}

Vector2D & Vector2D::operator+=(const Vector2D & other)
{
	return this->Add(other);
}

Vector2D & Vector2D::operator-=(const Vector2D & other)
{
	return this->Subtract(other);
}

Vector2D & Vector2D::operator*=(const Vector2D & other)
{
	return this->Multiply(other);
}

Vector2D & Vector2D::operator/=(const Vector2D & other)
{
	return this->Divide(other);
}

Vector2D& operator + (Vector2D& vec, const Vector2D&other)
{
	return vec.Add(other);
}

Vector2D& operator - (Vector2D& vec, const Vector2D&other)
{
	return vec.Subtract(other);
}

Vector2D& operator * (Vector2D& vec, const Vector2D&other)
{
	return vec.Multiply(other);
}

Vector2D& operator / (Vector2D& vec, const Vector2D&other)
{
	return vec.Divide(other);
}

//operatii cu scalari

Vector2D & Vector2D::Add(const float & other)
{
	this->x += other;
	this->y += other;

	return *this;
}

Vector2D & Vector2D::Subtract(const float & other)
{
	this->x -= other;
	this->y -= other;

	return *this;
}

Vector2D & Vector2D::Multiply(const float & other)
{
	this->x *= other;
	this->y *= other;

	return *this;
}

Vector2D & Vector2D::Divide(const float & other)
{
	this->x /= other;
	this->y /= other;

	return *this;
}

Vector2D & Vector2D::operator+=(const float & other)
{
	return this->Add(other);
}

Vector2D & Vector2D::operator-=(const float & other)
{
	return this->Subtract(other);
}

Vector2D & Vector2D::operator*=(const float & other)
{
	return this->Multiply(other);
}

Vector2D & Vector2D::operator/=(const float & other)
{
	return this->Divide(other);
}

Vector2D& operator + (Vector2D& vec, const float & other)
{
	return vec.Add(other);
}

Vector2D& operator - (Vector2D& vec, const float & other)
{
	return vec.Subtract(other);
}

Vector2D& operator * (Vector2D& vec, const float & other)
{
	return vec.Multiply(other);
}

Vector2D& operator / (Vector2D& vec, const float & other)
{
	return vec.Divide(other);
}
std::ostream& operator<< (std::ostream& stream, Vector2D& vector)
{
	stream << "(" << vector.x << "," << vector.y << ")";
	return stream;
}