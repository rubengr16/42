/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:19:41 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/01 14:55:01 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

# define FILENAME 1
# define OLDSTR 2
# define NEWSTR 3

# define BAD_ARGS 1

std::string	&ftReplace(std::string &str, const std::string oldString,
	const std::string newString);
bool		openFiles(std::ifstream &fin, std::ofstream &fout,
	const char *in_filename, const char *out_filename);

#endif
