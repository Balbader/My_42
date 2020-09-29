/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbader <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:34:43 by balbader          #+#    #+#             */
/*   Updated: 2020/09/29 12:27:41 by balbader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_length(char **strs, int size, char *sep)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (i < size)
	{
		length = length + ft_strlen(strs[i]);
		i++;
	}
	length = length + (size - 1) * ft_strlen(sep) + 1;
	return (length);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*dest;

	i = 0;
	if (size == 0)
	{
		if (!(dest = malloc(sizeof(char))))
			return (NULL);
		*dest = 0;
		return (dest);
	}
	if (!(dest = malloc(sizeof(char) * ft_length(strs, size, sep))))
		return (NULL);
	*dest = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i < size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}
