/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:16:41 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/08 22:32:25 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.h"

static Fixed&	_area(Point const p1, Point const p2, Point const p3)
{
	return (((p1.getX() * (p2.getY() - p3.getY()))
		+ (p2.getX() * (p3.getY() - p1.getY()))
		+ (p3.getX() * (p1.getY() - p2.getY()))) / 2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed&	triangleArea = _area(a, b, c);
	Fixed&	areaABPoint = _area(a, b, point);
	Fixed&	areaACPoint = _area(a, c, point);
	Fixed&	areaBCPoint = _area(b, c, point);

	if (!areaABPoint || !areaABPoint || !areaABPoint
		|| triangleArea != (areaABPoint + areaACPoint + areaABPoint))
		return (false);
	return (true);
}
