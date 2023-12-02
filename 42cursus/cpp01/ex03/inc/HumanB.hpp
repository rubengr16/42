/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:01:06 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/02 18:25:13 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;
	
	public:
		HumanB(std::string name);
		~HumanB(void);
		void			setWeapon(Weapon& weapon);
		void			attack(void) const;
};

#endif
