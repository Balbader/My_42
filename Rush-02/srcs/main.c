/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:55:12 by jmazoyer          #+#    #+#             */
/*   Updated: 2020/09/27 20:47:22 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int		ft_convert_stdin(t_dict_entry *dict, char *dict_name, int dict_size)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	int		error_code;

	while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		if (buffer[bytes_read - 1] == '\n')
			buffer[bytes_read - 1] = '\0';
		else
			buffer[bytes_read] = '\0';
		if ((error_code = ft_convert_number(buffer, dict, dict_size)) < 0)
		{
			if (error_code == ERROR)
				ft_putstr("Error\n");
			else
				ft_putstr("Dict Error\n");
		}
		else
			write(1, "\n", 1);
	}
	if (bytes_read == -1)
		ft_putstr("Error\n");
	return (ft_free_dict(dict, dict_name, dict_size, NULL));
}

int		ft_check_stdin(int argc, char *argv[])
{
	if (argc == 1)
		return (TRUE);
	if (argc == 3)
		if (argv[2][0] == '-' && argv[2][1] == '\0')
			return (TRUE);
	return (FALSE);
}

int		main(int argc, char *argv[])
{
	t_dict_entry	*dict;
	char			*dict_name;
	int				dict_size;
	char			*nbr_to_convert;
	int				call_stdin;

	if (argc > 3)
		return (ft_return_error(NULL, NULL, 0, NULL));
	call_stdin = ft_check_stdin(argc, argv);
	dict_name = (argc == 3) ? ft_strdup(argv[1]) : ft_strdup(DEFAULT_DICT);
	if (dict_name == NULL)
		return (ft_return_error(NULL, NULL, 0, NULL));
	dict = NULL;
	if ((dict_size = ft_parse_dict(dict_name, &dict)) < 0)
		return (ERROR);
	if (call_stdin == TRUE)
		return (ft_convert_stdin(dict, dict_name, dict_size));
	nbr_to_convert = (argc == 3) ? argv[2] : argv[1];
	if ((call_stdin = ft_convert_number(nbr_to_convert, dict, dict_size)) < 0)
		return (call_stdin == ERROR ?
				ft_return_error(dict, dict_name, dict_size, NULL)
				: ft_dict_error(dict, dict_name, dict_size, NULL));
	else
		write(1, "\n", 1);
	return (ft_free_dict(dict, dict_name, dict_size, NULL));
}
