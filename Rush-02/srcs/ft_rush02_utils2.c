/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:10:51 by jmazoyer          #+#    #+#             */
/*   Updated: 2020/09/27 18:18:27 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == INT_MIN)
	{
		ft_putnbr(INT_MIN / 10);
		ft_putchar(-(INT_MIN % 10) + '0');
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_print_dict(t_dict_entry *dict, int dict_size)
{
	int		i;

	i = 0;
	while (i < dict_size)
	{
		ft_putstr(dict[i].str);
		ft_putstr(" | ");
		ft_putstr("nbrlen = ");
		ft_putnbr(dict[i].nbrlen);
		ft_putstr(" | ");
		ft_putstr("number = ");
		ft_putnbr(dict[i++].number);
		ft_putstr("\n");
	}
}
