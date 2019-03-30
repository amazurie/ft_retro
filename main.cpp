#include <unistd.h>
#include <ctime>
#include "WindowHelper.hpp"
#include "AEntity.hpp"
#include "Player.hpp"
#include "Wall.hpp"
#include "FakeVec.hpp"

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
	Player *p = new Player(FakeVec(WindowHelper::getX() / 2, WindowHelper::getY() / 2));
	std::srand(time(NULL));
	Wall *wall = new Wall(FakeVec(0, 0), 1);

	while (1)
	{
		usleep(3000);
		timeout(0);
		check_input(p);
		clear();
		p->render();
		wall->render();
		wall->update();
		refresh();
	}

    return 0;
}
