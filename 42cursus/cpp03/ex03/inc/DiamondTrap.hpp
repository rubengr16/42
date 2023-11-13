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
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
		using ScavTrap::getHitPts;
		using ScavTrap::setHitPts;
		using ScavTrap::getEnergyPts;
		using ScavTrap::setEnergyPts;
		using ScavTrap::getDamagePts;
		using ScavTrap::setDamagePts;
		using FragTrap::getHitPts;
		using FragTrap::setHitPts;
		using FragTrap::getEnergyPts;
		using FragTrap::setEnergyPts;
		using FragTrap::getDamagePts;
		using FragTrap::setDamagePts;

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
		std::string			getName(void) const;
		std::string			getClapName(void) const;
		void				setName(std::string name);
		unsigned int		getHitPts(void) const;
		void				setHitPts(unsigned int	hitPts);
		unsigned int		getEnergyPts(void) const;
		void				setEnergyPts(unsigned int	energyPts);
		unsigned int		getDamagePts(void) const;
		void				setDamagePts(unsigned int	damagePts);
		void				WhoAmI(void);
};

#endif
