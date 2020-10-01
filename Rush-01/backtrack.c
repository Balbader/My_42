/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:43:46 by threiss           #+#    #+#             */
/*   Updated: 2020/09/19 22:06:22 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int		ft_backtracking(char **tab, int line, int col, char nb)
{
	if (line == '4' && col == '4')
	{
		ft_print_tab(tab);
		return (1);			// arrivé à tab[4][4] -> tout resolu
	}
	while (nb <= '4')
	{
		tab[line][col] = nb;
		if (!ft_full_check(tab, line, col, nb))
			tab[line][col] = '0';
		else
			nb = '1';
		if (col == '4')
			ft_backtracking(tab, line + 1, 1, nb);
		else
			ft_backtracking(tab, line, col + 1, nb);
		nb++;
	}
	return (0);
}

int		ft_full_check(char **tab, int line, int col, char nb)
{
	if (!ft_check_line_col(tab, line, col, nb))
		return (0);
	if (!ft_check_views(tab, line, col))
		return (0);
	return (1);
}

void		ft_print_tab(char **tab)
{
	int		line;
	int		col;

	line = 1;
	while (line < 5)
	{
		col = 1;
		while (col < 5)
		{
			ft_putchar(tab[line][col]);
			if (col < 4)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		line++;
	}
}
