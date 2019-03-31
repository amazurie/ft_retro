
#ifndef ENTITY_INTERFACE_H
# define ENTITY_INTERFACE_H

# include <curses.h>
# include "FakeVec.hpp"
# include "WindowHelper.hpp"

typedef enum Type
{
	PLAYER,
	ENEMY,
	BULLET,
	WALL,
	STAR
} EntType;

class AEntity
{
	private:
		EntType		_type;
		FakeVec		*_vec;
		bool		_render;

	public:
		AEntity(void);
		AEntity(EntType type, FakeVec *_vec);
		AEntity(AEntity const & obj);
		virtual ~AEntity(void);

		AEntity& operator=(AEntity const &rhs);

		virtual void update(void) = 0;
		virtual void render(void) = 0;

		virtual bool checkCollide(AEntity &ent) const = 0;
		virtual bool checkOOW() const = 0;

        FakeVec		*getVec(void) const;
        EntType		getType() const;

        void setVec(FakeVec *x);

        void enableRender();
        void disableRender();
        bool isRendered() const;
};

#endif // ENTITY_INTERFACE_H
