/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:03 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/01 13:55:46 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int	main(int argc, char **argv)
{
	std::ofstream	fout;
	std::ifstream	fin;
	std::string		line;


	if (argc != 4)
	{
		std::cout << "Sorry, bad number of arguments. "
			<< "Please enter 4 args:" << std::endl
			<< "./winner_sed <filename> <str2> <str2>"
			<< std::endl;
		return (1);
	}
	fout.open(((std::string)argv[FILENAME]).append(".replace").c_str(),
		std::ifstream::out);
	if (!fout.is_open())
	{
		std::cout << "ERROR!! " << argv[FILENAME]
			<< "couldn't be opened."
			<< std::endl;
		return (2);
	}
	fin.open(argv[FILENAME], std::ifstream::in);
	if (!fin.is_open())
	{
		std::cout << "ERROR!! " << argv[FILENAME]
			<< "couldn't be opened."
			<< std::endl;
		fout.close();
		return (2);
	}
	std::getline(fin, line);
	while (!fin.eof())
	{
		line = ft_replace(line, argv[STR1], argv[STR2]);
		fout << line
			<< std::endl;
		std::getline(fin, line);
	}
	fout.close();
	fin.close();
	return (0);
}
