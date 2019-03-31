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

Player::Player( Player const & src ) : AEntity(src.getType(), src.getVec())
{
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
	attroff(COLOR_PAIR(1));
}

void		Player::update(void)
{

}

// No type check required, either enemy or wall makes the player die and
// bullets are faster than the player

bool	Player::checkCollide(AEntity &ent) const
{
	if ((WALL != ent.getType()) && (ENEMY != ent.getType()))
	{
		// debug ?
	}

	if (ent.checkBox(getVec()->getX() - 3, getVec()->getY() - 2,
				getVec()->getX() + 3, getVec()->getY() + 1))
	{
		return (true);
	}

	return (false);
}

bool	Player::checkOOW() const
{
	return (false);
}

void	Player::resize(int, int)
{
}

bool	Player::checkBox(float, float, float, float) const
{
	return false;
}
