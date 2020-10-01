/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush02.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:28:35 by jmazoyer          #+#    #+#             */
/*   Updated: 2020/09/27 20:18:20 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH02_H
# define FT_RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

typedef struct	s_dict_entry
{
	char	*str;
	int		nbrlen;
	int		number;
}				t_dict_entry;

typedef struct	s_triplet
{
	int		number;
	int		suff_len;
}				t_triplet;

# define DEFAULT_DICT		"numbers.dict"

# define BUFFER_SIZE		4096

# define DICT_ERROR			-2
# define ERROR				-1
# define OK					0

# define FALSE				0
# define TRUE				1

# define SPACE				" "
# define NONE				""
# define COMMA				", "
# define AND				" and "
# define HYPHEN				"-"

void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(char *src);
char			*ft_strldup(char *src, int size);

int				ft_convert_number(char *number, t_dict_entry *dict,
									int dict_size);
int				ft_get_nbrlen(char **number);
int				ft_atoi_triplet(char *nbr, int size);
int				ft_print_number(char *str, char *suffix);

int				ft_parse_dict(char *dict_name, t_dict_entry **dict);
int				ft_get_file_size(char *file);
int				ft_get_dict_size(char *dict_name,
									char *dict_buffer, int dict_buffer_size);
int				ft_dict_nbrlen(char *str);
int				ft_dict_atoi(char *str);
int				ft_dict_strdup(char **dest, char *src);
int				ft_jump_spaces(char *dict_buffer, int i);
void			ft_sort_dict(t_dict_entry *dict, int dict_size);
int				ft_check_dict(t_dict_entry *dict, int dict_size);
int				ft_check_class(char *buffer);

void			ft_print_dict(t_dict_entry *dict, int dict_size);
int				ft_free_dict(t_dict_entry *dict, char *dict_name,
									int dict_size, char *dict_buffer);
int				ft_return_error(t_dict_entry *dict, char *dict_name,
									int dict_size, char *dict_buffer);
int				ft_dict_error(t_dict_entry *dict, char *dict_name,
									int dict_size, char *dict_buffer);

#endif
