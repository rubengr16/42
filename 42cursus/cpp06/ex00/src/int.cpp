/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:01:15 by rgallego          #+#    #+#             */
/*   Updated: 2024/07/31 16:34:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* *********************************** INT ********************************** */
int	ScalarConverter::getInt(std::string& input)
{
	char	*endptr = NULL;
	double dbl = strtod(input.c_str(), &endptr);

	if ((errno == ERANGE && dbl == -HUGE_VAL)
		|| dbl < std::numeric_limits<int>::min())
	{
		input = FT_UNDERFLOW;
		return (std::numeric_limits<int>::min());
	}
	else if ((errno == ERANGE && dbl == HUGE_VAL)
		|| dbl > std::numeric_limits<int>::max())
	{
		input = FT_OVERFLOW;
		return (std::numeric_limits<int>::max());
	}
	return (static_cast<int>(dbl));
}

void	ScalarConverter::toInt(const std::string& input, int nb)
{
	std::cout << "int: ";
	if (!input.compare(FT_UNDERFLOW) || !input.compare(FT_OVERFLOW))
		std::cout << input << std::endl;
	else
		std::cout << nb << std::endl;
}

void	ScalarConverter::toInt(const std::string& input, float flt)
{
	std::cout << "int: ";
	if(!input.compare(NANF42) || !input.compare(INFF) || !input.compare(NINFF))
		std::cout << "impossible" << std::endl;
	else if (flt < std::numeric_limits<int>::min())
		std::cout << FT_UNDERFLOW << std::endl;
	else if (flt > std::numeric_limits<int>::max())
		std::cout << FT_OVERFLOW << std::endl;
	else
		std::cout << static_cast<int>(flt) << std::endl;
}

void	ScalarConverter::toInt(const std::string& input, double dbl)
{
	std::cout << "int: ";
	if (!input.compare(NAN42) || !input.compare(INF)
		|| !input.compare(NINF) || !input.compare(NANF42)
		|| !input.compare(INFF) || !input.compare(NINFF))
		std::cout << "impossible" << std::endl;
	else if (dbl < std::numeric_limits<int>::min())
		std::cout << FT_UNDERFLOW << std::endl;
	else if (dbl > std::numeric_limits<int>::max())
		std::cout << FT_OVERFLOW << std::endl;
	else
		std::cout << static_cast<int>(dbl) << std::endl;
}
