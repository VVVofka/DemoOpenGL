#include "PaternLayX2.h"

PaternLayX2::PaternLayX2(int size_side_in_atom, BOOL DelayGetVal, BOOL DelayTransform) {
	sz = size_side_in_atom;		// длина стороны слоя в атомах
	cntRowCell = sz * BASE;		// площадь одного ряда cell в atom
	patterns = new Patterns(BASE);
	v = new atype[sz * sz]{};
	//for(int j = 0; j < vcnt; j++) v[j] = 0;
	dnLay = nullptr;
	bDelayGetVal = DelayGetVal;
	bDelayTransform = DelayTransform;
} // /////////////////////////////////////////////////////////////
PaternLayX2::~PaternLayX2() {
	delete[] v;
	delete patterns;
} // /////////////////////////////////////////////////////////////
void PaternLayX2::GetVal(){
	// по два цикла с step=2, чтоб не было конфликтов при многопоточности
	for(int y = 0; y < sz; y += 2) {
		for(int x = 0; x < sz; x += 2) {
			RecursGetVal(x, y);
		}
	}
	for(int y = 1; y < sz; y += 2) {
		for(int x = 1; x < sz; x += 2) {
			RecursGetVal(x, y);
		}
	}
}// /////////////////////////////////////////////////////////////
void PaternLayX2::Transform() {
	// по два цикла с step=2, чтоб не было конфликтов при многопоточности
	for(int y = 0; y < sz; y += 2) {
		for(int x = 0; x < sz; x += 2) {
			transform(x, y, 0);
		}
	}
	for(int y = 1; y < sz; y += 2) {
		for(int x = 1; x < sz; x += 2) {
			transform(x, y, 0);
		}
	}
} // /////////////////////////////////////////////////////////////

