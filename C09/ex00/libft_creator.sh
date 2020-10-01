# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balbader <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 12:30:39 by balbader          #+#    #+#              #
#    Updated: 2020/09/29 13:24:59 by balbader         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -c ft_putchar.c ft_putstr.c  ft_strcmp.c  ft_strlen.c  ft_swap.c
ar rc libft.a ft_putchar.o ft_putstr.o  ft_strcmp.o  ft_strlen.o  ft_swap.o

