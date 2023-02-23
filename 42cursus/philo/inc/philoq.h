/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:41:51 by rgallego          #+#    #+#             */
/*   Updated: 2023/02/23 17:30:32 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOQ_H
# define PHILOQ_H

typedef struct s_philon
{
	unsigned int	id;
	struct s_philon	*next;
	struct s_philon	*prvs;
}	t_philon;

typedef struct s_philoq
{
	t_philon	*head;
}	t_philoq;



#endif
