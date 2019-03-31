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
	move(getVec()->getY(), getVec()->getX());
	addstr("|");
}

void	Bullet::update()
{
	getVec()->setY(getVec()->getY() - 1);
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
	if (getVec()->getY() < 0)
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
