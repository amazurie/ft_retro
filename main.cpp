#include <unistd.h>
#include <ctime>
#include "WindowHelper.hpp"
#include "AEntity.hpp"
#include "Player.hpp"
#include "Wall.hpp"
#include "FakeVec.hpp"
#include "EntityList.hpp"
#include "Enemy.hpp"

void	check_input(Player *p)
{
	char	c;

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
		usleep(3000);
		timeout(0);
		check_input(p);
		entities.updateAll();
		count++;
		if (count > 300)
		{
			entities.addEnt(new Enemy(new FakeVec(0, (rand() % (WindowHelper::getX() / 2) + 20))));
			count = 0;
		}
		if (count % 10 == 0)
		{
			entities.addEnt(new Wall(new FakeVec(0, 0), 1));
			entities.addEnt(new Wall(new FakeVec(WindowHelper::getX(), 0), 2));
		}
		clear();
		entities.renderAll();
		refresh();
	}

    return 0;
}
