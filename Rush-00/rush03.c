/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbader <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:32:20 by balbader          #+#    #+#             */
/*   Updated: 2020/09/12 18:15:10 by balbader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_line(int i, int y)
{
	i = 1;
	while (i <= y)
	{
		if (i <= 0)
			return ;
		else if (i == 1)
			ft_putchar('A');
		else if (i > 1 && i < y)
			ft_putchar('B');
		else if (i == y)
			ft_putchar('C');
		i++;
	}
}

void	ft_print_in_between(int i, int x)
{
	i = 1;
	while (i <= x)
	{
		if (i <= 0)
			return ;
		else if (i == 1)
			ft_putchar('B');
		else if (i > 1 && i < x)
			ft_putchar(' ');
		else if (i == x)
			ft_putchar('B');
		i++;
	}
}

void	rush(int x, int y)
{
	int i;
	int j;

	i = 1;
	ft_print_line(i, x);
	ft_putchar('\n');
	j = 1;
	while (j < y - 1)
	{
		i = 1;
		ft_print_in_between(i, x);
		j++;
		ft_putchar('\n');
	}
	i = 1;
	if (y > 1)
	{
		ft_print_line(i, x);
		ft_putchar('\n');
	}
}
