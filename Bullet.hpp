#ifndef BULLET_H
#define BULLET_H

#include "AEntity.hpp"
#include "FakeVec.hpp"

class Bullet : public AEntity
{
	private:

		Bullet( void );

	public:
		Bullet( FakeVec *_vec );
		Bullet( Bullet const & src );
		~Bullet( void );

		void	render(void);
		void	update(void);
		bool	checkCollide(AEntity &entity);

		Bullet &	operator=( Bullet const & rhs );
};

#endif /* BULLET_H */
