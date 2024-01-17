/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:03:48 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/17 21:43:58 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
PmergeMe::PmergeMe(void)
{
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
/* ***************************** LIST MERGESORT ***************************** */
static void	merge(IntegerList& integerList, size_t start, size_t middle,
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

static void	mergesortAux(IntegerList& integerList, size_t start, size_t end)
{
	size_t	middle;

	if (start >= end)
		return ;
	middle = (start + end) / 2;
	mergesortAux(integerList, start, middle);
	mergesortAux(integerList, middle + 1, end);
	merge(integerList, start, middle, end);
}

void	PmergeMe::mergesort(IntegerList& integerList)
{
	mergesortAux(integerList, 0, integerList.size() - 1);
}

/* **************************** VECTOR MERGESORT **************************** */
static void	merge(IntegerVector& integerVector, size_t start, size_t middle,
	size_t end)
{
	IntegerVector			aux;
	IntegerVector::iterator	it;
	size_t					i = start;
	size_t					j = middle + 1;

	while (i <= middle && j <= end)
	{
		if (integerVector.get(i) < integerVector.get(j))
		{
			aux.push_back(integerVector.get(i));
			i++;
		}
		else
		{
			aux.push_back(integerVector.get(j));
			j++;
		}
	}
	for (; i <= middle; i++)
		aux.push_back(integerVector.get(i));
	for (; j <= end; j++)
		aux.push_back(integerVector.get(j));
	for (it = aux.begin(), i = start; i <= end; it++, i++)
		integerVector.get(i) = *it;
}

static void	mergesortAux(IntegerVector& integerVector, size_t start, size_t end)
{
	size_t	middle;

	if (start >= end)
		return ;
	middle = (start + end) / 2;
	mergesortAux(integerVector, start, middle);
	mergesortAux(integerVector, middle + 1, end);
	merge(integerVector, start, middle, end);
}

void	PmergeMe::mergesort(IntegerVector& integerVector)
{
	mergesortAux(integerVector, 0, integerVector.size() - 1);
}
