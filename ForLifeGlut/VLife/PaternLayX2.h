#pragma once
#include "Patterns.h"
typedef unsigned __int8 atype;
//typedef unsigned __int16 atype2;
typedef unsigned deeptype;	// uper cells Info (for transform)
// слой - клетка - атом

class PaternLayX2{
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

	atype val4Up(int ofset_in_atom);
	atype val4Up2();	// for second pass corner (once)
	atype val4Up2x(int ofset_in_atom);	// for second pass x-axe along (x=1..sz-1; y=0)
	atype val4Up2y(int ofset_in_atom);	// for second pass y-axe along (x=0; y=1..sz-1)
	deeptype transform(int x_v, int y_v, deeptype h);

	atype RecursGetVal0(int x_v, int y_v);
	atype RecursGetVal1(int x_v, int y_v);
	atype RecursGetVal2(int x_v, int y_v);
	atype RecursGetVal3(int x_v, int y_v);

	void transform0(int x_v, int y_v, deeptype h);
	void transform1(int x_v, int y_v, deeptype h);
	void transform2(int x_v, int y_v, deeptype h);
	void transform3(int x_v, int y_v, deeptype h);

	inline int Coord2Atom(int x, int y) { return x + y * sz; }
	inline int Coord2Cell(int x, int y) { return x / BASE + (y / BASE) * cntRowCell; }

	PaternLayX2* dnLay;	// нижележащий слой
protected:
	static const int BASE = 2;
	atype val4Up(int x, int y);
private:
	deeptype getPursH(deeptype h);
	Patterns* patterns;
	unsigned getVal(pattertype);
}; // ******************************************************************************************

