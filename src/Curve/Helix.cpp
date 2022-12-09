#include <curve_test/src/Curve/BasicCurve.h>
#include <cmath>
#include <stdexcept>

namespace curve {

Helix::Helix(const double theR,
			 const double theSt,
			 const double theXc,
			 const double theYc)
: myR(theR),
  mySt(theSt),
  myXc(theXc),
  myYc(theYc)
{
	if (myR <= 0. || mySt <= 0.) {
		throw std::invalid_argument(
			std::string(
				std::string("Helix::Helix : ") +
				std::string("radius and step must be positive")
			).c_str());
	}
}

void Helix::setR(const double theR)
{
	if (theR <= 0.) {
		throw std::invalid_argument(
			std::string(
				std::string("Helix::setR : ") +
				std::string("radius must be positive")
			).c_str());
	}

	myR = theR;
}

void Helix::setSt(const double theSt)
{
	if (theSt <= 0.) {
		throw std::invalid_argument(
			std::string(
				std::string("Helix::setSt : ") +
				std::string("Step must be positive")
			).c_str());
	}

	mySt = theSt;
}

bool Helix::getPnt(Point& thePnt, const double theT) const
{
	thePnt.setX(myXc + myR * cos(theT));
	thePnt.setY(myYc + myR * sin(theT));
	thePnt.setZ(mySt * theT / (2. * M_PI));

	return true;
}

bool Helix::getDer(Vector& theDer, const double theT) const
{
	theDer.setX(-myR * sin(theT));
	theDer.setY( myR * cos(theT));
	theDer.setZ(mySt / (2. * M_PI));

	return true;
}

} //namespace curve
