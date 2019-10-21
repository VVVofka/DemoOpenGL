#include "PaternLayX2.h"
// addon PaternLayX2

//o o o		
//3 4 o   order calls dnLay->RecursGetVal1(x,y)
//1 2 o    1: start point
atype PaternLayX2::RecursGetVal0(int x_v, int y_v) {
	atype* p0 = v + x_v + y_v * sz;
	if(dnLay != nullptr) {
		atype sum = dnLay->RecursGetVal0(x_v <<= 1, y_v <<= 1); //1 
		sum += dnLay->RecursGetVal1(x_v + 1, y_v);				//2 to right by bottom
		atype nodiag = sum;
		sum += dnLay->RecursGetVal2(x_v, ++y_v);				//3 to top by left
		sum += dnLay->RecursGetVal3(x_v + 1, y_v);				//4 to right by top
		if(sum < 2)	return *p0 = 0;
		if(sum > 2)	return *p0 = 1;
		*p0 = (nodiag >> 1);	// if(nodiag == 2) :)
	}
	return *p0;
} // ////////////////////////////////////////////////////////////////
//o o o
//o 2 4   order calls dnLay->RecursGetVal1(x,y)
//s 1 3    s: start point
atype PaternLayX2::RecursGetVal1(int x_v, int y_v) {
	atype* p0 = v + x_v + y_v * sz;
	if(dnLay != nullptr) {
		x_v = (x_v << 1) + 1;
		atype sum = dnLay->RecursGetVal1(x_v, y_v <<= 1);	//1 to left by bottom
		sum += dnLay->RecursGetVal1(x_v, y_v + 1);			//2 to up by left
		atype nodiag = sum;
		if(++x_v >= sz) x_v -= sz;
		sum += dnLay->RecursGetVal1(x_v, y_v);				//3 to right by bottom
		sum += dnLay->RecursGetVal1(x_v, y_v + 1);			//4 to up by right
		if(sum < 2)	return *p0 = 0;
		if(sum > 2)	return *p0 = 1;
		*p0 = (nodiag >> 1);	// if(nodiag == 2) :)
	}
	return *p0;
} // ////////////////////////////////////////////////////////////////
//3 4 o
//1 2 o    order calls dnLay->RecursGetVal1(x,y)
//s o o     s: start point
atype PaternLayX2::RecursGetVal2(int x_v, int y_v) {
	atype* p0 = v + x_v + y_v * sz;
	if(dnLay != nullptr) {
		y_v = (y_v << 1) + 1;
		atype sum = dnLay->RecursGetVal1(x_v << 1, y_v);	//1 to up by left
		sum += dnLay->RecursGetVal1(x_v + 1, y_v);			//2 to right by bottom
		atype nodiag = sum;
		if(++y_v >= sz) y_v -= sz;
		sum += dnLay->RecursGetVal1(x_v, y_v);				//3 to top by right
		sum += dnLay->RecursGetVal1(x_v + 1, y_v);			//4 to right by top
		if(sum < 2)	return *p0 = 0;
		if(sum > 2)	return *p0 = 1;
		*p0 = (nodiag >> 1);	// if(nodiag == 2) :)
	}
	return *p0;
} // ////////////////////////////////////////////////////////////////
//o 3 4
//o 1 2    order calls dnLay->RecursGetVal1(x,y);
//s o o     s: start point
atype PaternLayX2::RecursGetVal3(int x_v, int y_v) {
	atype* p0 = v + x_v + y_v * sz;
	if(dnLay != nullptr) {
		x_v = (x_v << 1) + 1;
		y_v = (y_v << 1) + 1;
		atype sum = dnLay->RecursGetVal1(x_v, y_v);		//1 to left & top by diag
		int x_bak = x_v;
		if(++x_v >= sz) x_v -= sz;
		sum += dnLay->RecursGetVal1(x_v, y_v);			//2 to left by bottom
		atype nodiag = sum;
		if(++y_v >= sz) y_v -= sz;
		sum += dnLay->RecursGetVal1(x_bak, y_v);		//3 to top by left
		sum += dnLay->RecursGetVal1(x_v, y_v);			//4 to right by top
		if(sum < 2)	return *p0 = 0;
		if(sum > 2)	return *p0 = 1;
		*p0 = (nodiag >> 1);	// if(nodiag == 2) :)
	}
	return *p0;
} // ////////////////////////////////////////////////////////////////
