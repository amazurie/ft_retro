#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "AEntity.hpp"
# include "FakeVec.hpp"
# include "Bullet.hpp"

class Enemy : public AEntity
{
	private:
		int		_type;
		int		_shootInt;
		int		_direction;

		Enemy(void);

	public:
		Enemy(FakeVec *vec);
		Enemy(Enemy const & obj);
		~Enemy(void);

		Enemy& operator=(Enemy const &rhs);

		void update(void);
		void render(void);

		void resize(int y, int x);
		bool checkCollide(AEntity &ent);
		bool checkBox(float startX, float startY, float endX, float endY);
		bool checkOOW() const;
		int		bulletNum();
		AEntity	*getBullets(int &) const;
};

#endif // ENEMY_HPP
