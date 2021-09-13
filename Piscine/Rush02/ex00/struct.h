/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugonzal <jugonzal@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:19:39 by jugonzal          #+#    #+#             */
/*   Updated: 2021/08/22 14:30:51 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_node
{
	char			*id;
	char			*nb_str;
	int				size;
	struct s_node	*next;	
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
}	t_list;

void	ft_write_num(t_list *list, char *num);

void	ft_init(t_list *list);
int		ft_empty(t_list *list);
void	ft_insert(t_list *list, char *id, char *nb_str, int size);
char	*ft_search_bigger(t_list *list, int size);
char	*ft_search_little(t_list *list, char id, int size);

void	ft_putstr(char *str);
char	*ft_strncpy(char *dest, char *src, int len);
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);

int		ft_open(char *str);
int		ft_file_size(char *str);
char	*ft_read_file(char *str);

char	*ft_trim(char *str);
int		ft_strlen2(char *str);	
int		ft_strlen3(char *str);
void	set_info(t_list *list, char *str);
#endif
