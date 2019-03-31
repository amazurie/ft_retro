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

Bullet::Bullet( Bullet const & src ) : AEntity(src.getType(), src.getVec())
{
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

bool	Bullet::checkCollide(AEntity &ent) const
{
	if (PLAYER == ent.getType())
	{
		// debug ?
	}

	else if ((getVec()->getX() == ent.getVec()->getX())
		|| (getVec()->getY() == ent.getVec()->getY()))
	{
		return (true);
	}

	return (false);
}

bool	Bullet::checkOOW() const
{
	if (getVec()->getY() < 0)
	{
		return (true);
	}

	return (false);
}

void	Bullet::resize(int, int)
{
}
