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
