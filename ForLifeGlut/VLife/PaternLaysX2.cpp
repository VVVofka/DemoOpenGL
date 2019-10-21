#include "PaternLaysX2.h"

PaternLaysX2::PaternLaysX2() {
	layscnt = 0;
	vlays = nullptr;
} // ///////////////////////////////////////////////////////////////////////////////////////
PaternLaysX2::PaternLaysX2(int max_size, int min_size = 1, BOOL DelayUp = TRUE, BOOL DelayTransform = TRUE) {
	Create(max_size,  min_size,  DelayUp,  DelayTransform);
} // ////////////////////////////////////////////////////////////////////////
PaternLaysX2::~PaternLaysX2() {
	delv();
} // /////////////////////////////////////////////////////////////////////////////////////////
void PaternLaysX2::Create(int max_size, int min_size, BOOL DelayUp, BOOL DelayTransform) {
	delv();
	layscnt = 0;
	int maxsize = 1;
	while(maxsize < max_size)
		maxsize *= 2, layscnt++;
	vlays = new PaternLayX2 * [layscnt];
	int newsz = 1;
	for(int nlay = 0; nlay < layscnt; nlay++) {
		vlays[nlay] = new PaternLayX2(newsz, DelayUp, DelayTransform);
		newsz *= 2;
	}
	for(int nlay = 1; nlay < layscnt; nlay++)
		vlays[nlay - 1]->dnLay = vlays[nlay];
} // //////////////////////////////////////////////////////////////////////////////////////
void PaternLaysX2::GetVal() {
	vlays[0]->GetVal();
} // /////////////////////////////////////////////////////////////////////////////
void PaternLaysX2::Transform() {
	vlays[0]->Transform();
} // /////////////////////////////////////////////////////////////////////////////
void PaternLaysX2::delv() {
	if(vlays != nullptr) {
		for(int nlay = 0; nlay < layscnt; nlay++)
			delete vlays[nlay];
		delete[] vlays;
	}
}  // /////////////////////////////////////////////////////////////////////////////////////////
