#include "Wall.hpp"

Wall::Wall( void )
{
	return;
}

Wall::Wall( FakeVec *vec, int pos ) :
	AEntity(WALL, vec), _size(rand() % 5 + 5), _pos(pos)
{
	return;
}

Wall::Wall( Wall const & src ) :
	AEntity(src.getType(), src.getVec()), _size(src._size), _pos(src._pos)
{
	return;
}

Wall::~Wall( void )
{
	return;
}

Wall &	Wall::operator=( Wall const & rhs )
{
	AEntity::operator=(rhs);
	_size = rhs._size;
	_pos = rhs._pos;
	return *this;
}

void		Wall::render(void)
{
	if (!(isRendered()))
		return;

	int i;

	if (_pos == 1)
	{
		move(getVec()->getY(), getVec()->getX());
		attron(COLOR_PAIR(2));
		i = _size;
		while (i--)
			addstr(" ");
		attroff(COLOR_PAIR(2));
		return ;
	}
	move(getVec()->getY(), getVec()->getX() - _size);
	attron(COLOR_PAIR(2));
	i = _size;
	while (i--)
		addstr(" ");
	attroff(COLOR_PAIR(2));
	return ;
}

void		Wall::update(void)
{
	getVec()->setY(getVec()->getY() + 0.1);
}

bool	Wall::checkCollide(AEntity &ent)
{
	if ((_pos == 1 && ent.checkBox(getVec()->getX(),
				getVec()->getY(), getVec()->getX() + _size, getVec()->getY()))
			|| (_pos == 2 && ent.checkBox(getVec()->getX() - _size,
				getVec()->getY(), getVec()->getX(), getVec()->getY())))
	{	
		return (true);
	}

	return (false);
}

bool	Wall::checkOOW() const
{
	if (getVec()->getY() > WindowHelper::getY())
	{
		return (true);
	}

	return (false);
}

void	Wall::resize(int y, int x)
{
	if (x < 100)
		getVec()->setY(y + 1);
	else if (_pos == 2)
		getVec()->setX(x);
}

bool	Wall::checkBox(float startX, float startY, float endX, float endY) const
{
	if (startY > getVec()->getY())
		return false;
	if (endY < getVec()->getY())
		return false;
	if (_pos == 1 && startX > getVec()->getX() + _size)
		return false;
	if (endX < getVec()->getX() - _size)
		return false;
	return true;
}

int		Wall::bulletNum()
{
	return 0;
}

AEntity	*Wall::getBullets(int &) const
{
	return NULL;
}
