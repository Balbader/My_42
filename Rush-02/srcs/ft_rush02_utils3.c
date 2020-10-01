/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:17:08 by jmazoyer          #+#    #+#             */
/*   Updated: 2020/09/27 17:27:32 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int		ft_free_dict(t_dict_entry *dict, char *dict_name,
									int dict_size, char *dict_buffer)
{
	int		i;

	if (dict_buffer)
		free(dict_buffer);
	if (dict_name)
		free(dict_name);
	i = -1;
	if (dict)
		while (++i < dict_size)
			if (dict[i].str)
				free(dict[i].str);
	if (dict)
		free(dict);
	return (OK);
}

int		ft_return_error(t_dict_entry *dict, char *dict_name,
									int dict_size, char *dict_buffer)
{
	ft_putstr("Error\n");
	ft_free_dict(dict, dict_name, dict_size, dict_buffer);
	return (ERROR);
}

int		ft_dict_error(t_dict_entry *dict, char *dict_name,
									int dict_size, char *dict_buffer)
{
	ft_putstr("Dict Error\n");
	ft_free_dict(dict, dict_name, dict_size, dict_buffer);
	return (ERROR);
}
