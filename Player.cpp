#include "Player.hpp"

Player::Player( void )
{
	return;
}

Player::Player( FakeVec vec ) :
	AEntity(vec)
{
	return;
}

Player::Player( FakeVec & vec ) :
	AEntity(vec)
{
	return;
}

Player::Player( Player const & src )
{
	*this = src;
	return;
}

Player::~Player( void )
{
	return;
}

Player &	Player::operator=( Player const & rhs )
{
	AEntity::operator=(rhs);
	return *this;
}

void		Player::render(void)
{
	move(getVec()->getY() - 3, getVec()->getX() - 8);
	addstr("  _ _ _  ");
	move(getVec()->getY() - 2, getVec()->getX() - 8);
	addstr("||=====||");
	move(getVec()->getY() - 1, getVec()->getX() - 7);
	addstr("\\=====/");
	move(getVec()->getY(), getVec()->getX() - 7);
	addstr("|=====|");
	move(getVec()->getY() + 1, getVec()->getX() - 8);
	addstr("|=======|");
	move(getVec()->getY() + 2, getVec()->getX() - 8);
	addstr("|| ||| || ");
}

void		Player::update(void)
{

}
