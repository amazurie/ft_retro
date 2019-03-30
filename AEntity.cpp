#include "AEntity.hpp"

AEntity::AEntity(void) :
	_vec(new FakeVec())
{
}

AEntity::AEntity(AEntity const & obj) :
	_vec(obj._vec)
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

FakeVec const *AEntity::getVec(void) const
{
	return _vec;
}

void AEntity::setVec(FakeVec *v)
{
    _vec = v;
}
