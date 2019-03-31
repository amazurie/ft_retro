#include "Enemy.hpp"
#include <cstdlib>

Enemy::Enemy(void) : AEntity()
{
}

Enemy::Enemy(FakeVec *vec) : AEntity( ENEMY, vec ),
	 _direction(rand() % 2 == 1 ? 1 : 0)
{
}

Enemy::Enemy(Enemy const & obj) : AEntity(obj)
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

bool	Enemy::checkCollide(AEntity &entity)
{
	return false;
}
