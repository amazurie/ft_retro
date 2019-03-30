#include "Wall.hpp"

Wall::Wall( void )
{
	return;
}

Wall::Wall( FakeVec vec, int pos ) :
	AEntity(vec), _size(rand() % 5), _pos(pos)
{
	return;
}

Wall::Wall( FakeVec & vec, int pos ) :
	AEntity(vec), _pos(pos)
{
	return;
}

Wall::Wall( Wall const & src ) :
	_size(src._size), _pos(src._pos)
{
	*this = src;
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

	move(getVec()->getY(), getVec()->getX());
	attron(COLOR_PAIR(2));
	i = _size;
	while (i--)
		addstr(" ");
	attroff(COLOR_PAIR(2));
}

void		Wall::update(void)
{
	getVec()->setY(getVec()->getY() + 1);
}
