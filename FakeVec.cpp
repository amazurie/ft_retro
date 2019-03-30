#include "FakeVec.hpp"

FakeVec::FakeVec(void) : _x(0), _y(0)
{
    return;
}

FakeVec::FakeVec(int x, int y) : _x(x), _y(y)
{
    return;
}

FakeVec::FakeVec(FakeVec const& src)
{
    *this = src;
}

FakeVec::~FakeVec(void)
{
    return;
}

int      FakeVec::getX(void) const
{
    return _x;
}

int      FakeVec::getY(void) const
{
    return _y;
}

void     FakeVec::setX(int n)
{
    _x = n;
}

void     FakeVec::setY(int n)
{
    _y = n;
}

FakeVec& FakeVec::operator=(FakeVec const& src)
{
	_x = src._x;
	_y = src._y;
	return *this;
}

FakeVec FakeVec::operator+(FakeVec const& rhs) const
{
	FakeVec tmp(_x + rhs._x, _y + rhs._y);
	return tmp;
}

FakeVec FakeVec::operator-(FakeVec const& rhs) const
{
	FakeVec tmp(_x - rhs._x, _y - rhs._y);
	return tmp;
}

bool FakeVec::operator==(FakeVec const& rhs) const
{
	if (_x == rhs._x && _y == rhs._y)
		return true;
	return false;
}

bool FakeVec::operator!=(FakeVec const& rhs) const {
	if (_x == rhs._x && _y == rhs._y)
		return false;
	return true;
}
