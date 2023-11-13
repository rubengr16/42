/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:19:31 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/13 01:36:56 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class	ICharacter;

class	AMateria
{
	protected:
		std::string	_type;
/* ****************************** CONSTRUCTORS ****************************** */
		AMateria(void);
		AMateria(const AMateria& materia);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		AMateria&			operator=(const AMateria& materia);

	public:
		AMateria(const std::string& type);
/* ******************************* DESTRUCTOR ******************************* */
		virtual ~AMateria(void);
/* **************************** MEMBER FUNCTIONS **************************** */
		const std::string&	getType(void) const;
		void				setType(const std::string& type);
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target) = 0;
};

#endif
