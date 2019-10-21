#pragma once
#include "Patterns.h"
typedef unsigned __int8 atype;
//typedef unsigned __int16 atype2;
typedef unsigned deeptype;	// uper cells Info (for transform)
// ���� - ������ - ����

class PaternLayX2 {
public:
	PaternLayX2(int size_side_in_atom, BOOL DelayTransform);
	~PaternLayX2();
	int sz; // ����� ������� ���� � ������
	int vcnt; // ������� � ������ sz^2 (������ v)
	int szInCell; //  ����� ������� ���� � cell
	int szCellInAtom;	// ����� ������� cell in atom
	int cntRowCell; //  ������� ������ ���� cell � atom
	int cntCell; //  ������� ���� � cell
	atype* v;	// base array
	BOOL bDelayTransform;

	void GetVal();
	void Transform();

	inline int Coord2Atom(int x, int y) { return x + y * sz; }
	inline int Coord2Cell(int x, int y) { return x / BASE + (y / BASE) * cntRowCell; }

	PaternLayX2* dnLay;	// ����������� ����
protected:
	static const int BASE = 2;
	atype RecursGetVal(int x_v, int y_v);
	void transform(int x_v, int y_v, deeptype h);
private:
	deeptype getPursH(deeptype h);
	Patterns* patterns;
	void getQuadro(int x, int y, atype** p);
}; // ******************************************************************************************

