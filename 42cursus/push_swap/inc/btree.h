/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:12:58 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/30 16:45:00 by rgallego         ###   ########.fr       */
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

typedef struct s_btree
{
	int		n_elem;
	t_bnode	*root;
}	t_btree;

/************************** BASIC BTREE FUNCTIONS *************************** */
t_btree	*btreeinit(void);
t_bnode	*newbnode(int num);
void	btreeadd_left(t_btree *btree, t_bnode *root, t_bnode *leaf);
void	btreeadd_left_num(t_btree *btree, t_bnode *root, int num);
void	btreeadd_right(t_btree *btree, t_bnode *root, t_bnode *leaf);
void	btreeadd_right_num(t_btree *btree, t_bnode *root, int num);
void	btreedelall(t_btree *btree);

#endif
