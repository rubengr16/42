/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 10:04:13 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/15 18:52:53 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sol(int sol[4][4], char inp[16]);

int	sum_row(int sol[4]);

int	backtracking(int sol[4][4], int row, int col, char inp[16])
{
	int	cand;
	int	val_sol;

	cand = 0;
	val_sol = 0;
	if (row == 4)
		return (is_sol(sol, inp));
	else
	{
		cand = 1;
		while (cand < 5 && !val_sol)
		{
			sol[row][col] = cand;
			if (col == 3 && sum_row(sol[row]) == 10)
				val_sol = backtracking(sol, row + 1, 0, inp);
			else if (col < 3)
				val_sol = backtracking(sol, row, col + 1, inp);
			if (!val_sol)
			{
				cand++;
				sol[row][col] = 0;
			}
		}
		return (val_sol);
	}
}

int	backtracking_call(int sol[4][4], char inp[16])
{
	return (backtracking(sol, 0, 0, inp));
}
