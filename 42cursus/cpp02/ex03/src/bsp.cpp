/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:16:41 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/09 00:14:49 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

static float	_area(Point const p1, Point const p2, Point const p3)
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

bool	bsp(Point const a, Point const b, Point const c, Point const point)
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
