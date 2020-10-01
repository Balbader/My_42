/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:00:44 by jmazoyer          #+#    #+#             */
/*   Updated: 2020/09/27 23:31:19 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int		ft_record_dict_entry(t_dict_entry *dict, char *dict_buffer,
									int dict_size)
{
	static int	i = 0;
	int			j;

	(void)dict_size;
	j = 0;
	dict[i].nbrlen = ft_dict_nbrlen(&dict_buffer[j]);
	if (dict[i].nbrlen <= 0)
		return (ERROR);
	if (dict[i].nbrlen >= 4 && dict[i].nbrlen % 3 != 1)
		return (ERROR);
	if (dict[i].nbrlen >= 4 && ft_check_class(&dict_buffer[j]) == ERROR)
		return (ERROR);
	if (dict[i].nbrlen < 4)
		dict[i].number = ft_dict_atoi(&dict_buffer[j]);
	while (dict_buffer[j] != ':')
		j++;
	while (dict_buffer[++j] == ' ')
		;
	if (ft_dict_strdup(&(dict[i++].str), &dict_buffer[j]) == ERROR)
		return (ERROR);
	if (i == dict_size)
		i = 0;
	return (TRUE);
}

int		ft_parse_dict_entries(t_dict_entry *dict, char *dict_buffer,
									int dict_buffer_size, int dict_size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < dict_buffer_size)
	{
		j = i;
		if (dict_buffer[i] < '0' || dict_buffer[i] > '9')
			continue ;
		while (dict_buffer[i] >= '0' && dict_buffer[i] <= '9')
			i++;
		i = ft_jump_spaces(dict_buffer, i);
		if (dict_buffer[i] != ':')
			continue ;
		i = ft_jump_spaces(dict_buffer, i + 1);
		if (dict_buffer[i] < 32 && dict_buffer[i] > 126)
			continue ;
		while (dict_buffer[i] >= 32 && dict_buffer[i] <= 126)
			i++;
		if (dict_buffer[i] != '\n')
			continue ;
		if (ft_record_dict_entry(dict, &dict_buffer[j], dict_size) == ERROR)
			return (ERROR);
	}
	return (TRUE);
}

void	ft_initialize_dict_entries(t_dict_entry *dict, int dict_size)
{
	int		i;

	i = 0;
	while (i < dict_size)
	{
		dict[i].str = NULL;
		dict[i].nbrlen = 0;
		dict[i++].number = -1;
	}
}

int		ft_check_key_val(t_dict_entry *dict, int dict_size)
{
	t_dict_entry	*ref_dict;
	int				ref_size;
	int				i;
	int				j;

	ref_size = ft_parse_dict(DEFAULT_DICT, &ref_dict);
	i = -1;
	while (++i < ref_size)
	{
		j = -1;
		if (ref_dict[i].number != -1)
		{
			while (++j < dict_size)
				if (ref_dict[i].number == dict[j].number)
					break ;
		}
		else
			while (++j < dict_size)
				if (ref_dict[i].nbrlen == dict[j].nbrlen)
					break ;
		if (j == dict_size)
			return (ERROR);
	}
	return (ft_free_dict(ref_dict, NULL, ref_size, NULL));
}

int		ft_parse_dict(char *dict_name, t_dict_entry **dict)
{
	int		dict_size;
	char	*dict_buffer;
	int		dict_buffer_size;

	if ((dict_buffer_size = ft_get_file_size(dict_name)) <= 0)
		return (ft_dict_error(*dict, dict_name, 0, NULL));
	if (!(dict_buffer = (char *)malloc(dict_buffer_size * sizeof(char))))
		return (ft_dict_error(*dict, dict_name, 0, NULL));
	if ((dict_size = ft_get_dict_size(dict_name, dict_buffer, dict_buffer_size))
			< 0)
		return (ft_dict_error(*dict, dict_name, dict_size, dict_buffer));
	if (!(*dict = (t_dict_entry *)malloc(dict_size * sizeof(t_dict_entry))))
		return (ft_dict_error(*dict, dict_name, dict_size, dict_buffer));
	ft_initialize_dict_entries(*dict, dict_size);
	if (ft_parse_dict_entries(*dict, dict_buffer, dict_buffer_size, dict_size)
			== ERROR)
		return (ft_dict_error(*dict, dict_name, dict_size, dict_buffer));
	free(dict_buffer);
	ft_sort_dict(*dict, dict_size);
	if (ft_check_dict(*dict, dict_size) == ERROR)
		return (ft_dict_error(*dict, dict_name, dict_size, NULL));
	if (ft_strcmp(dict_name, DEFAULT_DICT) != 0)
		if (ft_check_key_val(*dict, dict_size) == ERROR)
			return (ft_dict_error(*dict, dict_name, dict_size, NULL));
	return (dict_size);
}
