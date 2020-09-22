/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbader <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:34:43 by balbader          #+#    #+#             */
/*   Updated: 2020/09/22 19:42:45 by balbader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdilb.h>

int		ft_strlen(char *str)
{
	int		i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*dest;
	
	i = 0;
	j = 0;
	while (i < size)
		j = j + ft_strlen(strs[i++]);
	if (size > 0)
		j = j + (size - 1) * ft_strlen(sep);
	if (!(dest = malloc((j + 1) * sizeof(char))))
		return (0);
	i = 0;
	j = 0;
	while (i < size)
	{
		ft_strcpy(dest + j, strs[i]);
		j = j + ft_strlen(strs[i]);
		if (++i < size)
			j += dest + j + ft_strlen(sep) - ft_strcpy(dest + j, sep);
	}
	dest[j] = '\0';
	return (dest);
	
}

int		main(int ac, int **av)
{}
