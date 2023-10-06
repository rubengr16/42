/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:21:08 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/06 17:44:16 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					nb;
		const static int	point = 8;

	public:
		Fixed(void);
		Fixed(Fixed &fixed);
		~Fixed(void);
		Fixed& operator=(const Fixed& fixed);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
