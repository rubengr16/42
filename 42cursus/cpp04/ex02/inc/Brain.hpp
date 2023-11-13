/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:10:44 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/14 00:18:27 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define MAX_LENGTH 100

class	Brain
{
	private:
		std::string*	_ideas;
		unsigned int	_length;
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		Brain(void);
		Brain(const std::string* ideas, unsigned int length);
		Brain(const Brain& brain);
/* ******************************* DESTRUCTOR ******************************* */
		~Brain(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Brain&				operator=(const Brain& brain);
/* **************************** MEMBER FUNCTIONS **************************** */
		const std::string*	getIdeas(void) const;
		std::string			getIdea(unsigned int i) const;
		void				setIdeas(std::string ideas[], unsigned int length);
		void				addIdea(std::string idea);
		unsigned int		getLength(void) const;
};

#endif
