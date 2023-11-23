/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:30 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/23 20:25:09 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include "test.hpp"

int	main(void)
{
	std::vector<int> vector;
	std::deque<int> deque;
	std::list<int> list;

	std::cout << "4 containers created (vector, deque, forward list and list)"
		<< std::endl;
	test(vector, "vector");
	test(deque, "deque");
	test(list, "list");
	return (0);
}
