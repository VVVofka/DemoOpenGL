#pragma once
#include <math.h>
class Point {
public:
	int x, y;
	Point() { x = y = 0; }
	Point(int X, int Y) : x(X), y(Y) { }
	Point(int XY) { x = y = XY; }
	bool operator ==(const Point A) { return (x == A.x) && (y == A.y); }
	bool operator !=(const Point A) { return (x != A.x) || (y != A.y); }
	Point operator +(Point A) { return Point(x + A.x, y + A.y); }
	Point operator -(Point A) { return Point(x - A.x, y - A.y); }
	Point operator *(int A) { return Point(x * A, y * A); }
	void operator +=(Point A) { x += A.x; y += A.y; }
	void operator /=(int A) { x /= A; y /= A; }
	void operator /=(double A) { x = (int)round(x/A); y = (int)round(y/A); }
	double operator ^(Point A) {
		double dx = (double)x - (double)A.x, dy = (double)y -(double)A.y;
		return sqrt(dx * dx + dy * dy); }
	int of(int row_sz) { return x + y * row_sz; }
}; // *******************************************************************************
class PointF {
public:
	double x, y;
	PointF() { x = y = 0; }
	PointF(int X, int Y) : x(X), y(Y) { }
	PointF(int XY) { x = y = XY; }
	PointF(double X, double Y) : x(X), y(Y) { }
	PointF(double XY) { x = y = XY; }
	bool operator ==(double A) { return x == A && y == A; }
	PointF operator +(PointF A) { return PointF(x + A.x, y + A.y); }
	PointF operator -(PointF A) { return PointF(x - A.x, y - A.y); }
	PointF operator *(double A) { return PointF(x * A, y * A); }
	PointF operator *(int A) { return PointF(x * A, y * A); }
	void operator +=(PointF A) { x += A.x; y += A.y; }
	void operator +=(Point A) { x += A.x; y += A.y; }
	void operator /=(int A) { x /= A; y /= A; }
	void operator /=(size_t A) { x /= A; y /= A; }
	void operator /=(double A) { x /= A; y /= A; }
	double operator ^(PointF A) {
		double dx = x - A.x, dy = y - A.y;
		return sqrt(dx * dx + dy * dy);
	}
	double operator ^(Point A) {
		double dx = x - A.x, dy = y - A.y;
		return sqrt(dx * dx + dy * dy);
	}
}; // *******************************************************************************

