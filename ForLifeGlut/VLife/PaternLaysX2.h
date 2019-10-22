#pragma once
#include "PaternLayX2.h"
// слой - клетка - атом
class PaternLaysX2{
public:
	PaternLaysX2();
	PaternLaysX2(int maxsize, int min_size, BOOL DelayUp, BOOL DelayTransform);
	~PaternLaysX2();

	int layscnt;
	PaternLayX2** vlays;
	PaternLayX2* lastLay;
	atype* v;
	int sz;

	void Create(int maxsize, int min_size, BOOL DelayUp, BOOL DelayTransform);
	void GetVal();
	inline atype at(int x, int y) { return v[x + y* lastLay->sz]; }
	inline void at(int x, int y, int val) { v[x + y * lastLay->sz] = val; }
	void Transform();

private:
	void delv();
}; // **************************************************************************************************

