#include "AEntity.hpp"

AEntity::AEntity(void) :
	_vec(new FakeVec)
{
}

AEntity::AEntity(FakeVec & vec) : _vec(&vec)
{
}

AEntity::AEntity(AEntity const & src) :
	_vec(src._vec)
{
}

AEntity::~AEntity(void)
{
}

AEntity& AEntity::operator=(AEntity const &rhs)
{
	_vec = rhs._vec;

	return *this;
}

bool AEntity::checkCollide(AEntity &entity)
{
	return (_vec == entity._vec);
}

FakeVec *AEntity::getVec(void) const
{
	return _vec;
}

void AEntity::setVec(FakeVec *v)
{
    _vec = v;
}
