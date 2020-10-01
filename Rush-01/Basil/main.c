/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:20:15 by threiss           #+#    #+#             */
/*   Updated: 2020/09/19 22:06:26 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int		main(int ac, char **av)
{
	char		**tab;
	if (ac == 2)
	{
		if (check_param(av[1]))		// if params are ok (0 - 4, space % 2 etc)
		{
			tab = ft_fill_tab(ft_init_malloc(), av[1]); // malloc +  0's
			ft_backtracking(tab, 1, 1, '1');
		//	ft_print_tab(tab);
		}
		else
			ft_putchar('N');
	}
	else
		write(1, "Error", 5);
	ft_putchar('\n');
	return (0);
}
