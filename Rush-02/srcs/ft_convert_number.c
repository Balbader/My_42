/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:38:34 by jmazoyer          #+#    #+#             */
/*   Updated: 2020/09/27 20:35:08 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int		ft_write_triplet(int number, t_dict_entry *dict,
									int dict_size, char *suffix)
{
	int		rest;
	int		mult;
	int		i;

	rest = 0;
	mult = 0;
	i = dict_size;
	while (--i >= 0)
		if (dict[i].number == 0 || (dict[i].number != -1 &&
					(rest = number % dict[i].number) != number &&
					(dict[i].number < 20 || dict[i].number % 10 == 0)))
		{
			if (dict[i].number == 0)
				return (ft_print_number(dict[i].str, NONE));
			if ((mult = number / dict[i].number) && dict[i].number == 100)
				ft_write_triplet(mult, dict, dict_size, SPACE);
			if (dict[i].number == 100)
				ft_print_number(dict[i].str, (rest ? AND : suffix));
			else
				ft_print_number(dict[i].str, (rest ? HYPHEN : suffix));
			if (rest != 0)
				return (ft_write_triplet(rest, dict, dict_size, suffix));
			return (OK);
		}
	return (ERROR);
}

int		ft_write_class(int class_len, t_dict_entry *dict,
									int dict_size, char *suffix)
{
	int		i;

	i = dict_size;
	while (--i >= 0)
		if (dict[i].nbrlen != 0 && dict[i].nbrlen == class_len)
		{
			ft_putstr(dict[i].str);
			ft_putstr(suffix);
			return (OK);
		}
	return (ERROR);
}

char	*ft_get_suffix(t_triplet *array, int size, int i)
{
	int		j;
	char	*suffix;

	suffix = NULL;
	j = i;
	while (++j < size)
	{
		if (j == size - 1 && array[j].number == 0)
		{
			suffix = NONE;
			break ;
		}
		if (j == size - 1 && array[j].number > 0 && array[j].number < 100)
		{
			suffix = AND;
			break ;
		}
		if (array[j].number > 0)
		{
			suffix = COMMA;
			break ;
		}
	}
	return (suffix);
}

int		ft_write_numbers(t_triplet *array, int size,
									t_dict_entry *dict, int dict_size)
{
	int		i;
	char	*suffix;

	i = 0;
	while (i < size)
	{
		if (size == 1 && array[i].number == 0)
			return (ft_write_triplet(array[i].number, dict, dict_size, NONE));
		if (array[i].number != 0)
			ft_write_triplet(array[i].number, dict, dict_size,
					(i < size - 1 ? SPACE : NONE));
		if (array[i].number != 0 && i < size - 1)
		{
			suffix = ft_get_suffix(array, size, i);
			ft_write_class(array[i].suff_len, dict, dict_size, suffix);
		}
		i++;
	}
	return (OK);
}

int		ft_convert_number(char *number, t_dict_entry *dict, int dict_size)
{
	int			nbrlen;
	t_triplet	*array;
	int			size;
	int			i;

	if ((nbrlen = ft_get_nbrlen(&number)) <= 0)
		return (ERROR);
	if (nbrlen > dict[dict_size - 1].nbrlen + 2)
		return (DICT_ERROR);
	size = (nbrlen % 3 == 0) ? nbrlen / 3 : nbrlen / 3 + 1;
	if (!(array = (t_triplet *)malloc(size * sizeof(t_triplet))))
		return (ERROR);
	i = 0;
	while (nbrlen > 0)
	{
		array[i].number = ft_atoi_triplet(number, nbrlen % 3 ? nbrlen % 3 : 3);
		array[i++].suff_len = (size > 1 ? size * 3 - 2 : 0);
		number += nbrlen % 3 ? nbrlen % 3 : 3;
		nbrlen -= nbrlen % 3 ? nbrlen % 3 : 3;
		size--;
	}
	if (ft_write_numbers(array, i, dict, dict_size) == ERROR)
		return (ERROR);
	free(array);
	return (OK);
}
