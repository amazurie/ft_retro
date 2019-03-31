#include "Bullet.hpp"

Bullet::Bullet( void )
{
	return;
}

Bullet::Bullet(FakeVec *vec, bool const fromPlayer, char const dir) :
	AEntity(fromPlayer ? BULLET_PLAYER : BULLET_ENEMY, vec), _dir(dir)
{
	return;
}

Bullet::Bullet( Bullet const & src ) :
	AEntity(src.getType(), src.getVec()), _dir(src._dir)
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
	_dir = rhs._dir;
	return *this;
}

void	Bullet::render()
{
	if (getType() == BULLET_PLAYER)
		attron(COLOR_PAIR(5));
	else if (getType() == BULLET_ENEMY)
		attron(COLOR_PAIR(3));
	move(getVec()->getY(), getVec()->getX());
	addstr("|");
	if (getType() == BULLET_PLAYER)
		attroff(COLOR_PAIR(5));
	else if (getType() == BULLET_ENEMY)
		attroff(COLOR_PAIR(3));
}

void	Bullet::update()
{
	if (_dir == 'd')
		getVec()->setY(getVec()->getY() + 0.1);
	else if (_dir == 'l')
	{
		getVec()->setY(getVec()->getY() + 0.1);
		getVec()->setX(getVec()->getX() - 0.1);
	}
	else if (_dir == 'r')
	{
		getVec()->setY(getVec()->getY() + 0.1);
		getVec()->setX(getVec()->getX() + 0.1);
	}
	else
		getVec()->setY(getVec()->getY() - 0.3);
}

bool	Bullet::checkCollide(AEntity &ent)
{
	if (ent.checkBox(getVec()->getX(), getVec()->getY(),
				getVec()->getX(), getVec()->getY()))
		return (true);

	return (false);
}

bool	Bullet::checkOOW() const
{
	if ((getVec()->getY() < 0) || (getVec()->getX() < 0)
		|| (getVec()->getX() > WindowHelper::getX()))
		return (true);

	return (false);
}

void	Bullet::resize(int, int)
{
}

bool	Bullet::checkBox(float startX, float startY, float endX, float endY) const
{
	int x = getVec()->getX();
	int y = getVec()->getY();

	if ((startX <= x && startY <= y && endX >= x && endY >= y))
		return true;
	return false;
}

int		Bullet::bulletNum()
{
	return 0;
}

AEntity	*Bullet::getBullets(int &) const
{
	return NULL;
}
