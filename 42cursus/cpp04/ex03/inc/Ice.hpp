/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:02:42 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/15 00:46:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class	Ice: public AMateria
{

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		Ice(void);
		Ice(const std::string& type);
		Ice(const Ice& ice);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Ice&				operator=(const Ice& ice);
/* ******************************* DESTRUCTOR ******************************* */
		~Ice(void);
/* **************************** MEMBER FUNCTIONS **************************** */
		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif
