/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:21:08 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/08 00:22:33 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_nb;
		const static int	_point = 8;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		Fixed(void);
		Fixed(const int nb);
		Fixed(const float nb);
		Fixed(const Fixed& fixed);
/* ******************************* DESTRUCTOR ******************************* */
		~Fixed(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Fixed&	operator=(const Fixed& fixed);
/* **************************** MEMBER FUNCTIONS **************************** */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

/* ************************ OUTPUT OPERATOR OVERLOAD ************************ */
std::ostream&	operator<<(std::ostream& os, const Fixed& fixedObj);

#endif