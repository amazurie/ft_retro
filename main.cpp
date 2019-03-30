#include "WindowHelper.hpp"
#include "AEntity.hpp"
#include "Player.hpp"
#include "FakeVec.hpp"

#include <iostream>
int main(void)
{
    WindowHelper w = WindowHelper();
	Player *p = new Player(FakeVec(WindowHelper::getX() / 2, WindowHelper::getY() / 2));
	char	c;

	while (1)
	{
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
		clear();
		p->render();
		refresh();
	}

    return 0;
}
