#include "AEntity.hpp"

AEntity::AEntity(void) :
	_vec(new FakeVec)
{
}

AEntity::AEntity(EntType type, FakeVec *vec) : _type(type), _vec(vec)
{
}

AEntity::AEntity(AEntity const & src) :
	_vec(src._vec)
{
}

AEntity::~AEntity(void)
{
	delete _vec;
}

AEntity& AEntity::operator=(AEntity const &rhs)
{
	_type = rhs._type;
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

EntType	AEntity::getType() const
{
	return (_type);
}
