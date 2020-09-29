/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbader <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:50:07 by balbader          #+#    #+#             */
/*   Updated: 2020/09/29 12:56:10 by balbader         ###   ########.fr       */
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
