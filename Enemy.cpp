#include "Enemy.hpp"

Enemy::Enemy(void) : AEntity()
{
}

Enemy::Enemy(FakeVec vec) : AEntity( vec )
{
}

Enemy::Enemy(Enemy const & obj) : AEntity(obj)
{
}

Enemy::~Enemy(void)
{
}

Enemy& Enemy::operator=(Enemy const &rhs)
{
	AEntity::operator=(rhs);
	return *this;
}

void	Enemy::update()
{

}

void	Enemy::render()
{

}
