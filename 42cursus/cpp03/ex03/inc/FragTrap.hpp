/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:01:45 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/10 21:31:16 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& fragTrap);
/* ******************************* DESTRUCTOR ******************************* */
		~FragTrap(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		FragTrap&		operator=(FragTrap fragTrap);
/* **************************** MEMBER FUNCTIONS **************************** */
		void			highFiveGuys(void);
};

#endif
