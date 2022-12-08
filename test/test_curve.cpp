#include <curve_test/src/Curve/BasicCurve.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

int main() {
	//typedef typename curve::Point Pnt;
	//typedef typename curve::Vector Der;

	try
	{
		std::size_t randNumOfCurve = 10;

		std::cout << randNumOfCurve << std::endl;

		curve::BasicCurve* curve = new curve::Circle();
		curve::Point pnt;
		curve::Vector der;
		curve->getPnt(pnt, M_PI / 4.);
		curve->getDer(der, M_PI / 4.);

		std::cout << pnt.getX() << " " << pnt.getY() << " " << pnt.getZ() << std::endl;
		std::cout << der.getX() << " " << der.getY() << " " << der.getZ() << std::endl;

		delete curve;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}

	return 0;
}
