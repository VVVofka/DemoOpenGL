#pragma once
#include <set>
#include <list>
#include <atlstr.h>
#include "Point.h"

typedef unsigned int pattertype;
//using namespace std;
class Patterns {
public:
	Patterns(int x, int y);
	Patterns(int xy);
	~Patterns();
	inline pattertype operator [] (pattertype n) { _ASSERTE(n < szv); return v[n]; }
	inline pattertype at(pattertype n) { _ASSERTE(n < szv); return v[n]; }
	inline int RowSz() { return szx; }
	inline int ColSz() { return szy; }
	static CString PrintRow(pattertype, int szx, int n_row);
private:
	pattertype szx, szy, szv;
	pattertype* v;
	void Create(pattertype x, pattertype y);
	pattertype Density(pattertype a);	// концетрация
	pattertype Dissipation(pattertype a);	// рассеивание
	int a2lst(pattertype a, std::list<Point>*, pattertype type);
	//pattertype lst2a(std::list<Point>*, pattertype type);
	PointF getAvgPoint(std::list<Point>*);
	pattertype movPoint(Point pointFrom, pattertype a, PointF outPoint);
}; // ****************************************************************************************


