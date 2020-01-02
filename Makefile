# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 14:27:47 by atahiri           #+#    #+#              #
#    Updated: 2019/12/29 22:19:03 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
AR= ar
FLAGS = -Wall -Werror -Wextra
SRC = *.c
all:$(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	$(AR) rc $(NAME) *.o
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re:fclean all
