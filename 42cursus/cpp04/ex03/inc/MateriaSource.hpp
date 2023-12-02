/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:09:04 by rgallego          #+#    #+#             */
/*   Updated: 2023/12/02 14:00:26 by rgallego         ###   ########.fr       */
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
/* ******************************* DESTRUCTOR ******************************* */
		~MateriaSource(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		MateriaSource&	operator=(const MateriaSource& materiaSource);
/* **************************** MEMBER FUNCTIONS **************************** */
		AMateria*		getMateria(int idx) const;
		void			learnMateria(AMateria* m);
		AMateria*		createMateria(const std::string& type);
};

#endif
