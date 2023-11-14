/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:21:08 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/14 22:34:39 by rgallego         ###   ########.fr       */
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
		Fixed&				operator=(const Fixed& fixed);
/* ********************** COMPARISON OPERATORS OVERLOAD ********************* */
		bool				operator<(const Fixed& fixed) const;
		bool				operator>(const Fixed& fixed) const;
		bool				operator<=(const Fixed& fixed) const;
		bool				operator>=(const Fixed& fixed) const;
		bool				operator==(const Fixed& fixed) const;
		bool				operator!=(const Fixed& fixed) const;
/* ********************** LOGICAL NOT OPERATOR OVERLOAD ********************* */
		bool				operator!(void);
/* ********************* ARITHMETICS OPERATORS OVERLOAD ********************* */
		Fixed				operator+(const Fixed& fixed);
		Fixed				operator-(const Fixed& fixed);
		Fixed				operator*(const Fixed& fixed);
		Fixed				operator/(const Fixed& fixed);
/* ******************** {IN/DE}CREMENT OPERATORS OVERLOAD ******************* */
		Fixed				operator++(int);
		Fixed&				operator++(void);
		Fixed				operator--(int);
		Fixed&				operator--(void);
/* **************************** MEMBER FUNCTIONS **************************** */
		int					getRawBits(void) const;
		void				setRawBits(const int raw);
		float				toFloat(void) const;
		int					toInt(void) const;
/* *********************** OVERLOADED MEMBER FUNCTIONS ********************** */
		static Fixed&		min(Fixed& fixed1, Fixed& fixed2);
		const static Fixed&	min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed&		max(Fixed& fixed1, Fixed& fixed2);
		const static Fixed&	max(const Fixed& fixed1, const Fixed& fixed2);
};

/* ************************* INPUT OPERATOR OVERLOAD ************************ */
std::ostream&				operator<<(std::ostream& os, const Fixed& fixed);

#endif
