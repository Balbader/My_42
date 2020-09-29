/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbader <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:29:24 by balbader          #+#    #+#             */
/*   Updated: 2020/09/29 12:53:29 by balbader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);

char	*ft_rev_int_tab(char *tab, int size)
{
	int		i;
	char	tmp;

	i = 0;
	if (size == 0)
		size++;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
	tab[size] = '\0';
	return (tab);
}

int		check_base(char *str)
{
	int m;
	int p;

	m = 0;
	p = 0;
	while (str[m])
	{
		while (str[p])
		{
			if ((str[p] == '+' || str[p] == '-') ||
					(str[m] == str[p] && m != p) ||
					(str[p] >= 9 && str[p] <= 13) ||
					(str[p] == ' '))
				return (1);
			p++;
		}
		p = 0;
		m++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_putnbr_base(int nb, char *base, char *tab)
{
	int				i;
	int				j;
	int				neg;
	unsigned int	nbr;

	neg = 1;
	j = 0;
	i = ft_strlen(base);
	nbr = nb;
	if (nb < 0)
	{
		neg = -1;
		nbr = -nb;
	}
	if (nbr == 0)
		tab[j] = base[nbr % i];
	while (nbr)
	{
		tab[j++] = base[nbr % i];
		nbr /= i;
	}
	if (neg < 0)
		tab[j++] = '-';
	return (ft_rev_int_tab(tab, j));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len1;
	int		len2;
	char	*tab;
	int		nombre;

	len1 = ft_strlen(base_to);
	len2 = ft_strlen(base_from);
	tab = malloc(20 * sizeof(char));
	if ((check_base(base_to) == 1) || (check_base(base_from) == 1) ||
			len1 < 2 || len2 < 2)
		return (NULL);
	nombre = ft_atoi_base(nbr, base_from);
	ft_putnbr_base(nombre, base_to, tab);
	return (tab);
}
