/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:54:26 by jmazoyer          #+#    #+#             */
/*   Updated: 2020/09/27 19:02:44 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int		ft_get_nbrlen(char **number)
{
	char	*nbr;
	int		len;

	nbr = *number;
	while (*nbr == '0' && *(nbr + 1))
		nbr++;
	*number = nbr;
	len = 0;
	while (*nbr)
	{
		if (*nbr < '0' || *nbr > '9')
			return (ERROR);
		nbr++;
		len++;
	}
	return (len);
}

int		ft_atoi_triplet(char *nbr, int size)
{
	int			result;

	result = 0;
	while (size-- > 0)
		result = result * 10 + *nbr++ - '0';
	return (result);
}

int		ft_print_number(char *str, char *suffix)
{
	ft_putstr(str);
	ft_putstr(suffix);
	return (OK);
}
