#define _USE_MATH_DEFINES

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>

#include <curve_test/src/Curve/BasicCurve.h>


int main() {
	//typedef typename curve::Point Pnt;
	//typedef typename curve::Vector Der;

	try
	{
		srand((unsigned)time(0));
		std::size_t randNumOfCurve = (rand() % 10) + 1;
		
		std::cout << "random number of curves = " << randNumOfCurve << std::endl;

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

		//Populate a container curves created in random manner with random parameters
		std::vector<std::shared_ptr<curve::BasicCurve>> curves;

		enum CurveType { Circle, Ellipse, Helix };
		double paramMin = 0.1;
		double paramMax = 10.;

		for (std::size_t i = 0; i < randNumOfCurve; i++)
		{
			CurveType curveType = CurveType(rand() % 3);

			switch (curveType)
			{
			case Circle:
				{
				double r = paramMin + ((double)rand() / RAND_MAX) * (paramMax - paramMin);
				curves.emplace_back(std::make_shared<curve::Circle>(r));
				}
				break;
			case Ellipse:
				{
				double r1 = paramMin + ((double)rand() / RAND_MAX) * (paramMax - paramMin);
				double r2 = paramMin + ((double)rand() / RAND_MAX) * (paramMax - paramMin);
				curves.emplace_back(std::make_shared <curve::Ellipse>(r1, r2));
				}
				break;
			case Helix:
				{
				double  r = paramMin + ((double)rand() / RAND_MAX) * (paramMax - paramMin);
				double st = paramMin + ((double)rand() / RAND_MAX) * (paramMax - paramMin);
				curves.emplace_back(std::make_shared<curve::Ellipse>(r, st));//TODO
				}
				break;
			default:
				break;
			}
		}

		//Populate a second container that would contain only circles
		std::vector<std::shared_ptr<curve::Circle>> circles;

		std::for_each(curves.begin(), curves.end(),
			[&circles](auto& ptrCur) {
				auto ptrCirc = std::dynamic_pointer_cast<curve::Circle>(ptrCur);
				if (ptrCirc != nullptr)
					circles.emplace_back(ptrCirc);
			});

		//Sort the second container in the ascending order of circles’ radii
		std::sort(circles.begin(), circles.end(),
			[](auto& ptrL, auto& ptrR) {
				return *ptrL.get() < *ptrR.get();
			});

		//Compute the total sum of radii of all curves in the second container
		double sumR = std::accumulate(circles.begin(), circles.end(),
			0.,
			[](double sumR, auto& ptrCirc) {
				return sumR + ptrCirc.get()->getR();
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
