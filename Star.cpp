#include "Star.hpp"

Star::Star( void )
{
	return;
}

Star::Star( FakeVec *vec ) : AEntity(STAR, vec)
{
	return;
}

Star::Star( Star const & src ) : AEntity(src.getType(), src.getVec())
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
	if (!(isRendered()))
		return;

	move(getVec()->getY(), getVec()->getX());
	addstr("*");
}

void		Star::update(void)
{
	getVec()->setY(getVec()->getY() + 0.01);
}

bool	Star::checkCollide(AEntity &ent) const
{
	if (ent.checkBox(getVec()->getX(), getVec()->getY(),
				getVec()->getX(), getVec()->getY()))
		return (true);

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
	int	x = getVec()->getX();
	int y = getVec()->getY();

	if ((startX <= x && startY <= y && endX >= x && endY >= y))
		return true;
	return (false);
}

void	Star::resize(int, int)
{

}

int		Star::bulletNum() const
{
	return 0;
}

AEntity	**Star::getBullets() const
{
	return NULL;
}
