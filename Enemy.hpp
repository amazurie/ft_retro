#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "AEntity.hpp"
# include "FakeVec.hpp"

class Enemy : public AEntity
{
	private:
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
		bool checkCollide(AEntity &ent) const;
		bool checkOOW() const;
};

#endif // ENEMY_HPP
