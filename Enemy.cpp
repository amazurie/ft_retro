#include "Enemy.hpp"
#include <cstdlib>

Enemy::Enemy(void) : AEntity()
{
}

Enemy::Enemy(FakeVec *vec) : AEntity( ENEMY, vec ),
	 _direction(rand() % 2 == 1 ? 1 : 0)
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
	getVec()->setY(getVec()->getY() + 0.05);
/*	if (_direction == 1)
		getVec()->setX(getVec()->getX() + 1);
	else
		getVec()->setX(getVec()->getX() - 1);
*/}

void	Enemy::render()
{
	int	x = getVec()->getX();
	int	y = getVec()->getY();

	attron(COLOR_PAIR(3));
	if (y > 2)
	{
		move(y - 2, x - 2);
		addstr("/\\__/\\");
	}
	if (y > 1)
	{
		move(y - 1, x - 2);
		addstr("|    |");
	}
	move(y, x - 3);
	addstr("| |  | |");
	move(y + 1, x);
	addstr("||");
	attroff(COLOR_PAIR(3));
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
