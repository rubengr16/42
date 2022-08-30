/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:12:58 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/30 20:04:28 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# include <stdlib.h>

typedef struct s_bnode
{
	int				num;
	struct s_bnode	*left;
	struct s_bnode	*right;
}	t_bnode;

/************************** BASIC BTREE FUNCTIONS *************************** */
t_bnode	*newbnode(int num);
void	btreeadd_left(t_bnode *root, t_bnode *leaf);
t_bnode	*btreeadd_left_num(t_bnode *root, int num);
void	btreeadd_right(t_bnode *root, t_bnode *leaf);
t_bnode	*btreeadd_right_num(t_bnode *root, int num);
void	btreedelall(t_bnode *btree);

#endif
