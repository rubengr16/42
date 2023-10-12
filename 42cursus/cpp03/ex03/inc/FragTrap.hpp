/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:01:45 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/11 10:44:48 by rgallego         ###   ########.fr       */
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
		friend void		swap(FragTrap& fragTrap1, FragTrap& fragTrap2);
		FragTrap&		operator=(FragTrap fragTrap);
/* **************************** MEMBER FUNCTIONS **************************** */
		void			highFiveGuys(void);
};

#endif
