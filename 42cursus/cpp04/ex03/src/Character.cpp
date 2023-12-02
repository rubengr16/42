/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:52:05 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/02 13:58:49 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
Character::Character(void):
	_name("Unnamed"),
	_unequipped(NULL),
	_unequippedSize(0)
{
	unsigned int	i;

	std::cout << "[Default Constructor] Character: named as" << this->_name
		<< " has been created" << std::endl
		<< "----------------------------------------------------" << std::endl;
	for (i = 0; i < MAX_INVENTORY; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string& name):
	_name(name),
	_unequipped(NULL),
	_unequippedSize(0)
{
	unsigned int	i;

	std::cout << "[Constructor] Character: named as " << this->_name
		<< " has been created" << std::endl
		<< "----------------------------------------------------" << std::endl;
	for (i = 0; i < MAX_INVENTORY; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& character):
	_name(character.getName()),
	_unequipped(NULL),
	_unequippedSize(0)
{
	const AMateria*	aux;
	unsigned int	i;

	std::cout << "[Copy Constructor] Character: named as " << this->_name
		<< " has been copy created" << std::endl
		<< "----------------------------------------------------" << std::endl;
	for (i = 0; i < MAX_INVENTORY; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
	for (i = 0; i < MAX_INVENTORY; i++)
	{
		aux = character.getInventoryMateria(i);
		if (aux)
			this->_inventory[i] = aux->clone();
		else
			this->_inventory[i] = NULL;
	}
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Character&	Character::operator=(const Character& character)
{
	const AMateria*	aux;
	unsigned int	i;

	if (this == &character)
		return (*this);
	this->_name = character.getName();
	this->_unequipped = NULL;
	this->_unequippedSize = 0;
	for (i = 0; i < MAX_INVENTORY; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
	for (i = 0; i < MAX_INVENTORY; i++)
	{
		aux = character.getInventoryMateria(i);
		if (aux)
			this->_inventory[i] = aux->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << "[Copy Assignment Operator] Character: named as "
		<< this->_name << " has been copy assigned" << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* ******************************* DESTRUCTOR ******************************* */
Character::~Character(void)
{
	unsigned int	i;

	std::cout << "[Destructor] Character: named as " << this->_name
		<< " is being destructed" << std::endl
		<< "----------------------------------------------------" << std::endl;
	for (i = 0; i < MAX_INVENTORY; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
	for (i = 0; i < this->_unequippedSize; i++)
		delete this->_unequipped[i];
	delete[] this->_unequipped;
}

/* **************************** MEMBER FUNCTIONS **************************** */
const std::string&	Character::getName() const
{
	return (this->_name);
}

AMateria*	Character::getInventoryMateria(int idx) const
{
	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << "[Get Inventory Materia] Character: named as "
			<< this->_name << " says 'index out of range'!!" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		return (NULL);
	}
	if (!this->_inventory[idx])
	{
		std::cout << "[Get Inventory Materia] Character: named as "
			<< this->_name << "is returning NULL as their materia at index"
			<< idx << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		return (NULL);
	}
	std::cout << "[Get Inventory Materia] Character: named as "
		<< this->_name << "is returning " << this->_inventory[idx]->getType()
		<< " as their materia at index" << idx << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (this->_inventory[idx]->clone());
}


void	Character::equip(AMateria* m)
{
	unsigned int	i;

	i = 0;
	while (i < MAX_INVENTORY && this->_inventory[i])
		i++;
	if (i == MAX_INVENTORY)
	{
		std::cout << "[Equip] Character: inventory is full!!" << std::endl
		<< "----------------------------------------------------" << std::endl;
		return ;
	}
	this->_inventory[i] = m;
	std::cout << "[Equip] Character: materia " << m->getType() << " equipped"
 		<< std::endl
		<< "----------------------------------------------------" << std::endl;
}

void	Character::unequip(int idx)
{
	unsigned int	i;
	AMateria**		aux;

	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << "[Unequip] Character: index out of range!!" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
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
 		<< std::endl
		<< "----------------------------------------------------" << std::endl;
	this->_inventory[idx] = NULL;
	delete[] aux;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << "[Use] Character: index out of range!!" << std::endl
		<< "----------------------------------------------------" << std::endl;
		return ;
	}
	std::cout << "[Use] Character: using use of "
		<< this->_inventory[idx]->getType() << " in index "
		<< idx << std::endl
		<< "----------------------------------------------------" << std::endl;
	this->_inventory[idx]->use(target);
}
