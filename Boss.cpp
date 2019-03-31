#include "Boss.hpp"
#include <cstdlib>

int	Boss::_life = 0;

Boss::Boss(void) : AEntity()
{
}

Boss::Boss(FakeVec *vec) : AEntity( BOSS, vec ),
	_shootInt1(300), _shootInt2(150)
{
	_life = 8000;
	getVec()->setY(0);
}

Boss::Boss(Boss const & src) :
	AEntity(src.getType(), src.getVec()),
	_shootInt1(src._shootInt1), _shootInt2(src._shootInt2)
{
}

Boss::~Boss(void)
{
}

Boss& Boss::operator=(Boss const &rhs)
{
	AEntity::operator=(rhs);
	_shootInt1 = rhs._shootInt1;
	_shootInt2 = rhs._shootInt2;
	return *this;
}

void	Boss::update()
{
}

void	Boss::render()
{
	if (!(isRendered()))
		return;

	int	x = getVec()->getX();
	int	y = getVec()->getY();

	attron(COLOR_PAIR(3));
	move(y, x - 16);
	addstr("_____ _    ___||||___    _ _____");
	move(y + 1, x - 16);
	addstr("\\    | |  /          \\  | |     /");
	move(y + 2, x - 16);
	addstr("||\\  | | / __________ \\ | |   /||");
	move(y + 3, x - 16);
	addstr("||  \\| |/ |          | \\| | /  ||");
	move(y + 4, x - 11);
	addstr("| |  |          |  | |");
	move(y + 5, x - 11);
	addstr("| || |__________| || |");
	move(y + 6, x - 11);
	addstr("| | |            | | |");
	move(y + 7, x - 10);
	addstr("|   |__________|   |");
	attroff(COLOR_PAIR(3));
}

// No type check required because enemies doesn't collide with walls
// and player is already checked, so bullets only

bool	Boss::checkCollide(AEntity &ent)
{
	if (ent.checkBox(getVec()->getX() - 16, getVec()->getY(),
				getVec()->getX() + 16, getVec()->getY() + 3))
		return (true);
	if (ent.checkBox(getVec()->getX() - 11, getVec()->getY() + 3,
				getVec()->getX() + 11, getVec()->getY() + 7))
	{
		return (true);
	}
	return (false);
}

bool	Boss::checkOOW() const
{
	if (getVec()->getY() > WindowHelper::getY())
		return (true);
	else if (getVec()->getX() > WindowHelper::getX())
		return (true);

	return (false);
}

void	Boss::resize(int, int)
{
	getVec()->setX(WindowHelper::getX() / 2);
}

bool	Boss::checkBox(float startX, float startY, float endX, float endY)
{
	if (startY > getVec()->getY() + 7)
		return false;
	else if (startX > getVec()->getX() + 14)
		return false;
	else if (endX < getVec()->getX() - 14)
		return false;
	else if (endY < getVec()->getY())
		return false;
	return true;
}

int		Boss::bulletNum()
{
	if (_shootInt1 == 0)
	{
		_shootInt1 = 300;
		return 3;
	}
	_shootInt1--;
	if (_shootInt2 == 0)
	{
		_shootInt2 = 150;
		return 6;
	}
	_shootInt2--;
	return 0;
}

AEntity	*Boss::getBullets(int & i) const
{
	if (_shootInt1 == 300)
	{
		if (i == 3)
		{
			i--;
			return new Bullet(new FakeVec(getVec()->getX() - 2 + rand() % 4, getVec()->getY() + 8), false, 'l');
		}
		if (i == 2)
		{
			i--;
			return new Bullet(new FakeVec(getVec()->getX() - 2 + rand() % 4, getVec()->getY() + 8), false, 'r');
			return NULL;
		}
		if (i-- == 1)
			return new Bullet(new FakeVec(getVec()->getX() - 2 + rand() % 4, getVec()->getY() + 8), false, 'd');
	}
	if (_shootInt2 == 150)
	{
		if (i == 6)
		{
			i--;
			return new Bullet(new FakeVec(getVec()->getX() + rand() % 2 + 8, getVec()->getY() + 8), false, 'l');
		}
		if (i == 5)
		{
			i--;
			return new Bullet(new FakeVec(getVec()->getX() + rand() % 2 + 8, getVec()->getY() + 8), false, 'r');
			return NULL;
		}
		if (i == 4)
		{
			i--;
			return new Bullet(new FakeVec(getVec()->getX() + rand() % 2 + 8, getVec()->getY() + 8), false, 'd');
		}
		if (i == 3)
		{
			i--;
			return new Bullet(new FakeVec(getVec()->getX() - (rand() % 2 + 8), getVec()->getY() + 8), false, 'l');
		}
		if (i == 2)
		{
			i--;
			return new Bullet(new FakeVec(getVec()->getX() - (rand() % 2 + 8), getVec()->getY() + 8), false, 'r');
			return NULL;
		}
		if (i-- == 1)
			return new Bullet(new FakeVec(getVec()->getX() - (rand() % 2 + 8), getVec()->getY() + 8), false, 'd');
	}
	i--;
	return NULL;
}

int	Boss::getLife()
{
	return _life;
}

void	Boss::setLife(int l)
{
	_life = l;
}
