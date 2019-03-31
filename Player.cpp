#include "Player.hpp"

Player::Player( void )
{
	return;
}

Player::Player( FakeVec *vec ) :
	AEntity(PLAYER, vec), _shootInt(3)
{
	return;
}

Player::Player( Player const & src ) :
	AEntity(src.getType(), src.getVec()), _shootInt(src._shootInt)
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
	_shootInt = rhs._shootInt;
	return *this;
}

void		Player::render(void)
{
	if (!(isRendered()))
		return;
	
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

bool	Player::checkCollide(AEntity &ent)
{
	if ((WALL != ent.getType()) && (ENEMY != ent.getType()))
	{
		// debug ?
	}

	if (ent.checkBox(getVec()->getX() - 3, getVec()->getY() - 2,
				getVec()->getX() + 3, getVec()->getY() + 1))
		return (true);

	return (false);
}

bool	Player::checkOOW() const
{
	return (false);
}

void	Player::resize(int, int)
{
}

bool	Player::checkBox(float startX, float startY, float endX, float endY) const
{
	if (startY > getVec()->getY())
		return false;
	else if (startX > getVec()->getX() + 3)
		return false;
	else if (endX < getVec()->getX() - 2)
		return false;
	else if (endY < getVec()->getY() - 2)
		return false;
	return true;
}

int		Player::bulletNum()
{
	if (!_shootInt)
	{
		_shootInt = 3;
		return 2;
	}
	_shootInt--;
	return 0;
}

AEntity *Player::getBullets(int & i) const
{
	if (i == 2)
	{
		i--;
		return (new Bullet(new FakeVec(getVec()->getX() - 3, getVec()->getY() - 3)));
	}
	else if (i-- == 1)
		return (new Bullet(new FakeVec(getVec()->getX() + 3, getVec()->getY() - 3)));
	return NULL;
}
