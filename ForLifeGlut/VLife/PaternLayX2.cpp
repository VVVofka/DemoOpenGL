#include "PaternLayX2.h"

PaternLayX2::PaternLayX2(int size_side_in_atom, BOOL DelayTransform) {
	sz = size_side_in_atom;		// ����� ������� ���� � ������
	szInCell = sz / BASE;		// ����� ������� ���� � cell
	cntRowCell = sz * BASE;		// ������� ������ ���� cell � atom
	cntCell = szInCell * szInCell; // ������� ���� � cell
	szCellInAtom = BASE;		// ����� ������� cell in atom
	patterns = new Patterns(BASE);
	vcnt = sz * sz;				// vcnt- ������� � ������ sz^2 (������ v)
	v = new atype[vcnt];
	for(int j = 0; j < vcnt; j++) v[j] = 0;
	dnLay = nullptr;
	bDelayTransform = DelayTransform;
} // /////////////////////////////////////////////////////////////
PaternLayX2::~PaternLayX2() {
	delete[] v;
	delete patterns;
} // /////////////////////////////////////////////////////////////
void PaternLayX2::GetVal(){
	// �� ��� ����� � step=2, ���� �� ���� ���������� ��� ���������������
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
	// �� ��� ����� � step=2, ���� �� ���� ���������� ��� ���������������
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

