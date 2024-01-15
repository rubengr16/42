/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:16:15 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/15 22:47:43 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ****************************** CONSTRUCTORS ****************************** */
RPN::RPN(void)
{
}

RPN::RPN(const RPN& rhs)
{
	(void)rhs;
}

/* ******************************* DESTRUCTOR ******************************* */
RPN::~RPN(void)
{
}

/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
RPN&	RPN::operator=(const RPN& rhs)
{
	(void)rhs;
	return (*this);
}
/* **************************** MEMBER FUNCTIONS **************************** */
static void	checkInputChars(std::string& str)
{
	std::string::iterator	it = str.begin();
	std::string				allowedChars(ALLOWED_CHARS);

	while (it != str.end() && allowedChars.find(*it) != std::string::npos)
		it++;
	if (it != str.end())
		throw (RPN::InvalidCharactersException());
}

static double	addition(double lhs, double rhs)
{
	return (lhs + rhs);
}

static double	subtraction(double lhs, double rhs)
{
	return (lhs - rhs);
}

static double	multiplication(double lhs, double rhs)
{
	return (lhs * rhs);
}

static double	division(double lhs, double rhs)
{
	// What happens with 0 / 0, N / 0??
	return (lhs / rhs);
}

static void	operate(std::stack<float>& stackRPN, size_t pos)
{
	double	(*operations[4])(double, double) = {addition, subtraction,
		multiplication, division};
	double	lhs;
	double	rhs;
	double	result;

	if (stackRPN.size() < 2)
		throw (RPN::NotEnoughNumbersException());
	rhs = stackRPN.top();
	stackRPN.pop();
	lhs = stackRPN.top();
	stackRPN.pop();
	result = operations[pos](lhs, rhs);
	if (result != -std::numeric_limits<float>::infinity()
		&& result != std::numeric_limits<float>::infinity()
		&& (result < -std::numeric_limits<float>::max()
		|| std::numeric_limits<float>::max() < result))
		throw (RPN::OutOfRangeResultException());
	stackRPN.push(static_cast<float>(result));
}

static void getNumber(std::stack<float>& stackRPN, long long int number)
{
	if (number < 0 || number > 10)
		throw (RPN::OutOfRangeOperatorException());
	stackRPN.push(static_cast<float>(number));
}

static void	manageElem(std::stack<float>& stackRPN, std::string elem)
{
	size_t	pos;
	std::stringstream stream(elem);
	long long int number;

	if (elem.length() != 1)
		throw (RPN::InvalidCharactersException());
	pos = std::string(OPERANDS).find(elem);
	if (pos != std::string::npos)
		operate(stackRPN, pos);
	else
	{
		stream >> number;
		getNumber(stackRPN, number);
	}
}

float	RPN::calculate(std::string str)
{
	std::stack<float>	stackRPN;
	std::stringstream	stream(str);
	std::string			elem;

	checkInputChars(str);
	while (!stream.eof())
	{
		stream >> elem;
		manageElem(stackRPN, elem);
	}
	if (stackRPN.size() != 1)
		throw (NotEnoughOperandsException());
	return (stackRPN.top());
}

/* ******************************* EXCEPTIONS ******************************* */
const char*	RPN::InvalidCharactersException::what(void) const throw()
{
	return ("Error: the given operation contains invalid characters.");
}

const char*	RPN::NotEnoughNumbersException::what(void) const throw()
{
	return ("Error: not enough numbers in the operation were provided.");
}

const char*	RPN::NotEnoughOperandsException::what(void) const throw()
{
	return ("Error: not enough operands in the operation were provided.");
}

const char*	RPN::OutOfRangeResultException::what(void) const throw()
{
	return ("Error: could not represent the result number.");
}

const char*	RPN::OutOfRangeOperatorException::what(void) const throw()
{
	return ("Error: operators must be between 0 and 9 (inclusive).");
}

