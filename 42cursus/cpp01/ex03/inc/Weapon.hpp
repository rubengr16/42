/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:00:28 by rgallego          #+#    #+#             */
/*   Updated: 2023/09/29 18:08:40 by rgallego         ###   ########.fr       */
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
		Weapon(std::string &weapon);
		const std::string	&getType(void);
		void				setType(std::string &weapon);
}

#endif
