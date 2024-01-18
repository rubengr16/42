/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:03:48 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/18 14:32:38 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
PmergeMe::PmergeMe(void):
	_list(IntegerList()),
	_vector(std::vector<unsigned int>())
{
}

PmergeMe::PmergeMe(char** values, int size)
{
	size_t	i;

	if (size < 0 || size == std::numeric_limits<size_t>::max())
		throw (WrongNumberOfArgumentsException());
	fill(this->_list, values, static_cast<size_t>(size));
	fill(this->_vector, values, static_cast<size_t>(size));
}

PmergeMe::PmergeMe(const PmergeMe& rhs):
	_list(rhs.getList()),
	_vector(rhs.getVector())
{
}

/* ******************************* DESTRUCTOR ******************************* */
PmergeMe::~PmergeMe(void)
{
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
	(void)rhs;
	return (*this);
}

/* *************************** AUXILIARY FUNCTIONS ************************** */
template <typename Container>
void	fill(Container& container, char** values, size_t size)
{
	size_t i;

	for(i = 0; i < size && values[i]; i++)
		container.push_back(this->get_number(values[i]));
}

unsigned int	get_number(char *str)
{
	std::stringstream	stream (str);
	long long int		value;

	stream >> value;
	if (!stream.eof() || value < 0
		|| (value != -std::numeric_limits<unsigned int>::infinity()
		&& value != std::numeric_limits<unsigned int>::infinity()
		&& (value < -std::numeric_limits<unsigned int>::max()
		|| std::numeric_limits<unsigned int>::max() < value 
		|| (errno == ERANGE && value == -HUGE_VALL))))
		throw (PmergeMe::WrongNumberException());
	return (static_cast<unsigned int>(value));
}

template <typename T>
static void	merge(T& integerList, size_t start, size_t middle,
	size_t end)
{
	IntegerList				aux;
	IntegerList::iterator	it;
	size_t					i = start;
	size_t					j = middle + 1;

	while (i <= middle && j <= end)
	{
		if (integerList.get(i) < integerList.get(j))
		{
			aux.push_back(integerList.get(i));
			i++;
		}
		else
		{
			aux.push_back(integerList.get(j));
			j++;
		}
	}
	for (; i <= middle; i++)
		aux.push_back(integerList.get(i));
	for (; j <= end; j++)
		aux.push_back(integerList.get(j));
	for (it = aux.begin(), i = start; i <= end; it++, i++)
		integerList.get(i) = *it;
}

template <typename T>
static void	mergesort(T& integerList, size_t start, size_t end)
{
	size_t	middle;

	if (start >= end)
		return ;
	middle = (start + end) / 2;
	mergesortAux(integerList, start, middle);
	mergesortAux(integerList, middle + 1, end);
	merge(integerList, start, middle, end);
}

/* **************************** MEMBER FUNCTIONS **************************** */
const IntegerList&	PmergeMe::getList(void) const
{
	return (this->_list);
}

const std::vector<unsigned int>&	PmergeMe::getVector(void) const
{
	return (this->_vector);
}

void	PmergeMe::mergesortList(void)
{
	mergesort(this->_vector, 0, this->_vector.size() - 1);
}

void	PmergeMe::mergesortVector(void)
{
	mergesort(this->_vector, 0, this->_vector.size() - 1);
}

/* ******************************* EXCEPTIONS ******************************* */
const char*	PmergeMe::WrongNumberException::what(void) const throw()
{
	return ("Error: the given number is not a positive integer.");
}

const char*	PmergeMe::WrongNumberOfArgumentsException::what(void) const throw()
{
	return ("Error: wrong number of arguments was introduced.");
}
