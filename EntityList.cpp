#include <iostream>
#include "EntityList.hpp"
#include "Boss.hpp"

EntityList::EntityList(unsigned int size) :
	_nbMaxEnts(size), _nbEnts(0), _list(new AEntity *[_nbMaxEnts])
{
}

EntityList::EntityList(EntityList const &src)
{
	*this = src;
}

EntityList		&EntityList::operator=(EntityList const &rhs)
{
	_nbMaxEnts = rhs._nbMaxEnts;
	_nbEnts = rhs._nbEnts;
	_list = rhs._list;
	return (*this);
}

EntityList::~EntityList()
{
	delAllEnts();
	delete [] _list;
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

	for (; i < _nbEnts; i++)
	{
		if (_list[i] == ent)
		{
			found = true;
			break;
		}
	}
	return (i);
}

bool		EntityList::delEnt(AEntity *ent, unsigned int idx)
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
		AEntity *tmp = _list[idx];
		_list[idx] = _list[(_nbEnts - 1)];
		_list[(_nbEnts - 1)] = NULL;
		delete tmp;
	}

	_nbEnts -= 1;
	return (true);
}

bool	EntityList::addEntsTab(unsigned int size, AEntity** ents)
{
	if ((0 == size) || (NULL == ents)
		|| (size > _nbMaxEnts) || ((_nbEnts + size) > _nbMaxEnts))
	{
		return (false);
	}

	for (unsigned int i = 0; i < size; ++i)
		if (NULL != ents[i])
			addEnt(ents[i]);

	return (true);
}

void	EntityList::_collideEvent(AEntity & ent1, AEntity & ent2, unsigned int i1, unsigned int i2)
{
	// Player & All
	if ((PLAYER == ent1.getType()) && (STAR != ent2.getType())
	&& (BULLET_PLAYER != ent2.getType())) // Player can't be ent2 because checked first
	{
		delEnt(&ent1, i1);
	}

	// Wall & Bullets
	else if ((WALL == ent1.getType())
		&& ((BULLET_PLAYER == ent2.getType()) || (BULLET_ENEMY == ent2.getType())))
	{
		delEnt(&ent2, i2);
	}
	else if (((BULLET_PLAYER == ent1.getType()) || (BULLET_ENEMY == ent1.getType())) 
		&& (WALL == ent2.getType()))
	{
		delEnt(&ent1, i1);
	}

	// Enemy & Bullets, Bullets & Bullets
	else if (((BULLET_PLAYER == ent1.getType()) && (ENEMY == ent2.getType()))
		|| ((ENEMY == ent1.getType()) && (BULLET_PLAYER == ent2.getType())))
	{
		WindowHelper::addScore(100);
		delEnt(&ent1, i1);
		delEnt(&ent2, i2);
	}

	//Stars
	else if (STAR == ent1.getType())
	{
		ent1.disableRender();
	}
	else if (STAR == ent2.getType())
	{
		ent2.disableRender();
	}

	else if ((BULLET_PLAYER == ent1.getType()) && (BOSS == ent2.getType()))
	{
		if (Boss::getLife())
			Boss::setLife(Boss::getLife() - 1);
		else
			delEnt(&ent2, i2);
	}
	else if ((BOSS == ent1.getType()) && (BULLET_PLAYER == ent2.getType()))
	{
		if (Boss::getLife())
			Boss::setLife(Boss::getLife() - 1);
		else
			delEnt(&ent1, i1);
	}
}

void	EntityList::checkOOW()
{
	if ((0 == _nbEnts) || (0 == _nbMaxEnts))
		return;
	for (unsigned int i = 0; i < _nbEnts; ++i)
	{
		if (PLAYER == _list[i]->getType())
			continue;
		else if (_list[i]->checkOOW())
		{
			delEnt(_list[i], i);
		}
	}
}

void	EntityList::delAllEnts()
{
	for (unsigned int i = 0; i < _nbEnts; i++)
		delete _list[i];
}

// Player can collide with: Horizontal Walls, Enemies
// Enemies can collide with: Player, Bullets

bool	EntityList::checkCollide()
{
	if ((0 == _nbEnts) || (0 == _nbMaxEnts))
		return (false);

	bool	playerDied = false;
	for (unsigned int i = 0; i < _nbEnts; ++i)
	{
		for (unsigned int j = (i + 1); j < _nbEnts; ++j)
		{
			if (_list[i]->checkCollide(*(_list[j])))
			{
				_collideEvent(*(_list[i]), *(_list[j]), i, j);
				if ((0 == i) && (STAR != _list[j]->getType()) && (BULLET_PLAYER != _list[j]->getType()))
					playerDied = true;
			}			
		}
	}
	return (playerDied);
}

void	EntityList::updateAll(void)
{
	for (unsigned int i = 0; i < _nbEnts; i++)
		_list[i]->update();
	shootAll();
}

void	EntityList::renderAll(void)
{
	for (unsigned int i = 0; i < _nbEnts; i++)
	{
		if (_list[i]->isRendered())
			_list[i]->render();
		else
			_list[i]->enableRender();
	}
}


void	EntityList::resize(int y, int x)
{
	for (unsigned int i = 0; i < _nbEnts; i++)
		_list[i]->resize(y, x);
}

void	EntityList::shootAll()
{
	unsigned int	nb = _nbEnts;
	int	j;

	for (unsigned int i = 0; i < nb; i++)
	{
		j = _list[i]->bulletNum();
		while (j)
		{
			AEntity *e = _list[i]->getBullets(j);
			if (e != NULL)
				addEnt(e);
		}
	}
}
