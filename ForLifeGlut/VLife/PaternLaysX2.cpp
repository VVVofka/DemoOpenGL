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
} // ////////////////////////////////////////////////////////////////////////
PaternLaysX2::~PaternLaysX2() {
	if(vlays != nullptr) {
		for(int nlay = 0; nlay < layscnt; nlay++)
			delete vlays[nlay];
		delete[] vlays;
	}
} // ////////////////////////////////////////////////////////////////////////
void PaternLaysX2::GetVal() {
	vlays[0]->GetVal();
} // /////////////////////////////////////////////////////////////////////////////
void PaternLaysX2::Transform(){
	vlays[0]->Transform();
} // /////////////////////////////////////////////////////////////////////////////
