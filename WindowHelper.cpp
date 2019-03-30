#include <ncurses.h>
#include <csignal>
#include "WindowHelper.hpp"

int		WindowHelper::_x = 0;
int		WindowHelper::_y = 0;

void	onResize(int)
{
	endwin();
	refresh();
	clear();

	int x, y;
	getmaxyx(stdscr, y, x);
	WindowHelper::setY(y);
	WindowHelper::setX(x);
}

WindowHelper::WindowHelper(void)
{
	initscr();
	cbreak();
	noecho();

	curs_set(0);

	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	scrollok(stdscr, FALSE);
	std::signal(SIGWINCH, onResize);

	getmaxyx(stdscr, _y, _x);
    return ;
}

WindowHelper::WindowHelper(WindowHelper const &src)
{
    *this = src;
    return ;
}

WindowHelper& WindowHelper::operator=(WindowHelper const &rhs)
{
    _x = rhs._x;
    _y = rhs._y;
    return *this;
}



WindowHelper::~WindowHelper(void)
{
	endwin();
    return ;
}

void WindowHelper::setX(int x)
{
	_x = x;
}

void WindowHelper::setY(int y)
{
	_y = y;
}

int WindowHelper::getX(void)
{
	return _x;
}

int WindowHelper::getY(void)
{
	return _y;
}
