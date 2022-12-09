#include <curve_test/src/Curve/BasicCurve.h>
#include <cmath>
#include <stdexcept>

namespace curve {

Ellipse::Ellipse(const double theR1,
				 const double theR2,
				 const double theXc,
				 const double theYc)
: myR1(theR1),
  myR2(theR2),
  myXc(theXc),
  myYc(theYc)
{
	if (myR1 <= 0. || myR2 <= 0.) {
		throw std::invalid_argument(
			std::string(
				std::string("Ellipse::Ellipse : ") +
				std::string("radii must be positive")
			).c_str());
	}
}

void Ellipse::setR1(const double theR)
{
	if (theR <= 0.) {
		throw std::invalid_argument(
			std::string(
				std::string("Ellipse::setR : ") +
				std::string("1st radius must be positive")
			).c_str());
	}

	myR1 = theR;
}

void Ellipse::setR2(const double theR)
{
	if (theR <= 0.) {
		throw std::invalid_argument(
			std::string(
				std::string("Ellipse::setR : ") +
				std::string("2nd radius must be positive")
			).c_str());
	}

	myR2 = theR;
}

bool Ellipse::getPnt(Point& thePnt, const double theT) const
{
	thePnt.setX(myXc + myR1 * cos(theT));
	thePnt.setY(myYc + myR2 * sin(theT));
	thePnt.setZ(0.);

	return true;
}

bool Ellipse::getDer(Vector& theDer, const double theT) const
{
	theDer.setX(-myR1 * sin(theT));
	theDer.setY( myR2 * cos(theT));
	theDer.setZ(0.);

	return true;
}

} //namespace curve