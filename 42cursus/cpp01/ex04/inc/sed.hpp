/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 01:19:41 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/01 13:57:12 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

# define FILENAME 1
# define STR1 2
# define STR2 3

std::string	&ft_replace(std::string &str, const std::string oldString,
	const std::string newString);

#endif
