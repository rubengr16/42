/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 10:31:34 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/15 18:28:10 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_diff(int sol[4][4], int i);
int	get_up_view(int sol[4][4], int i);
int	get_down_view(int sol[4][4], int i);
int	get_left_view(int sol[4][4], int i);
int	get_right_view(int sol[4][4], int i);

int	sum_row(int sol[4])
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	while (i < 4)
	{
		sum += sol[i];
		i++;
	}
	return (sum);
}

int	sum_col(int sol[4][4], int j)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < 4)
	{
		sum += sol[i][j];
		i++;
	}
	return (sum);
}

int	is_sol(int sol[4][4], char inp[16])
{
	int	i;
	int	val_sol;

	i = 0;
	val_sol = 1;
	while (i < 4 && val_sol)
	{
		if (sum_col(sol, i) != 10 || !is_diff(sol, i)
			|| inp[i] != get_up_view(sol, i)
			|| inp[i + 4] != get_down_view(sol, i))
			val_sol = 0;
		i++;
	}
	i = 8;
	while (i < 12 && val_sol)
	{
		if (inp[i] != get_left_view(sol, i % 4)
			|| inp[i + 4] != get_right_view(sol, i % 4))
			val_sol = 0;
		i++;
	}
	return (val_sol);
}
