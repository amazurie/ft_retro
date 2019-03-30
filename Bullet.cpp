#include "Bullet.hpp"

Bullet::Bullet( void )
{
	return;
}

Bullet::Bullet( FakeVec *vec ) :
	AEntity(BULLET, vec)
{
	return;
}

Bullet::Bullet( Bullet const & src ) :
	AEntity(src)
{
	*this = src;
	return;
}

Bullet::~Bullet( void )
{
	return;
}

Bullet &	Bullet::operator=( Bullet const & rhs )
{
	AEntity::operator=(rhs);
	return *this;
}

void	Bullet::render()
{
}

void	Bullet::update()
{
}

bool	Bullet::checkCollide(AEntity &entity)
{
	return false;
}
