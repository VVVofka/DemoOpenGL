#include "PaternLaysX2.h"

PaternLaysX2::PaternLaysX2(int max_size, BOOL DelayUp, BOOL DelayTransform) {
	maxsize = 1;
	layscnt = 1;
	while(maxsize < max_size)
		maxsize *= 2, layscnt++;
	vlays = new PaternLayX2 * [layscnt];
	int newsz = 1;
	for(int nlay = 0; nlay < layscnt; nlay++) {
		vlays[nlay] = new PaternLayX2(newsz, TRUE);
		newsz *= 2;
	}
	for(int nlay = 1; nlay < layscnt; nlay++)
		vlays[nlay - 1]->dnLay = vlays[nlay];

	bDelayUp = DelayUp;
	bTransform = DelayTransform;
	fTransform = DelayTransform ? &PaternLaysX2::fTransformDelay : &PaternLaysX2::fTransformNoDelay;
} // ////////////////////////////////////////////////////////////////////////
PaternLaysX2::~PaternLaysX2() {
	if(vlays != nullptr) {
		for(int nlay = 0; nlay < layscnt; nlay++)
			delete vlays[nlay];
		delete[] vlays;
	}
} // ////////////////////////////////////////////////////////////////////////
void PaternLaysX2::Run() {
	fUpUniver(&PaternLaysX2::fUp1);
	fTransformUniver(&PaternLaysX2::fTransform1);
	fUpUniver(&PaternLaysX2::fUp2);
	fTransformUniver(&PaternLaysX2::fTransform2);
} // /////////////////////////////////////////////////////////////////////////////
// -------------------- Univer ---------------------------------------------------
void PaternLaysX2::fUpUniver(void (PaternLaysX2::* f)(int nlay)) {
	if(bDelayUp)
		for(int nlay = 1; nlay < layscnt; nlay++)
			(this->*f)(nlay);
	else
		for(int nlay = layscnt - 1; nlay > 0; nlay--)
			(this->*f)(nlay);
} // /////////////////////////////////////////////////////////////////////////////
void PaternLaysX2::fUp1(int nlay_src) {
	PaternLayX2* src = vlays[nlay_src];
	PaternLayX2* dst = vlays[nlay_src - 1];
	atype* vdst = dst->v;
	for(int y = 0; y < src->vcnt; y += src->cntRowCell) {		// TODO: Multi
		for(int x = 0; x < src->sz; x += src->szCellInAtom) {
			int pos = y + x;
			*vdst = src->val4Up(pos);
			vdst++;
		}
	}
}// /////////////////////////////////////////////////////////////////////////////
void PaternLaysX2::fUp2(int nlay_src) {
	PaternLayX2* src = vlays[nlay_src];
	PaternLayX2* dst = vlays[nlay_src - 1];
	atype* vdst = dst->v;
	for(int y = 0; y < src->vcnt; y += src->cntRowCell) {		// TODO: Multi
		for(int x = 0; x < src->sz; x += src->szCellInAtom) {
			int pos = y + x;
			*vdst = src->val4Up(pos);
			vdst++;
		}
	}
	// правый вертикальный
	vdst = dst->v;													// TODO: Multi(3 or 2 - this up)
	int start = src->sz * 2 - src->szCellInAtom + 1;
	int stop = start + (src->szInCell - 1) * src->cntRowCell;
	vdst = dst->v + dst->sz - 1;
	for(int pos = start; pos < stop; pos += src->cntRowCell) {	
		*vdst = src->val4Up2y(pos);
		vdst++;
	}
	// верхний горизонтальный
	vdst = dst->v;
	start = (src->szInCell - 1) * src->cntRowCell + src->sz + 1;
	stop = start + src->sz - src->szCellInAtom;
	vdst = dst->v + dst->vcnt - dst->sz;
	for(int pos = start; pos < stop; pos += src->szCellInAtom) {
		*vdst = src->val4Up2x(pos);
		vdst++;
	}
	*vdst = src->val4Up2();
} // /////////////////////////////////////////////////////////////////////////////
// ----------------- end Univer. start Transform -----------------------------------
void PaternLaysX2::fTransformUniver(void (PaternLaysX2::* f)(int nlay)) {
	if(bTransform)
		for(int nlay = layscnt - 1; nlay > 0; nlay--)
			(this->*f)(nlay);
	else
		for(int nlay = 1; nlay < layscnt; nlay++)
			(this->*f)(nlay);
}// /////////////////////////////////////////////////////////////////////////////
void PaternLaysX2::fTransform1(int nlay) {
	PaternLayX2* src = vlays[nlay - 1];
	PaternLayX2* dst = vlays[nlay];
	atype* vdst = dst->v;
	for(int y = 0; y < src->vcnt; y += src->cntRowCell) {		// TODO: Multi
		for(int x = 0; x < src->sz; x += src->szCellInAtom) {
			int pos = y + x;
			*vdst = src->val4Up(pos);
			vdst++;
		}
	}
} // /////////////////////////////////////////////////////////////////////////////
unsigned PaternLaysX2::getH(int nlay, int pos) {
	unsigned sum = 0;
	if(--nlay < 0) return 1;

	return 0;
} // ////////////////////////////////////////////////////////////////////////////
void PaternLaysX2::fTransform2(int nlay_src) {
	PaternLayX2* src = vlays[nlay_src];
	PaternLayX2* dst = vlays[nlay_src - 1];
	atype* vdst = dst->v;
	for(int y = 0; y < src->vcnt; y += src->cntRowCell) {		// TODO: Multi
		for(int x = 0; x < src->sz; x += src->szCellInAtom) {
			int pos = y + x;
			*vdst = src->val4Up(pos);
			vdst++;
		}
	}
	// правый вертикальный
	vdst = dst->v;													// TODO: Multi(3 or 2 - this up)
	int start = src->sz * 2 - src->szCellInAtom + 1;
	int stop = start + (src->szInCell - 1) * src->cntRowCell;
	vdst = dst->v + dst->sz - 1;
	for(int pos = start; pos < stop; pos += src->cntRowCell) {
		*vdst = src->val4Up2y(pos);
		vdst++;
	}
	// верхний горизонтальный
	vdst = dst->v;
	start = (src->szInCell - 1) * src->cntRowCell + src->sz + 1;
	stop = start + src->sz - src->szCellInAtom;
	vdst = dst->v + dst->vcnt - dst->sz;
	for(int pos = start; pos < stop; pos += src->szCellInAtom) {
		*vdst = src->val4Up2x(pos);
		vdst++;
	}
	*vdst = src->val4Up2();
} // /////////////////////////////////////////////////////////////////////////////
// ----------------- End Transform -----------------------------------------------
void PaternLaysX2::fTransformDelay(PaternLayX2* layaa) {
	deeptype h = 0;
	for(int nlay = 1; nlay < layscnt; nlay++) {
		PaternLayX2* src = vlays[nlay];
		PaternLayX2* dst = vlays[nlay - 1];
		atype* vdst = dst->v;
		for(int y = 0; y < src->vcnt; y += src->cntRowCell) {		// TODO: Multi
			for(int x = 0; x < src->sz; x += src->szCellInAtom) {
				int pos = y + x;
				dst->transform(x, y, h);
				*vdst = src->val4Up(pos);
				vdst++;
			}
		}

		
	}
} // /////////////////////////////////////////////////////////////////////////////
void PaternLaysX2::fTransformNoDelay(PaternLayX2* lay) {
	//
} // /////////////////////////////////////////////////////////////////////////////
//								for 3 x 3
//				first pass					  second pass
//---	-------------------------											*:	src->val4Up(pos)
//	8	| . . . | . . . | . . . |		. | . 6 . | . 7 . | . 8		8 2		X:	src->val4Up2x(pos)
//2	7	| . 6 . | . 7 . | . 8 . |		. | X . . | X . . | W .		7		Y:	src->val4Up2y(pos)
//	6	| * . . | * . . | * . . |		-----------------------				W:	src->val4Up2()
//---	|-----------------------|		. | . . . | . . . | . .		6
//	5	| . . . | . . . | . . . |		. | . 3 . | . 4 . | . 5		5 1
//1	4	| . 3 . | . 4 . | . 5 . |		. | * . . | * . . | Y .		4
//	3	| * . . | * . . | * . . |		-----------------------
//---	|-----------------------|		. | . . . | . . . | . .		3
//	2	| . . . | . . . | . . . |		. | . 0 . | . 1 . | . 2		2 0
//0	1	| . 0 . | . 1 . | . 2 . |		. | * . . | * . . | Y .		1
//	0	| * . . | * . . | * . . |		-----------------------
//---	-------------------------		. | . . . | . . . | . .		0 2
//		  0 1 2   3 4 5   6 7 8			0   1 2 3   4 5 6   7 8
//			0		1		2			2	  0		  1	      2