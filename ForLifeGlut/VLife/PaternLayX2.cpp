#include "PaternLayX2.h"

PaternLayX2::PaternLayX2(int size_side_in_atom, BOOL DelayTransform) {
	sz = size_side_in_atom;		// длина стороны слоя в атомах
	szInCell = sz / BASE;		// длина стороны слоя в cell
	cntRowCell = sz * BASE;		// площадь одного ряда cell в atom
	cntCell = szInCell * szInCell; // площадь слоя в cell
	szCellInAtom = BASE;		// длина стороны cell in atom
	patterns = new Patterns(BASE);
	vcnt = sz * sz;				// vcnt- площадь в атомах sz^2 (размер v)
	v = new atype[vcnt];
	for(int j = 0; j < vcnt; j++) v[j] = 0;
	dnLay = nullptr;
	bDelayTransform = DelayTransform;
} // /////////////////////////////////////////////////////////////
PaternLayX2::~PaternLayX2() {
	delete[] v;
	delete patterns;
} // /////////////////////////////////////////////////////////////
atype PaternLayX2::val4Up(int x_cell, int y_cell) {
	int ofs = x_cell * BASE + y_cell * cntRowCell;
	return val4Up(ofs);
} // /////////////////////////////////////////////////////////////
atype PaternLayX2::val4Up(int ofset_in_atom) {
	atype ret = v[ofset_in_atom];
	ret += v[ofset_in_atom + 1];
	ofset_in_atom += sz;
	ret += v[ofset_in_atom];
	ret += v[ofset_in_atom + 1];
	return ret;
} // /////////////////////////////////////////////////////////////
// for second pass x-axe along (x=1..sz-1; y=0)
atype PaternLayX2::val4Up2x(int ofset_in_atom) {
	atype ret = v[ofset_in_atom];
	ret += v[ofset_in_atom + 1];
	int ofs = ofset_in_atom + sz * (sz - 1);
	ret += v[ofs];
	ret += v[ofs + 1];
	return ret;
} // /////////////////////////////////////////////////////////////
// for second pass y-axe along (x=0; y=1..sz-1)
atype PaternLayX2::val4Up2y(int ofset_in_atom) {
	atype ret = v[ofset_in_atom];	// left bottom
	int ofs = ofset_in_atom + sz;
	ret += v[ofs];					// left top
	ret += v[--ofs];				// right bottom
	ret += v[ofs + sz];				// right top
	return ret;
} // /////////////////////////////////////////////////////////////
// for second pass corner (once)
atype PaternLayX2::val4Up2() {
	atype ret = v[0];
	ret += v[sz - 1];
	ret += v[vcnt - sz];
	ret += v[vcnt - 1];
	return ret;
} // /////////////////////////////////////////////////////////////
deeptype PaternLayX2::transform(int x, int y, deeptype h) { // only BASE==2
	if(x >= sz) x -= sz;
	if(y >= sz) y -= sz;
	int ofs = Coord2Atom(x, y);
	pattertype inPattern = v[ofs] > 0 ? 1 : 0;	// (2x2)<<1 | h
	inPattern += v[ofs + 1] > 0 ? 2 : 0;
	int ofs2 = ofs + sz;
	inPattern += v[ofs2] > 0 ? 4 : 0;
	inPattern += v[ofs2 + 1] > 0 ? 8 : 0;
	deeptype pursh = getPursH(h);
	pattertype transformedCell = patterns->at((inPattern << 1) | pursh);

	// save result & add to h
	unsigned sumCell;
	if(bDelayTransform) {
		sumCell = getVal(inPattern);
		v[ofs] = transformedCell & 1;
		v[ofs + 1] = transformedCell & 2 ? 1 : 0;
		v[ofs2] = transformedCell & 4 ? 1 : 0;
		v[ofs2 + 1] = transformedCell & 8 ? 1 : 0;
	}
	else {
		sumCell = (v[ofs] = transformedCell & 1);
		sumCell += (v[ofs + 1] = transformedCell & 2 ? 1 : 0);
		sumCell += (v[ofs2] = transformedCell & 4 ? 1 : 0);
		sumCell += (v[ofs2 + 1] = transformedCell & 8 ? 1 : 0);
	}
	if(sumCell < (BASE * BASE) / 2)
		h <<= 1;
	else if(sumCell > (BASE * BASE) / 2) {
		h <<= 1;
		h |= 1;
	}
	else {
		unsigned tmp = h & 1;	// TODO: add tmp = ~h & 1
		h <<= 1;
		h |= tmp;
	}
	return h;
} // ////////////////////////////////////////////////////////////////
unsigned PaternLayX2::getVal(pattertype i) {
	unsigned r = (i & 1);
	r += (i >>= 1) & 1;
	r += (i >>= 1) & 1;
	r += (i >>= 1) & 1;
	return r;
} // ////////////////////////////////////////////////////////////////
deeptype PaternLayX2::getPursH(deeptype h) {
	deeptype ret = h & 1;
	if((h & 2) != 0) ret++;	// TODO: if()?
	if((h & 4) != 0) ret++;
	if(ret > 1) return 1;
	return 0;
} // ///////////////////////////////////////////////////////////////



//h = (h << 1) | (h & 1);
////	Добавляем к h значение нашего слоя
//atype sum = *p0 + *(p0 + 1);
//p0 += sz;
//sum += *p0 + *(p0 + 1);
//if(sum < 2)
//	h = h << 1;
//else if(sum > 2)
//h = (h << 1) | 1;
//else
//h = (h << 1) | (h & 1);
//
//if(dnLay != nullptr) {							// x y
//	int x2 = x_v + x_v, y2 = y_v + y_v;			// 0 0
//	*p0 = dnLay->RecursGetVal1(x2, y2, h);
//	atype ret = *p0;
//
//	if(x2 + 1 >= sz) x2 -= sz;
//	atype* p = p0 + 1;
//	_ASSERTE(p < v + vcnt);
//	*p = dnLay->RecursGetVal1(x2 + 1, y2, h);	// 1 0
//	ret += *p;
//
//	if(++y2 >= sz) y2 -= sz;
//	p = p0 + sz;
//	_ASSERTE(p < v + vcnt);
//	*p = dnLay->RecursGetVal1(x2, y2, h);		// 0 1
//	ret += *p;
//
//	p++;
//	_ASSERTE(p < v + vcnt);
//	*p = dnLay->RecursGetVal1(x2 + 1, y2, h);	// 1 1
//	ret += *p;
//
//	if(ret < 2)
//		return 0;
//	else if(ret > 2)
//		return 1;
//}
//return  h & 1;
