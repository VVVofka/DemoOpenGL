#include "PaternLayX2.h"
// addon PaternLayX2

// 3 4
// 1 2    order calls dnLay->RecursGetVal1(x,y);
atype PaternLayX2::RecursGetVal(int x_v, int y_v) {
	atype* p0 = v + x_v + y_v * sz;
	if(dnLay != nullptr) {
		atype sum = dnLay->RecursGetVal(x_v <<= 1, y_v <<= 1);	//1
		int x_bak = x_v;
		if(++x_v >= sz) x_v -= sz;
		sum += dnLay->RecursGetVal(x_v, y_v);		//2
		atype nodiag = sum;
		if(++y_v >= sz) y_v -= sz;
		sum += dnLay->RecursGetVal(x_bak, y_v);		//3 
		sum += dnLay->RecursGetVal(x_v, y_v);		//4 
		if(sum < 2)	return *p0 = 0;
		if(sum > 2)	return *p0 = 1;
		*p0 = (nodiag >> 1);	// if(nodiag == 2) :)
	}
	return *p0;
} // ////////////////////////////////////////////////////////////////
//o o o		
//3 4 o   order calls dnLay->transform(x,y,h)
//1 2 o    1: start point
void PaternLayX2::transform(int x, int y, deeptype h) { // only BASE==2
	{	atype* quadro[4];
	getQuadro(x, y, quadro);

	// get pattern
	pattertype a = *quadro[0] > 0 ? 1 : 0;
	a += *quadro[1] > 0 ? 2 : 0;
	a += *quadro[2] > 0 ? 4 : 0;
	a += *quadro[3] > 0 ? 8 : 0;
	deeptype pursh = getPursH(h);
	a = (a << 1) + pursh;
	pattertype m = patterns->at(a);

	// save
	*quadro[0] = m & 1;
	*quadro[1] = m & 2 ? 1 : 0;
	*quadro[2] = m & 4 ? 1 : 0;
	*quadro[3] = m & 8 ? 1 : 0;
	if(dnLay == nullptr) return;

	// transform shildren
		// add to h
	atype sum = *quadro[0] + *quadro[1];
	atype nodiag = sum;
	sum += *quadro[2] + *quadro[3];
	h <<= 1;
	if(sum >= 2)	
		h++;
	else if(sum == 2)
		h |= (nodiag >> 1);	// if(nodiag == 2) :)
	}	// out range quadro

	x <<= 1;  y <<= 1;
	dnLay->transform(x, y, h);
	dnLay->transform(x + 1, y, h);
	dnLay->transform(x, y + 1, h);
	dnLay->transform(x + 1, y + 1, h);
} // ////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////
void PaternLayX2::getQuadro(int x, int y, atype** p) {
	atype* beginRow = v + y * sz;
	p[0] = beginRow + x;	// left bottom

	int x1 = x + 1;
	_ASSERTE(x1 <= sz);
	if(x1 == sz)
		x1 = 0;
	p[1] = beginRow + x1;	// right bottom

	int y1 = y + 1;
	_ASSERTE(y1 <= sz);
	if(y1 == sz)
		beginRow = v;
	else
		beginRow += sz;
	p[2] = beginRow + x;	// left top
	p[3] = beginRow + x1;	// right top
} // ////////////////////////////////////////////////////////////////
deeptype PaternLayX2::getPursH(deeptype h) {
	deeptype ret = h & 1;
	if((h & 2) != 0) ret++;	// TODO: if()?
	if((h & 4) != 0) ret++;
	if(ret > 1) return 1;
	return 0;
} // ///////////////////////////////////////////////////////////////
