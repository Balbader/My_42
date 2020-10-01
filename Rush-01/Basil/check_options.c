/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbader <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 12:59:25 by balbader          #+#    #+#             */
/*   Updated: 2020/09/20 18:22:26 by balbader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mylib.h>

void	check_fixed_pos(char **tab, int line, int col)
{
	int		i;
	int		j;

	i = 1;
	while (i < 6)	// Check top-line view == 4
	{
		if (tab[0][i] == '4')
		{
			j = 1;
			while (j < 5)
			{
				tab[j][1] = j;
				j++;
			}
		}
		i++;
	}
	i = 1;
	while (i > 6)	// Check bottom-line view == 4
	{
		if (tab[5][i] == '4')
		{
			j = 1;
			while (j < 5)
			{
				tab[j][1] = j;
				j++;
			}
		}
		i--;
	}
	i = 1;
	while (i < 6) // Check left_col view == 4
	{
		if (tab[i][0] == '4')
		{
			j = 1;
			while (j < 5)
			{
				tab[i][1] = j;
				j++;
			}
		}
		i++;
	}
	i = 1;
	while (i > 6) //check right col view == 4	
	{
		if (tab[i][5] == '4')
		{
			j = 1;
			while (j < 5)
			{
				tab[i][5] == j;
				j++;
			}
		}
		i++;
	}
	i = 1;
	if (tab[0][i] == '1') // top line  view == 1
		tab[1][i] == '4';
	if (tab[5][i] == '1') // bottom line view == 1
		tab[1][i] == '4';
	if (tab[i][0] == '1') // left col view == 1
		tab[1][i] == '4';
	if (tab[i][5] == '1') // right col view == 1
		tab[1][i] == '4';
}
