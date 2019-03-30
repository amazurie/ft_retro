#ifndef WALL_H
#define WALL_H

# include <cstdlib>
# include "AEntity.hpp"

class Wall : public AEntity
{
	private:
		int			_size;
		int			_pos;

		Wall( void );

	public:
		Wall( FakeVec _vec , int pos);
		Wall( FakeVec & _vec , int pos);
		Wall( Wall const & src );
		virtual ~Wall( void );

		virtual void render(void);
		virtual void update(void);

		Wall &	operator=( Wall const & rhs );
};

#endif /* WALL_H */
