/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:58:02 by jmazoyer          #+#    #+#             */
/*   Updated: 2020/09/27 22:04:29 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int		ft_jump_spaces_and_colon(char *dict_buffer, int i)
{
	while (dict_buffer[i] == ' ')
		i++;
	if (dict_buffer[i++] != ':')
		return (ERROR);
	while (dict_buffer[i] == ' ')
		i++;
	return (i);
}

int		ft_is_digit_or_newline(char c)
{
	if ((c >= '0' && c <= '9') || c == '\n')
		return (TRUE);
	return (ERROR);
}

int		ft_compute_dict_size(char *dict_buffer, int dict_buffer_size)
{
	int		dict_size;
	int		i;

	dict_size = 0;
	i = -1;
	while (++i < dict_buffer_size)
	{
		if (dict_buffer[i] == '\n')
			continue ;
		if (dict_buffer[i] < '0' || dict_buffer[i] > '9')
			return (ERROR);
		while (dict_buffer[i] >= '0' && dict_buffer[i] <= '9')
			i++;
		if ((i = ft_jump_spaces_and_colon(dict_buffer, i)) == ERROR)
			return (ERROR);
		if (dict_buffer[i] < 32 && dict_buffer[i] > 126)
			return (ERROR);
		while (dict_buffer[i] >= 32 && dict_buffer[i] <= 126)
			i++;
		if (dict_buffer[i] != '\n')
			return (ERROR);
		dict_size++;
	}
	return (dict_size > 0 ? dict_size : ERROR);
}

int		ft_load_dict(char *dict_name, char *dict_buffer, int dict_buffer_size)
{
	int				fd;
	int				bytes_read;
	int				file_size;

	if ((fd = open(dict_name, O_RDONLY)) <= 2)
		return (ERROR);
	bytes_read = 0;
	file_size = 0;
	while ((bytes_read = read(fd, dict_buffer, dict_buffer_size)) > 0)
		file_size += bytes_read;
	close(fd);
	if (bytes_read < 0)
		return (ERROR);
	return (file_size);
}

int		ft_get_dict_size(char *dict_name,
									char *dict_buffer, int dict_buffer_size)
{
	int		dict_size;

	if (ft_load_dict(dict_name, dict_buffer, dict_buffer_size)
			!= dict_buffer_size)
		return (ERROR);
	if ((dict_size = ft_compute_dict_size(dict_buffer, dict_buffer_size))
			== ERROR)
		return (ERROR);
	return (dict_size);
}
