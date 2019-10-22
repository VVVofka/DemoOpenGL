#pragma once
//#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Include/GL/freeglut.h"
#include "VLife/PaternLaysX2.h"
//#define MAINENABL
struct Para {
	Para() { x = 0; y = 0; };
	Para(int X, int Y) { x = X; y = Y; };
	void set(int X, int Y) { x = X; y = Y; };
	int Min() { return (x > y) ? y : x; }
	int x, y;
}; // ********************************************************************************************
class TestGlut {
public:
	TestGlut() {}
private:
	PaternLaysX2 lays;
	const static int sz = 6;
	// ------------------------------------------------------------------------------------------
public:
	int size() { return lays.lastLay->sz; }
	GLbyte operator [](int n) {
		return lays.v[n];
		//return v[n];
	} // ////////////////////////////////////////////////////////////////////////////////////////
	void Create(int max_size, int min_size = 1, BOOL DelayUp = TRUE, BOOL DelayTransform = TRUE) {
		lays.Create(max_size, min_size, DelayUp, DelayTransform);
	} // /////////////////////////////////////////////////////////////////////////////////////////
	inline atype at(int x, int y) { return lays.v[x + y * lays.lastLay->sz]; }
	inline void at(int x, int y, int val) { lays.v[x + y * lays.lastLay->sz] = (atype)val; }
	// /////////////////////////////////////////////////////////////////////////////////////////
	void getVal() {
		//lays.GetVal();
	} // /////////////////////////////////////////////////////////////////////////////////////////
	void Transform() {
		//lays.Transform();
	} // /////////////////////////////////////////////////////////////////////////////////////////

}; // ********************************************************************************************

