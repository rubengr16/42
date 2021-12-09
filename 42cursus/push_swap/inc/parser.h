/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com>       +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:53:55 by rgallego          #+#    #+#             */
/*   Updated: 2021/12/09 14:37:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "libft.h"
#include "queue.h"

int		ft_setisdigit(char **set);
void	ft_argtostack(t_queue *queue, char **argv);

#endif
