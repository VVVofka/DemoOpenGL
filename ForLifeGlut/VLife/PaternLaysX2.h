#pragma once
#include "PaternLayX2.h"
// слой - клетка - атом
class PaternLaysX2{
public:
	PaternLaysX2(int maxsize, BOOL DelayUp, BOOL DelayTransform);
	~PaternLaysX2();

	int maxsize;	// длина стороны самого большого слоя
	int layscnt;
	PaternLayX2** vlays;

	void Run();
	BOOL bDelayUp;
	BOOL bTransform;

private:
	void fUpUniver(void (PaternLaysX2::* f)(int nlay_src));		// call from Run(). Use fUp1(), fUp2()
	void fUp1(int nlay_src);
	void fUp2(int nlay_src);

	void fTransformUniver(void (PaternLaysX2::* f)(int nlay));	// call from Run()
	void fTransform1(int nlay_src);
	void fTransform2(int nlay_src);
	unsigned getH(int nlay, int pos);

	void fTransformDelay(PaternLayX2* lay);
	void fTransformNoDelay(PaternLayX2* lay);
	void (PaternLaysX2::*fTransform)(PaternLayX2* lay);

}; // **************************************************************************************************

