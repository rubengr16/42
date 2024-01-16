/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:17:53 by rgallego          #+#    #+#             */
/*   Updated: 2024/01/16 18:12:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <List.hpp>

class	PmergeMe
{
	private:
		List						_list;
		std::vector<unsigned int>	_vector;

	public:
/* ****************************** CONSTRUCTORS ****************************** */
		PmergeMe(void);
		PmergeMe(const PmergeMe& rhs);
/* ******************************* DESTRUCTOR ******************************* */
		~PmergeMe(void);
/* ******************** COPY ASSIGNMENT OPERATOR OVERLOAD ******************* */
		PmergeMe&			operator=(const PmergeMe& rhs);
/* **************************** MEMBER FUNCTIONS **************************** */
};

#endif
