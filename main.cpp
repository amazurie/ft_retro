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
	Player *p = new Player(FakeVec(WindowHelper::getX() / 2, WindowHelper::getY() / 2));
	entities.addEnt(p);
	int	count = 0;

	while (1)
	{
		usleep(3000);
		timeout(0);
		check_input(p);
		count++;
		if (count > 300)
		{
			entities.addEnt(new Enemy(FakeVec(0, (rand() % (WindowHelper::getX() / 2) + 20))));
			count = 0;
		}
		entities.updateAll();
		std::srand(time(NULL));
		entities.addEnt(new Wall(FakeVec(0, 0), 1));
		clear();
		entities.renderAll();
		refresh();
	}

    return 0;
}
