/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balbader <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:26:31 by balbader          #+#    #+#             */
/*   Updated: 2020/09/27 19:09:05 by balbader         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_display_file(char *str)
{
	int		fd;
	int		n;
	char	buf[4096];

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	while ((n = read(fd, buf, 4096)) > 0)
		write(1, buf, n);
}

int		main(int ac, char **av)
{
   if (ac < 2)
	   ft_putstr("File name missing.");
   else if (ac > 2)
	   ft_putstr("Too many arguments.");
   else
	   ft_display_file(av[1]);
   return (0);
}
