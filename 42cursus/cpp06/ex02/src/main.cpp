/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:25:21 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/21 18:13:58 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "controller.hpp"

int	main(void)
{
	Base*	base = generate();

	identify(base);
	identify(*base);
	delete base;
	return (0);
}
