/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrazale <lbrazale@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 14:53:07 by lbrazale          #+#    #+#             */
/*   Updated: 2021/08/26 13:16:11 by lbrazale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_sol
{
	int	i;
	int	j;
	int	length;

}	t_sol;

typedef struct s_map
{
	int		x;
	int		y;
	char	**map;
	char	empty;
	char	full;
	char	obstacle;

}	t_map;

void	ft_putchar(char c);
int		is_diff(t_map *map, char *file);
void	ft_print_error(void);
char	*ft_atoi(char *str, int *nb);

int		ft_str(char *str);
void	ft_create_map(t_map *map);
void	ft_fill_map(t_map *map, char *file);
void	ft_print_matrix(t_map *map);
void	ft_set_map(char	*file, t_map *map);

int		ft_file_size(char *str);
void	ft_read_stdin(void);
char	*ft_read_file(char *str);

void	ft_solve_write(t_map *map, t_sol *sol);
void	ft_solve(t_map *map, t_sol *sol);
void	ft_solution(t_map *map, t_sol *sol, int col, int row);
int		ft_pos_sol(t_map *map, int col, int row, int	length);
void	ft_putsol(t_map *map, t_sol *sol);

#endif
