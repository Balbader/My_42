/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:06:35 by jmazoyer          #+#    #+#             */
/*   Updated: 2020/09/27 17:10:20 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int		ft_dict_strlen(char *str)
{
	int		len;
	int		i;

	len = 0;
	while (*str != '\n')
	{
		if (*str == ' ')
		{
			i = 1;
			while (str[i] == ' ')
				i++;
			if (str[i] == '\n')
				break ;
			else
				str = &(str[i - 1]);
		}
		str++;
		len++;
	}
	return (len > 0 ? len : ERROR);
}

int		ft_dict_nbrlen(char *str)
{
	int		len;

	len = 0;
	while (*str >= '0' && *str <= '9')
	{
		str++;
		len++;
	}
	return (len > 0 ? len : ERROR);
}

int		ft_dict_atoi(char *str)
{
	int		nbr;

	nbr = 0;
	while (*str >= '0' && *str <= '9')
		nbr = nbr * 10 + *str++ - '0';
	return (nbr);
}

int		ft_dict_strdup(char **dest, char *src)
{
	int		size;
	int		i;
	int		j;

	if ((size = ft_dict_strlen(src)) == ERROR)
		return (ERROR);
	if (!(*dest = (char *)malloc((size + 1) * sizeof(char))))
		return (ERROR);
	i = 0;
	while (*src != '\n')
	{
		if (*src == ' ')
		{
			j = 1;
			while (src[j] == ' ')
				j++;
			if (src[j] == '\n')
				break ;
			else
				src = &src[j - 1];
		}
		(*dest)[i++] = *src++;
	}
	(*dest)[i] = '\0';
	return (TRUE);
}
