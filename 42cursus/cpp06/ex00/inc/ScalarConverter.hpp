/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:41:15 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/19 11:23:17 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	private:
/* ****************************** CONSTRUCTORS ****************************** */
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& scalarConverter);
/* ******************************* DESTRUCTOR ******************************* */
		~ScalarConverter(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		ScalarConverter&	operator=(const ScalarConverter& scalarConverter);
	public:
/* **************************** MEMBER FUNCTIONS **************************** */
		static void	conversion(const std::string& input);
		static void	conversion(const std::string& input, char& c);
		static void	conversion(const std::string& input, int& nb);
		static void	conversion(const std::string& input, float& flt);
		static void	conversion(const std::string& input, double& dbl);
};

#endif
