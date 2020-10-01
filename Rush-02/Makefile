# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmazoyer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/27 18:09:34 by jmazoyer          #+#    #+#              #
#    Updated: 2020/09/27 18:13:00 by jmazoyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(INC_PATH)
RM = rm -fr

INC_PATH = includes
INT = $(addprefix $(INC_PATH)/, $(INC_NAME))
INC_NAME =		ft_rush02.h

SRC_PATH = srcs
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
SRC_NAME =		main.c				\
				ft_parse_dict.c		\
				ft_dict_utils.c		\
				ft_dict_utils2.c	\
				ft_dict_utils3.c	\
				ft_convert_number.c	\
				ft_convert_utils.c	\
				ft_rush02_utils.c	\
				ft_rush02_utils2.c	\
				ft_rush02_utils3.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
