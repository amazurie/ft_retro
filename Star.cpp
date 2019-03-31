#include "Star.hpp"

Star::Star( void )
{
	return;
}

Star::Star( FakeVec *vec ) : AEntity(STAR, vec), _render(true)
{
	return;
}

Star::Star( Star const & src ) : AEntity(src.getType(), src.getVec()), _render(true)
{
	return;
}

Star::~Star( void )
{
	return;
}

Star &	Star::operator=( Star const & rhs )
{
	AEntity::operator=(rhs);
	return *this;
}

void		Star::render(void)
{
	move(getVec()->getY(), getVec()->getX());
	addstr("*");
}

void		Star::update(void)
{
	getVec()->setY(getVec()->getY() + 0.2);
}

bool	Star::checkCollide(AEntity &ent) const
{
	if ((getVec()->getX() == ent.getVec()->getX())
		|| (getVec()->getY() == ent.getVec()->getY()))
	{
		return (true);
	}

	return (false);
}

bool	Star::checkOOW() const
{
	if (getVec()->getY() > WindowHelper::getY())
	{
		return (true);
	}

	return (false);
}

bool	Star::checkBox(float startX, float startY, float endX, float endY) const
{
	(void)startX;(void)startY;(void)endX;(void)endY;
	return (false);
}
