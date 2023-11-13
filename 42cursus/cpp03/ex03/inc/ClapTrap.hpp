/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:24:33 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/11 20:38:43 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPts;
		unsigned int	_energyPts;
		unsigned int	_damagePts;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& clapTrap);
/* ******************************* DESTRUCTOR ******************************* */
		~ClapTrap(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		ClapTrap&		operator=(ClapTrap clapTrap);
/* **************************** MEMBER FUNCTIONS **************************** */
		std::string		getName(void) const;
		void			setName(std::string name);
		unsigned int	getHitPts(void) const;
		void			setHitPts(unsigned int	hitPts);
		unsigned int	getEnergyPts(void) const;
		void			setEnergyPts(unsigned int	energyPts);
		unsigned int	getDamagePts(void) const;
		void			setDamagePts(unsigned int	damagePts);
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif
