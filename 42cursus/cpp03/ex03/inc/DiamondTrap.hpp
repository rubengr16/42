/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap copy.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:01:45 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/10 19:40:25 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ClapTrap
{
	private:
		std::string _name;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& diamondTrap);
/* ******************************* DESTRUCTOR ******************************* */
		~DiamondTrap(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		DiamondTrap&		operator=(DiamondTrap diamondTrap);
/* **************************** MEMBER FUNCTIONS **************************** */
		void			guardGate(void);
};

#endif
