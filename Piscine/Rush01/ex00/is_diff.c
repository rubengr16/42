/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_diff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:19:16 by rgallego          #+#    #+#             */
/*   Updated: 2021/08/15 18:25:59 by rgallego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_diff(int sol[4][4], int i)
{
	int	cnt1;
	int	cnt2;
	int	diff;

	cnt1 = 0;
	diff = 1;
	while (cnt1 < 3 && diff)
	{
		cnt2 = cnt1 + 1;
		while (cnt2 < 4 && diff)
		{
			if (sol[cnt1][i] == sol[cnt2][i])
				diff = 0;
			cnt2++;
		}
		cnt1++;
	}
	return (diff);
}
