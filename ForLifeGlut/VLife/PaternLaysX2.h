#pragma once
#include "PaternLayX2.h"
// слой - клетка - атом
class PaternLaysX2{
public:
	PaternLaysX2();
	PaternLaysX2(int maxsize, int min_size, BOOL DelayUp, BOOL DelayTransform);
	~PaternLaysX2();

	int layscnt;
	PaternLayX2** vlays;

	void Create(int maxsize, int min_size, BOOL DelayUp, BOOL DelayTransform);
	void GetVal();
	void Transform();

private:
	void delv();
}; // **************************************************************************************************

