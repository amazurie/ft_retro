
#ifndef ENTITY_INTERFACE_H
# define ENTITY_INTERFACE_H

# include "FakeVec.hpp"

class AEntity
{
	private:
        FakeVec *_vec;

	public:
		AEntity(void);
		AEntity(AEntity const & obj);
		virtual ~AEntity(void);

		AEntity& operator=(AEntity const &rhs);

		virtual void update(void) = 0;
		virtual void render(void) = 0;
        bool checkCollide(AEntity &entity);

        FakeVec const *getVec(void) const;

        void setVec(FakeVec *x);
};

#endif // ENTITY_INTERFACE_H
