/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:03:48 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/18 19:39:26 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* *************************** AUXILIARY FUNCTIONS ************************** */
static double	get_time_diff(struct timespec start, struct timespec end)
{
	return ((end.tv_sec - start.tv_sec) * 1e3
		+ (end.tv_nsec - start.tv_nsec) * 1e-6);
}

static unsigned int	get_number(char *str)
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

template <typename Container>
static void	fill_container(Container& container, char** values, size_t size)
{
	size_t i;

	for(i = 0; i < size && values[i]; i++)
		container.push_back(get_number(values[i]));
}


template <typename Container>
static void	merge(Container& container, size_t start, size_t middle,
	size_t end)
{
	Container						aux;
	typename Container::iterator	it;
	size_t							i = start;
	size_t							j = middle + 1;

	while (i <= middle && j <= end)
	{
		if (container.at(i) < container.at(j))
		{
			aux.push_back(container.at(i));
			i++;
		}
		else
		{
			aux.push_back(container.at(j));
			j++;
		}
	}
	for (; i <= middle; i++)
		aux.push_back(container.at(i));
	for (; j <= end; j++)
		aux.push_back(container.at(j));
	for (it = aux.begin(), i = start; i <= end; it++, i++)
		container.at(i) = *it;
}

template <typename Container>
static void	mergesort(Container& container, size_t start, size_t end)
{
	size_t	middle;

	if (start >= end)
		return ;
	middle = (start + end) / 2;
	mergesort(container, start, middle);
	mergesort(container, middle + 1, end);
	merge(container, start, middle, end);
}
template <typename Container>
static void	print_numbers(Container& container, std::string str)
{
	typename Container::iterator	it;

	std::cout << str;
	for (it = container.begin(); it != container.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

static void	print_time(size_t size, double time, std::string container)
{
	std:: cout << "Time to process a range of " << size
		<< " elements with std::" << container << " : "
		<< std::setprecision(PRECISION) << std::fixed << time << " ms"
		<< std::endl;
}

/* ****************************** CONSTRUCTORS ****************************** */
PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(char** values, int size)
{
	IntegerList::iterator	it;
	struct timespec			start;
	struct timespec			end;

	if (size < 0)
		throw (WrongNumberOfArgumentsException());
	clock_gettime(CLOCK_MONOTONIC, &start);
	fill_container(this->_list, values, static_cast<size_t>(size));
	clock_gettime(CLOCK_MONOTONIC, &end);
	this->_listTime = get_time_diff(start, end);
	clock_gettime(CLOCK_MONOTONIC, &start);
	fill_container(this->_vector, values, static_cast<size_t>(size));
	clock_gettime(CLOCK_MONOTONIC, &end);
	this->_vectorTime = get_time_diff(start, end);
	print_numbers(this->_list, BEFORE);
	clock_gettime(CLOCK_MONOTONIC, &start);
	mergesortList(this->_list);
	clock_gettime(CLOCK_MONOTONIC, &end);
	this->_listTime += get_time_diff(start, end);
	clock_gettime(CLOCK_MONOTONIC, &start);
	mergesortList(this->_list);
	clock_gettime(CLOCK_MONOTONIC, &end);
	this->_vectorTime += get_time_diff(start, end);
	print_numbers(this->_list, AFTER);
	print_time(size, this->_listTime, "list");
	print_time(size, this->_vectorTime, "vector");
}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	(void)rhs;
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

/* **************************** MEMBER FUNCTIONS **************************** */
const IntegerList&	PmergeMe::getList(void) const
{
	return (this->_list);
}

const std::vector<unsigned int>&	PmergeMe::getVector(void) const
{
	return (this->_vector);
}

void	PmergeMe::mergesortList(IntegerList& list)
{
	mergesort(list, 0, list.size() - 1);
}

void	PmergeMe::mergesortVector(std::vector<unsigned int> vector)
{
	mergesort(vector, 0, vector.size() - 1);
}

/* ******************************* EXCEPTIONS ******************************* */
const char*	PmergeMe::WrongNumberException::what(void) const throw()
{
	return ("Error: the given number is not a valid integer.");
}

const char*	PmergeMe::WrongNumberOfArgumentsException::what(void) const throw()
{
	return ("Error: wrong number of arguments was introduced.");
}
