#ifndef STAR_H
#define STAR_H

# include <cstdlib>
# include "AEntity.hpp"

class Star : public AEntity
{
	private:
		Star( void );

	public:
		Star( FakeVec *_vec );
		Star( Star const & src );
		~Star( void );

		void render(void);
		void update(void);
	
		bool checkCollide(AEntity &ent) const;
		bool checkOOW() const;
		bool checkBox(float, float, float, float) const;
		void resize(int, int);
		int		bulletNum() const;
		AEntity	*getBullets(int &);

		Star &	operator=( Star const & rhs );
};

#endif /* STAR_H */
