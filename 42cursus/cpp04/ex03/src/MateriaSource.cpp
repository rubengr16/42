/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:35:36 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/02 14:00:44 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
MateriaSource::MateriaSource(void)
{
	unsigned int	i;

	std::cout << "[Default Constructor] Materia Source: has been created"
		<< std::endl
		<< "----------------------------------------------------" << std::endl;
	for (i = 0; i < MAX_MATERIA; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
	unsigned int	i;

	std::cout << "[Copy Constructor] Materia Source: has been copy created"
		<< std::endl
		<< "----------------------------------------------------" << std::endl;
	for (i = 0; i < MAX_MATERIA; i++)
		this->_materias[i] = materiaSource.getMateria(i);
}

/* ******************************* DESTRUCTOR ******************************* */
MateriaSource::~MateriaSource(void)
{
	std::cout << "[Destructor] Materia Source: is being destructed"
		<< std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
MateriaSource&	MateriaSource::operator=(const MateriaSource& materiaSource)
{
	unsigned int	i;

	if (this == &materiaSource)
		return (*this);
	for (i = 0; i < MAX_MATERIA; i++)
		this->_materias[i] = materiaSource.getMateria(i);
	std::cout << "[Copy Assignment Operator] Materia Source: has been copy "
		<< "assigned."
		<< std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
AMateria*	MateriaSource::getMateria(int idx) const
{
	if (idx < 0 || idx >= MAX_MATERIA)
	{
		std::cout << "[Get Materia] Materia Source: index out of range!!"
 			<< std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		return (NULL);
	}
	if (!this->_materias[idx])
	{
		std::cout << "[Get Materia] Materia Source: is returning NULL as its "
			<< " materia at index"	<< idx  << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		return (NULL);
	}
	else
	{
		std::cout << "[Get Materia] Materia Source: is returning "
			<< this->_materias[idx]->getType() << " as its  materia at index"
			<< idx  << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
	}
	return (this->_materias[idx]);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	unsigned int	i;

	i = 0;
	while (i < MAX_MATERIA && this->_materias[i])
		i++;
	if (i == MAX_MATERIA)
	{
		std::cout << "[Learn Materia] Materia Source: materias are full!!"
			<< std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		return ;
	}
	if (!m)
	{
		std::cout << "[Learn Materia] Materia Source: setting materia at"
			<< " index " << i << " as NULL" << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
	}
	else
	{
		std::cout << "[Learn Materia] Materia Source: setting materia at"
			<< " index " << i << " as " << m->getType() << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
	}
	this->_materias[i] = m;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	unsigned int	i;

	i = 0;
	while (i < MAX_MATERIA && this->_materias[i]
		&& this->_materias[i]->getType().compare(type))
		i++;
	if (i == MAX_MATERIA || !this->_materias[i])
	{
		std::cout << "[Create Materia] Materia Source: no materia with "
			<< type << " as type found!!" << std::endl
		<< "----------------------------------------------------" << std::endl;
		return (0);
	}
	std::cout << "[Create Materia] Materia Source: materia with "<< type
		<< " as type found" << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (this->_materias[i]->clone());
}
