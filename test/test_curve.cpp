#include <algorithm>
#include <curve_test/src/Curve/BasicCurve.h>
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>

int main() {
	//typedef typename curve::Point Pnt;
	//typedef typename curve::Vector Der;

	try
	{
		std::size_t randNumOfCurve = 10;

		std::cout << randNumOfCurve << std::endl;

		//curve::BasicCurve* curve = new curve::Circle();
		//curve::Point pnt;
		//curve::Vector der;
		//curve->getPnt(pnt, M_PI / 4.);
		//curve->getDer(der, M_PI / 4.);
		//
		//std::cout << pnt.getX() << " " << pnt.getY() << " " << pnt.getZ() << std::endl;
		//std::cout << der.getX() << " " << der.getY() << " " << der.getZ() << std::endl;
		//
		//curve::BasicCurve* curve1 = new curve::Ellipse();
		//curve1->getPnt(pnt);
		//curve1->getDer(der);
		//
		//std::cout << pnt.getX() << " " << pnt.getY() << " " << pnt.getZ() << std::endl;
		//std::cout << der.getX() << " " << der.getY() << " " << der.getZ() << std::endl;
		//delete curve;
		//delete curve1;

		curve::Circle c1 = curve::Circle(2.);
		curve::Circle c2 = curve::Circle(5.);
		curve::Ellipse c3 = curve::Ellipse();
		curve::Circle c4 = curve::Circle();

		//vector of curves pointers
		std::vector<curve::BasicCurve*> curves;

		curves.push_back(&c1);
		curves.push_back(&c2);
		curves.push_back(&c3);
		curves.push_back(&c4);

		//Populate a second container that would contain only circles
		std::vector<curve::BasicCurve*> circles;

		std::copy_if(curves.begin(), curves.end(),
			std::back_inserter(circles),
			[](curve::BasicCurve* ptrCur) {
				curve::Circle* ptrCirc = dynamic_cast<curve::Circle*>(ptrCur);
				return ptrCirc != nullptr;
			});


		//Populate a second container that would contain only circles
		std::vector<curve::Circle*> circles1;

		std::for_each(curves.begin(), curves.end(),
			[&circles1](curve::BasicCurve* ptrCur) {
				curve::Circle* ptrCirc = dynamic_cast<curve::Circle*>(ptrCur);
				if (ptrCirc != nullptr) circles1.push_back(ptrCirc);
			});

		//Sort the second container in the ascending order of circles’ radii
		std::sort(circles1.begin(), circles1.end(),
			[](curve::Circle* ptrL, curve::Circle* ptrR) {
				return *ptrL < *ptrR;
			});

		//Compute the total sum of radii of all curves in the second container
		double sumR = std::accumulate(circles1.begin(), circles1.end(),
			0.,
			[](double sumR, curve::Circle* ptrCirc) {
				return sumR + ptrCirc->getR();
			});

		std::cout << "sumR = " << sumR << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}

	return 0;
}
