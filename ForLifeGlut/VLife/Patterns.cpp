#include "Patterns.h"
#include <map>
#pragma warning(push)
#pragma warning(disable: 26451)
Patterns::Patterns(int x, int y) {
	Create(x, y);
} // //////////////////////////////////////////////////////////////////////////////////////
Patterns::Patterns(int xy) {
	Create(xy, xy);
} // //////////////////////////////////////////////////////////////////////////////////////
Patterns::~Patterns() {
	if(v != nullptr) delete[]v;
} // //////////////////////////////////////////////////////////////////////////////////////
void Patterns::Create(pattertype X, pattertype Y) {
	if(X > 0 && Y > 0) {
		pattertype sz = 1 << ((szx = X) * (szy = Y));
		szv = sz + sz;
		if(v != nullptr)
			delete[] v;
		v = new pattertype[szv];
		for(pattertype n = 0; n < sz; n++) {
			_RPT1(_CRT_WARN, "%u\n", n);
			_ASSERTE(2 * n + 1 < szv);
			v[2 * n] = Dissipation(n);
			v[2 * n + 1] = Density(n);
		}
	}
	else {
		szx = szy = 0;
		v = nullptr;
	}
} // /////////////////////////////////////////////////////////////////////
pattertype Patterns::Density(pattertype a) {
	std::list<Point> srcSet;
	if(a2lst(a, &srcSet, 1) == 0)
		return a;
	PointF avgPoint = getAvgPoint(&srcSet);
	PointF midPoint(0.5 * (szx - 1.), 0.5 * (szy - 1.));
	PointF outPoint((avgPoint * 2) - midPoint);
	std::multimap<double, Point> vOrdSet;
	for(Point p : srcSet)
		vOrdSet.insert(std::pair<double, Point>(outPoint ^ p, p));

	pattertype ret = a;
	for(std::pair<double, Point>pair : vOrdSet)
		ret = movPoint(pair.second, ret, outPoint);
	return ret;
} // /////////////////////////////////////////////////////////////////////
pattertype Patterns::Dissipation(pattertype a) {
	std::list<Point> srcSet;
	if(a2lst(a, &srcSet, 1) == 0)
		return a;
	PointF avgPoint = getAvgPoint(&srcSet);
	PointF midPoint(0.5 * (szx - 1.), 0.5 * (szy - 1.));
	PointF outPoint((midPoint * 3) - (avgPoint * 2));
	std::multimap<double, Point> vOrdSet;
	for(Point p : srcSet)
		vOrdSet.insert(std::pair<double, Point>(outPoint ^ p, p));

	pattertype ret = a;
	for(std::pair<double, Point>pair : vOrdSet)
		ret = movPoint(pair.second, ret, outPoint);
	return ret;
} // /////////////////////////////////////////////////////////////////////
int Patterns::a2lst(pattertype a, std::list<Point>* v, pattertype type) {
	int ret = 0;
	if(type != 0) type = 1;
	v->clear();
	for(unsigned y = 0, n = 0; y < (unsigned)szy; y++) {
		for(unsigned x = 0; x < (unsigned)szx; x++) {
			unsigned p1 = (a >> n++) & 1;
			if(p1 == type) {
				v->push_back(Point(x, y));
				ret++;
			}
		}
	}
	return ret;
} // /////////////////////////////////////////////////////////////////////
PointF Patterns::getAvgPoint(std::list<Point>* srcSet) {
	PointF sumy(0);
	for(Point pnt : *srcSet)
		sumy += pnt;
	sumy /= srcSet->size();
	return sumy;
} // /////////////////////////////////////////////////////////////////////
pattertype Patterns::movPoint(Point pointFrom, pattertype a, PointF outPoint) {
	std::list<Point> srcEmpty;
	if(a2lst(a, &srcEmpty, 0) == 0)
		return a;
	double minOutD = outPoint ^ pointFrom;
	Point bestPoint(-1);
	for(Point curEmptyPoint : srcEmpty) {
		double curd = pointFrom ^ curEmptyPoint;
		if(curd < 1.5) {
			double outd = outPoint ^ curEmptyPoint;
			if(outd < minOutD) {
				minOutD = outd;
				bestPoint = curEmptyPoint;
			}
		}
	}
	if(bestPoint != -1) {
		a |= 1 << bestPoint.of(szx);
		a &= ~(1 << pointFrom.of(szx));
	}
	return a;
} // /////////////////////////////////////////////////////////////////////
CString Patterns::PrintRow(pattertype a, int szx, int n_row) {
	CString ret;
	unsigned n = n_row * szx;
	_RPT0(_CRT_WARN, "zadavaka+S1");
	for(unsigned x = 0; x < (unsigned)szx; x++) {
		unsigned p1 = (a >> n++) & 1;
		ret += p1 == 0 ? "0" : "1";
	}
	return ret;
} // /////////////////////////////////////////////////////////////////////////////////////

#pragma warning(pop)
//pattertype Patterns::lst2a(std::list<Point>* v, pattertype type_def) {
//	pattertype ret;
//	if(type_def == 0) {
//		ret = 0;
//		for(Point p : *v) {
//			unsigned shift = p.x + p.y * szx;
//			unsigned mask = 1 << shift;
//			ret |= mask;
//		}
//	}
//	else { // if(type_def == 0) 
//		ret = (1 << (szx * szy + 1)) - 1;
//		for(Point p : *v) {
//			unsigned shift = p.x + p.y * szx;
//			unsigned mask = ~(1 << shift);
//			ret &= mask;
//		}
//	}
//	return ret;
//} // /////////////////////////////////////////////////////////////////////