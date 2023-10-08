/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 00:36:35 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/08 23:24:11 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		Point(void);
		Point(const float x, const float y);
		Point(const Point& point);
/* ******************************* DESTRUCTOR ******************************* */
		~Point(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Point&			operator=(const Point& point);
/* **************************** MEMBER FUNCTIONS **************************** */
		const Fixed&	getX(void) const;
		void			setX(Fixed& x);
		const Fixed&	getY(void) const;
		void			setY(Fixed& y);
};

#endif
