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
		Wall( FakeVec *_vec , int pos);
		Wall( Wall const & src );
		~Wall( void );

		void render(void);
		void update(void);
		void resize(int y, int x);

		bool checkCollide(AEntity &ent) const;
		bool checkOOW() const;

		Wall &	operator=( Wall const & rhs );
};

#endif /* WALL_H */
