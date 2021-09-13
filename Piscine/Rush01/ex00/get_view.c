/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 10:31:34 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/15 18:25:31 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	get_up_view(int sol[4][4], int i)
{
	int	j;
	int	view;
	int	biggest;

	j = 1;
	view = 1;
	biggest = sol[0][i];
	while (j < 4)
	{
		if (biggest < sol[j][i])
		{
			view++;
			biggest = sol[j][i];
		}
		j++;
	}
	return (view + '0');
}

char	get_down_view(int sol[4][4], int i)
{
	int	j;
	int	view;
	int	biggest;

	j = 2;
	view = 1;
	biggest = sol[3][i];
	while (j >= 0)
	{
		if (biggest < sol[j][i])
		{
			view++;
			biggest = sol[j][i];
		}
		j--;
	}
	return (view + '0');
}

char	get_left_view(int sol[4][4], int i)
{
	int	j;
	int	view;
	int	biggest;

	j = 1;
	view = 1;
	biggest = sol[i][0];
	while (j < 4)
	{
		if (biggest < sol[i][j])
		{
			view++;
			biggest = sol[i][j];
		}
		j++;
	}
	return (view + '0');
}

char	get_right_view(int sol[4][4], int i)
{
	int	j;
	int	view;
	int	biggest;

	j = 2;
	view = 1;
	biggest = sol[i][3];
	while (j >= 0)
	{
		if (biggest < sol[i][j])
		{
			view++;
			biggest = sol[i][j];
		}
		j--;
	}
	return (view + '0');
}
