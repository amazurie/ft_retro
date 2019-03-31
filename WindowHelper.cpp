#include <ncurses.h>
#include <csignal>
#include "WindowHelper.hpp"

int		WindowHelper::_x = 0;
int		WindowHelper::_y = 0;
bool	WindowHelper::_pause = false;
unsigned int	WindowHelper::_score = 0;

void	onResize(int)
{
	endwin();
	refresh();
	clear();

	int x, y;
	getmaxyx(stdscr, y, x);
	WindowHelper::setY(y);
	WindowHelper::setX(x);
	WindowHelper::setPause(true);
	move(y / 2, x / 2 - 3);
	addstr("PAUSED");
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

    start_color();

    init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_color(COLOR_YELLOW, 700, 600, 0);
    init_pair(2, COLOR_WHITE, COLOR_YELLOW);
	init_color(COLOR_RED, 1000, 600, 300);
    init_pair(3, COLOR_RED, COLOR_BLACK);
	init_color(COLOR_BLUE, 150, 300, 600);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_color(COLOR_WHITE, 500, 500, 500);
    init_pair(5, COLOR_RED, COLOR_WHITE);
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

void WindowHelper::setPause(bool b)
{
	_pause = b;
}

int WindowHelper::getX(void)
{
	return _x;
}

int WindowHelper::getY(void)
{
	return _y;
}

bool WindowHelper::getPause(void)
{
	return _pause;
}

void	WindowHelper::setScore(unsigned int score)
{
	_score = score;
}

void	WindowHelper::addScore(unsigned int score)
{
	_score += score;
}

unsigned int	WindowHelper::getScore(void)
{
	return _score;
}
