/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:21:08 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/13 15:00:54 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_nb;
		const static int	_point = 8;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		Fixed(void);
		Fixed(const Fixed &fixedObj);
/* ******************************* DESTRUCTOR ******************************* */
		~Fixed(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Fixed& operator=(const Fixed& fixedObj);
/* **************************** MEMBER FUNCTIONS **************************** */
		int getRawBits(void) const;
		void setRawBits(const int raw);
};

#endif
