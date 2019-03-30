#ifndef NCURSES_CLASS_H
# define NCURSES_CLASS_H

# include <curses.h>
# include <cstddef>

class WindowHelper
{
	private:
		int _x;
		int _y;

    public:
		WindowHelper(void);
		WindowHelper(WindowHelper const &);
		~WindowHelper(void);

		WindowHelper& operator=(WindowHelper const &);

        void    setX(int);
        void    setY(int);

		int getX(void) const;
		int getY(void) const;
};

WindowHelper* env(WindowHelper *c = NULL);

#endif

