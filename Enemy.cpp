#include "Enemy.hpp"

Enemy::Enemy(void) : AEntity()
{
}

Enemy::Enemy(FakeVec *vec) : AEntity(ENEMY, vec)
{
}

Enemy::Enemy(Enemy const & src) : AEntity(src.getType(), src.getVec())
{
}

Enemy::~Enemy(void)
{
}

Enemy& Enemy::operator=(Enemy const &rhs)
{
	AEntity::operator=(rhs);
	return *this;
}

void	Enemy::update()
{

}

void	Enemy::render()
{

}

// No type check required because enemies doesn't collide with walls
// and player is already checked, so bullets only

bool	Enemy::checkCollide(AEntity &ent) const
{
	if (BULLET != ent.getType())
	{
		// debug?
	}

	else if ((getVec()->getX() == ent.getVec()->getX())
		|| (getVec()->getY() == ent.getVec()->getY()))
	{
		return (true);
	}

	return (false);
}

bool	Enemy::checkOOW() const
{
	if (getVec()->getY() < WindowHelper::getY())
	{
		return (true);
	}

	return (false);
}
