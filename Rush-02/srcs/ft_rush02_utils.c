/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:53:27 by jmazoyer          #+#    #+#             */
/*   Updated: 2020/09/27 17:27:32 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (i > 0)
		write(1, str, i);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (int)((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strdup(char *src)
{
	unsigned int	i;
	char			*dup;

	i = 0;
	while (src[i])
		i++;
	if ((dup = (char *)malloc(++i * sizeof(char))) == NULL)
		return (NULL);
	while (i-- > 0)
		dup[i] = src[i];
	return (dup);
}

char	*ft_strldup(char *src, int size)
{
	int		i;
	char	*dup;

	if ((dup = (char *)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		dup[i] = src[i];
	dup[size] = '\0';
	return (dup);
}
