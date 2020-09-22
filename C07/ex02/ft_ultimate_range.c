/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbader <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:50:07 by balbader          #+#    #+#             */
/*   Updated: 2020/09/22 18:54:58 by balbader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (!(*range = (int*)malloc(sizeof(int*) * (max - min))))
		return (-1);
	while (i < max - min)
	{
		(*range)[i] = i + min;
		i++;
	}
	return (i);
}
#include <stdio.h>
int main()
{
	int	i;
	int *test;

	i = 0;
	test = 0;
	printf("%d", ft_ultimate_range(&test, 6, 5));
	while (i < 0)
	{
		printf("%d\n", test[i]);
		i++;
	}
	free(test);
	return (0);
}
