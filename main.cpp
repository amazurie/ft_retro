#include <unistd.h>
#include <ctime>
#include <ncurses.h>
#include "WindowHelper.hpp"
#include "AEntity.hpp"
#include "Player.hpp"
#include "Wall.hpp"
#include "FakeVec.hpp"
#include "EntityList.hpp"
#include "Enemy.hpp"
#include "Star.hpp"

void	check_input(Player *p)
{
	char	c;

	if (WindowHelper::getPause() || WindowHelper::getX() < 50
			|| WindowHelper::getY() < 50)
	{
		clear();
		move(0, 0);
		addstr("window too little");
		p->getVec()->setY(WindowHelper::getY() - 20);
		p->getVec()->setX(WindowHelper::getX() / 2);
		refresh();
	}
	while (WindowHelper::getPause() || WindowHelper::getX() < 50
			|| WindowHelper::getY() < 50)
	{
		c = getch();
		if (c == 'p')
		{
			WindowHelper::setPause(false);
			p->getVec()->setY(WindowHelper::getY() - 20);
			p->getVec()->setX(WindowHelper::getX() / 2);
			break;
		}
	}
	while ((c = getch()) != ERR)
	{
		if (c == 'w')
			p->getVec()->setY(p->getVec()->getY() - 1);
		else if (c == 'a')
			p->getVec()->setX(p->getVec()->getX() - 1);
		else if (c == 's')
			p->getVec()->setY(p->getVec()->getY() + 1);
		else if (c == 'd')
			p->getVec()->setX(p->getVec()->getX() + 1);
		else if (c == 'p')
			WindowHelper::setPause(true);
	}
}

int		main(void)
{
    WindowHelper w = WindowHelper();
	EntityList entities(1024);
	Player *p = new Player(new FakeVec(WindowHelper::getX() / 2, WindowHelper::getY() / 2));
	entities.addEnt(p);
	int	count = 0;
	std::srand(time(NULL));

	while (1)
	{
		usleep(30000);
		timeout(0);
		entities.updateAll();
		entities.checkOOW();
		if (entities.checkCollide())
		{
			while (1)
			{
				move(WindowHelper::getY() / 2, WindowHelper::getX() / 2 - 4);
				addstr("YOU LOSE!");
			}
		}
		entities.resize(WindowHelper::getY(), WindowHelper::getX());
		check_input(p);
		count++;
		if (count > 300)
		{
			entities.addEnt(new Enemy(new FakeVec((rand() % (WindowHelper::getX() / 2) + (WindowHelper::getX() / 4)), 0)));
			count = 0;
		}
		if (count % 10 == 0 && WindowHelper::getX() > 100)
		{
			entities.addEnt(new Star(new FakeVec((rand() % WindowHelper::getX()), 0)));
			entities.addEnt(new Wall(new FakeVec(0, 0), 1));
			entities.addEnt(new Wall(new FakeVec(WindowHelper::getX(), 0), 2));
		}
		clear();
		entities.renderAll();
		move(1, 1);
		addstr(" Lives  : ");
		addch('0' + 3);
		move(2, 1);
		addstr(" Points : ");
		addch('0');
		move(3, 1);
		refresh();
	}

    return 0;
}
