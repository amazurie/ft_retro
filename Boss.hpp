#ifndef BOSS_HPP
# define BOSS_HPP

# include "AEntity.hpp"
# include "FakeVec.hpp"
# include "Bullet.hpp"

class Boss : public AEntity
{
	private:
		static int		_life;
		int		_shootInt1;
		int		_shootInt2;
		
		Boss(void);

	public:
		Boss(FakeVec *vec);
		Boss(Boss const & obj);
		~Boss(void);

		Boss& operator=(Boss const &rhs);

		void update(void);
		void render(void);
		static int  getLife(void);
		static void setLife(int);

		void resize(int y, int x);
		bool checkCollide(AEntity &ent);
		bool checkBox(float startX, float startY, float endX, float endY);
		bool checkOOW() const;
		int		bulletNum();
		AEntity	*getBullets(int &) const;
};

#endif // BOSS_HPP
