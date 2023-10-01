/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:19:38 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/01 14:55:47 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

std::string	&ftReplace(std::string &str, const std::string oldString,
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

bool	openFiles(std::ifstream &fin, std::ofstream &fout,
	const char *in_filename, const char *out_filename)
{
	fin.open(in_filename, std::ifstream::in);
	if (!fin.is_open())
	{
		std::cout << "ERROR!! " << in_filename
			<< " couldn't be opened."
			<< std::endl;
		return (false);
	}
	fout.open(out_filename, std::ifstream::out);
	if (!fout.is_open())
	{
		std::cout << "ERROR!! " << out_filename
			<< " couldn't be opened."
			<< std::endl;
		fin.close();
		return (false);
	}
	return (true);
}
