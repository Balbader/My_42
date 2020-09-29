/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbader <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:52:56 by balbader          #+#    #+#             */
/*   Updated: 2020/09/29 12:54:52 by balbader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		base_length(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		inside_base(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		search_base(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int cmp;
	int resultat;

	i = 0;
	cmp = 1;
	resultat = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			cmp *= -1;
		i++;
	}
	while (str[i] && inside_base(base, str[i]) == 1)
	{
		resultat *= base_length(base);
		resultat += search_base(base, str[i]);
		i++;
	}
	return (resultat * cmp);
}
