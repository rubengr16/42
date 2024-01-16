/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:51:01 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/16 11:15:00 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST
# define LIST

# include <list>

class List: public std::list<unsigned int>
{
	public:
/* ****************************** CONSTRUCTORS ****************************** */
		List(void);
		List(void);
/* ******************************* DESTRUCTOR ******************************* */
		~List(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		List&	operator=(const List& rhs);

		List&	operator[](unsigned int i) const;

};

# endif
