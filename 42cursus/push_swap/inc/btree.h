/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:12:58 by rgallego          #+#    #+#             */
/*   Updated: 2022/08/31 16:08:14 by rgallego         ###   ########.fr       */
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
	struct s_bnode	*stack;
}	t_bnode;

typedef struct s_btree
{
	t_bnode	*root;
}	t_btree;

/************************** BASIC BTREE FUNCTIONS *************************** */
t_bnode	*newbnode(int num);
t_btree	*btreeinit(void);
t_btree	*btreeinitnode(t_bnode	*bnode);
t_btree	*btreeinitnum(int num);
void	btreeadd_left(t_bnode *root, t_bnode *leaf);
t_bnode	*btreeadd_left_num(t_bnode *root, int num);
void	btreeadd_right(t_bnode *root, t_bnode *leaf);
t_bnode	*btreeadd_right_num(t_bnode *root, int num);
t_btree	*btreepush(t_btree *stack, t_bnode *bnode);
t_btree	*btreepushnum(t_btree *stack, int num);
t_bnode	*btreepop(t_btree *stack);
void	btreedelall(t_btree *btree);

#endif
