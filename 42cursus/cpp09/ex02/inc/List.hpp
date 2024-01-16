/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:51:01 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/16 23:53:05 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST
# define LIST

# include <list>
# include <stdexcept>	// std::out_of_range
# include <AContainer.hpp>

class	List: public AContainer<std::list<unsigned int> >
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		List(void);
		List(const List& rhs);
/* ******************************* DESTRUCTOR ******************************* */
		~List(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		List&			operator=(const List& rhs);
/* **************************** MEMBER FUNCTIONS **************************** */
		unsigned int&	at(size_t n);

};

# endif
