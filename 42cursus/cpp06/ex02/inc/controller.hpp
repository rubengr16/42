/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:59:35 by rgallego          #+#    #+#             */
/*   Updated: 2023/11/21 18:07:31 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_HPP
# define CONTROLLER_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
