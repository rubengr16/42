/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:01:45 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/10 18:45:14 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& scavTrap);
/* ******************************* DESTRUCTOR ******************************* */
		~ScavTrap(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		ScavTrap&		operator=(ScavTrap scavTrap);
/* **************************** MEMBER FUNCTIONS **************************** */
		void			guardGate(void);
};

#endif
