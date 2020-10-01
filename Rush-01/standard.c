/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:25:53 by threiss           #+#    #+#             */
/*   Updated: 2020/09/19 22:06:29 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_init_malloc(void)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * 6)))
		return (0);
	while (i < 6)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * 6)))
			return (0);
		i++;
	}
	return (tab);
}

char		**ft_fill_tab(char **tab, char *str)			// lignes à supprimer > 25 lignes
{
	int		line;
	int		col;
	int		i;

	line = 0;
	i = 0;
	while (i < 16)			// fill in line 1 + line 6
	{
		col = 1;
		while (col < 6 - 1)
		{
			tab[line][col] = str[i];
			col++;
			i += 2;
		}
		line = 5;
	}
	col = 0;
	while (i < 32)		// fill in col 1 + col 6
	{
		line = 1;
		while (line < 6 - 1)
		{
			tab[line][col] = str[i];
			line++;
			i += 2;
		}
		col = 5;
	}
	return (ft_fill_inner_tab(tab));
}

char		**ft_fill_inner_tab(char **tab)
{
	int		line;
	int		col;

	line = 1;
	while (line < 5)
	{
		col = 1;
		while (col < 5)
		{
			tab[line][col] = '0';
			col++;
		}
		line++;
	}
	return (tab);
}
