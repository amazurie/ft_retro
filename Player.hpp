#ifndef PLAYER_H
#define PLAYER_H

# include "AEntity.hpp"
# include "Bullet.hpp"

class Player : public AEntity
{
	private:
		int	_shootInt;
		Player(void);

	public:
		Player( FakeVec *_vec );
		Player( Player const & src );
		~Player( void );

		void render(void);
		void update(void);

		void resize(int y, int x);
		bool checkCollide(AEntity &ent);
		bool checkBox(float startX, float startY, float endX, float endY) const;
		bool checkOOW() const;
		int		bulletNum();
		AEntity	*getBullets(int &) const;

		Player &	operator=( Player const & rhs );
};

#endif /* PLAYER_H */
