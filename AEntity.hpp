
#ifndef ENTITY_INTERFACE_H
# define ENTITY_INTERFACE_H

# include <curses.h>
# include "FakeVec.hpp"
# include "WindowHelper.hpp"

typedef enum Type
{
	PLAYER,
	ENEMY,
	BULLET_PLAYER,
	BULLET_ENEMY,
	WALL,
	STAR
} EntType;

class AEntity
{
	private:
		EntType			_type;
		FakeVec			*_vec;
		bool			_render;
		unsigned int	_idx;

		AEntity(void);

	public:
		AEntity(EntType type, FakeVec *_vec);
		AEntity(AEntity const & obj);
		virtual ~AEntity(void);

		AEntity& operator=(AEntity const &rhs);

		virtual void update(void) = 0;
		virtual void render(void) = 0;
		virtual void resize(int y, int x) = 0;

		virtual bool checkCollide(AEntity &ent) = 0;
		virtual bool checkBox(float, float, float, float) const = 0;
		virtual bool checkOOW() const = 0;
		virtual	int  bulletNum() = 0;
		virtual AEntity *getBullets(int &) const = 0;

        FakeVec		*getVec(void) const;
        EntType		getType() const;

        void setVec(FakeVec *x);

        void enableRender();
        void disableRender();
        bool isRendered() const;
};

#endif // ENTITY_INTERFACE_H
