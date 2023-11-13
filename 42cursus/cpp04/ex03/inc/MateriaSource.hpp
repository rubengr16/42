/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:09:04 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/13 01:34:50 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define MAX_MATERIA 4

class	MateriaSource: public IMateriaSource
{
	private:
		AMateria*	_materias[MAX_MATERIA];

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		MateriaSource(void);
		MateriaSource(const MateriaSource& materiaSource);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		MateriaSource&	operator=(const MateriaSource& materiaSource);
/* ******************************* DESTRUCTOR ******************************* */
		~MateriaSource(void);
/* **************************** MEMBER FUNCTIONS **************************** */
		AMateria*		getMateria(int idx) const;
		void			learnMateria(AMateria* m);
		AMateria*		createMateria(const std::string& type);
};

#endif
