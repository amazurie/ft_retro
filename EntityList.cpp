#include <iostream>
#include "EntityList.hpp"

EntityList::EntityList(unsigned int size) :
	_nbMaxEnts(size), _nbEnts(0), _list(new AEntity *[_nbMaxEnts])
{
	std::cout << "Contructor called" << std::endl;
}

EntityList::EntityList(EntityList const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

EntityList		&EntityList::operator=(EntityList const &rhs)
{
	_nbMaxEnts = rhs._nbMaxEnts;
	_nbEnts = rhs._nbEnts;
	_list = rhs._list;
	std::cout << "Assignment operator called" << std::endl;
	return (*this);
}

EntityList::~EntityList()
{
	for (unsigned int i = 0; i < _nbEnts; ++i)
		delete _list[i];
	delete [] _list;
	std::cout << "Destructor called" << std::endl;
}

bool			EntityList::addEnt(AEntity *ent)
{
	if ((NULL == ent) || (_nbEnts == _nbMaxEnts) || (0 == _nbMaxEnts))
		return (false);
	_list[_nbEnts] = ent;
	_nbEnts += 1;
	return (true);
}

unsigned int	EntityList::getNbEnts() const
{
	return (_nbEnts);
}

unsigned int	EntityList::getNbMaxEnts() const
{
	return (_nbMaxEnts);
}

unsigned int	EntityList::_findEnt(AEntity *ent, bool & found) const
{
	unsigned int i = 0;

	for (; i < _nbEnts; ++i)
	{
		if (_list[i] == ent)
		{
			found = true;
			break;
		}
	}
	return (i);
}

bool		EntityList::delEnt(AEntity *ent)
{
	if ((NULL == ent) || (0 == _nbEnts) || (0 == _nbMaxEnts))
		return (false);

	if (_list[(_nbEnts - 1)] == ent)
	{
		delete _list[(_nbEnts - 1)];
		_list[(_nbEnts - 1)] = NULL;
	}
	else
	{
		bool found = false;
		unsigned int idx = _findEnt(ent, found);
		if (!(found))
			return (false);
		AEntity *tmp = _list[idx];
		_list[idx] = _list[(_nbEnts - 1)];
		_list[(_nbEnts - 1)] = NULL;
		delete tmp;
	}
	_nbEnts -= 1;
	return (true);
}

// Player can collide with: Horizontal Walls, Enemies
// Enemies can collide with: Player, Bullets

bool	EntityList::checkCollide()
{
	if ((0 == _nbEnts) || (0 == _nbMaxEnts))
		return;

	bool		playerCollision = false;
	AEntity*	player = _list[0];

	for (unsigned int i = 0; i < _nbEnts; ++i)
	{
		for (unsigned int j = (i + 1); j < _nbEnts; ++j)
		{
			if (_list[i].isCollide(_list[j]))
			{
				// do stuff
			}			
		}
	}
}
















































