/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:01:45 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/02 15:25:58 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
	private:
		unsigned int	_hitPts;
		unsigned int	_energyPts;
		unsigned int	_damagePts;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& fragTrap);
/* ******************************* DESTRUCTOR ******************************* */
		~FragTrap(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		FragTrap&		operator=(const FragTrap& fragTrap);
/* **************************** MEMBER FUNCTIONS **************************** */
		unsigned int	getHitPts(void) const;
		void			setHitPts(unsigned int	hitPts);
		unsigned int	getEnergyPts(void) const;
		void			setEnergyPts(unsigned int	energyPts);
		unsigned int	getDamagePts(void) const;
		void			setDamagePts(unsigned int	damagePts);
		void			highFiveGuys(void);
};

#endif
