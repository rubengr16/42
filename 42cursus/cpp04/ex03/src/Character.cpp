/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:52:05 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/12 01:51:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void):
	_name("Unnamed"),
	_unequipped(NULL),
	_unequippedSize(0)
{
	std::cout << "[Default Constructor] Character: named as" << this->_name
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
	int	i;
	for (i = 0; i < MAX_INVENTORY; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string& name):
	_name(name),
	_unequipped(NULL),
	_unequippedSize(0)
{
	std::cout << "[Constructor] Character: named as " << this->_name
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
	int	i;
	for (i = 0; i < MAX_INVENTORY; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& character):
	_name(character.getName()),
	_unequipped(NULL),
	_unequippedSize(0)
{
	std::cout << "[Copy Constructor] Character: named as " << this->_name
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
	int	i;
	for (i = 0; i < MAX_INVENTORY; i++)
		this->_inventory[i] = NULL;
}

Character&	Character::operator=(const Character& character)
{
	this->_name = character.getName();
	this->_unequipped = NULL;
	this->_unequippedSize = 0;
	std::cout << "[Copy Assignment Operator] Character: named as "
		<< this->_name << " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
	int	i;
	for (i = 0; i < MAX_INVENTORY; i++)
		this->_inventory[i] = NULL;
}

std::string const&	Character::getName() const
{
	return (this->_name);
}

Character::~Character(void)
{
	int	i;

	for (i = 0; i < MAX_INVENTORY; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
	for (i = 0; i < this->_unequippedSize; i++)
		delete this->_unequipped[i];
	delete[] this->_unequipped;
}

void	Character::equip(AMateria* m)
{
	int	idx;

	idx = 0;
	while (idx < MAX_INVENTORY && this->_inventory[idx])
		idx++;
	if (idx == MAX_INVENTORY)
	{
		std::cout << "[Equip] Character: inventory is full!!" << std::endl;
		return ;
	}
	this->_inventory[idx] = m;
	std::cout << "[Equip] Character: materia " << m->getType() << " equipped"
		<< std::endl;
}

void	Character::unequip(int idx)
{
	int			i;
	AMateria**	aux;

	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << "[Unequip] Character: index out of range!!" << std::endl;
		return ;
	}
	aux = this->_unequipped;
	this->_unequippedSize++;
	this->_unequipped = new AMateria*[this->_unequippedSize];
	i = 0;
	for (i = 0; i < (this->_unequippedSize - 1); i++)
		this->_unequipped[i] = aux[i];
	this->_unequipped[this->_unequippedSize - 1] = this->_inventory[idx];
	std::cout << "[Unequip] Character: unequip "
		<< this->_inventory[idx]->getType() << " at index " << idx
		<< std::endl;
	this->_inventory[idx] = NULL;
	delete[] aux;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << "[Use] Character: index out of range!!" << std::endl;
		return ;
	}
	std::cout << "[Use] Character: using use of "
		<< this->_inventory[idx]->getType() << " in index "
		<< idx << std::endl;
	this->_inventory[idx]->use(target);
}
