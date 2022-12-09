#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <numeric>
#include <sstream>
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
		std::cout << std::endl;

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
				curves.emplace_back(std::make_shared<curve::Helix>(r, st));
				}
				break;
			default:
				break;
			}
		}

		//Print coordinates of points and derivatives of all curves in the container at t = PI / 4
		double t = M_PI / 4.;
		std::cout << "t = " << t << std::endl;
		
		curve::Point pnt;
		curve::Vector der;

		for(const auto& ptrCur : curves) {
			ptrCur->getPnt(pnt, t);
			ptrCur->getDer(der, t);

			std::cout << "x(t) = " << pnt.getX() << ", y(t) = " << pnt.getY() << ", z(t) = " << pnt.getZ() << std::endl;
			std::cout << "x'(t) = " << der.getX() << ", y'(t) = " << der.getY() << ", z'(t) = " << der.getZ() << std::endl;
			std::cout << std::endl;
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
