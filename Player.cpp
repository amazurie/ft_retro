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
	move(getVec()->getY(), getVec()->getX());
	addstr("P");
}

void		Player::update(void)
{

}
