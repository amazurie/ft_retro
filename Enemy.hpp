#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "AEntity.hpp" 

class Enemy : public AEntity
{
	private:
		
	public:
		Enemy(void);
		Enemy(Enemy const & obj);
		~Enemy(void);

		Enemy& operator=(Enemy const &rhs);

		void update(void);
		void render(void);

		bool isCollide(AEntity &entity);
};

#endif // ENEMY_HPP
