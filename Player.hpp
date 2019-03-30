#ifndef PLAYER_H
#define PLAYER_H

# include "AEntity.hpp"
# include "FakeVec.hpp"

class Player : public AEntity
{
	private:

		Player( void );

	public:
		Player( FakeVec _vec );
		Player( FakeVec & _vec );
		Player( Player const & src );
		~Player( void );

		void render(void);
		void update(void);

		Player &	operator=( Player const & rhs );
};

#endif /* PLAYER_H */
