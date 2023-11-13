/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:01:45 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/11 20:40:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
	private:
		unsigned int	_hitPts;
		unsigned int	_energyPts;
		unsigned int	_damagePts;

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
		unsigned int	getHitPts(void) const;
		void			setHitPts(unsigned int	hitPts);
		unsigned int	getEnergyPts(void) const;
		void			setEnergyPts(unsigned int	energyPts);
		unsigned int	getDamagePts(void) const;
		void			setDamagePts(unsigned int	damagePts);
		void			attack(const std::string& target);
		void			guardGate(void);
};

#endif
