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
#include "Boss.hpp"

void	check_input(Player *p)
{
	char	c;

	if (WindowHelper::getPause())
	{
		p->getVec()->setY(WindowHelper::getY() - 20);
		p->getVec()->setX(WindowHelper::getX() / 2);
	}
	if (WindowHelper::getX() < 50
			|| WindowHelper::getY() < 50)
	{
		clear();
		move(0, 0);
		addstr("window too little");
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
		if ((c == 'w') && ((p->getVec()->getY() - 3) >= 0))
		{
			p->getVec()->setY(p->getVec()->getY() - 1);
		}
		else if (c == 'a')
			p->getVec()->setX(p->getVec()->getX() - 2);
		else if (c == 's' && ((p->getVec()->getY() + 3) <= WindowHelper::getY()))
			p->getVec()->setY(p->getVec()->getY() + 1);
		else if (c == 'd')
			p->getVec()->setX(p->getVec()->getX() + 2);
		else if (c == 'p')
			WindowHelper::setPause(true);
	}
}

void	infoBoard()
{
	unsigned int sc;
	int	i;
	int j;

	sc = WindowHelper::getScore();
	j = sc;
	i = 1;
	while (j /= 10)
		i *= 10;
	attron(COLOR_PAIR(3));
	move(1, 1);
	addstr(" Lives : ");
	addstr(">:) ");
	j = 1;
	while (i / j > 100)
	{
		j *= 10;
		addch(' ');
	}
	move(2, 1);
	addstr(" Score : ");
	j = i;
	while (i)
	{
		addch('0' + sc / i % 10);
		i /= 10;
	}
	addch(' ');
	attroff(COLOR_PAIR(5));
}

int		main(void)
{
    WindowHelper w = WindowHelper();
	EntityList entities(1024);
	Player *p = new Player(new FakeVec(WindowHelper::getX() / 2, WindowHelper::getY() - 20));
	entities.addEnt(p);
	int	count = 0;
	std::srand(time(NULL));

	int	y = WindowHelper::getY();
	while (y--)
	{
			entities.addEnt(new Wall(new FakeVec(0, y), 1));
			entities.addEnt(new Wall(new FakeVec(WindowHelper::getX(), y), 2));
	}
	entities.addEnt(new Boss(new FakeVec(WindowHelper::getX() / 2, 0)));
	while (1)
	{
		usleep(3000);
		timeout(0);
		entities.updateAll();
		entities.checkOOW();
		if (entities.checkCollide() || WindowHelper::getScore() > 2000000000)
		{
			char c = 0;
			while (c != 'r')
			{
				while ((c = getch()) != ERR)
				{
					if (c == 'q')
						return 0;
					if (c == 'r')
					{
						WindowHelper::setScore(0);
						while (y--)
						{
								entities.addEnt(new Wall(new FakeVec(0, y), 1));
								entities.addEnt(new Wall(new FakeVec(WindowHelper::getX(), y), 2));
						}
						//TODO entities.dellAll();
						p = new Player(new FakeVec(WindowHelper::getX() / 2, WindowHelper::getY() - 20));
						entities.addEnt(p);
						break;
					}
				}
				move(WindowHelper::getY() / 2 - 1, WindowHelper::getX() / 2 - 4);
				addstr("YOU LOSE!");
				if (WindowHelper::getScore() > 2000000000)
				{
					move(WindowHelper::getY() / 2, WindowHelper::getX() / 2 - 18);
					addstr("CHEATER! I think... (maybe... hehehe)");
				}
				refresh();
			}
		}
		entities.resize(WindowHelper::getY(), WindowHelper::getX());
		check_input(p);
		count++;
		if (count > 300)
		{
			entities.addEnt(new Enemy(new FakeVec((rand() % (WindowHelper::getX() - 30) + 15), 0)));
			count = rand() % 100;
		}
		if (count % 10 == 0 && WindowHelper::getX() > 100)
		{
			entities.addEnt(new Star(new FakeVec((rand() % (WindowHelper::getX() - 20)) + 10, 0)));
			entities.addEnt(new Wall(new FakeVec(0, 0), 1));
			entities.addEnt(new Wall(new FakeVec(WindowHelper::getX(), 0), 2));
		}
		erase();
		entities.renderAll();
		infoBoard();
		refresh();
	}

    return 0;
}
