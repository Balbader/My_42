# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balbader <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 12:56:22 by balbader          #+#    #+#              #
#    Updated: 2020/09/30 09:08:44 by balbader         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = includes

SRCS = srcs/ft_putchar.c \
	   srcs/ft_swap.c \
	   srcs/ft_strlen.c \
	   srcs/ft_strcmp.c \
	   srcs/ft_putstr.c

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -I $(HEADER)

$(NAME) : $(OBJS)
		ar rc ${NAME} ${OBJS}

.c.0 :
		$(CC) ${CFLAGS} -c $< -o ${<:.c=.o}

all : $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean re fclean
