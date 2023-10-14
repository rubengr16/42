/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:10:53 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/14 20:52:23 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void):
	_ideas(new std::string[MAX_LENGTH]),
	_length(0)
{
	std::cout << "[Default Constructor] Brain: of size " << this->_length
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Brain::Brain(const std::string *ideas, unsigned int length):
	_ideas(new std::string[MAX_LENGTH])
{
	unsigned int i;

	if (length > MAX_LENGTH)
		length = MAX_LENGTH;
	this->_length = length;
	for (i = 0; i < length; i++)
		this->_ideas[i] = ideas[i];
	std::cout << "[Constructor] Brain: of size " << this->_length
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

Brain::Brain(const Brain& brain):
	_ideas(new std::string[MAX_LENGTH]),
	_length(brain.getLength())
{
	unsigned int i;

	for (i = 0; i < this->_length; i++)
		this->_ideas[i] = brain.getIdea(i);
	std::cout << "[Copy Constructor] Brain: of size " << this->_length
		<< " has been created." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

/* ******************************* DESTRUCTOR ******************************* */
Brain::~Brain(void)
{
	std::cout << "[Destructor] Brain: of size " << this->_length
		<< " is been destructed." << std::endl
		<< "----------------------------------------------------" << std::endl;
	delete [] this->_ideas;
	this->_length = 0;
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
Brain&	Brain::operator=(const Brain& brain)
{
	unsigned int i;
	
	if (this == &brain)
		return (*this);
	for (i = 0; i < this->_length; i++)
		this->_ideas[i] = brain.getIdea(i);
	std::cout << "[Copy Assignment operator] Brain: of size " << this->_length
		<< " has been assigned." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (*this);
}

/* **************************** MEMBER FUNCTIONS **************************** */
const std::string*	Brain::getIdeas(void) const
{
	return (this->_ideas);
}

std::string	Brain::getIdea(unsigned int i) const
{
	if (i > this->_length)
	{
		std::cout << "[Set Ideas] Brain: no idea with the given idex has been "
			<< " found." << std::endl
			<< "----------------------------------------------------" << std::endl;
		return (NULL);
	}
	std::cout << "[Set Ideas] Brain: idea: " << this->_ideas[i]
		<< " is going to be returned." << std::endl
		<< "----------------------------------------------------" << std::endl;
	return (this->_ideas[i]);
}


void	Brain::setIdeas(std::string ideas[], unsigned int length)
{
	unsigned int i;

	if (length > MAX_LENGTH)
		length = MAX_LENGTH;
	for (i = 0; i < length; i++)
		this->_ideas[i] = ideas[i];
	this->_length = length;
	std::cout << "[Set Ideas] Brain: of size " << this->_length
		<< " has been set." << std::endl
		<< "----------------------------------------------------" << std::endl;
}

void	Brain::addIdea(std::string idea)
{
	if (this->_length == MAX_LENGTH)
	{
		std::cout << "[Add Idea] Brain: can accept more ideas, on "
			<< MAX_LENGTH << " has reached its limit." << std::endl
			<< "----------------------------------------------------"
			<< std::endl;
		return ;
	}
	std::cout << "[Add Idea] Brain: has received a new idea: "
		<< idea << ", now it stores " << this->_length << " ideas."
		<< std::endl << "----------------------------------------------------"
		<< std::endl;
	this->_ideas[_length] = idea;
	this->_length++;
}

unsigned int	Brain::getLength(void) const
{
	std::cout << "[Get Lenght] Brain: has " << this->_length
	<< " ideas." << std::endl
	<< "----------------------------------------------------" << std::endl;
	return (this->_length);
}
