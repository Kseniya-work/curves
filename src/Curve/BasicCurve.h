#include <iostream>//TODO
namespace curve {

struct Point {
	Point()
	: myX(0.0),
	  myY(0.0),
	  myZ(0.0)
	{}

	Point(const double theX, const double theY, const double theZ)
	: myX(theX),
	  myY(theY),
	  myZ(theZ)
	{}

	void setX(const double theX) { myX = theX; }
	void setY(const double theY) { myY = theY; }
	void setZ(const double theZ) { myZ = theZ; }

	double getX() const { return myX; }
	double getY() const { return myY; }
	double getZ() const { return myZ; }

private:
	double myX;
	double myY;
	double myZ;
};


struct Vector {
	Vector()
	: myX(0.0),
	  myY(0.0),
	  myZ(0.0)
	{}

	Vector(const double theX, const double theY, const double theZ)
	: myX(theX),
	  myY(theY),
	  myZ(theZ)
	{}

	void setX(const double theX) { myX = theX; }
	void setY(const double theY) { myY = theY; }
	void setZ(const double theZ) { myZ = theZ; }

	double getX() const { return myX; }
	double getY() const { return myY; }
	double getZ() const { return myZ; }

private:
	double myX;
	double myY;
	double myZ;
};

class BasicCurve {

public:
	virtual ~BasicCurve() { std::cout << "~BasicCurve"; }; //TODO

	virtual bool getPnt(Point& thePnt,
						const double theT = 0.0) const = 0;
	virtual bool getDer(Vector& theDer,
						const double theT = 0.0) const = 0;
};

class Circle : public BasicCurve
{
public:
	explicit Circle(const double theR = 1.,
					const double theXc = 0.,
					const double theYc = 0.);

	~Circle() { std::cout << "~Circle"; } //TODO

	void setR(const double theR);
	double getR() const { return myR; }

	bool getPnt(Point&  thePnt, const double theT = 0.0) const override;
	bool getDer(Vector& theDer, const double theT = 0.0) const override;

	bool operator<(const Circle& theR) const;

private:
	double myR;
	double myXc;
	double myYc;
};

class Ellipse : public BasicCurve
{
public:
	explicit Ellipse(const double theR1 = 1.,
					 const double theR2 = 2.,
					 const double theXc = 0.,
					 const double theYc = 0.);

	~Ellipse() { std::cout << "~Ellipse"; } //TODO

	void setR1(const double theR);
	void setR2(const double theR);

	double getR1() const { return myR1; }
	double getR2() const { return myR2; }

	bool getPnt(Point&  thePnt, const double theT = 0.0) const override;
	bool getDer(Vector& theDer, const double theT = 0.0) const override;

private:
	double myR1;
	double myR2;
	double myXc;
	double myYc;
};

} //namespace curve