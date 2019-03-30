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
	bool			delEnt(AEntity *);

private:
	EntityList();
	unsigned int		_nbMaxEnts;
	unsigned int		_nbEnts;
	AEntity**			_list;
	bool				_contiguous;
	unsigned int		_findEnt(AEntity *, bool &) const;
};

#endif
