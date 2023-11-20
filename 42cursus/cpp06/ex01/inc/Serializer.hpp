/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:19:24 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/20 23:38:50 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp" 


class Serializer
{
	private:
/* ****************************** CONSTRUCTORS ****************************** */
		Serializer(void);
		Serializer(const Serializer& serializer);
/* ******************************* DESTRUCTOR ******************************* */
		~Serializer(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		Serializer&	operator=(const Serializer& serializer);
	public:
/* **************************** MEMBER FUNCTIONS **************************** */
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
