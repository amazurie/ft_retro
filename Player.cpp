#include "Player.hpp"

Player::Player( void )
{
	return;
}

Player::Player( FakeVec *vec ) :
	AEntity(PLAYER, vec)
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
	int	x = getVec()->getX();
	int	y = getVec()->getY();

	attron(COLOR_PAIR(1));
	move(y - 2, x - 3);
	addstr("||   ||");
	move(y - 1, x - 3);
	addstr("|=| |=|");
	move(y, x - 2);
	addstr("|=|=|");
	move(y + 1, x - 3);
	addstr("|=| |=|");
	move(y + 2, x - 2);
	addstr("|| ||");
	attroff(COLOR_PAIR(1));
}

void		Player::update(void)
{

}

bool	Player::checkCollide(AEntity &entity)
{
	return false;
}
