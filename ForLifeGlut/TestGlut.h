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
	TestGlut() {v[2] = v[7] = v[17] = v[18] = 1;}
private:
	PaternLaysX2 lays;
	const static int sz = 6;
	GLbyte v[sz * sz] = {};
	// ------------------------------------------------------------------------------------------
public:
	int size() {return lays.vlays[lays.layscnt - 1]->sz;}
	GLbyte operator [](int n) {
		return lays.vlays[lays.layscnt - 1]->v[n];
		//return v[n];
	} // ////////////////////////////////////////////////////////////////////////////////////////
	void Rand() {
		int rnd = rand();
		int range_min = 0, range_max = sz * sz;
		int u = (int)((double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min);
		v[u] = (v[u] + 1) & 1;
	} // /////////////////////////////////////////////////////////////////////////////////////////
	void Create(int max_size, int min_size = 1, BOOL DelayUp = TRUE, BOOL DelayTransform = TRUE) {
		lays.Create(max_size, min_size, DelayUp, DelayTransform);
	} // /////////////////////////////////////////////////////////////////////////////////////////
	void getVal() {
		//lays.GetVal();
	} // /////////////////////////////////////////////////////////////////////////////////////////
	void Transform() {
		//lays.Transform();
	} // /////////////////////////////////////////////////////////////////////////////////////////

}; // ********************************************************************************************

