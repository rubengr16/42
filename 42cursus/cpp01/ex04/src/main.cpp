/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:59:03 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/01 15:01:54 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int	main(int argc, char **argv)
{
	std::ifstream	fin;
	std::ofstream	fout;
	std::string		line;


	if (argc != 4)
	{
		std::cout << "Sorry, bad number of arguments. "
			<< "Please enter 4 args:" << std::endl
			<< "./winner_sed <filename> <str2> <str2>"
			<< std::endl;
		return (BAD_ARGS);
	}
	if (!openFiles(fin, fout, argv[FILENAME],
		((std::string)argv[FILENAME]).append(".replace").c_str()))
		return (errno);
	std::getline(fin, line);
	while (!fin.eof())
	{
		line = ftReplace(line, argv[OLDSTR], argv[NEWSTR]);
		fout << line
			<< std::endl;
		std::getline(fin, line);
	}
	fout.close();
	fin.close();
	return (0);
}
