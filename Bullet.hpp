#ifndef BULLET_H
#define BULLET_H

#include "AEntity.hpp"
#include "FakeVec.hpp"

class Bullet : public AEntity
{
	private:
		int	_dir;

		Bullet( void );

	public:
		Bullet( FakeVec *_vec, bool const fromPlayer, char dir );
		Bullet( Bullet const & src );
		~Bullet( void );

		void	render(void);
		void	update(void);

		void	resize(int y, int x);
		bool	checkCollide(AEntity &ent);
		bool	checkBox(float startX, float startY, float endX, float endY) const;
		bool 	checkOOW() const;
		int		bulletNum();
		AEntity	*getBullets(int &) const;

		Bullet &	operator=( Bullet const & rhs );
};

#endif /* BULLET_H */
