#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "AEntity.hpp"
# include "FakeVec.hpp"

class Enemy : public AEntity
{
	private:
		
		Enemy(void);

	public:
		Enemy(FakeVec *vec);
		Enemy(Enemy const & obj);
		~Enemy(void);

		Enemy& operator=(Enemy const &rhs);

		void update(void);
		void render(void);
};

#endif // ENEMY_HPP
