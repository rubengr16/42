/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:16:41 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/13 15:04:21 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

static float	_area(const Point p1, const Point p2, const Point p3)
{
	float	area = 
		((p1.getY().toFloat() * (p2.getX().toFloat() - p3.getX().toFloat()))
		+ (p2.getY().toFloat() * (p3.getX().toFloat() - p1.getX().toFloat()))
		+ (p3.getY().toFloat() * (p1.getX().toFloat() - p2.getX().toFloat())))
		/ 2;
	if (area < 0)
		return (area * -1);
	return (area);
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	float	triangleArea = _area(a, b, c);
	float	areaABPoint = _area(a, b, point);
	float	areaACPoint = _area(a, c, point);
	float	areaBCPoint = _area(b, c, point);

	if (!areaABPoint || !areaABPoint || !areaBCPoint
		|| triangleArea != (areaABPoint + areaACPoint + areaBCPoint))
		return (false);
	return (true);
}
