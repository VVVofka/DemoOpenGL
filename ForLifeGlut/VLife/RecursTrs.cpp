#include "PaternLayX2.h"
// addon PaternLayX2

//o o o		
//3 4 o   order calls dnLay->transform1(x,y,h)
//1 2 o    1: start point
void PaternLayX2::transform0(int x, int y, deeptype h) { // only BASE==2
	atype* p0 = v + x + y * sz;	// left bottom

	// get pattern
	pattertype a = *p0 > 0 ? 1 : 0;
	a += *(p0 + 1) > 0 ? 2 : 0;
	atype* p2 = p0 + sz;	// left top
	a += *p2 > 0 ? 4 : 0;
	a += *(p2 + 1) > 0 ? 8 : 0;
	deeptype pursh = getPursH(h);
	a = (a << 1) + pursh;
	pattertype m = patterns->at(a);

	// save
	*p0 = m & 1;
	*(p0 + 1) = m & 2 ? 1 : 0;
	*p2 = m & 4 ? 1 : 0;
	*(p2 + 1) = m & 8 ? 1 : 0;

	// transform shildren
	if(dnLay != nullptr) {	// если внизу есть слой, то
		// add to h
		atype sum = *p0 + *(p0 + 1);
		atype nodiag = sum;
		sum += *p2 + *(p2 + 1);
		h <<= 1;
		if(sum >= 2)	h++;
		else if(sum == 2)
			h |= (nodiag >> 1);	// if(nodiag == 2) :)
		
		x <<= 1;  y <<= 1;
		dnLay->transform(x, y, h);
		dnLay->transform(x + 1, y, h);
		dnLay->transform(x, y + 1, h);
		dnLay->transform(x + 1, y + 1, h);
	}
} // ////////////////////////////////////////////////////////////////
//o o o
//o 2 4   order calls dnLay->RecursGetVal1(x,y)
//s 1 3    s: start point
void PaternLayX2::transform1(int x, int y, deeptype h) { // only BASE==2
	atype* p0 = v + x + y * sz;	// left bottom

	// get pattern
	pattertype a = *p0 > 0 ? 1 : 0;
	a += *(p0 + 1) > 0 ? 2 : 0;
	atype* p2 = p0 + sz;	// left top
	a += *p2 > 0 ? 4 : 0;
	a += *(p2 + 1) > 0 ? 8 : 0;
	deeptype pursh = getPursH(h);
	a = (a << 1) + pursh;
	pattertype m = patterns->at(a);

	// save
	*p0 = m & 1;
	*(p0 + 1) = m & 2 ? 1 : 0;
	*p2 = m & 4 ? 1 : 0;
	*(p2 + 1) = m & 8 ? 1 : 0;

	// transform shildren
	if(dnLay != nullptr) {	// если внизу есть слой, то
		// add to h
		atype sum = *p0 + *(p0 + 1);
		atype nodiag = sum;
		sum += *p2 + *(p2 + 1);
		h <<= 1;
		if(sum >= 2)	h++;
		else if(sum == 2)
			h |= (nodiag >> 1);	// if(nodiag == 2) :)

		x <<= 1;  y <<= 1;
		dnLay->transform(x, y, h);
		dnLay->transform(x + 1, y, h);
		dnLay->transform(x, y + 1, h);
		dnLay->transform(x + 1, y + 1, h);
	}
} // ////////////////////////////////////////////////////////////////
//3 4 o
//1 2 o    order calls dnLay->RecursGetVal1(x,y)
//s o o     s: start point
void PaternLayX2::transform2(int x, int y, deeptype h) { // only BASE==2
	atype* p0 = v + x + y * sz;	// left bottom

	// get pattern
	pattertype a = *p0 > 0 ? 1 : 0;
	a += *(p0 + 1) > 0 ? 2 : 0;
	atype* p2 = p0 + sz;	// left top
	a += *p2 > 0 ? 4 : 0;
	a += *(p2 + 1) > 0 ? 8 : 0;
	deeptype pursh = getPursH(h);
	a = (a << 1) + pursh;
	pattertype m = patterns->at(a);

	// save
	*p0 = m & 1;
	*(p0 + 1) = m & 2 ? 1 : 0;
	*p2 = m & 4 ? 1 : 0;
	*(p2 + 1) = m & 8 ? 1 : 0;

	// transform shildren
	if(dnLay != nullptr) {	// если внизу есть слой, то
		// add to h
		atype sum = *p0 + *(p0 + 1);
		atype nodiag = sum;
		sum += *p2 + *(p2 + 1);
		h <<= 1;
		if(sum >= 2)	h++;
		else if(sum == 2)
			h |= (nodiag >> 1);	// if(nodiag == 2) :)

		x <<= 1;  y <<= 1;
		dnLay->transform(x, y, h);
		dnLay->transform(x + 1, y, h);
		dnLay->transform(x, y + 1, h);
		dnLay->transform(x + 1, y + 1, h);
	}
} // ////////////////////////////////////////////////////////////////
//o 3 4
//o 1 2    order calls dnLay->RecursGetVal1(x,y);
//s o o     s: start point
void PaternLayX2::transform3(int x, int y, deeptype h) { // only BASE==2
	atype* p0 = v + x + y * sz;	// left bottom

	// get pattern
	pattertype a = *p0 > 0 ? 1 : 0;
	a += *(p0 + 1) > 0 ? 2 : 0;
	atype* p2 = p0 + sz;	// left top
	a += *p2 > 0 ? 4 : 0;
	a += *(p2 + 1) > 0 ? 8 : 0;
	deeptype pursh = getPursH(h);
	a = (a << 1) + pursh;
	pattertype m = patterns->at(a);

	// save
	*p0 = m & 1;
	*(p0 + 1) = m & 2 ? 1 : 0;
	*p2 = m & 4 ? 1 : 0;
	*(p2 + 1) = m & 8 ? 1 : 0;

	// transform shildren
	if(dnLay != nullptr) {	// если внизу есть слой, то
		// add to h
		atype sum = *p0 + *(p0 + 1);
		atype nodiag = sum;
		sum += *p2 + *(p2 + 1);
		h <<= 1;
		if(sum >= 2)	h++;
		else if(sum == 2)
			h |= (nodiag >> 1);	// if(nodiag == 2) :)

		x <<= 1;  y <<= 1;
		dnLay->transform0(x, y, h);
		dnLay->transform1(x + 1, y, h);
		dnLay->transform2(x, y + 1, h);
		dnLay->transform3(x + 1, y + 1, h);
	}
} // ////////////////////////////////////////////////////////////////////////////