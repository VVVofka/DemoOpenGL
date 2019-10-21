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

	void GetVal();
	void Transform();
	BOOL bDelayUp;
	BOOL bTransform;

private:


}; // **************************************************************************************************

