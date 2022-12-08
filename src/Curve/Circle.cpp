#include <curve_test/src/Curve/BasicCurve.h>
#include <cmath>
#include <stdexcept>

namespace curve {

Circle::Circle(const double theR,
			   const double theXc,
			   const double theYc)
: myR(theR),
  myXc(theXc),
  myYc(theYc)
{
	if (myR <= 0.) {
		throw std::invalid_argument(
			std::string(
				std::string("Circle::Circle : ") +
				std::string("radii must be positive")
			).c_str());
	}
}

void Circle::setR(const double theR)
{
	if (theR <= 0.) {
		throw std::invalid_argument(
			std::string(
				std::string("Circle::setR : ") +
				std::string("radii must be positive")
			).c_str());
	}

	myR = theR;
}

bool Circle::getPnt(Point& thePnt, const double theT) const
{
	thePnt.setX(myXc + myR * cos(theT));
	thePnt.setY(myYc + myR * sin(theT));
	thePnt.setZ(0.);

	return true;
}

bool Circle::getDer(Vector& theDer, const double theT) const
{
	theDer.setX(-myR * sin(theT));
	theDer.setY( myR * cos(theT));
	theDer.setZ(0.);

	return true;
}

} //namespace curve