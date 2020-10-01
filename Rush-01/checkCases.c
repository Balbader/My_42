/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkCases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:44:46 by threiss           #+#    #+#             */
/*   Updated: 2020/09/19 22:06:31 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int		ft_check_line_col(char **tab, int line, int col, char nb)
{
	int		i_line;
	int		i_col;

	i_line = 1;
	i_col = 1;
	while (i_line < line)
	{
		if (tab[i_line][1] == nb)
			return (0);
		i_line++;
	}
	while (i_col < col)
	{
		if (tab[1][i_col] == nb)
			return (0);
		i_col++;
	}
	return (1);
}

int		ft_check_views(char **tab, int line, int col)
{
	int		i;
	int		view;

	i = 1;
	view = 1;
	while (i < 4)					// line
	{
		if (tab[line][i] < tab[line][i + 1])
			view++;
		i++;
	}
	if (view != tab[line][0])
		return (0);

	i = 4;
	view = 1;
	while (i > 1)					// line
	{
		if (tab[line][i] < tab[line][i - 1])
			view++;
		i++;
	}
	if (view != tab[line][5])
		return (0);
	i = 1;
	view = 1;
	while (i < 4)					// col
	{
		if (tab[i][col] < tab[i + 1][col])
			view++;
		i++;
	}
	if (view != tab[0][col])
		return (0);
	i = 4;
	view = 1;
	while (i > 1)					// col
	{
		if (tab[i][col] < tab[i - 1][col])
			view++;
		i++;
	}
	if (view != tab[5][col])
		return (0);
	return (1);
}


/*{
	char	view_up;		// delete view_variables if no lines left
	char	view_down;
	char	view_left;
	char	view_right;
	int		i;

	view_up = tab[0][col];
	ft_putchar(view_up);
	view_down = tab[5][col];
	ft_putchar(view_down);
	view_left = tab[line][0];
	ft_putchar(view_left);
	view_right = tab[line][5];
	ft_putchar(view_right);
	// check views == last nb in line/col
	return (1);
}*/
