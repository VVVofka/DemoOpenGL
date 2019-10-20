#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
class TestGGlut {
public:
	const static int sz = 6;
	TestGGlut() {
		v[2] = v[7] = v[17] = v[18] = 1;
	}
	GLbyte v[sz * sz] = {};
	void Rand() {
		int rnd = rand();
		int range_min = 0, range_max = sz * sz;
		int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
		v[u] = (v[u] + 1) & 1;
	}
};

