#ifndef ENTITYLIST_HPP
# define ENTITYLIST_HPP

# include "AEntity.hpp"

class EntityList
{
	public:
		EntityList(unsigned int size);
		EntityList(EntityList const &);
		~EntityList();

		EntityList	&operator=(EntityList const &);

		unsigned int	getNbEnts() const;
		unsigned int	getNbMaxEnts() const;
		bool			addEnt(AEntity *);
		bool			addEntsTab(unsigned int size, AEntity** ents);
		bool			delEnt(AEntity *, unsigned int idx);
		void			updateAll(void);
		void			renderAll(void);
		bool			checkCollide();
		void			checkOOW();
		void			resize(int y, int x);
		void			shootAll(void);
		void			delAllEnts();

	private:
		EntityList();
		unsigned int		_nbMaxEnts;
		unsigned int		_nbEnts;
		AEntity**			_list;
		unsigned int		_findEnt(AEntity *ent, bool & found) const;
		void				_collideEvent(AEntity &, AEntity &, unsigned, unsigned);
};

#endif
