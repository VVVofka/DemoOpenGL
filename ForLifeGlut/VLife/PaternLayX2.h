#pragma once
#include "Patterns.h"
typedef unsigned __int8 atype;
//typedef unsigned __int16 atype2;
typedef unsigned deeptype;	// uper cells Info (for transform)
// слой - клетка - атом

class PaternLayX2 {
public:
	PaternLayX2(int size_side_in_atom, BOOL DelayTransform);
	~PaternLayX2();
	int sz; // длина стороны слоя в атомах
	int vcnt; // площадь в атомах sz^2 (размер v)
	int szInCell; //  длина стороны слоя в cell
	int szCellInAtom;	// длина стороны cell in atom
	int cntRowCell; //  площадь одного ряда cell в atom
	int cntCell; //  площадь слоя в cell
	atype* v;	// base array
	BOOL bDelayTransform;

	void GetVal();
	void Transform();

	inline int Coord2Atom(int x, int y) { return x + y * sz; }
	inline int Coord2Cell(int x, int y) { return x / BASE + (y / BASE) * cntRowCell; }

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

