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
		addstr("| || |");
	}
	move(y, x - 2);
	addstr("|\\__/|");
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

	else if (ent.checkBox(getVec()->getX() - 2, getVec()->getY() - 2,
				getVec()->getX() + 3, getVec()->getY()))
	{
		return (true);
	}

	return (false);
}

bool	Enemy::checkOOW() const
{
	if (getVec()->getY() > WindowHelper::getY())
		return (true);
	else if (getVec()->getX() > WindowHelper::getX())
		return (true);

	return (false);
}

void	Enemy::resize(int, int)
{
}

bool	Enemy::checkBox(float startX, float startY, float endX, float endY) const
{
	if (startY > getVec()->getY())
		return false;
	else if (startX > getVec()->getX() + 3)
		return false;
	else if (endX < getVec()->getX() - 2)
		return false;
	else if (endY < getVec()->getY() - 2)
		return false;
	return true;
}

int		Enemy::bulletNum() const
{
	return 0;
}

AEntity	**Enemy::getBullets() const
{
	return NULL;
}
