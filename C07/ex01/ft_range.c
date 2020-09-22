/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbader <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:19:36 by balbader          #+#    #+#             */
/*   Updated: 2020/09/22 09:16:53 by balbader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;

	i = 0;
	if (min >= max)
		return (NULL);
	if (!(tab = (int *)malloc(sizeof(int) * (max - min))))
		return (0);
	while (i < max - min)
	{
		tab[i] = i + min;
		i++;
	}
	return (tab);
}

#include <stdio.h>
int main()
{
	int	i;
	int	*test;

	i = 0;
	test = ft_range(5, 25);
	while (i < 20)
	{
		printf("%d\n", test[i]);
		i++;
	}
	free(test);
	return (0);
}
