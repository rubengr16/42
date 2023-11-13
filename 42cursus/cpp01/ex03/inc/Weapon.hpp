/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:00:28 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/13 23:58:56 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string	type;
	
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		void				setType(std::string type);
		const std::string&	getType(void) const;
};

#endif
