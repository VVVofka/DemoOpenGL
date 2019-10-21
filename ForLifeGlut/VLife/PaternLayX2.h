#pragma once
#include "Patterns.h"
typedef unsigned __int8 atype;
typedef unsigned deeptype;	// uper cells Info (for transform)
// слой - клетка - атом

class PaternLayX2 {
public:
	PaternLayX2(int size_side_in_atom, BOOL DelayGetVal, BOOL DelayTransform);
	~PaternLayX2();
	int sz; // длина стороны слоя в атомах
	atype* v;	// base array
	BOOL bDelayGetVal;
	BOOL bDelayTransform;

	void GetVal();
	void Transform();

	inline int Coord2Atom(int x, int y) { return x + y * sz; }

	PaternLayX2* dnLay;	// нижележащий слой
protected:
	static const int BASE = 2;
	atype RecursGetVal(int x_v, int y_v);
	void transform(int x_v, int y_v, deeptype h);
private:
	deeptype getPursH(deeptype h);
	Patterns* patterns;
	void getQuadro(int x, int y, atype** p);
}; // ******************************************************************************************

