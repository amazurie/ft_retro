#include "AEntity.hpp"

AEntity::AEntity(void) : _vec(new FakeVec), _render(true)
{
}

AEntity::AEntity(EntType type, FakeVec *vec) : _type(type), _vec(vec), _render(true)
{
}

AEntity::AEntity(AEntity const & src) : _type(src._type), _vec(src._vec), _render(src._render)
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

void	AEntity::enableRender()
{
	_render = true;
}

void	AEntity::disableRender()
{
	_render = true;
}

bool	AEntity::isRendered() const
{
	return (_render);
}
