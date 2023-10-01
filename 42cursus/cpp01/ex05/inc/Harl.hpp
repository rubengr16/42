/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:07:09 by rgallego          #+#    #+#             */
/*   Updated: 2023/10/01 17:23:19 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HALR_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};


#endif
