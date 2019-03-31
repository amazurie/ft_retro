#include "Wall.hpp"

Wall::Wall( void )
{
	return;
}

Wall::Wall( FakeVec *vec, int pos ) :
	AEntity(WALL, vec), _size(rand() % 10), _pos(pos)
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

bool	Wall::checkCollide(AEntity &ent) const
{
	if (BULLET != ent.getType())
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

bool	Wall::checkOOW() const
{
	if (getVec()->getY() > WindowHelper::getY())
	{
		return (true);
	}

	return (false);
}
