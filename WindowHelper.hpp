#ifndef NCURSES_CLASS_H
# define NCURSES_CLASS_H

# include <curses.h>
# include <cstddef>

class WindowHelper
{
	private:
		static int _x;
		static int _y;

    public:
		WindowHelper(void);
		WindowHelper(WindowHelper const &);
		~WindowHelper(void);

		WindowHelper& operator=(WindowHelper const &);

        static void    setX(int);
        static void    setY(int);

		static int getX(void);
		static int getY(void);
};

WindowHelper* env(WindowHelper *c = NULL);

#endif

