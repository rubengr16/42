/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:19:38 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/01 13:57:07 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

std::string	&ft_replace(std::string &str, const std::string oldString,
	const std::string newString)
{
	std::size_t		pos;
	pos = str.find(oldString);
	while (pos != std::string::npos)
	{
		str = str.substr(0, pos)
			.append(newString)
			.append(&str[pos + oldString.length()]);
		pos = str.find(oldString);
	}
	return str;
}
