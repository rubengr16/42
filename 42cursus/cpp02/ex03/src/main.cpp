/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:21:10 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/09 00:13:41 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "bsp.hpp"

static void	printBSP(bool bspResult, Point& p)
{
	if (bspResult)
		std::cout << "(" << p.getX() << ", " << p.getY()
			<< ") is inside the Triangle" << std::endl;
	else
		std::cout << "(" << p.getX() << ", " << p.getY()
			<< ") is outside the Triangle" << std::endl;
}

int	main(void)
{
	Point	p1(1.0f, 0.0f);
	Point	p2(3.0f, 4.0f);
	Point	p3(7.0f, 2.0f);
	Point	pEdge(2.0f, 2.0f);
	Point	pInside(3.0f, 2.0f);

	std::cout << "### POINT EDGE ###" << std::endl;
	printBSP(bsp(p1, p2, p3, pEdge), pEdge);
	std::cout << "### POINT VERTEX ###" << std::endl;
	printBSP(bsp(p1, p2, p3, p3), p3);
	std::cout << "### POINT INSIDE ###" << std::endl;
	printBSP(bsp(p1, p2, p3, pInside), pInside);
	return (0);
}
