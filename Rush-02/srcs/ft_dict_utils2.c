/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:01:45 by jmazoyer          #+#    #+#             */
/*   Updated: 2020/09/27 23:30:31 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int		ft_jump_spaces(char *dict_buffer, int i)
{
	while (dict_buffer[i] == ' ')
		i++;
	return (i);
}

int		ft_get_file_size(char *file)
{
	int				fd;
	char			buffer[BUFFER_SIZE];
	int				bytes_read;
	int				file_size;

	if ((fd = open(file, O_RDONLY)) <= 2)
		return (ERROR);
	bytes_read = 0;
	file_size = 0;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
		file_size += bytes_read;
	close(fd);
	if (bytes_read < 0)
		return (ERROR);
	return (file_size);
}

void	ft_sort_dict(t_dict_entry *dict, int dict_size)
{
	int				i;
	t_dict_entry	tmp;

	i = 0;
	while (i + 1 < dict_size)
	{
		if (dict[i].nbrlen > dict[i + 1].nbrlen)
		{
			tmp = dict[i + 1];
			dict[i + 1] = dict[i];
			dict[i] = tmp;
			i = -1;
		}
		else if (dict[i].nbrlen == dict[i + 1].nbrlen)
		{
			if (dict[i].number > dict[i + 1].number)
			{
				tmp = dict[i + 1];
				dict[i + 1] = dict[i];
				dict[i] = tmp;
				i = -1;
			}
		}
		i++;
	}
}

int		ft_check_dict(t_dict_entry *dict, int dict_size)
{
	int		i;

	i = 0;
	while (i < dict_size - 1)
	{
		if (dict[i].nbrlen < 4 && dict[i].number == dict[i + 1].number)
			if (ft_strcmp(dict[i].str, dict[i + 1].str) != 0)
				return (ERROR);
		if (dict[i].nbrlen >= 4 && dict[i].nbrlen == dict[i + 1].nbrlen)
			if (ft_strcmp(dict[i].str, dict[i + 1].str) != 0)
				return (ERROR);
		i++;
	}
	return (OK);
}

int		ft_check_class(char *buffer)
{
	if (*buffer++ != '1')
		return (ERROR);
	while (*buffer >= '0' && *buffer <= '9')
		if (*buffer++ != '0')
			return (ERROR);
	return (OK);
}
