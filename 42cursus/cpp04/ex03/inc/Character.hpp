/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:52:05 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/12 21:42:55 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

# define MAX_INVENTORY 4

class Character: public ICharacter
{
	private:
		std::string		_name;
		AMateria*		_inventory[MAX_INVENTORY];
		AMateria**		_unequipped;
		unsigned int	_unequippedSize;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		Character(void);
		Character(const std::string& name);
		Character(const Character& character);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Character&			operator=(const Character& character);
/* ******************************* DESTRUCTOR ******************************* */
		~Character(void);
/* **************************** MEMBER FUNCTIONS **************************** */
		std::string const&	getName() const;
		AMateria*			getInventoryMateria(int idx) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};


#endif
