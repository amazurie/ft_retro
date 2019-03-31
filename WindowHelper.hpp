#ifndef NCURSES_CLASS_H
# define NCURSES_CLASS_H

# include <curses.h>
# include <cstddef>

class WindowHelper
{
	private:
		static unsigned int _score;
		static int _x;
		static int _y;
		static bool _pause;

    public:
		WindowHelper(void);
		WindowHelper(WindowHelper const &);
		~WindowHelper(void);

		WindowHelper& operator=(WindowHelper const &);

        static void		setScore(unsigned int);
		static void		addScore(unsigned int);
        static void		setX(int);
        static void		setY(int);
		static void		setPause(bool);

		static unsigned int	getScore(void);
		static int	getX(void);
		static int	getY(void);
		static bool	getPause(void);
};

WindowHelper* env(WindowHelper *c = NULL);

#endif

